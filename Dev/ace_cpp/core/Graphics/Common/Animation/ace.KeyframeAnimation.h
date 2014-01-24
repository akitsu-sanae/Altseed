﻿
#pragma once

#include "../../../ace.Core.Base.h"
#include "../../../ace.ReferenceObject.h"

#include <Math/ace.Vector2DF.h>

namespace ace
{
	/**
		@brief	Fカーブのキーフレーム
	*/
	class FCurveKeyframe
	{
	public:
		/**
			@brief	時間と値
		*/
		Vector2DF				KeyValue;

		/**
			@brief	制御用ハンドル
		*/
		Vector2DF				LeftHandle;

		/**
		@brief	制御用ハンドル
		*/
		Vector2DF				RightHandle;

		/**
		@brief	補間方法
		*/
		eInterpolationType		InterpolationType;

		FCurveKeyframe()
		{
			InterpolationType = eInterpolationType::INTERPOLATION_TYPE_LINEAR;
		}
	};

	/**
		@brief	キーフレームで指定するアニメーションのクラス
	*/
	class KeyframeAnimation
		: public IReference
	{
	protected:
		KeyframeAnimation() {}
		virtual ~KeyframeAnimation() {}

	public:
		/**
			@brief	名称を取得する。
			@return	名称
		*/
		virtual const achar* GetName() = 0;

		/**
			@brief	名称を指定する。
			@param	name	名称
		*/
		virtual void SetName(const achar* name) = 0;

		/**
			@brief	キーフレームを追加する。
			@param	kf	キーフレーム
		*/
		virtual void AddKeyframe(const FCurveKeyframe& kf) = 0;

		/**
			@brief	指定した時間の値を取得する。
			@param	time	時間
			@return	値
		*/
		virtual float GetValue(float time) = 0;
	};
}