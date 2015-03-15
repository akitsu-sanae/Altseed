﻿#include <list>
#include <exception>
#include "ace.Layer2D.h"
using namespace std;

namespace ace
{
	extern ObjectSystemFactory* g_objectSystemFactory;

	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
	Layer2D::Layer2D()
		: m_coreLayer(nullptr)
		, m_objects()
		, m_components(this)
	{
		m_coreLayer = CreateSharedPtrWithReleaseDLL(g_objectSystemFactory->CreateLayer2D());
		m_commonObject = m_coreLayer;
	}

	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
	Layer2D::~Layer2D()
	{
		for (auto& object : m_objects.GetContents())
		{
			object->SetLayer(nullptr);
		}
	}

	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
	void Layer2D::Update()
	{
		if (!m_isUpdated || !m_isAlive)
		{
			return;
		}

		OnUpdating();
		m_objects.Update();

		for (auto& vanishing : m_objects.GetVanishingContents())
		{
			RemoveObject(vanishing);
		}
		m_objects.GetVanishingContents().clear();

		m_components.Update();
		OnUpdated();
	}

	void Layer2D::BeginUpdating()
	{
		m_coreLayer->BeginUpdating();
	}

	void Layer2D::EndUpdateting()
	{
		m_coreLayer->EndUpdating();
	}

	void Layer2D::DrawAdditionally()
	{
		if (!m_isDrawn)
		{
			return;
		}

		for (auto& object : m_objects.GetContents())
		{
			object->OnDrawAdditionally();
		}
		OnDrawAdditionally();
	}

	void Layer2D::CallDestroy()
	{
		for (auto& o : m_objects.GetContents())
		{
			if (o->GetIsAlive())
			{
				o->CallDestroy();
			}
		}
		OnDispose();
	}


	void Layer2D::OnUpdating()
	{
	}

	void Layer2D::OnUpdated()
	{
	}

	void Layer2D::OnDrawAdditionally()
	{

	}

	void Layer2D::DrawSpriteAdditionally(Vector2DF upperLeftPos, Vector2DF upperRightPos, Vector2DF lowerRightPos, Vector2DF lowerLeftPos,
		Color upperLeftCol, Color upperRightCol, Color lowerRightCol, Color lowerLeftCol,
		Vector2DF upperLeftUV, Vector2DF upperRightUV, Vector2DF lowerRightUV, Vector2DF lowerLeftUV,
		std::shared_ptr<Texture2D>  texture, AlphaBlend alphaBlend, int32_t priority)
	{
		m_coreLayer->DrawSpriteAdditionally(upperLeftPos, upperRightPos, lowerRightPos, lowerLeftPos, upperLeftCol, upperRightCol, lowerRightCol, lowerLeftCol, upperLeftUV, upperRightUV, lowerRightUV, lowerLeftUV, texture.get(), alphaBlend, priority);
	}

	void Layer2D::DrawTextAdditionally(Vector2DF pos, Color color, std::shared_ptr<Font> font, const achar* text, WritingDirection writingDirection, AlphaBlend alphaBlend, int32_t priority)
	{
		m_coreLayer->DrawTextAdditionally(
			pos,
			color,
			font.get(),
			text,
			writingDirection,
			alphaBlend,
			priority);
	}

	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
	void Layer2D::AddObject(const Object2D::Ptr& object)
	{
		ACE_ASSERT(object->GetLayer() == nullptr, "追加しようとしたオブジェクトは、すでに別のレイヤーに所属しています。");
		m_objects.Add(object);
		auto coreObj = object->GetCoreObject();
		m_coreLayer->AddObject(coreObj);
		object->SetLayer(this);
		object->Start();
	}

	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
	void Layer2D::RemoveObject(const Object2D::Ptr& object)
	{
		m_objects.Remove(object);
		m_coreLayer->RemoveObject(object->GetCoreObject());
		object->SetLayer(nullptr);
	}

	const list<Object2D::Ptr>& Layer2D::GetObjects() const
	{
		return m_objects.GetContents();
	}

	void Layer2D::Clear()
	{
		for (auto object : m_objects.GetContents())
		{
			object->SetLayer(nullptr);
		}
		m_objects.Clear();
		m_coreLayer->Clear();
	}
	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
	void Layer2D::AddComponent(const Layer2DComponent::Ptr& component, astring key)
	{
		m_components.Add(component, key);
	}

	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
	const Layer2DComponent::Ptr& Layer2D::GetComponent(astring key)
	{
		return m_components.Get(key);
	}

	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
	bool Layer2D::RemoveComponent(astring key)
	{
		return m_components.Remove(key);
	}

}
