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

#include "VPanel.h"
#include "vgui2/IClientPanel.h"

namespace vgui2
{

void VPanel::Init(IClientPanel *panel)
{
	mpClientPanel = panel;
};

void VPanel::GetClipRect(int &x0, int &y0, int &x1, int &y1)
{
	mpClientPanel->GetClipRect(x0, y0, x1, y1);
};

void VPanel::SetInset(int left, int top, int right, int bottom)
{
	// TODO
};

void VPanel::GetInset(int &left, int &top, int &right, int &bottom)
{
	mpClientPanel->GetInset(left, top, right, bottom);
};

void VPanel::MoveToFront()
{
	// TODO
};

void VPanel::MoveToBack()
{
	// TODO
};

bool VPanel::HasParent(VPanel *potentialParent) const
{
	return mpParent == potentialParent;
};

void VPanel::Render_SetPopupVisible(bool state)
{
	// TODO
};

bool VPanel::Render_GetPopupVisible() const
{
	// TODO
	return false;
};

bool VPanel::IsProportional() const
{
	return mpClientPanel->IsProportional();
};

void VPanel::Solve()
{
	// TODO
};

const char *VPanel::GetClassName() const
{
	return mpClientPanel->GetClassName();
};

void VPanel::SendMessage(KeyValues *params, VPANEL ifromPanel)
{
	mpClientPanel->OnMessage(params, ifromPanel);
};

void VPanel::Think()
{
	mpClientPanel->Think();
};

void VPanel::PerformApplySchemeSettings()
{
	mpClientPanel->PerformApplySchemeSettings();
};

void VPanel::PaintTraverse(bool forceRepaint, bool allowForce)
{
	mpClientPanel->PaintTraverse(forceRepaint, allowForce);
};

void VPanel::Repaint()
{
	mpClientPanel->Repaint();
};

VPANEL VPanel::IsWithinTraverse(int x, int y, bool traversePopups) const
{
	return mpClientPanel->IsWithinTraverse(x, y, traversePopups);
};

void VPanel::OnChildAdded(VPANEL child)
{
	mpClientPanel->OnChildAdded(child);
};

void VPanel::OnSizeChanged(int newWide, int newTall)
{
	mpClientPanel->OnSizeChanged(newWide, newTall);
};

void VPanel::InternalFocusChanged(bool lost)
{
	mpClientPanel->InternalFocusChanged(lost);
};

bool VPanel::RequestInfo(KeyValues *outputData) const
{
	if(outputData)
		return mpClientPanel->RequestInfo(outputData);
	
	return false;
};

void VPanel::RequestFocus(int direction)
{
	mpClientPanel->RequestFocus(direction);
};

bool VPanel::RequestFocusPrev(VPANEL existingPanel)
{
	return mpClientPanel->RequestFocusPrev(existingPanel);
};

bool VPanel::RequestFocusNext(VPANEL existingPanel)
{
	return mpClientPanel->RequestFocusNext(existingPanel);
};

VPANEL VPanel::GetCurrentKeyFocus() const
{
	return mpClientPanel->GetCurrentKeyFocus();
};

int VPanel::GetTabPosition() const
{
	return mpClientPanel->GetTabPosition();
};

void VPanel::SetPlat(SurfacePlat *Plat)
{
	// TODO
};

SurfacePlat *VPanel::GetPlat() const
{
	// TODO
	return nullptr;
};

Panel *VPanel::GetPanel(const char *destinationModule) const
{
	return mpClientPanel->GetPanel();
};

void *VPanel::GetClient() const
{
	return mpClientPanel; // TODO: use this instead of all other methods?
};

const char *VPanel::GetModuleName() const
{
	return mpClientPanel->GetModuleName();
};

}; // namespace vgui2