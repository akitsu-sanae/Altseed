﻿
#pragma once

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
#include "ace.Renderer2D.h"
#include "../../ace.Core.Base_Imp.h"

#include <Math/ace.Vector3DF.h>
#include <Math/ace.Vector4DF.h>
#include <Math/ace.Matrix44.h>
#include <Math/ace.RectF.h>

#include <Culling2D.h>

#if _DEBUG
#pragma comment(lib,"Debug/Culling2D.lib")
#else
#pragma comment(lib,"Release/Culling2D.lib")
#endif

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace ace {
	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
	/**
		@brief	2D描画全てを管理するクラス
		@note
		内部で管理しているスプライトは全て、[左上、右上、右下、左下]の順番で情報を格納する。
	*/
	class Renderer2D_Imp : public Renderer2D
	{
	private:
		/**
			@brief	スプライト描画時に使用する頂点
		*/
		struct SpriteVertex
		{
			Vector3DF	Position;
			Vector2DF	UV;
			Color		Color_;
		};

		/**
			@brief	スプライト描画時に使用する定数バッファ
		*/
		struct vector2DF
		{
			float	X;
			float	Y;
		};

		struct  color
		{
			uint8_t	R;
			uint8_t	G;
			uint8_t	B;
			uint8_t	A;
		};

		/**
			@brief	描画イベント
		*/
		struct Event
		{
			enum class eEventType
			{
				Sprite,
				Effect,
			} Type;

			int32_t	Priority;

			union 
			{
				/**
					@brief	スプライト描画イベント
				*/
				struct DrawSprite
				{
					vector2DF	Positions[4];
					color		Colors[4];
					vector2DF	UV[4];
					Texture2D*	TexturePtr;
					AlphaBlend	AlphaBlendState;
				} Sprite;

				/**
				@brief	エフェクト描画イベント
				*/
				struct DrawEffect
				{
					::Effekseer::Handle EffectHandle;
				} Effect;
			} Data;
		};

	private:
		/**
			@brief	最大同時スプライト描画数
		*/
		static const int32_t SpriteCount = 1024;

		/**
			@brief	現在描画しているスプライトの状態
		*/
		struct SpriteState
		{
			Texture2D*	TexturePtr;
			AlphaBlend	AlphaBlendState;
		} m_state;

		/**
			@brief	描画中のスプライト
		*/
		std::vector<Event*>	m_drawingSprites;

		std::vector<Event*>	drawingEffects;

		Graphics_Imp*	m_graphics;
		Log*			m_log;

		std::shared_ptr<ace::VertexBuffer_Imp>	m_vertexBuffer;
		std::shared_ptr<ace::IndexBuffer_Imp>	m_indexBuffer;

		/**
			@brief	テクスチャありのスプライトシェーダー
		*/
		std::shared_ptr<ace::NativeShader_Imp>		m_shader;

		/**
		@brief	テクスチャなしのスプライトシェーダー
		*/
		std::shared_ptr<ace::NativeShader_Imp>		m_shader_nt;

		std::map<int32_t, std::vector<Event>>	m_events;

		RectF									area;

		Effekseer::Manager*						m_effectManager = nullptr;
		EffekseerRenderer::Renderer*			m_effectRenderer = nullptr;

	public:
		Renderer2D_Imp(Graphics* graphics, Log* log);
		virtual ~Renderer2D_Imp();

		void SetArea(const RectF& area) override;

		void DrawCache();

		void ClearCache();

		void AddSprite(Vector2DF positions[4], Color colors[4], Vector2DF uv[4], Texture2D* texture, AlphaBlend alphaBlend, int32_t priority);

		void AddText(Matrix33& parentMatrix, Matrix33& matrix, Vector2DF centerPosition, bool turnLR, bool turnUL, Color color, Font* font, const achar* text, WritingDirection writingDirection, AlphaBlend alphaBlend, int32_t priority) override;

		void AddEffect(::Effekseer::Handle handle, int32_t priority);

		Effekseer::Manager*	GetEffectManager() { return m_effectManager; }

		culling2d::World* CullingWorld = nullptr;

	private:
		void AddEvent(int32_t priority, Event& e);

		void StartDrawing();

		void Draw(Event& e);

		void EndDrawing();

		void DrawSprite();

		void DrawEffect();
	};

	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------

}
