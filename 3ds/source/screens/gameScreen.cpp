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

#include "gameScreen.hpp"

extern bool exiting;
extern int fadeAlpha;

/*
	Initialisiere den Spiel-Screen.
*/
GameScreen::GameScreen() {
	this->currentGame = std::make_unique<Game>();
}

/*
	Zeichne das Spiel.
*/
void GameScreen::Draw(void) const {
	GFX::DrawBaseTop();
	Gui::Draw_Rect(0, 0, 400, 25, BAR_COLOR);
	Gui::Draw_Rect(0, 215, 400, 25, BAR_COLOR);

	Gui::DrawStringCentered(0, 1, 0.7f, TEXT_COLOR, V_APPNAME " - GameScreen", 390);
	Gui::DrawStringCentered(0, 218, 0.6f, TEXT_COLOR, "Press X to show 'Hello!' from the example.", 390);
	if (fadeAlpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(0, 0, 0, fadeAlpha));

	GFX::DrawBaseBottom();
	if (fadeAlpha > 0) Gui::Draw_Rect(0, 0, 320, 240, C2D_Color32(0, 0, 0, fadeAlpha));
}

/*
	Die Spiel-Logik.
*/
void GameScreen::Logic(u32 hDown, u32 hHeld, touchPosition touch) {
	if (hDown & KEY_X) {
		Msg::DisplayWaitMsg(this->currentGame->example()); // Zeige "Hello!" von der Beispiel-Funktion.
	}

	/* Beende die app. */
	if (hDown & KEY_START) {
		exiting = true;
	}
}