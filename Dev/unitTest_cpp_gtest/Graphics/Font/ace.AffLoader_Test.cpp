﻿#include "../../PCH/ace.UnitTestCpp.PCH.h"
#include <Graphics/Font/ace.AffLoader.h>
#include <memory>
#include <cstdint>

using namespace std;
using namespace ace;

bool ContainsChar(map<achar, GlyphData>& glyphs, achar charactor)
{
	auto pred = [&](map<achar, GlyphData>::value_type& g)
	{
		return g.second.GetCharactor() == charactor;
	};
	auto iter = find_if(glyphs.begin(), glyphs.end(), pred);
	return iter != glyphs.end();
}

void Font_AffLoader()
{
	static astring fileName = ToAString(L"Data/Font/forTest.aff");

	AffLoader loader(fileName);
	auto glyphs = loader.GetGlyphs();
	astring str = ToAString(L"Font");

	for (auto& c : str)
	{
		ASSERT_TRUE(ContainsChar(glyphs, c));
	}
}

TEST(Font, AffLoader_GetGlyphs)
{
	Font_AffLoader();
}