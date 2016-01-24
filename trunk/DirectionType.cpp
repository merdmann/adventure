/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * DirectionType.h is part of Adventure.
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
 *  Created on: Nov 10, 2014
 *      Author: MIchael
 */

#include <stdlib.h>

#include "DirectionType.h"

namespace adventure {

Direction_Type Random_Direction() {
	static Direction_Type dirs[] = { E_Left, E_Right, E_Up, E_Down };

	return dirs[ rand() % 4];
}


} /* namespace adventure */
