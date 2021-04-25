/*
 *	This file is part of OGS Engine
 *	Copyright (C) 2016-2018, 2021 BlackPhrase
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

#pragma once

#include <Color.h>

#include "vgui2/IImage.h"

namespace vgui2
{

class CImage : public IImage
{
public:
	void Paint() override;

	void SetPos(int x, int y) override;

	void GetContentSize(int &wide, int &tall) override;

	void GetSize(int &wide, int &tall) override;
	void SetSize(int wide, int tall) override;

	void SetColor(Color color) override;
private:
	Color mColor{};
	
	int mnPosX{0};
	int mnPosY{0};
	
	int mnWidth{0};
	int mnHeight{0};
};

}; // namespace vgui2