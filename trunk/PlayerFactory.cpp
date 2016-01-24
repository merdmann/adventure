/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * Player.cpp is part of Adventure.
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
 *  Created on: Nov 15, 2014
 *      Author: MIchael
 */

#include <strings.h>
#include <map>

#include "PlayerFactory.h"
#include "IPlayable.h"
#include "PlayerInteractive.h"
#include "IComponent.h"
#include "ComponentException.h"

namespace adventure {

const std::string PlayerFactory::CONTEXT = "_context_" ;
const std::string PlayerFactory::NAME = "_name_";
const std::string PlayerFactory::PLAYER_TYPE = "_player_";
const std::string PlayerFactory::PLAYER_X = "_player_x_";
const std::string PlayerFactory::PLAYER_Y = "_player_y_";

// ---------------------------------------------------------------------------------------

PlayerFactory::PlayerFactory() {
	this->players_.clear();
}

PlayerFactory::~PlayerFactory() {
	// TODO Auto-generated destructor stub
}

// ---------------------------------------------------------------------------------------

IPlayable* PlayerFactory::getPlayerByName(std::string name) {
	return this->players_[name];
}

std::vector<std::string> PlayerFactory::getAllPlayers() {
	std::vector<std::string> result;

	for( std::map<std::string, IPlayable*>::iterator it=this->players_.begin(); it != this->players_.end(); ++it) {
		result.push_back(it->first);
	}
	return result;
}

IPlayable* PlayerFactory::newPlayer(FlexArguments *args) {
	IPlayable* result;
	const std::string* typeName = (std::string*)(args->getValue(PLAYER_TYPE));

	IComponent* comp = IComponent::getComponentByType(*typeName);
	if( comp == NULL ) {
		throw ComponentException() << ComponentException_Info(Component_Not_Found);
	}

	result = comp->createInstance(args);
	this->players_[*((std::string*)args->getValue(PlayerFactory::NAME))] = result;
	return result;
}

} /* namespace adventure */
