﻿#pragma once

//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include "../asd.common.Base.h"

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace asd
{
	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------

	/**
		@brief	2次元ベクトル
		*/
	struct Vector2DF
	{
	public:
		/**
			@brief	X成分
			*/
		float	X;

		/**
			@brief	Y成分
			*/
		float	Y;

		/**
			@brief	コンストラクタ
			*/
		Vector2DF();

		/**
			@brief	コンストラクタ
			@param	x	X成分
			@param	y	Y成分
		*/
		Vector2DF(float x, float y);

		/**
			@brief	このベクトルの長さを取得する。
		*/
		float GetLength() const
		{
			return sqrt(GetSquaredLength());
		}

		/**
		@brief	このベクトルの長さの二乗を取得する。
		*/
		float GetSquaredLength() const
		{
			return X * X + Y * Y;
		}

		/**
			@brief	このベクトルの長さを設定する。
		*/
		void SetLength(float value)
		{
			float length = GetLength();
			(*this) *= (value / length);
		}

		/**
		@brief	このベクトルの単位ベクトルを取得する。
		*/
		Vector2DF GetNormal()
		{
			float length = GetLength();
			return Vector2DF(X / length, Y / length);
		}

		/**
		@brief	このベクトルの単位ベクトル化する。
		*/
		void Normalize()
		{
			float length = GetLength();
			(*this) /= length;
		}

		/**
			@brief	このベクトルの向きを弧度法で取得する。
		*/
		float GetRadian() const
		{
			return atan2(Y, X);
		}

		/**
			@brief	このベクトルの向きを弧度法で設定する。
			@note 大きさを維持したまま、向きを変更する。
		*/
		void SetRadian(float value)
		{
			float length = GetLength();
			SinCos(value, Y, X);
			X *= length;
			Y *= length;
		}

		/**
			@brief	このベクトルの向きを度数法で取得する。
		*/
		float GetDegree() const
		{
			return RadianToDegree(atan2(Y, X));
		}

		/**
			@brief	このベクトルの向きを度数法で設定する。
		*/
		void SetDegree(float value)
		{
			float length = GetLength();
			SinCos(DegreeToRadian(value), Y, X);
			X *= length;
			Y *= length;
		}

		bool operator==(const Vector2DF& right);

		bool operator!=(const Vector2DF& right);

		bool operator > (const Vector2DF& o) const;
		bool operator < (const Vector2DF& o) const;

		Vector2DF operator-();

		Vector2DF operator+(const Vector2DF& right) const;

		Vector2DF operator-(const Vector2DF& right) const;

		Vector2DF operator*(const Vector2DF& right) const;

		Vector2DF operator/(const Vector2DF& right) const;

		Vector2DF operator*(float right) const;

		Vector2DF operator/(float right) const;

		Vector2DF& operator+=(const Vector2DF& right);

		Vector2DF& operator-=(const Vector2DF& right);

		Vector2DF& operator*=(const Vector2DF& right);

		Vector2DF& operator/=(const Vector2DF& right);

		Vector2DF& operator*=(float right);

		Vector2DF& operator/=(float right);
		
		/**
			@brief	内積を取得する。
			@param	v1	v1ベクトル
			@param	v2	v2ベクトル
			@return 内積v1・v2
		*/
		static float Dot(const Vector2DF& v1, const Vector2DF& v2)
		{
			return v1.X * v2.X + v1.Y * v2.Y;
		}

		/**
		@brief	外積を取得する。
		@param	v1	v1ベクトル
		@param	v2	v2ベクトル
		@return 外積v1×v2
		*/
		static float Cross(const Vector2DF& v1, const Vector2DF& v2)
		{
			return v1.X * v2.Y - v1.Y * v2.X;
		}

		/**
		@brief	2点間の距離を取得する。
		@param	v1	v1ベクトル
		@param	v2	v2ベクトル
		@return v1とv2との距離
		*/
		static float Distance(const Vector2DF& v1, const Vector2DF& v2)
		{
			float dx = v1.X - v2.X;
			float dy = v1.Y - v2.Y;
			return sqrt(dx * dx + dy * dy);
		}

		/**
		@brief	加算する。
		@param	v1	v1ベクトル
		@param	v2	v2ベクトル
		@return v1+v2
		*/
		static Vector2DF Add(Vector2DF v1, Vector2DF v2)
		{
			return Vector2DF(v1.X + v2.X, v1.Y + v2.Y);
		}

		/**
		@brief	減算する。
		@param	v1	v1ベクトル
		@param	v2	v2ベクトル
		@return v1-v2
		*/
		static Vector2DF Subtract(Vector2DF v1, Vector2DF v2)
		{
			return Vector2DF(v1.X - v2.X, v1.Y - v2.Y);
		}

		/**
		@brief	除算する。
		@param	v1	値1
		@param	v2	値2
		@return	v1/v2
		*/
		static Vector2DF Divide(const Vector2DF& v1, const Vector2DF& v2)
		{
			return Vector2DF(v1.X / v2.X, v1.Y / v2.Y);
		}

		/**
		@brief	スカラーで除算する。
		@param	v1	値1
		@param	v2	値2
		@return	v1/v2
		*/
		static Vector2DF DivideByScalar(const Vector2DF& v1, float v2)
		{
			return Vector2DF(v1.X / v2, v1.Y / v2);
		}

		/**
			@brief	Vector2DI型に変換する。
			@return	Vector2DI型
		*/
		Vector2DI To2DI() const;
	};

	//----------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------
}
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
