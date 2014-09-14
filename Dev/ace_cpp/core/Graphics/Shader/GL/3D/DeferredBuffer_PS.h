﻿static const char* deferred_buffer_ps_gl = R"(

uniform sampler2D		g_gbuffer0Texture;

uniform sampler2D		g_gbuffer1Texture;

uniform sampler2D		g_gbuffer2Texture;

uniform sampler2D		g_gbuffer3Texture;

uniform sampler2D		g_shadowmapTexture;

uniform sampler2D		g_ssaoTexture;

uniform sampler2D		g_environmentTexture;

in vec4 voutPosition;
in vec2 voutUV;

out vec4 outOutput0;

uniform float	flag;

vec3 GetDiffuse(vec2 uv)
{
	return texture(g_gbuffer0Texture, uv).xyz;
}

vec4 GetSpecularColorAndSmoothness(vec2 uv)
{
	return texture(g_gbuffer1Texture, uv).xyzw;
}

vec3 GetNormal(vec2 uv)
{
	return texture(g_gbuffer2Texture, uv).xyz;
}

vec3 GetEnvironment(vec2 uv)
{
	return texture(g_environmentTexture, uv).xyz;
}

vec3 GetAO(float2 uv)
{
	float ao = texture(g_ssaoTexture, uv).x;
	return vec3(ao,ao,ao);
}


void main()
{
	vec2 uv = voutUV;
	uv.y = 1.0 - uv.y;

	vec4 color = vec4(0.0,0.0,0.0,1.0);

	if(flag == 0.0)
	{
		color.xyz = GetDiffuse(uv);
	}
	else if(flag == 1.0)
	{
		color.xyz = GetNormal(uv);
	}
	else if(flag == 2.0)
	{
		color.xyz = GetSpecularColorAndSmoothness(uv).xyz;
	}
	else if(flag == 3.0)
	{
		float s = GetSpecularColorAndSmoothness(uv).w;
		color.xyz = vec3(s,s,s);
	}
	else if(flag == 4.0)
	{
		color.xyz = GetEnvironment(uv).xyz;
	}
	else if(flag == 5.0)
	{
		color.xyz = GetAO(uv).xyz;
	}

	outOutput0 = color;
}

)";