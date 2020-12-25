/*
 * This file is part of VGUI2
 * Copyright (C) 2019-2020 BlackPhrase
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

#pragma once

#include "vgui2/IClientPanel.h"

namespace vgui2
{

/*
	Panel(Panel *apParent, const char *asName, IScheme::Handle anScheme);
	
	virtual void DeletePanel();
	
	void SetName(const char *asName);
	
	virtual void SetVisible(bool abState);
	virtual bool IsVisible() const;
	
	virtual void SetParent(Panel *apParent);
	virtual Panel *GetParent() const;
	
	int GetChildCount() const;
	Panel *GetChild(int anIndex) const;
	
	Panel *FindChildByName(const char *asName, bool abRecurseDown = false);
	
	virtual void SetCursor(CursorHandle_t anCursor);
	virtual CursorHandle_t GetCursor() const;
	
	virtual bool HasFocus() const;
	
	// Scheme access
	virtual void SetScheme(IScheme::Handle anScheme);
	virtual IScheme::Handle GetScheme() const;
	
	// Message handlers
	virtual void OnThink();
	
	// Input messages
	virtual void OnCursorEntered();
	virtual void OnCursorExited();
*/

class Panel : public IClientPanel
{
public:
	Panel();
	Panel(Panel *apParent);
	Panel(Panel *apParent, const char *asName);
	Panel(Panel *apParent, const char *asName, HScheme ahScheme);
	
	virtual ~Panel();
public: // IClientPanel interface implementation

	/// @return pointer to Panel's vgui VPanel interface handle
	VPANEL GetVPanel() override {return mnPanel;}
	
	void Think() override;
	
	void PerformApplySchemeSettings() override;
	
	void PaintTraverse(bool bForceRepaint, bool bAllowForce) override;
	
	void Repaint() override;
	
	VPANEL IsWithinTraverse(int x, int y, bool bTraversePopups) override;
	
	void GetInset(int &top, int &left, int &right, int &bottom) override;
	void GetClipRect(int &x0, int &y0, int &x1, int &y1) override;
	
	void OnChildAdded(VPANEL nChild) override;
	void OnSizeChanged(int nNewWide, int nNewTall) override;
	
	void InternalFocusChanged(bool bLost) override;
	
	bool RequestInfo(KeyValues *pOutputData) override;
	
	void RequestFocus(int nDirection = 0) override;
	bool RequestFocusPrev(VPANEL nExistingPanel) override;
	bool RequestFocusNext(VPANEL nExistingPanel) override;
	
	void OnMessage(const KeyValues *pParams, VPANEL nFromPanel) override;
	
	VPANEL GetCurrentKeyFocus() override;
	
	int GetTabPosition() override;
	
	const char *GetName() override;
	const char *GetClassName() override;
	
	HScheme GetScheme() override;
	
	bool IsProportional() override;
	bool IsAutoDeleteSet() override;
	
	void DeletePanel() override;
	
	void *QueryInterface(EInterfaceID nId) override;
	Panel *GetPanel() override {return this;}
	const char *GetModuleName() override;
private:
	void Init(int anPosX, int anPosY, int anWidth, int anHeight);
	
	void SetParent(Panel *apParent);
	Panel *GetParent() const {return mpParent;}
	
	void SetName(const char *asName){msName = asName;}
	
	void SetScheme(HScheme ahScheme){mhScheme = ahScheme;}
	
	void SetPos(int anPosX, int anPosY);
	void SetSize(int anWidth, int anHeight);
private:
	VPANEL mnPanel{};
	
	Panel *mpParent{nullptr};
	
	const char *msName{""};
	
	HScheme mhScheme{};
private:
	//IVGui *mpVGUI{nullptr};
	//IPanel *mpPanelManager{nullptr};
};

}; // namespace vgui2