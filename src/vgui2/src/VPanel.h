/*
 * This file is part of OGS Engine
 * Copyright (C) 2018-2020 BlackPhrase
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

#include <vector>

#include "VGUI.h"

namespace vgui2
{

struct IClientPanel;
class SurfacePlat;
class Panel;

class VPanel;
//using tPanelVec = std::vector<VPanel*>;

class VPanel
{
public:
	VPanel(VPanel *apParent) : mpParent(apParent){}
	VPanel(VPanel *apParent, const char *asName) : mpParent(apParent), msName(asName){}
	
	void Init(IClientPanel *panel);

	void SetPos(int x, int y){mnXPos = x; mnYPos = y;}
	void GetPos(int &x, int &y){x = mnXPos; y = mnYPos;}

	void SetSize(int wide, int tall)
	{
		if(wide < mnWidthMin)
			wide = mnWidthMin;
		
		if(tall < mnHeightMin)
			tall = mnHeightMin;
		
		mnWidth = wide;
		mnHeight = tall;
	};
	
	void GetSize(int &wide, int &tall){wide = mnWidth; tall = mnHeight;}

	void SetMinimumSize(int wide, int tall){mnWidthMin = wide; mnHeightMin = tall;}
	void GetMinimumSize(int &wide, int &tall){wide = mnWidthMin; tall = mnHeightMin;}

	void SetZPos(int z){mnZPos = z;}
	int GetZPos() const {return mnZPos;}

	void GetAbsPos(int &x, int &y)
	{
		x = mnXPos;
		y = mnYPos;
	};

	void GetClipRect(int &x0, int &y0, int &x1, int &y1);

	void SetInset(int left, int top, int right, int bottom);
	void GetInset(int &left, int &top, int &right, int &bottom);

	void SetVisible(bool state){mbVisible = state;}
	bool IsVisible() const {return mbVisible;}

	void SetParent(VPanel *newParent)
	{
		if(mpParent != newParent)
			mpParent = newParent;
	};

	int GetChildCount() const {return mvChildren.size();}

	VPanel *GetChild(int index) const {return mvChildren.at(index).get();}
	VPanel *GetParent() const {return mpParent;}

	void MoveToFront();
	void MoveToBack();

	bool HasParent(VPanel *potentialParent) const;

	void SetPopup(bool state){mbPopup = state;}
	bool IsPopup() const {return mbPopup;}

	void Render_SetPopupVisible(bool state);
	bool Render_GetPopupVisible() const;

	HScheme GetScheme() const {return mhScheme;}

	bool IsProportional() const;
	bool IsAutoDeleteSet() const {return mbAutoDelete;}

	void DeletePanel(){delete this;} // TODO: should this be here?

	void SetKeyBoardInputEnabled(bool state){mbKeyboardInputEnabled = state;}
	void SetMouseInputEnabled(bool state){mbMouseInputEnabled = state;}

	bool IsKeyBoardInputEnabled() const {return mbKeyboardInputEnabled;}
	bool IsMouseInputEnabled() const {return mbMouseInputEnabled;}

	void Solve();

	const char *GetName() const {return msName;}
	const char *GetClassName() const;

	void SendMessage(KeyValues *params, VPANEL ifromPanel);

	void Think();

	void PerformApplySchemeSettings();

	void PaintTraverse(bool forceRepaint, bool allowForce = true);
	void Repaint();

	VPANEL IsWithinTraverse(int x, int y, bool traversePopups) const;

	void OnChildAdded(VPANEL child);
	void OnSizeChanged(int newWide, int newTall);

	void InternalFocusChanged(bool lost);

	bool RequestInfo(KeyValues *outputData) const;
	void RequestFocus(int direction = 0);
	bool RequestFocusPrev(VPANEL existingPanel);
	bool RequestFocusNext(VPANEL existingPanel);

	VPANEL GetCurrentKeyFocus() const;

	int GetTabPosition() const;

	void SetPlat(SurfacePlat *Plat);
	SurfacePlat *GetPlat() const;

	Panel *GetPanel(const char *destinationModule) const;

	void SetEnabled(bool state){mbEnabled = state;}
	bool IsEnabled() const {return mbEnabled;}
	
	void *GetClient() const;

	const char *GetModuleName() const;
	
	inline VPANEL ToVPANEL() const {return reinterpret_cast<uintptr_t>(this);}
//private:
	tPanelVec mvChildren;
	
	VPanel *mpParent{nullptr};
	IClientPanel *mpClientPanel{nullptr};
	
	HScheme mhScheme{0};
	
	const char *msName{""};
	
	int mnXPos{0};
	int mnYPos{0};
	int mnZPos{0};
	
	int mnWidth{0};
	int mnHeight{0};
	
	int mnWidthMin{0};
	int mnHeightMin{0};
	
	bool mbEnabled{false};
	bool mbVisible{false};
	bool mbPopup{false};
	bool mbAutoDelete{false};
	
	bool mbKeyboardInputEnabled{false};
	bool mbMouseInputEnabled{false};
};

}; // namespace vgui2