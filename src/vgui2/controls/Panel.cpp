/*
 * This file is part of VGUI2
 * Copyright (C) 2020 BlackPhrase
 *
 * VGUI2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * VGUI2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with VGUI2. If not, see <http://www.gnu.org/licenses/>.
 */

/// @file

#include "Panel.hpp"

namespace vgui2
{

Panel::Panel()
{
	Init(0, 0, 64, 24);
};

Panel::Panel(Panel *apParent) : Panel()
{
	SetParent(apParent);
};

Panel::Panel(Panel *apParent, const char *asName) : Panel(apParent)
{
	SetName(asName);
	SetBuildModeEditable(true);
};

Panel::~Panel()
{
	SetParent(reinterpret_cast<VPANEL>(nullptr));
	
	gpVGUI->FreePanel(mnPanel);
	mnPanel = 0;
};

Panel::Panel(Panel *apParent, const char *asName, HScheme ahScheme) : Panel(apParent, asName)
{
	SetScheme(ahScheme);
};

const char *Panel::GetName()
{
	if(msName)
		return msName;
	
	return "";
};

const char *Panel::GetClassName()
{
	return "Panel";
};

void Panel::Init(int anPosX, int anPosY, int anWidth, int anHeight)
{
	mnPanel = gpVGUI->AllocPanel();
	gpPanelWrapper->Init(mnPanel, this);
	
	SetPos(anPosX, anPosY);
	SetSize(anWidth, anHeight);
};

}; // namespace vgui2