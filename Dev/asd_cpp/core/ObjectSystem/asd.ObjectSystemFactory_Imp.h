﻿
#pragma once

#include "../asd.Core.Base_Imp.h"
#include "asd.ObjectSystemFactory.h"

namespace asd
{
	class ObjectSystemFactory_Imp : public ObjectSystemFactory
	{
	private:
		Core_Imp*	core = nullptr;
		Graphics_Imp* m_graphics;
		Log_Imp* m_logger;
		Vector2DI m_windowSize;

	public:
		ObjectSystemFactory_Imp(Core_Imp* core, Graphics_Imp* graphics, Log_Imp* logger, Vector2DI windowSize);
		virtual ~ObjectSystemFactory_Imp();

		CoreChip2D* CreateChip2D() override;
		CoreTextureObject2D* CreateTextureObject2D() override;
		CoreCameraObject2D* CreateCameraObject2D() override;
		CoreTextObject2D* CreateTextObject2D() override;
		CoreEffectObject2D* CreateEffectObject2D() override;
		CoreMapObject2D* CreateMapObject2D() override;
		CoreGeometryObject2D* CreateGeometryObject2D() override;
		CoreLayer2D* CreateLayer2D() override;

		CoreModelObject3D* CreateModelObject3D() override;
		CoreCameraObject3D* CreateCameraObject3D() override;
		CoreEffectObject3D* CreateEffectObject3D() override;
		CoreDirectionalLightObject3D* CreateDirectionalLightObject3D() override;
		CoreMassModelObject3D* CreateCoreMassModelObject3D() override;
		CoreTerrainObject3D* CreateCoreTerrainObject3D() override;
		CoreLayer3D* CreateLayer3D(RenderSettings settings) override;

		CoreScene* CreateScene() override;
		CorePostEffect* CreatePostEffect() override;

		CoreTransition* CreateTransition() override;

		CoreArcShape* CreateArcShape() override;
		CoreCircleShape* CreateCircleShape() override;
		CoreLineShape* CreateLineShape() override;
		CoreRectangleShape* CreateRectangleShape() override;
		CoreTriangleShape* CreateTriangleShape() override;
		CorePolygonShape* CreatePolygonShape() override;

		CoreCircleCollider* CreateCircleCollider() override;
		CoreLineCollider* CreateLineCollider() override;
		CoreRectangleCollider* CreateRectangleCollider() override;
		CorePolygonCollider* CreatePolygonCollider() override;
	};
}