﻿#pragma once

#include "../ace.Core.Base.h"
#include "ace.BaseFile_Imp.h"
#include "ace.Path_Imp.h"

namespace ace
{
	class BaseFile_Imp;

	struct RootPath_Imp
	{
	private:
		bool IsPack(const astring& file)
		{
			return file.find(ToAString(".pack")) != astring::npos;
		}

	public:
		Path_Imp m_path;
		astring m_key;
		bool m_isPackFile;

		RootPath_Imp() : RootPath_Imp(astring(), astring())
		{
		}


		RootPath_Imp(const astring& path, const astring& key = astring()) :
			m_path(path),
			m_key(key),
			m_isPackFile(false)
		{
			for (auto iter = m_path.ImpBegin();
				iter != m_path.ImpEnd();
				++iter)
			{
				if (IsPack(*iter))
				{
					m_isPackFile = true;
					break;
				}
			}
			//for (const auto& elem : m_path)
			//{
			//	if (IsPack(elem))
			//	{
			//	   m_isPackFile = true;
			//	   break;
			//	}
			//}
		}

		bool operator==(const RootPath_Imp& target) const
		{
			return m_key == target.m_key &&
				m_isPackFile == target.m_isPackFile &&
				m_path == target.m_path;
		}
	};
}