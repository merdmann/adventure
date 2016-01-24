/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * PlayerWombat.cpp is part of adv.
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
 *  Created on: Dec 25, 2014
 *      Author: MIchael
 */

#include <iostream>

#include <boost/exception/all.hpp>

#include "PlayerWombat.h"
#include "Canvas.h"
#include "PlayerFactory.h"
#include "PlayerWombat.h"
#include "TheMatrix.h"
#include "Helpers.h"
#include "Location.h"
#include "MovementException.h"
#include "DirectionType.h"

namespace adventure {

// ---------------------------------------------------------------------------------------
PlayerWombat::PlayerWombat(std::string name, IGameContext *ctx) : IPlayable(name,0,0) {
	TheMatrix *matrix = (TheMatrix*)ctx;

	this->getLocation()->setRange(
			(Coordinate_Type)matrix->getWidth(),
			(Coordinate_Type)matrix->getHeight());
}

PlayerWombat::~PlayerWombat() {
	// TODO Auto-generated destructor stub
}

// ----------------------------------------------------------------------------------------

bool PlayerWombat::Play(IGameContext* ctx) {
	TheMatrix* matrix =  (TheMatrix*)ctx;
	PlayerFactory* factory = matrix->getPlayerFactory();

	std::string myName = this->getName();
	IPlayable* player = factory->getPlayerByName(myName);

	Direction_Type intend = Random_Direction();

	std::cout <<  myName << " moves " << helpers::To_String(intend);

	try {
		matrix->move(player,intend);
		std::cout << std::endl;
	}
	catch( Movement_Exception& e) {
		adventure::Direction_Type* mv=boost::get_error_info<Movement_Exception_Info>(e);
		std::cout << ", but the door is closed!" << std::endl;
	}

	return true;
}

char PlayerWombat::Glyph() {
    return 'W';
}

} /* namespace adventure */
