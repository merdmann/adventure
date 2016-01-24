/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 *
 * Canvas.cpp is part of Adventure.
 *
 * Adventure is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Adventure is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Adventure. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: Nov 9, 2014
 *      Author: MIchael
 */
#include "Helpers.h"

#include <string.h>
#include <iostream>
#include <map>
#include <utility>

namespace helpers {

using namespace adventure;

// infrastructure for display of
static std::map<Direction_Type, std::string> directions = {
		{ E_Left, "left" },
		{ E_Right, "right" },
		{ E_Up, "up" },
		{ E_Down, "down" }

};

std::string To_String(Direction_Type e) { return directions[e];}


} /* end name space */
