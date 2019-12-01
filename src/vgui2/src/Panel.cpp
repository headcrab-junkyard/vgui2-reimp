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

EXPOSE_SINGLE_INTERFACE(CPanel, IPanel, VGUI_PANEL_INTERFACE_VERSION)

void CPanel::Init(VPANEL vguiPanel, IClientPanel *panel)
{
};

void CPanel::SetPos(VPANEL vguiPanel, int x, int y)
{
	mvPanels[vguiPanel]->SetPos(x, y);
};

void CPanel::GetPos(VPANEL vguiPanel, int &x, int &y)
{
	mvPanels[vguiPanel]->GetPos(x, y);
};

void CPanel::SetSize(VPANEL vguiPanel, int wide, int tall)
{
	mvPanels[vguiPanel]->SetSize(wide, tall);
};

void CPanel::GetSize(VPANEL vguiPanel, int &wide, int &tall)
{
	mvPanels[vguiPanel]->GetSize(wide, tall);
};

void CPanel::SetMinimumSize(VPANEL vguiPanel, int wide, int tall)
{
	mvPanels[vguiPanel]->SetMinimumSize(wide, tall);
};

void CPanel::GetMinimumSize(VPANEL vguiPanel, int &wide, int &tall)
{
	mvPanels[vguiPanel]->GetMinimumSize(wide, tall);
};

void CPanel::SetZPos(VPANEL vguiPanel, int z)
{
	mvPanels[vguiPanel]->SetZPos(z);
};

int CPanel::GetZPos(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetZPos();
};

void CPanel::GetAbsPos(VPANEL vguiPanel, int &x, int &y)
{
};

void CPanel::GetClipRect(VPANEL vguiPanel, int &x0, int &y0, int &x1, int &y1)
{
};

void CPanel::SetInset(VPANEL vguiPanel, int left, int top, int right, int bottom)
{
};

void CPanel::GetInset(VPANEL vguiPanel, int &left, int &top, int &right, int &bottom)
{
};

void CPanel::SetVisible(VPANEL vguiPanel, bool state)
{
};

bool CPanel::IsVisible(VPANEL vguiPanel)
{
	return false;
};

void CPanel::SetParent(VPANEL vguiPanel, VPANEL newParent)
{
};

int CPanel::GetChildCount(VPANEL vguiPanel)
{
	return 0;
};

VPANEL CPanel::GetChild(VPANEL vguiPanel, int index)
{
	return 0;
};

VPANEL CPanel::GetParent(VPANEL vguiPanel)
{
	return 0;
};

void CPanel::MoveToFront(VPANEL vguiPanel)
{
};

void CPanel::MoveToBack(VPANEL vguiPanel)
{
};

bool CPanel::HasParent(VPANEL vguiPanel, VPANEL potentialParent)
{
	return false;
};

bool CPanel::IsPopup(VPANEL vguiPanel)
{
	return false;
};

void CPanel::SetPopup(VPANEL vguiPanel, bool state)
{
};

bool CPanel::Render_GetPopupVisible(VPANEL vguiPanel)
{
	return false;
};

void CPanel::Render_SetPopupVisible(VPANEL vguiPanel, bool state)
{
};

HScheme CPanel::GetScheme(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetScheme();
};

bool CPanel::IsProportional(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsProportional();
};

bool CPanel::IsAutoDeleteSet(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsAudoDeleteSet();
};

void CPanel::DeletePanel(VPANEL vguiPanel)
{
	// TODO
};

void CPanel::SetKeyBoardInputEnabled(VPANEL vguiPanel, bool state)
{
	mvPanels[vguiPanel]->SetKeyBoardInputEnabled(state);
};

void CPanel::SetMouseInputEnabled(VPANEL vguiPanel, bool state)
{
	mvPanels[vguiPanel]->SetMouseInputEnabled(state);
};

bool CPanel::IsKeyBoardInputEnabled(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsKeyBoardInputEnabled();
};

bool CPanel::IsMouseInputEnabled(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsMouseInputEnabled();
};

void CPanel::Solve(VPANEL vguiPanel)
{
	mvPanels[vguiPanel]->Solve();
};

const char *CPanel::GetName(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetName();
};

const char *CPanel::GetClassName(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetClassName();
};

void CPanel::SendMessage(VPANEL vguiPanel, KeyValues *params, VPANEL ifromPanel)
{
	mvPanels[vguiPanel]->SendMessage(params, ifromPanel);
};

void CPanel::Think(VPANEL vguiPanel)
{
	mvPanels[vguiPanel]->Think();
};

void CPanel::PerformApplySchemeSettings(VPANEL vguiPanel)
{
	mvPanels[vguiPanel]->PerformApplySchemeSettings();
};

void CPanel::PaintTraverse(VPANEL vguiPanel, bool forceRepaint, bool allowForce)
{
	mvPanels[vguiPanel]->PaintTraverse();
};

void CPanel::Repaint(VPANEL vguiPanel)
{
	mvPanels[vguiPanel]->Repaint();
};

VPANEL CPanel::IsWithinTraverse(VPANEL vguiPanel, int x, int y, bool traversePopups)
{
	return mvPanels[vguiPanel]->IsWithinTraverse(x, y, traversePopups);
};

void CPanel::OnChildAdded(VPANEL vguiPanel, VPANEL child)
{
	mvPanels[vguiPanel]->OnChildAdded(child);
};

void CPanel::OnSizeChanged(VPANEL vguiPanel, int newWide, int newTall)
{
	mvPanels[vguiPanel]->OnSizeChanged(newWide, newTall);
};

void CPanel::InternalFocusChanged(VPANEL vguiPanel, bool lost)
{
	mvPanels[vguiPanel]->InternalFocusChanged(lost);
};

bool CPanel::RequestInfo(VPANEL vguiPanel, KeyValues *outputData)
{
	return mvPanels[vguiPanel]->RequestInfo(outputData);
};

void CPanel::RequestFocus(VPANEL vguiPanel, int direction)
{
	mvPanels[vguiPanel]->RequestFocus(direction);
};

bool CPanel::RequestFocusPrev(VPANEL vguiPanel, VPANEL existingPanel)
{
	return mvPanels[vguiPanel]->RequestFocusPrev(existingPanel);
};

bool CPanel::RequestFocusNext(VPANEL vguiPanel, VPANEL existingPanel)
{
	return mvPanels[vguiPanel]->RequestFocusNext(existingPanel);
};

VPANEL CPanel::GetCurrentKeyFocus(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetCurrentKeyFocus();
};

int CPanel::GetTabPosition(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetTabPosition();
};

SurfacePlat *CPanel::Plat(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetPlat();
};

void CPanel::SetPlat(VPANEL vguiPanel, SurfacePlat *Plat)
{
	mvPanels[vguiPanel]->SetPlat(Plat);
};

Panel *CPanel::GetPanel(VPANEL vguiPanel, const char *destinationModule)
{
	return mvPanels[vguiPanel]->GetPanel(destinationModule);
};

bool CPanel::IsEnabled(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->IsEnabled();
};

void CPanel::SetEnabled(VPANEL vguiPanel, bool state)
{
	mvPanels[vguiPanel]->SetEnabled(state);
};

void *CPanel::Client(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetClient();
};

const char *CPanel::GetModuleName(VPANEL vguiPanel)
{
	return mvPanels[vguiPanel]->GetModuleName();
};

}; // namespace vgui2