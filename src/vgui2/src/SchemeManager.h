/*
 * This file is part of OGS Engine
 * Copyright (C) 2016-2018, 2021 BlackPhrase
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

#include <vector>

#include "vgui2/IScheme.h"

namespace vgui2
{

class CScheme;
using tSchemeVec = std::vector<CScheme*>;

class CSchemeManager : public ISchemeManager
{
public:
	//~CSchemeManager();
	
	HScheme LoadSchemeFromFile(const char *asFileName, const char *asTag) override;

	void ReloadSchemes() override;

	HScheme GetDefaultScheme() override;
	HScheme GetScheme(const char *asTag) override;

	IImage *GetImage(const char *asImageName, bool abHardwareFiltered) override;
	HTexture GetImageID(const char *asImageName, bool abHardwareFiltered) override;

	IScheme *GetIScheme(HScheme ahScheme) override;

	void Shutdown(bool abFull = true) override;

	int GetProportionalScaledValue(int anNormalizedValue) override;
	int GetProportionalNormalizedValue(int anScaledValue) override;
private:
	void UnloadSchemes();
private:
	tSchemeVec mvSchemes;
};

}; // namespace vgui2