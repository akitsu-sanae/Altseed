﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ace
{
	/// <summary>
	/// インスタンスのネイティブの直接のラッパーを取得するためのメソッド集
	/// </summary>
	class IG
	{
		static public swig.Texture2D GetTexture2D(Texture2D o)
		{
			if (o == null) return null;
			return o.SwigObject;
		}

		static public swig.RenderTexture2D GetRenderTexture2D(RenderTexture2D o)
		{
			if (o == null) return null;
			return (swig.RenderTexture2D)o.SwigObject;
		}

		static public swig.Material2D GetMaterial2D(Material2D o)
		{
			if (o == null) return null;
			return o.SwigObject;
		}

		static public swig.Effect GetEffect(Effect o)
		{
			if (o == null) return null;
			return o.SwigObject;
		}

		static public swig.Chip2D GetChip2D(Chip2D o)
		{
			if (o == null) return null;
			return o.SwigObject;
		}

		static public swig.Font GetFont(Font o)
		{
			if (o == null) return null;
			return o.SwigObject;
		}
	}
}