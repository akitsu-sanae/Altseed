﻿
#pragma once

//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include "../ace.common.Base.h"

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace ace { 
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------

/**
	@brief	4x4行列
	@note
	M * V[x,y,z,1] の形<BR>
	[0,0][0,1][0,2][0,3]
	[1,0][1,1][1,2][1,3]
	[2,0][2,1][2,2][2,3]
	[3,0][3,1][3,2][3,3]
*/
struct Matrix44
{
private:

public:

	/**
		@brief	コンストラクタ
	*/
	Matrix44();

	/**
		@brief	行列の値
	*/
	float	Values[4][4];

	/**
		@brief	単位行列化する。
		@return	このインスタンスへの参照
	*/
	Matrix44& Indentity();

	/**
		@brief	転置行列化する。
		@return	このインスタンスへの参照
	*/
	Matrix44& Transpose();

	/**
		@brief	逆行列化する。
		@return	このインスタンスへの参照
	*/
	Matrix44& Invert();

	/**
		@brief	逆行列を取得する。
		@return	逆行列
	*/
	Matrix44 GetInverted();


	/**
		@brief	カメラ行列化(右手系)する。
		@param	eye	カメラの位置
		@param	at	カメラの注視点
		@param	up	カメラの上方向
		@return	このインスタンスへの参照
	*/
	Matrix44& SetLookAtRH( const Vector3DF& eye, const Vector3DF& at, const Vector3DF& up );

	/**
		@brief	カメラ行列化(左手系)する。
		@param	eye	カメラの位置
		@param	at	カメラの注視点
		@param	up	カメラの上方向
		@return	このインスタンスへの参照
	*/
	Matrix44& SetLookAtLH(const Vector3DF& eye, const Vector3DF& at, const Vector3DF& up);

	/**
		@brief	射影行列化(右手系)する。
		@param	ovY	Y方向への視野角(ラジアン)
		@param	aspect	画面のアスペクト比
		@param	zn	最近距離
		@param	zf	最遠距離
		@return	このインスタンスへの参照
	*/
	Matrix44& SetPerspectiveFovRH(float ovY, float aspect, float zn, float zf);

	/**
		@brief	OpenGL用射影行列化(右手系)する。
		@param	ovY	Y方向への視野角(ラジアン)
		@param	aspect	画面のアスペクト比
		@param	zn	最近距離
		@param	zf	最遠距離
		@return	このインスタンスへの参照
	*/
	Matrix44& SetPerspectiveFovRH_OpenGL(float ovY, float aspect, float zn, float zf);

	/**
		@brief	射影行列化(左手系)する。
		@param	ovY	Y方向への視野角(ラジアン)
		@param	aspect	画面のアスペクト比
		@param	zn	最近距離
		@param	zf	最遠距離
		@return	このインスタンスへの参照
	*/
	Matrix44& SetPerspectiveFovLH(float ovY, float aspect, float zn, float zf);

	/**
		@brief	正射影行列化(右手系)する。
		@param	width	横幅
		@param	height	縦幅
		@param	zn	最近距離
		@param	zf	最遠距離
		@return	このインスタンスへの参照
	*/
	Matrix44& SetOrthographicRH(float width, float height, float zn, float zf);

	/**
		@brief	正射影行列化(左手系)する。
		@param	width	横幅
		@param	height	縦幅
		@param	zn	最近距離
		@param	zf	最遠距離
		@return	このインスタンスへの参照
	*/
	Matrix44& SetOrthographicLH(float width, float height, float zn, float zf);

	/**
		@brief	移動行列化する。
		@param	x	X方向移動量
		@param	y	Y方向移動量
		@param	z	Z方向移動量
		@return	このインスタンスへの参照
	*/
	Matrix44& SetTranslation(float x, float y, float z);

	/**
		@brief	X軸回転行列(右手)化する。
		@param	angle	X軸回転量(ラジアン)
		@return	このインスタンスへの参照
	*/
	Matrix44& SetRotationX(float angle);

	/**
		@brief	Y軸回転行列(右手)化する。
		@param	angle	Y軸回転量(ラジアン)
		@return	このインスタンスへの参照
	*/
	Matrix44& SetRotationY(float angle);

	/**
		@brief	Z軸回転行列(右手)化する。
		@param	angle	Z軸回転量(ラジアン)
		@return	このインスタンスへの参照
	*/
	Matrix44& SetRotationZ(float angle);

	/**
	@brief	任意軸で反時計回転行列(右手)化する。
	@param	axis	軸
	@param	angle	回転量(ラジアン)
	@return	このインスタンスへの参照
	*/
	Matrix44& SetRotationAxis(const Vector3DF& axis, float angle);

	/**
	@brief	クオータニオンを設定し回転行列(右手)化する。
	@param	x	クオータニオン
	@param	y	クオータニオン
	@param	z	クオータニオン
	@param	w	クオータニオン
	@return	このインスタンスへの参照
	*/
	Matrix44& SetQuaternion(float x, float y, float z, float w);

	/**
	@brief	拡大行列化する。
	@param	x	X方向拡大率
	@param	y	Y方向拡大率
	@param	z	Z方向拡大率
	@return	このインスタンスへの参照
	*/
	Matrix44& SetScale(float x, float y, float z);

	/**
	@brief	行列でベクトルを変形させる。
	@param	in	変形前ベクトル
	@return	変形後ベクトル
	*/
	Vector3DF Transform3D(const Vector3DF& in);

	/**
	@brief	行列でベクトルを変形させる。
	@param	in	変形前ベクトル
	@return	変形後ベクトル
	*/
	Vector4DF Transform4D(const Vector4DF& in);

	/**
		@brief	乗算を行う。
		@param	o	行列
		@return	行列
	*/
	Matrix44 operator * (const Matrix44& o) const;

	/**
		@brief	乗算を行う。
		@param	o	出力先
		@param	in1	行列1
		@param	in2	行列2
		@return	出力先の参照
	*/
	static Matrix44& Mul( Matrix44& o, const Matrix44& in1, const Matrix44& in2 );

};

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
 } 
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
