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

#include "vgui2/IInputInternal.h"

namespace vgui2
{

class CInputInternal : public IInputInternal
{
public:
	// IInput interface methods
	
	void SetMouseFocus(VPANEL newMouseFocus) override;
	void SetMouseCapture(VPANEL panel) override;

	void GetKeyCodeText(KeyCode code, char *buf, int buflen) override;

	VPANEL GetFocus() override;
	VPANEL GetMouseOver() override;

	void SetCursorPos(int x, int y) override;
	void GetCursorPos(int &x, int &y) override;

	bool WasMousePressed(MouseCode code) override;
	bool WasMouseDoublePressed(MouseCode code) override;

	bool IsMouseDown(MouseCode code) override;

	void SetCursorOveride(HCursor cursor) override;
	HCursor GetCursorOveride() override;

	bool WasMouseReleased(MouseCode code) override;
	bool WasKeyPressed(KeyCode code) override;

	bool IsKeyDown(KeyCode code) override;

	bool WasKeyTyped(KeyCode code) override;
	bool WasKeyReleased(KeyCode code) override;

	VPANEL GetAppModalSurface() override;
	void SetAppModalSurface(VPANEL panel) override;
	void ReleaseAppModalSurface() override;

	void GetCursorPosition(int &x, int &y) override;
	
	// IInputInternal interface methods
	
	void RunFrame() override;

	void UpdateMouseFocus(int x, int y) override;

	void PanelDeleted(VPANEL panel) override;

	bool InternalCursorMoved(int x, int y) override;

	bool InternalMousePressed(MouseCode code) override;
	bool InternalMouseDoublePressed(MouseCode code) override;
	bool InternalMouseReleased(MouseCode code) override;
	bool InternalMouseWheeled(int delta) override;

	bool InternalKeyCodePressed(KeyCode code) override;
	void InternalKeyCodeTyped(KeyCode code) override;
	void InternalKeyTyped(wchar_t unichar) override;
	bool InternalKeyCodeReleased(KeyCode code) override;

	HInputContext CreateInputContext() override;
	void DestroyInputContext(HInputContext context) override;

	void AssociatePanelWithInputContext(HInputContext context, VPANEL pRoot) override;
	void ActivateInputContext(HInputContext context) override;

	VPANEL GetMouseCapture() override;

	bool IsChildOfModalPanel(VPANEL panel) override;

	void ResetInputContext(HInputContext context) override;
};

}; // namespace vgui2