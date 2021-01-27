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

#include "SchemeManager.h"

namespace vgui2
{

EXPOSE_SINGLE_INTERFACE(CSchemeManager, ISchemeManager, VGUI_SCHEME_INTERFACE_VERSION);

HScheme CSchemeManager::LoadSchemeFromFile(const char *asFileName, const char *asTag)
{
	return 0; // TODO
};

void CSchemeManager::ReloadSchemes()
{
	for(It : mvSchemes)
		It->Reload();
};

HScheme CSchemeManager::GetDefaultScheme()
{
	return mvSchemes.at(0);
};

HScheme CSchemeManager::GetScheme(const char *asTag)
{
	return 0; // TODO
};

IImage *CSchemeManager::GetImage(const char *asImageName, bool abHardwareFiltered)
{
	return nullptr; // TODO
};

HTexture CSchemeManager::GetImageID(const char *asImageName, bool abHardwareFiltered)
{
	return 0; // TODO
};

IScheme *CSchemeManager::GetIScheme(HScheme ahScheme)
{
	return mvSchemes.at(ahScheme);
};

void CSchemeManager::Shutdown(bool abFull)
{
	UnloadSchemes();
};

int CSchemeManager::GetProportionalScaledValue(int anNormalizedValue)
{
	return 0; // TODO
};

int CSchemeManager::GetProportionalNormalizedValue(int anScaledValue)
{
	return 0; // TODO
};

void CSchemeManager::UnloadSchemes()
{
	// TODO
};

}; // namespace vgui2