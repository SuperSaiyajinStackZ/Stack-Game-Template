/*
*   This file is part of Stack-Game-Template
*   Copyright (C) 2020 SuperSaiyajinStackZ
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#include "common.hpp"
#include "config.hpp"
#include "structs.hpp"

#include <vector>

extern std::unique_ptr<Config> config;
const std::vector<Structs::ButtonPos> promptBtn = {
	{10, 100, 140, 40}, // Yes.
	{170, 100, 140, 40}, // No.
	{100, 100, 140, 40} // OK.
};

extern touchPosition touch;
extern bool touching(touchPosition touch, Structs::ButtonPos button);

// Display a Message, which needs to be confirmed with A/B.
bool Msg::promptMsg2(std::string promptMsg) {
	s32 selection = 0;
	while(1) {
		Gui::clearTextBufs();
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(Top, C2D_Color32(0, 0, 0, 0));
		C2D_TargetClear(Bottom, C2D_Color32(0, 0, 0, 0));
		GFX::DrawTop();
		Gui::Draw_Rect(0, 60, 400, 100, config->barColor());
		Gui::DrawStringCentered(0, (240-Gui::GetStringHeight(0.8f, promptMsg))/2-10, 0.8f, config->textColor(), promptMsg, 390, 90);
		GFX::DrawBottom();
		// Draw Bottom Screen part.
		Gui::Draw_Rect(10, 100, 140, 40, config->buttonColor());
		Gui::Draw_Rect(170, 100, 140, 40, config->buttonColor());
		Gui::DrawStringCentered(-150+70, 105, 0.8f, config->textColor(), "Yes", 140);
		Gui::DrawStringCentered(150-70, 105, 0.8f, config->textColor(), "No", 140);
		GFX::DrawButtonSelector(promptBtn[selection].x, promptBtn[selection].y);
		C3D_FrameEnd(0);

		// Selection part.
		gspWaitForVBlank();
		hidScanInput();
		hidTouchRead(&touch);

		if (hidKeysDown() & KEY_LEFT) {
			selection = 0;
		} else if (hidKeysDown() & KEY_RIGHT) {
			selection = 1;
		}

		if (hidKeysDown() & KEY_A) {
			if (selection == 0) {
				return true;
			} else {
				return false;
			}
		}
		
		if (hidKeysDown() & KEY_TOUCH && touching(touch, promptBtn[0])) {
			return true;
		}

		if (hidKeysDown() & KEY_TOUCH && touching(touch, promptBtn[1])) {
			return false;
		}
	}
}

bool Msg::promptMsg(std::string msg) {
	return Msg::promptMsg2(msg);
}

// Displays a Warn Message.
void Msg::DisplayWarnMsg(std::string Text) {
	Gui::clearTextBufs();
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(Top, C2D_Color32(0, 0, 0, 0));
	C2D_TargetClear(Bottom, C2D_Color32(0, 0, 0, 0));
	GFX::DrawTop();
	Gui::Draw_Rect(0, 80, 400, 80, config->barColor());
	Gui::DrawStringCentered(0, (240-Gui::GetStringHeight(0.8f, Text))/2, 0.8f, config->textColor(), Text, 395, 70);
	GFX::DrawBottom();
	C3D_FrameEnd(0);
	for (int i = 0; i < 60*2; i++) {
		gspWaitForVBlank();
	}
}

// Displays a Warn Message. This is mostly be used for things with more text.
void Msg::DisplayWarnMsg2(std::string Text) {
	Gui::clearTextBufs();
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(Top, C2D_Color32(0, 0, 0, 0));
	C2D_TargetClear(Bottom, C2D_Color32(0, 0, 0, 0));
	GFX::DrawTop();
	Gui::Draw_Rect(0, 80, 400, 80, config->barColor());
	Gui::DrawStringCentered(0, (240-Gui::GetStringHeight(0.8f, Text))/2, 0.8f, config->textColor(), Text, 395, 70);
	GFX::DrawBottom();
	C3D_FrameEnd(0);
	for (int i = 0; i < 60*2; i++) {
		gspWaitForVBlank();
	}
}

// Display a Message, which can be skipped with A.
void Msg::DisplayWaitMsg(std::string waitMsg, ...) {
	Gui::clearTextBufs();
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(Top, C2D_Color32(0, 0, 0, 0));
	C2D_TargetClear(Bottom, C2D_Color32(0, 0, 0, 0));
	GFX::DrawTop();
	Gui::Draw_Rect(0, 80, 400, 80, config->barColor());
	Gui::DrawStringCentered(0, (240-Gui::GetStringHeight(0.8f, waitMsg))/2, 0.8f, config->textColor(), waitMsg, 390, 70);
	Gui::DrawStringCentered(0, 214, 0.8f, config->textColor(), "Press \uE000 to continue.", 390);
	GFX::DrawBottom();
	Gui::Draw_Rect(100, 100, 140, 40, config->buttonColor());
	Gui::DrawStringCentered(-60+70, 105, 0.8f, config->textColor(), "OK", 140);
	C3D_FrameEnd(0);

	while(1) {
		gspWaitForVBlank();
		hidScanInput();
		hidTouchRead(&touch);
		if ((hidKeysDown() & KEY_A) || (hidKeysDown() & KEY_TOUCH && touching(touch, promptBtn[2]))) break;
	}
}

void Msg::HelperBox(std::string Msg) {
	Gui::clearTextBufs();
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	Gui::ScreenDraw(Top);
	Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(0, 0, 0, 190));
	int textBoxHeight = Gui::GetStringHeight(0.6f, Msg) + 5;

	Gui::Draw_Rect(40, 211 - textBoxHeight, 320, textBoxHeight, config->barColor());
	Gui::Draw_Rect(40, 211 - textBoxHeight, 320, textBoxHeight, C2D_Color32(0, 0, 0, 190));
	Gui::Draw_Rect(44, 215 - textBoxHeight, 312, textBoxHeight - 8, config->barColor());
	Gui::DrawStringCentered(0, 215 - textBoxHeight-2, 0.6, config->textColor(), Msg, 305, Gui::GetStringHeight(0.6f, Msg));
	Gui::ScreenDraw(Bottom);
	Gui::Draw_Rect(0, 0, 320, 240, C2D_Color32(0, 0, 0, 190));
	C3D_FrameEnd(0);
}

void Msg::DisplayMsg(std::string Message) {
	Gui::clearTextBufs();
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(Top, C2D_Color32(0, 0, 0, 0));
	C2D_TargetClear(Bottom, C2D_Color32(0, 0, 0, 0));
	GFX::DrawTop();
	Gui::Draw_Rect(0, 80, 400, 80, config->barColor());
	Gui::DrawStringCentered(0, (240-Gui::GetStringHeight(0.8f, Message))/2, 0.8f, config->textColor(), Message, 390, 70);
	GFX::DrawBottom();
	C3D_FrameEnd(0);
}

void Msg::NotImplementedYet(void) {
	Msg::DisplayWaitMsg("This is not implemented yet!");
}

// For debug messages with "Debug": true in the config.
void Msg::DebugMessage(std::string msg) {
	if (config->debug()) {
		Msg::DisplayWaitMsg(msg);
	}
}