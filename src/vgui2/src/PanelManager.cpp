/*
 *	This file is part of OGS Engine
 *	Copyright (C) 2018-2019 BlackPhrase
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

#include "Panel.h"

namespace vgui2
{

EXPOSE_SINGLE_INTERFACE(VPanelWrapper, IPanel, VGUI_PANEL_INTERFACE_VERSION);

void VPanelWrapper::Init(VPANEL vguiPanel, IClientPanel *panel)
{
};

void VPanelWrapper::SetPos(VPANEL vguiPanel, int x, int y)
{
	mvPanels[vguiPanel]->SetPos(x, y);
};

void VPanelWrapper::GetPos(VPANEL vguiPanel, int &x, int &y)
{
	mvPanels[vguiPanel]->GetPos(x, y);
};

void VPanelWrapper::SetSize(VPANEL vguiPanel, int wide, int tall)
{
	mvPanels[vguiPanel]->SetSize(wide, tall);
};

void VPanelWrapper::GetSize(VPANEL vguiPanel, int &wide, int &tall)
{
	mvPanels[vguiPanel]->GetSize(wide, tall);
};

void VPanelWrapper::SetMinimumSize(VPANEL vguiPanel, int wide, int tall)
{
	mvPanels[vguiPanel]->SetMinimumSize(wide, tall);
};

void VPanelWrapper::GetMinimumSize(VPANEL vguiPanel, int &wide, int &tall)
{
	mvPanels[vguiPanel]->GetMinimumSize(wide, tall);
};

void VPanelWrapper::SetZPos(VPANEL vguiPanel, int z)
{
	mvPanels[vguiPanel]->SetZPos(z);
};

int VPanelWrapper::GetZPos(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetZPos();
};

void VPanelWrapper::GetAbsPos(VPANEL vguiPanel, int &x, int &y)
{
};

void VPanelWrapper::GetClipRect(VPANEL vguiPanel, int &x0, int &y0, int &x1, int &y1)
{
};

void VPanelWrapper::SetInset(VPANEL vguiPanel, int left, int top, int right, int bottom)
{
};

void VPanelWrapper::GetInset(VPANEL vguiPanel, int &left, int &top, int &right, int &bottom)
{
};

void VPanelWrapper::SetVisible(VPANEL vguiPanel, bool state)
{
};

bool VPanelWrapper::IsVisible(VPANEL vguiPanel)
{
	return false;
};

void VPanelWrapper::SetParent(VPANEL vguiPanel, VPANEL newParent)
{
};

int VPanelWrapper::GetChildCount(VPANEL vguiPanel)
{
	return 0;
};

VPANEL VPanelWrapper::GetChild(VPANEL vguiPanel, int index)
{
	return 0;
};

VPANEL VPanelWrapper::GetParent(VPANEL vguiPanel)
{
	return 0;
};

void VPanelWrapper::MoveToFront(VPANEL vguiPanel)
{
};

void VPanelWrapper::MoveToBack(VPANEL vguiPanel)
{
};

bool VPanelWrapper::HasParent(VPANEL vguiPanel, VPANEL potentialParent)
{
	return false;
};

bool VPanelWrapper::IsPopup(VPANEL vguiPanel)
{
	return false;
};

void VPanelWrapper::SetPopup(VPANEL vguiPanel, bool state)
{
};

bool VPanelWrapper::Render_GetPopupVisible(VPANEL vguiPanel)
{
	return false;
};

void VPanelWrapper::Render_SetPopupVisible(VPANEL vguiPanel, bool state)
{
};

HScheme VPanelWrapper::GetScheme(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetScheme();
};

bool VPanelWrapper::IsProportional(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsProportional();
};

bool VPanelWrapper::IsAutoDeleteSet(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsAudoDeleteSet();
};

void VPanelWrapper::DeletePanel(VPANEL vguiPanel)
{
	// TODO
};

void VPanelWrapper::SetKeyBoardInputEnabled(VPANEL vguiPanel, bool state)
{
	mvPanels[vguiPanel]->SetKeyBoardInputEnabled(state);
};

void VPanelWrapper::SetMouseInputEnabled(VPANEL vguiPanel, bool state)
{
	mvPanels[vguiPanel]->SetMouseInputEnabled(state);
};

bool VPanelWrapper::IsKeyBoardInputEnabled(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsKeyBoardInputEnabled();
};

bool VPanelWrapper::IsMouseInputEnabled(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsMouseInputEnabled();
};

void VPanelWrapper::Solve(VPANEL vguiPanel)
{
	mvPanels[vguiPanel]->Solve();
};

const char *VPanelWrapper::GetName(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetName();
};

const char *VPanelWrapper::GetClassName(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetClassName();
};

void VPanelWrapper::SendMessage(VPANEL vguiPanel, KeyValues *params, VPANEL ifromPanel)
{
	mvPanels[vguiPanel]->SendMessage(params, ifromPanel);
};

void VPanelWrapper::Think(VPANEL vguiPanel)
{
	mvPanels[vguiPanel]->Think();
};

void VPanelWrapper::PerformApplySchemeSettings(VPANEL vguiPanel)
{
	mvPanels[vguiPanel]->PerformApplySchemeSettings();
};

void VPanelWrapper::PaintTraverse(VPANEL vguiPanel, bool forceRepaint, bool allowForce)
{
	mvPanels[vguiPanel]->PaintTraverse();
};

void VPanelWrapper::Repaint(VPANEL vguiPanel)
{
	mvPanels[vguiPanel]->Repaint();
};

VPANEL VPanelWrapper::IsWithinTraverse(VPANEL vguiPanel, int x, int y, bool traversePopups)
{
	return mvPanels[vguiPanel]->IsWithinTraverse(x, y, traversePopups);
};

void VPanelWrapper::OnChildAdded(VPANEL vguiPanel, VPANEL child)
{
	mvPanels[vguiPanel]->OnChildAdded(child);
};

void VPanelWrapper::OnSizeChanged(VPANEL vguiPanel, int newWide, int newTall)
{
	mvPanels[vguiPanel]->OnSizeChanged(newWide, newTall);
};

void VPanelWrapper::InternalFocusChanged(VPANEL vguiPanel, bool lost)
{
	mvPanels[vguiPanel]->InternalFocusChanged(lost);
};

bool VPanelWrapper::RequestInfo(VPANEL vguiPanel, KeyValues *outputData)
{
	return mvPanels[vguiPanel]->RequestInfo(outputData);
};

void VPanelWrapper::RequestFocus(VPANEL vguiPanel, int direction)
{
	mvPanels[vguiPanel]->RequestFocus(direction);
};

bool VPanelWrapper::RequestFocusPrev(VPANEL vguiPanel, VPANEL existingPanel)
{
	return mvPanels[vguiPanel]->RequestFocusPrev(existingPanel);
};

bool VPanelWrapper::RequestFocusNext(VPANEL vguiPanel, VPANEL existingPanel)
{
	return mvPanels[vguiPanel]->RequestFocusNext(existingPanel);
};

VPANEL VPanelWrapper::GetCurrentKeyFocus(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetCurrentKeyFocus();
};

int VPanelWrapper::GetTabPosition(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetTabPosition();
};

SurfacePlat *VPanelWrapper::Plat(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetPlat();
};

void VPanelWrapper::SetPlat(VPANEL vguiPanel, SurfacePlat *Plat)
{
	mvPanels[vguiPanel]->SetPlat(Plat);
};

Panel *VPanelWrapper::GetPanel(VPANEL vguiPanel, const char *destinationModule)
{
	return mvPanels[vguiPanel]->GetPanel(destinationModule);
};

bool VPanelWrapper::IsEnabled(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsEnabled();
};

void VPanelWrapper::SetEnabled(VPANEL vguiPanel, bool state)
{
	mvPanels[vguiPanel]->SetEnabled(state);
};

void *VPanelWrapper::Client(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetClient();
};

const char *VPanelWrapper::GetModuleName(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetModuleName();
};

}; // namespace vgui2