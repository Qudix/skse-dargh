// ============================================================================
//                             Setting.cpp
// ----------------------------------------------------------------------------
// Part of the open-source Dynamic Animation Replacer (DARGH).
// 
// Copyright (c) 2023 Nox Sidereum
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the �Software�), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is furnished
// to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED �AS IS�, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
// 
// (The MIT License)
// ============================================================================
#include "RE/S/Setting.h"

SettingType Setting_GetType(Setting* setting)
{
	char* name;
	char firstCharName;
	SettingType result;

	name = setting->name;
	if (!name)
	{
		return kType_Unknown;
	}

	firstCharName = name[0];
	if (!firstCharName)
	{
		return kType_Unknown;
	}

	switch (firstCharName)
	{
	case 'S':
	case 's':
		result = kType_String;
		break;
	case 'a':
		result = kType_ID;
		break;
	case 'b':
		result = kType_Bool;
		break;
	case 'f':
		result = kType_Float;
		break;
	case 'i':
		result = kType_Integer;
		break;
	case 'r':
		result = kType_ID6;
		break;
	default:
		return kType_Unknown;
	}
	return result;
}