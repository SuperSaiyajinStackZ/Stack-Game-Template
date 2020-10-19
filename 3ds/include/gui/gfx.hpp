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

#ifndef _STACK_GAME_TEMPLATE_GFX_HPP
#define _STACK_GAME_TEMPLATE_GFX_HPP

#include "sprites.h"
#include <string>

/* Definiere die Farben hier. */
#define TEXT_COLOR C2D_Color32(255, 255, 255, 255) // Text Farbe.
#define BAR_COLOR C2D_Color32(0, 160, 160, 255) // Balken Farbe.
#define BG_COLOR C2D_Color32(0, 120, 120, 255) // Hintergrund Farbe.
#define BOX_COLOR C2D_Color32(0, 160, 160, 255) // TextBox Farbe.

#define DIM_COLOR C2D_Color32(0, 0, 0, 170) // Gedunkelter Bildschirm Farbe.
#define NO_COLOR C2D_Color32(0, 0, 0, 0) // Transparente Farbe.

namespace GFX {
	void DrawBaseTop();
	void DrawBaseBottom();
	void DrawSprite(int index, int x, int y, float ScaleX = 1, float ScaleY = 1);
};

#endif