/*
 * This file is part of OGS Engine
 * Copyright (C) 2016-2021 BlackPhrase
 *
 * OGS Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGS Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGS Engine.  If not, see <http://www.gnu.org/licenses/>.
 */

/// @file

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "vgui2/ILocalize.h"

namespace vgui2
{

struct SLocalizedString
{
	SLocalizedString() = default;
	SLocalizedString(const char *asTokenName, wchar_t *asValue, const char *asFileName) : msName(asTokenName), msValue(asValue), msFileName(asFileName){}
	
	const char *msName{""};
	wchar_t *msValue{nullptr};
	const char *msFileName{""};
	
	SLocalizedString *mpNext{nullptr};
};

class CLocalizationFile
{
public:
	void Reload();
//private:
	std::string msName{""};
	//std::unordered_map<std::string, std::wstring> mTokenValueMap;
	std::unordered_map<std::string, wchar_t*> mTokenValueMap;
};

using tLocFileVec = std::vector<CLocalizationFile*>;

class CLocalize : public ILocalize
{
public:
	CLocalize();
	~CLocalize();
	
	bool AddFile(IFileSystem *apFileSystem, const char *asFileName) override;

	void RemoveAll() override;

	wchar_t *Find(char const *tokenName) override;

	int ConvertANSIToUnicode(const char *ansi, wchar_t *unicode, int unicodeBufferSizeInBytes) override;
	int ConvertUnicodeToANSI(const wchar_t *unicode, char *ansi, int ansiBufferSize) override;

	StringIndex_t FindIndex(const char *tokenName) override;

	void ConstructString(wchar_t *unicodeOuput, int unicodeBufferSizeInBytes, wchar_t *formatString, int numFormatParameters, ...) override;

	const char *GetNameByIndex(StringIndex_t anIndex) override;
	wchar_t *GetValueByIndex(StringIndex_t anIndex) override;

	StringIndex_t GetFirstStringIndex() override;
	StringIndex_t GetNextStringIndex(StringIndex_t anIndex) override;

	void AddString(const char *tokenName, wchar_t *unicodeString, const char *asFileName) override;

	void SetValueByIndex(StringIndex_t anIndex, wchar_t *newValue) override;

	bool SaveToFile(IFileSystem *apFileSystem, const char *asFileName) override;

	int GetLocalizationFileCount() override;

	const char *GetLocalizationFileName(int anIndex) override;
	const char *GetFileNameByIndex(StringIndex_t anIndex) override;

	void ReloadLocalizationFiles() override;

	// BP: THIS IS REALLY BAD SINCE OVERLOADED FUNCS ORDER IN VIRTUAL INTERFACES CAN BE DIFFERENT ON VARIOUS COMPILERS VALVE!!!!!!!!!!!!
	void ConstructString(wchar_t *unicodeOutput, int unicodeBufferSizeInBytes, const char *tokenName, KeyValues *localizationVariables) override;
	void ConstructString(wchar_t *unicodeOutput, int unicodeBufferSizeInBytes, StringIndex_t unlocalizedTextSymbol, KeyValues *localizationVariables) override;
private:
	tLocFileVec mvLocFiles;
	
	CLocalizationFile *mpCurrentLocFile{nullptr};
	
	SLocalizedString *mpLocStringHead{nullptr};
};

}; // namespace vgui2