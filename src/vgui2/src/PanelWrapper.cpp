/*
 *	This file is part of OGS Engine
 *	Copyright (C) 2018-2020 BlackPhrase
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

#include "PanelWrapper.h"
#include "VPanel.h"

namespace vgui2
{

EXPOSE_SINGLE_INTERFACE(VPanelWrapper, IPanel, VGUI_PANEL_INTERFACE_VERSION);

void VPanelWrapper::Init(VPANEL vguiPanel, IClientPanel *panel)
{
	ToVPanelPtr(vguiPanel)->Init(panel);
};

void VPanelWrapper::SetPos(VPANEL vguiPanel, int x, int y)
{
	ToVPanelPtr(vguiPanel)->mnXPos = x;
	ToVPanelPtr(vguiPanel)->mnYPos = y;
};

void VPanelWrapper::GetPos(VPANEL vguiPanel, int &x, int &y)
{
	x = ToVPanelPtr(vguiPanel)->mnXPos;
	y = ToVPanelPtr(vguiPanel)->mnYPos;
};

void VPanelWrapper::SetSize(VPANEL vguiPanel, int wide, int tall)
{
	if(wide < ToVPanelPtr(vguiPanel)->mnWidthMin)
		wide = ToVPanelPtr(vguiPanel)->mnWidthMin;
	
	if(tall < ToVPanelPtr(vguiPanel)->mnHeightMin)
		tall = ToVPanelPtr(vguiPanel)->mnHeightMin;
	
	ToVPanelPtr(vguiPanel)->mnWidth = wide;
	ToVPanelPtr(vguiPanel)->mnHeight = tall;
};

void VPanelWrapper::GetSize(VPANEL vguiPanel, int &wide, int &tall)
{
	wide = ToVPanelPtr(vguiPanel)->mnWidth;
	tall = ToVPanelPtr(vguiPanel)->mnHeight;
};

void VPanelWrapper::SetMinimumSize(VPANEL vguiPanel, int wide, int tall)
{
	ToVPanelPtr(vguiPanel)->SetMinimumSize(wide, tall);
};

void VPanelWrapper::GetMinimumSize(VPANEL vguiPanel, int &wide, int &tall)
{
	ToVPanelPtr(vguiPanel)->GetMinimumSize(wide, tall);
};

void VPanelWrapper::SetZPos(VPANEL vguiPanel, int z)
{
	ToVPanelPtr(vguiPanel)->mnZPos = z;
};

int VPanelWrapper::GetZPos(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mnZPos;
};

void VPanelWrapper::GetAbsPos(VPANEL vguiPanel, int &x, int &y)
{
	x = ToVPanelPtr(vguiPanel)->mnXPos;
	y = ToVPanelPtr(vguiPanel)->mnYPos;
};

void VPanelWrapper::GetClipRect(VPANEL vguiPanel, int &x0, int &y0, int &x1, int &y1)
{
	ToVPanelPtr(vguiPanel)->GetClipRect(x0, y0, x1, y1);
};

void VPanelWrapper::SetInset(VPANEL vguiPanel, int left, int top, int right, int bottom)
{
	ToVPanelPtr(vguiPanel)->SetInset(left, top, right, bottom);
};

void VPanelWrapper::GetInset(VPANEL vguiPanel, int &left, int &top, int &right, int &bottom)
{
	ToVPanelPtr(vguiPanel)->GetInset(left, top, right, bottom);
};

void VPanelWrapper::SetVisible(VPANEL vguiPanel, bool state)
{
	ToVPanelPtr(vguiPanel)->mbVisible = state;
};

bool VPanelWrapper::IsVisible(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mbVisible;
};

void VPanelWrapper::SetParent(VPANEL vguiPanel, VPANEL newParent)
{
	ToVPanelPtr(vguiPanel)->mpParent = ToVPanelPtr(newParent);
};

int VPanelWrapper::GetChildCount(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mvChildren.size();
};

VPANEL VPanelWrapper::GetChild(VPANEL vguiPanel, int index)
{
	return ToVPanelPtr(vguiPanel)->GetChild(index)->ToVPANEL();
};

VPANEL VPanelWrapper::GetParent(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mpParent->ToVPANEL();
};

void VPanelWrapper::MoveToFront(VPANEL vguiPanel)
{
	ToVPanelPtr(vguiPanel)->MoveToFront();
};

void VPanelWrapper::MoveToBack(VPANEL vguiPanel)
{
	ToVPanelPtr(vguiPanel)->MoveToBack();
};

bool VPanelWrapper::HasParent(VPANEL vguiPanel, VPANEL potentialParent)
{
	return ToVPanelPtr(vguiPanel)->HasParent(ToVPanelPtr(potentialParent));
};

bool VPanelWrapper::IsPopup(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mbPopup;
};

void VPanelWrapper::SetPopup(VPANEL vguiPanel, bool state)
{
	ToVPanelPtr(vguiPanel)->mbPopup = state;
};

bool VPanelWrapper::Render_GetPopupVisible(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->Render_GetPopupVisible();
};

void VPanelWrapper::Render_SetPopupVisible(VPANEL vguiPanel, bool state)
{
	ToVPanelPtr(vguiPanel)->Render_SetPopupVisible(state);
};

HScheme VPanelWrapper::GetScheme(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mhScheme;
};

bool VPanelWrapper::IsProportional(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->IsProportional();
};

bool VPanelWrapper::IsAutoDeleteSet(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mbAutoDelete;
};

void VPanelWrapper::DeletePanel(VPANEL vguiPanel)
{
	ToVPanelPtr(vguiPanel)->DeletePanel(); // TODO
};

void VPanelWrapper::SetKeyBoardInputEnabled(VPANEL vguiPanel, bool state)
{
	ToVPanelPtr(vguiPanel)->mbKeyboardInputEnabled = state;
};

void VPanelWrapper::SetMouseInputEnabled(VPANEL vguiPanel, bool state)
{
	ToVPanelPtr(vguiPanel)->mbMouseInputEnabled = state;
};

bool VPanelWrapper::IsKeyBoardInputEnabled(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mbKeyboardInputEnabled;
};

bool VPanelWrapper::IsMouseInputEnabled(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mbMouseInputEnabled;
};

void VPanelWrapper::Solve(VPANEL vguiPanel)
{
	ToVPanelPtr(vguiPanel)->Solve();
};

const char *VPanelWrapper::GetName(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->msName;
};

const char *VPanelWrapper::GetClassName(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->GetClassName();
};

void VPanelWrapper::SendMessage(VPANEL vguiPanel, KeyValues *params, VPANEL ifromPanel)
{
	ToVPanelPtr(vguiPanel)->SendMessage(params, ifromPanel);
};

void VPanelWrapper::Think(VPANEL vguiPanel)
{
	ToVPanelPtr(vguiPanel)->Think();
};

void VPanelWrapper::PerformApplySchemeSettings(VPANEL vguiPanel)
{
	ToVPanelPtr(vguiPanel)->PerformApplySchemeSettings();
};

void VPanelWrapper::PaintTraverse(VPANEL vguiPanel, bool forceRepaint, bool allowForce)
{
	ToVPanelPtr(vguiPanel)->PaintTraverse(forceRepaint, allowForce);
};

void VPanelWrapper::Repaint(VPANEL vguiPanel)
{
	ToVPanelPtr(vguiPanel)->Repaint();
};

VPANEL VPanelWrapper::IsWithinTraverse(VPANEL vguiPanel, int x, int y, bool traversePopups)
{
	return ToVPanelPtr(vguiPanel)->IsWithinTraverse(x, y, traversePopups);
};

void VPanelWrapper::OnChildAdded(VPANEL vguiPanel, VPANEL child)
{
	ToVPanelPtr(vguiPanel)->OnChildAdded(child);
};

void VPanelWrapper::OnSizeChanged(VPANEL vguiPanel, int newWide, int newTall)
{
	ToVPanelPtr(vguiPanel)->OnSizeChanged(newWide, newTall);
};

void VPanelWrapper::InternalFocusChanged(VPANEL vguiPanel, bool lost)
{
	ToVPanelPtr(vguiPanel)->InternalFocusChanged(lost);
};

bool VPanelWrapper::RequestInfo(VPANEL vguiPanel, KeyValues *outputData)
{
	return ToVPanelPtr(vguiPanel)->RequestInfo(outputData);
};

void VPanelWrapper::RequestFocus(VPANEL vguiPanel, int direction)
{
	ToVPanelPtr(vguiPanel)->RequestFocus(direction);
};

bool VPanelWrapper::RequestFocusPrev(VPANEL vguiPanel, VPANEL existingPanel)
{
	return ToVPanelPtr(vguiPanel)->RequestFocusPrev(existingPanel);
};

bool VPanelWrapper::RequestFocusNext(VPANEL vguiPanel, VPANEL existingPanel)
{
	return ToVPanelPtr(vguiPanel)->RequestFocusNext(existingPanel);
};

VPANEL VPanelWrapper::GetCurrentKeyFocus(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->GetCurrentKeyFocus();
};

int VPanelWrapper::GetTabPosition(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->GetTabPosition();
};

SurfacePlat *VPanelWrapper::Plat(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->GetPlat();
};

void VPanelWrapper::SetPlat(VPANEL vguiPanel, SurfacePlat *Plat)
{
	ToVPanelPtr(vguiPanel)->SetPlat(Plat);
};

Panel *VPanelWrapper::GetPanel(VPANEL vguiPanel, const char *destinationModule)
{
	return ToVPanelPtr(vguiPanel)->GetPanel(destinationModule);
};

bool VPanelWrapper::IsEnabled(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->mbEnabled;
};

void VPanelWrapper::SetEnabled(VPANEL vguiPanel, bool state)
{
	ToVPanelPtr(vguiPanel)->mbEnabled = state;
};

void *VPanelWrapper::Client(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->GetClient();
};

const char *VPanelWrapper::GetModuleName(VPANEL vguiPanel)
{
	return ToVPanelPtr(vguiPanel)->GetModuleName();
};

}; // namespace vgui2