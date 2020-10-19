/*
	Diese Datei ist Teil von Stack-Game-Template.
	Copyright (C) 2020 bei SuperSaiyajinStackZ.

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Additional Terms 7.b and 7.c of GPLv3 apply to this file:
		* Requiring preservation of specified reasonable legal notices or
		  author attributions in that material or in the Appropriate Legal
		  Notices displayed by works containing it.
		* Prohibiting misrepresentation of the origin of that material,
		  or requiring that modified versions of such material be marked in
		  reasonable ways as different from the original version.
*/

#include "common.hpp"

/*
	Zeight eine Nachricht an, welche mit A übersprungen werden kann.

	std::string waitMsg: Die Nachricht.
*/
void Msg::DisplayWaitMsg(std::string waitMsg, ...) {
	Gui::clearTextBufs();
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(Top, NO_COLOR);
	C2D_TargetClear(Bottom, NO_COLOR);

	GFX::DrawBaseTop();
	Gui::Draw_Rect(0, 60, 400, 120, BOX_COLOR);

	Gui::Draw_Rect(0, 215, 400, 25, BAR_COLOR);
	Gui::DrawStringCentered(0, (240 - Gui::GetStringHeight(0.7f, waitMsg)) / 2, 0.7f, TEXT_COLOR, waitMsg, 390, 70);
	Gui::DrawStringCentered(0, 217, 0.6f, TEXT_COLOR, "Press \uE000 to continue.", 390);

	GFX::DrawBaseBottom();
	C3D_FrameEnd(0);

	while(1) {
		gspWaitForVBlank();
		hidScanInput();

		if ((hidKeysDown() & KEY_A)) break;
	}
}

/*
	Zeigt eine Nachricht an.

	std::string Message: Die Nachricht.
*/
void Msg::DisplayMsg(std::string Message) {
	Gui::clearTextBufs();
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(Top, NO_COLOR);
	C2D_TargetClear(Bottom, NO_COLOR);

	GFX::DrawBaseTop();
	Gui::Draw_Rect(0, 70, 400, 110, BOX_COLOR);
	Gui::DrawStringCentered(0, (240 - Gui::GetStringHeight(0.7f, Message)) / 2, 0.7f, TEXT_COLOR, Message, 390, 70);

	GFX::DrawBaseBottom();
	C3D_FrameEnd(0);
}