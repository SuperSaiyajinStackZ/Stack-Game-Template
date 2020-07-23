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

#ifndef _STACK_GAME_TEMPLATE_COLORHELPER_HPP
#define _STACK_GAME_TEMPLATE_COLORHELPER_HPP

#include <citro2d.h>
#include <sstream>
#include <string>

/**
 * @brief Creates an 8 byte RGBA color.
 * @param r red component of the color.
 * @param g green component of the color.
 * @param b blue component of the color.
 * @param a alpha component of the color.
 */
#define RGBA8(r, g, b, a) ((((r)&0xFF)<<0) | (((g)&0xFF)<<8) | (((b)&0xFF)<<16) | (((a)&0xFF)<<24))

#define BAR_COLOR C2D_Color32(60, 60, 220, 255)
#define BG_COLOR C2D_Color32(160, 160, 220, 255)
#define TEXT_COLOR C2D_Color32(255, 255, 255, 255)
#define SELECTED_COLOR C2D_Color32(0, 0, 255, 255)
#define BUTTON_COLOR C2D_Color32(60, 0, 170, 255)

namespace ColorHelper {
	int getColorValue(int color, int bgr);
	std::string getColorName(int color, int bgr);
}

#endif