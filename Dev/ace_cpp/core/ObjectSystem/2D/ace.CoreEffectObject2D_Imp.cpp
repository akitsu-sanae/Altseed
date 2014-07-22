﻿
#include "ace.CoreEffectObject2D_Imp.h"
#include "../../Graphics/Resource/ace.Effect_Imp.h"

namespace ace
{
	Effekseer::Matrix43 CoreEffectObject2D_Imp::CalcEffectMatrix()
	{
		auto pos = GetPosition();

		auto parentMatrix = m_transform.GetParentsMatrix();
		auto matrix = m_transform.GetMatrixToTransform();
		auto mat = parentMatrix * matrix;
		auto v3 = Vector3DF(pos.X, pos.Y, 1);
		auto pos_ = parentMatrix * matrix * v3;

		Effekseer::Matrix43 efMat;
		efMat.Indentity();

		// 転置して代入
		for (auto c = 0; c < 2; c++)
		{
			for (auto r = 0; r < 2; r++)
			{
				efMat.Value[r][c] = mat.Values[c][r];
			}
		}

		// スケール調整(行列式を使用)
		efMat.Value[2][2] = sqrt(efMat.Value[0][0] * efMat.Value[1][1] - efMat.Value[0][1] * efMat.Value[1][0]);

		// 位置調整
		efMat.Value[3][0] = pos.X;
		efMat.Value[3][1] = -pos.Y;
		efMat.Value[3][2] = 0.0f;

		// Y軸回転
		Effekseer::Matrix43 rotyMat;
		Effekseer::Matrix43 ef2Mat;
		rotyMat.RotationY(DegreeToRadian(m_rotation));
		Effekseer::Matrix43::Multiple(ef2Mat, rotyMat, efMat);

		return ef2Mat;
	}

	CoreEffectObject2D_Imp::CoreEffectObject2D_Imp(Graphics_Imp* graphics)
		: CoreObject2D_Imp(graphics)
		, m_effect(nullptr)
		, m_renderer(nullptr)
	{

	}

	CoreEffectObject2D_Imp::~CoreEffectObject2D_Imp()
	{
		SafeRelease(m_effect);
	}

	void CoreEffectObject2D_Imp::SetEffect(Effect* effect)
	{
		SafeSubstitute(m_effect, effect);
	}

	void CoreEffectObject2D_Imp::Play()
	{
		if (m_effect == nullptr) return;
		if (m_renderer == nullptr) return;

		auto e = (Effect_Imp*) m_effect;
		auto ne = e->GetEffect();

		Effekseer::Matrix43 efMat = CalcEffectMatrix();
		
		auto handle = m_renderer->GetEffectManager()->Play(ne, 0.0f, 0.0f, 0.0f);
		m_renderer->GetEffectManager()->SetMatrix(handle, efMat);
		m_handles.push_back(handle);
	}

	void CoreEffectObject2D_Imp::Stop()
	{
		for (auto& h : m_handles)
		{
			m_renderer->GetEffectManager()->StopEffect(h);
		}
		m_handles.clear();
	}

	void CoreEffectObject2D_Imp::StopRoot()
	{
		for (auto& h : m_handles)
		{
			m_renderer->GetEffectManager()->StopRoot(h);
		}
	}

	float CoreEffectObject2D_Imp::GetEffectRotation() const
	{
		return m_rotation;
	}

	void CoreEffectObject2D_Imp::SetEffectRotation(float value)
	{
		m_rotation = value;
	}

	void CoreEffectObject2D_Imp::OnAdded(Renderer2D* renderer)
	{
		assert(m_renderer == nullptr);
		m_renderer = (Renderer2D_Imp*)renderer;
	}

	void CoreEffectObject2D_Imp::OnRemoving(Renderer2D* renderer)
	{
		assert(m_renderer != nullptr);
		
		for (auto& h : m_handles)
		{
			m_renderer->GetEffectManager()->StopEffect(h);
		}

		m_renderer = nullptr;
	}

	void CoreEffectObject2D_Imp::Draw(Renderer2D* renderer)
	{
		// 一定以上たまったら削除処理
		if (m_handles.size() > GCThreshold)
		{
			for (size_t i = 0; i < m_handles.size();)
			{
				if (m_renderer->GetEffectManager()->Exists(m_handles[i]))
				{
					i++;
				}
				else
				{
					for (size_t j = i; j < m_handles.size() - 1; j++)
					{
						m_handles[j] = m_handles[j + 1];
					}
					m_handles.resize(m_handles.size() - 1);
				}
			}
		}

		if (m_syncEffects && m_handles.size() > 0)
		{
			Effekseer::Matrix43 efMat = CalcEffectMatrix();

			for (size_t i = 0; i < m_handles.size();)
			{
				if (m_renderer->GetEffectManager()->Exists(m_handles[i]))
				{
					m_renderer->GetEffectManager()->SetMatrix(m_handles[i], efMat);
					i++;
				}
				else
				{
					for (size_t j = i; j < m_handles.size() - 1; j++)
					{
						m_handles[j] = m_handles[j + 1];
					}
					m_handles.resize(m_handles.size() - 1);
				}
			}
		}
	}
}