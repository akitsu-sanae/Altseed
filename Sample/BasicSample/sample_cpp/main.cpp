﻿#include "SampleGuide.h"
#define INFO(func) { func, #func }

#if _WIN32
#ifdef _DEBUG
#pragma comment(lib,"Debug/Altseed.lib")
#else
#pragma comment(lib,"Release/Altseed.lib")
#endif
#endif

#include <string>

#if _WIN32
#include <Windows.h>
std::wstring ToWide(const char* pText);
void GetDirectoryName(char* dst, char* src);
#endif

extern void Basic_Empty();

extern void Keyboard();
extern void Mouse();
extern void Joystick();
extern void Sound();

extern void EffectObject2D();
extern void TextObject2D();
extern void TextureObject2D();
extern void MapObject2D();
extern void CameraObject2D();
extern void GeometryObject2D();
extern void Collision2D();
extern void ImagePackage();

extern void Object2DComponent();
extern void Transition();

extern void PostEffect();

int main(int argc, char** argv)
{
#if _WIN32
	char current_path[MAX_PATH + 1];
	GetDirectoryName(current_path, argv[0]);
	SetCurrentDirectoryA(current_path);
#endif

	std::vector<SampleInfo> samples =
	{
		INFO(Basic_Empty),
		INFO(Keyboard),
		INFO(Mouse),
		INFO(Joystick),

		INFO(Sound),

		INFO(Object2DComponent),
		INFO(Transition),

		INFO(CameraObject2D),
		INFO(EffectObject2D),
		INFO(TextObject2D),
		INFO(TextureObject2D),
		INFO(MapObject2D),
		INFO(ImagePackage),
		INFO(GeometryObject2D),

		INFO(PostEffect),
		INFO(Collision2D),

	};

	auto cui = SampleGuide(samples);
	cui.Show();

	return 0;
}

#if _WIN32
static std::wstring ToWide(const char* pText)
{
	int Len = ::MultiByteToWideChar(CP_ACP, 0, pText, -1, NULL, 0);

	wchar_t* pOut = new wchar_t[Len + 1];
	::MultiByteToWideChar(CP_ACP, 0, pText, -1, pOut, Len);
	std::wstring Out(pOut);
	delete [] pOut;

	return Out;
}

void GetDirectoryName(char* dst, char* src)
{
	auto Src = std::string(src);
	int pos = 0;
	int last = 0;
	while (Src.c_str()[pos] != 0)
	{
		dst[pos] = Src.c_str()[pos];

		if (Src.c_str()[pos] == L'\\' || Src.c_str()[pos] == L'/')
		{
			last = pos;
		}

		pos++;
	}

	dst[pos] = 0;
	dst[last] = 0;
}
#endif