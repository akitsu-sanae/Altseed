#pragma once

#include "../../asd.Core.Base.h"

#include <Math/asd.Vector2DI.h>

namespace asd {

/**
	@brief	�f���t�@�C�����Đ����邽�߂̃N���X
*/
class MediaPlayer
{
private:

protected:

public:

	/**
		@brief	�f�����Đ�����B
	*/
	virtual bool Play() = 0;

	/**
		@brief	�f����ǂݍ��ށB
		@param	path	�t�@�C���̃p�X
		@note
		Windows��p�BH264�����B
	*/
	virtual bool Load(const achar* path) = 0;

	/**
		@brief	�ǂݍ��񂾉f���̑傫�����擾����B
	*/
	virtual Vector2DI GetSize() const = 0;

	/**
		@brief	���ݍĐ����̉f���̃t���[���ԍ����擾����B
	*/
	virtual int32_t GetCurrentFrame() const = 0;
};

}