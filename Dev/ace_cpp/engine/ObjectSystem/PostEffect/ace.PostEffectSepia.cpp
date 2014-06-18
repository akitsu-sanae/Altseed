﻿#include "ace.PostEffectSepia.h"

#include <vector>
namespace ace{

	// 現在のアルゴリズム:グレースケール化→セピア色(107, 74, 43)をグレースケール化した場合の
	// 明度とRGB各値の比を取り、グレースケール化した各画素の成分ごとに乗ずる
	PostEffectSepia::PostEffectSepia(Graphics *g)
	{
		std::vector<ace::ShaderVariableProperty> props;
		auto prop_tex = ace::ShaderVariableProperty();
		prop_tex.Name = ace::ToAString("g_texture").c_str();
		prop_tex.Offset = 0;
		prop_tex.Type = ace::SHADER_VARIABLE_TYPE_TEXTURE2D;
		props.push_back(prop_tex);

		m_shader = g->CreateShader2D(
			ToAString(m_corePostEffect->GetSepiaShader(g->GetGraphicsType())).c_str(),
			props
			);

		m_material2d = g->CreateMaterial2D(m_shader);
	}

	void PostEffectSepia::OnDraw(std::shared_ptr<RenderTexture2D> dst, std::shared_ptr<RenderTexture2D> src)
	{
		m_material2d->SetTexture2D(ace::ToAString("g_texture").c_str(), src);

		DrawOnTexture2DWithMaterial(dst, m_material2d);
	}

}
