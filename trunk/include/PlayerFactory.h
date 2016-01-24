/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * Player.h is part of Adventure.
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

#ifndef INCLUDE_PLAYERFACTORY_H_
#define INCLUDE_PLAYERFACTORY_H_

#include <string>
#include <map>
#include <vector>

#include "IPlayable.h"
#include "FlexArguments.h"

namespace adventure {

class PlayerFactory  {

private:
	std::map<std::string, IPlayable*> players_;

public:
	PlayerFactory();
	virtual ~PlayerFactory();

	IPlayable* newPlayer(FlexArguments*);
	IPlayable* getPlayerByName(std::string);

	std::vector<std::string> getAllPlayers();

	void addAttribute(std::string, void*);
	void* getAttribute(std::string);

	// player attributes for building a player
	static const std::string CONTEXT;
	static const std::string NAME;
	static const std::string PLAYER_TYPE;
	static const std::string PLAYER_X;
	static const std::string PLAYER_Y;
};


} /* adventure */
#endif /* INCLUDE_PLAYERFACTORY_H_ */
