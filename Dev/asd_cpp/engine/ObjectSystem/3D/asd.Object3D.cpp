﻿#include "asd.Object3D.h"
#include "asd.Layer3D.h"
#include "../Registration/asd.EventToDisposeContent.h"
using namespace std;

namespace asd
{
	void Object3D::RaiseOnAdded()
	{
		OnAdded();
	}

	void Object3D::RaiseOnRemoved()
	{
		OnRemoved();
	}

	void Object3D::Dispose()
	{
		Engine::m_changesToCommit.push(make_shared<EventToDisposeContent>(shared_from_this()));
	}

	void Object3D::DisposeImmediately()
	{
		if (GetIsAlive())
		{
			m_isAlive = false;
			OnDispose();
			if (m_owner != nullptr)
			{
				m_owner->ImmediatelyRemoveObject(shared_from_this());
			}
		}
	}

	void Object3D::Update()
	{
		if (!m_isUpdated || !GetIsAlive())
		{
			return;
		}

		OnUpdate();

		OnUpdateInternal();
	}

	void Object3D::OnAdded()
	{
	}

	void Object3D::OnRemoved()
	{
	}

	void Object3D::OnDispose()
	{
	}


	void Object3D::SetLayer(Layer3D* layer)
	{
		m_owner = layer;
	}

	CoreObject3D* Object3D::GetCoreObject() const
	{
		return m_commonObject;
	}

	Object3D::Object3D()
		: m_owner(nullptr)
		, m_commonObject(nullptr)
		, m_isUpdated(true)
		, m_isDrawn(true)
		, m_isAlive(true)
		, m_onUpdatePriorityChanged(nullptr)
	{
	}

	Object3D::~Object3D()
	{

	}

	Layer3D* Object3D::GetLayer() const
	{
		return m_owner;
	}


	bool Object3D::GetIsUpdated() const
	{
		return m_isUpdated;
	}

	void Object3D::SetIsUpdated(bool value)
	{
		m_isUpdated = value;
	}

	bool Object3D::GetIsDrawn() const
	{
		return m_isDrawn;
	}

	void Object3D::SetIsDrawn(bool value)
	{
		m_isDrawn = value;
		GetCoreObject()->SetIsDrawn(value);
	}

	bool Object3D::GetIsAlive() const
	{
		return m_isAlive;
	}

	Vector3DF Object3D::GetPosition() const
	{
		return m_commonObject->GetPosition();
	}

	void Object3D::SetPosition(Vector3DF position)
	{
		m_commonObject->SetPosition(position);
	}

	Vector3DF Object3D::GetRotation() const
	{
		return m_commonObject->GetRotation();
	}

	void Object3D::SetRotation(Vector3DF angle)
	{
		m_commonObject->SetRotation(angle);
	}

	Vector3DF Object3D::GetScale() const
	{
		return m_commonObject->GetScale();
	}

	void Object3D::SetScale(Vector3DF scale)
	{
		m_commonObject->SetScale(scale);
	}

	Matrix44 Object3D::GetLocalMatrix()
	{
		return m_commonObject->GetLocalMatrix();
	}

	/*
	void Object3D::SetLoalMatrixDirectly(Matrix44 localMat)
	{
		m_commonObject->SetLoalMatrixDirectly(localMat);
	}
	*/

	int Object3D::GetUpdatePriority() const
	{
		return m_updatePriority;
	}

	void Object3D::SetUpdatePriority(int value)
	{
		m_updatePriority = value;
		if (m_onUpdatePriorityChanged != nullptr)
		{
			m_onUpdatePriorityChanged(value);
		}
	}


	void Object3D::DrawSpriteAdditionally(Vector3DF upperLeftPos, Vector3DF upperRightPos, Vector3DF lowerRightPos, Vector3DF lowerLeftPos,
		Color upperLeftCol, Color upperRightCol, Color lowerRightCol, Color lowerLeftCol,
		Vector2DF upperLeftUV, Vector2DF upperRightUV, Vector2DF lowerRightUV, Vector2DF lowerLeftUV,
		std::shared_ptr<Texture2D>  texture, AlphaBlendMode alphaBlend, bool depthWrite, bool depthTest)
	{
		auto layer = GetLayer();
		layer->DrawSpriteAdditionally(
			upperLeftPos, upperRightPos, lowerRightPos, lowerLeftPos,
			upperLeftCol, upperRightCol, lowerRightCol, lowerLeftCol,
			upperLeftUV, upperRightUV, lowerRightUV, lowerLeftUV,
			texture, alphaBlend, depthWrite, depthTest);
	}
}