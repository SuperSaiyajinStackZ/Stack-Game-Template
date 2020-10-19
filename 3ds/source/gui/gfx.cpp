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

extern C2D_SpriteSheet sprites;

/*
	Zeichne eine basis für den Top Screen.
*/
void GFX::DrawBaseTop() {
	Gui::ScreenDraw(Top);
	Gui::Draw_Rect(0, 0, 400, 240, BG_COLOR);
}

/*
	Zeichne eine basis für den Touch Screen.
*/
void GFX::DrawBaseBottom() {
	Gui::ScreenDraw(Bottom);
	Gui::Draw_Rect(0, 0, 320, 240, BG_COLOR);
}

/*
	Zeichne einen Sprite von der sprites spritesheet.

	int index: Der index des Sprites.
	int x: Die X Position des Sprites.
	int y: Die Y Position des Sprites.
	float ScaleX: Breiten-Skalierung.
	float ScaleY: Höhen-Skalierung.
*/
void GFX::DrawSprite(int index, int x, int y, float ScaleX, float ScaleY) {
	Gui::DrawSprite(sprites, index, x, y, ScaleX, ScaleY);
}