/*
 *	This file is part of OGS Engine
 *	Copyright (C) 2018-2019, 2021 BlackPhrase
 *
 *	OGS Engine is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	OGS Engine is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with OGS Engine.  If not, see <http://www.gnu.org/licenses/>.
 */

/// @file

#include "Localize.h"

namespace vgui2
{

EXPOSE_SINGLE_INTERFACE(CLocalize, ILocalize, VGUI_LOCALIZE_INTERFACE_VERSION);

CLocalize::CLocalize()
{
	mpLocStringHead = new SLocalizedString;
};

CLocalize::~CLocalize()
{
	while(mpLocStringHead)
	{
		auto pNewHead{mpLocStringHead->mpNext};
		delete mpLocStringHead;
		mpLocStringHead = pNewHead;
	};
};

bool CLocalize::AddFile(IFileSystem *apFileSystem, const char *asFileName)
{
	if(!apFileSystem)
		return false;
	
	if(!asFileName || !*asFileName)
		return false;
	
	mvLocFiles.emplace_back(new CLocalizationFile());
	return true;
};

void CLocalize::RemoveAll()
{
};

wchar_t *CLocalize::Find(char const *asTokenName)
{
	if(!asTokenName || !*asTokenName)
		return nullptr; // TODO: ""?
	
	auto It{mpCurrentLocFile->mTokenValueMap.find(asTokenName)};
	if(It != mpCurrentLocFile->mTokenValueMap.end())
		return It->second;
	
	return nullptr; // TODO: ""?
};

int CLocalize::ConvertANSIToUnicode(const char *ansi, wchar_t *unicode, int unicodeBufferSizeInBytes)
{
	return 0;
};

int CLocalize::ConvertUnicodeToANSI(const wchar_t *unicode, char *ansi, int ansiBufferSize)
{
	return 0;
};

StringIndex_t CLocalize::FindIndex(const char *asTokenName)
{
	return 0;
};

void CLocalize::ConstructString(wchar_t *unicodeOuput, int unicodeBufferSizeInBytes, wchar_t *formatString, int numFormatParameters, ...)
{
};

const char *CLocalize::GetNameByIndex(StringIndex_t anIndex)
{
	return reinterpret_cast<SLocalizedString*>(anIndex)->msName;
};

wchar_t *CLocalize::GetValueByIndex(StringIndex_t anIndex)
{
	return reinterpret_cast<SLocalizedString*>(anIndex)->msValue;
};

StringIndex_t CLocalize::GetFirstStringIndex()
{
	return reinterpret_cast<StringIndex_t>(mpLocStringHead);
};

StringIndex_t CLocalize::GetNextStringIndex(StringIndex_t anIndex)
{
	return reinterpret_cast<StringIndex_t>(reinterpret_cast<SLocalizedString*>(anIndex)->mpNext);
};

void CLocalize::AddString(const char *asTokenName, wchar_t *unicodeString, const char *asFileName)
{
	mpLocStringHead->mpNext = new SLocalizedString(asTokenName, unicodeString, asFileName);
};

void CLocalize::SetValueByIndex(StringIndex_t anIndex, wchar_t *newValue)
{
	reinterpret_cast<SLocalizedString*>(anIndex)->msValue = newValue;
};

bool CLocalize::SaveToFile(IFileSystem *apFileSystem, const char *fileName)
{
	if(!apFileSystem)
		return false;
	
	return false;
};

int CLocalize::GetLocalizationFileCount()
{
	return mvLocFiles.size();
};

const char *CLocalize::GetLocalizationFileName(int anIndex)
{
	return mvLocFiles.at(anIndex)->msName.c_str();
};

const char *CLocalize::GetFileNameByIndex(StringIndex_t anIndex)
{
	return reinterpret_cast<SLocalizedString*>(anIndex)->msFileName;
};

void CLocalize::ReloadLocalizationFiles()
{
	for(auto It : mvLocFiles)
		It->Reload();
};

void CLocalize::ConstructString(wchar_t *unicodeOutput, int unicodeBufferSizeInBytes, const char *tokenName, KeyValues *localizationVariables)
{
};

void CLocalize::ConstructString(wchar_t *unicodeOutput, int unicodeBufferSizeInBytes, StringIndex_t unlocalizedTextSymbol, KeyValues *localizationVariables)
{
};

}; // namespace vgui2