static const char* lightweight_model_internal_ps_dx = R"(

//<|| モデル共通レジスタ
Texture2D		g_colorTexture		: register( t0 );
SamplerState	g_colorSampler		: register( s0 );
//>||

struct PS_Input
{
	float4 Position		: SV_POSITION;
	float4 Pos			: POSITION0;	

	float4 Color	: Color0;
	half2 UV		: TEXCOORD0;
	half3 Normal	: NORMAL0;
};

float4 main( const PS_Input Input ) : SV_Target
{
	float4 Output = Input.Color;
	if(Output.a == 0.0f) discard;

	if(hasTextures.x != 0.0)
	{
		Output = Output * g_colorTexture.Sample(g_colorSampler, Input.UV);
	}
	if(Output.a == 0.0f) discard;

	return Output;
}

)";
