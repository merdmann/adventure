/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * PlayerInteractive.cpp is part of adv.
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

#include <boost/exception/all.hpp>

#include "PlayerInteractive.h"
#include "Canvas.h"
#include "PlayerFactory.h"
#include "PlayerInteractive.h"
#include "TheMatrix.h"
#include "Helpers.h"
#include "Location.h"
#include "MovementException.h"

namespace adventure {

// ---------------------------------------------------------------------------------------

#ifdef FOO
IPlayable* PlayerInteractive::createInstance(std::string name, IGameContext* ctx) {
	return new PlayerInteractive( name, ctx);
}
#endif

// ---------------------------------------------------------------------------------------

PlayerInteractive::PlayerInteractive(std::string name, IGameContext *ctx) : IPlayable(name,0,0) {
	TheMatrix *matrix = (TheMatrix*)ctx;

	this->getLocation()->setRange(
			(Coordinate_Type)matrix->getWidth(),
			(Coordinate_Type)matrix->getHeight());
}

PlayerInteractive::~PlayerInteractive() {
	// TODO Auto-generated destructor stub
}

// ----------------------------------------------------------------------------------------

bool PlayerInteractive::Play(IGameContext* ctx) {
	TheMatrix* matrix =  (TheMatrix*)ctx;
	PlayerFactory* factory = matrix->getPlayerFactory();
	std::string myName = this->getName();
	IPlayable* player = factory->getPlayerByName(myName);

	Location* loc = player->getLocation();

	Direction_Type intend = E_None;

	while( intend == E_None ) {
		std::string cmd;
		cmd[0] = '\0';

		std::cout << "[ " <<loc->toString() << "] $ ";
		std::getline( std::cin, cmd);

		if( cmd[0] == 'q' )
			return false;
		else if( cmd[0] == 'm') {
			matrix->show();
			continue;
		}

		switch(cmd[0]) {
			case 'f':
				intend = E_Up;
				break;
			case 'b':
				intend = E_Down;
				break;
			case 'l':
				intend = E_Left;
				break;
			case 'r':
				intend = E_Right;
				break;
		}
	}

	try {
		matrix->move(player,intend);
	}
	catch( Movement_Exception& e) {
		adventure::Direction_Type* mv=boost::get_error_info<Movement_Exception_Info>(e);

		std::cerr << "The door is closed at the " << helpers::To_String(*mv) << "." << std::endl;
	}

	return true;
}

char PlayerInteractive::Glyph() {
	return 'A';
}

} /* namespace adventure */
