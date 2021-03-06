﻿
#pragma once

#include "asd.CoreObject3D.h"

namespace asd
{
	class CoreMassModelObject3D
		: public CoreObject3D
	{
	protected:
		CoreMassModelObject3D(){}
		virtual ~CoreMassModelObject3D(){}

	public:
		virtual void SetMaterialPropertyBlock(MaterialPropertyBlock* block) = 0;

		virtual void SetModel(MassModel* model) = 0;

		virtual void PlayAnimation(const achar* name) = 0;

		virtual void StopAnimation() = 0;

		virtual void CrossFadeAnimation(const achar* name, float time) = 0;

		virtual bool GetIsAnimationPlaying() = 0;


	};
}
