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

#include <string>
#include <memory>
#include <unordered_map>

#include <vgui2/IScheme.h>

namespace vgui2
{

using tColorMap = std::unordered_map<std::string, std::unique_ptr<Color>>;

class CScheme : public IScheme
{
public: // IScheme interface methods
	const char *GetResourceString(const char *stringName) override;
	IBorder *GetBorder(const char *borderName) override;
	HFont GetFont(const char *fontName, bool proportional) override;
	Color GetColor(const char *colorName, Color defaultColor) override;
public: // Other public methods
	void Reload();
private:
	tColorMap mColorMap;
};

}; // namespace vgui2