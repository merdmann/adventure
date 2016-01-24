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

#ifndef INCLUDE_DIRECTIONTYPE_H_
#define INCLUDE_DIRECTIONTYPE_H_

namespace adventure {

/**
 * THis is the direction where we wanrt to move to
 */
typedef enum { E_Left = 0, E_Right = 1, E_Up = 2, E_Down=3, E_None = 99 } Direction_Type;

Direction_Type Random_Direction();


} /* namespace adventure */

#endif /* INCLUDE_DIRECTIONTYPE_H_ */
