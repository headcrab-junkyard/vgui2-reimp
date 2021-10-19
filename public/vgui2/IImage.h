/*
 * This file is part of OGS Engine
 * Copyright (C) 2018-2019, 2021 BlackPhrase
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
 * along with OGS Engine. If not, see <http://www.gnu.org/licenses/>.
 */

/// @file

#pragma once

//#include <public/Color.h>

#include "VGUI.h"

class Color;

namespace vgui2
{

struct IImage
{
	///
	virtual void Paint() = 0;
	
	/// Set the position of the image
	virtual void SetPos(int x, int y) = 0;
	
	/// Get the size of the content
	virtual void GetContentSize(int &anWidth, int &anHeight) = 0;
	
	///
	virtual void GetSize(int &anWidth, int &anHeight) = 0;
	
	/// Set the size of the image
	virtual void SetSize(int anWidth, int anHeight) = 0;
	
	/// Set the draw color
	virtual void SetColor(Color aColor) = 0;
};

}; // namespace vgui2