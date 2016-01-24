/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * Door.cpp is part of adv.
 *
 * adv is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * adv is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with adv. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: Dec 7, 2014
 *      Author: MIchael
 */
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "Door.h"

namespace adventure {

static DoorState_Type randomState() {
   static DoorState_Type result [] = { E_Open, E_Closed, E_Locked };

   return result[rand() % 3 ];
}


// ---------------------------------------------------------------------------
Door::Door(DoorState_Type state) {
	this->state_ = state;
}

Door::Door() : Door(randomState()) { }

Door::~Door() {
	// TODO Auto-generated destructor stub
}

// ----------------------------------------------------------------------------
void Door::open() {
	this->state_ = E_Open;
}

void Door::close() {
	this->state_ = E_Closed;
}

bool Door::isOpen() {
	return this->state_ == E_Open;
}

} /* namespace adventure */
