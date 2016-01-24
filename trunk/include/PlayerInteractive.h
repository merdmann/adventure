/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * PlayerInteractive.h is part of adv.
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

#ifndef PLAYERINTERACTIVE_H_
#define PLAYERINTERACTIVE_H_

#include "IGameContext.h"
#include "IPlayable.h"

namespace adventure {

class PlayerInteractive : public IPlayable {

public:
	PlayerInteractive(std::string name, IGameContext* ctx);
	virtual ~PlayerInteractive();

	bool Play(IGameContext*);
	char Glyph();

	static IPlayable* createInstance(std::string, IGameContext* ctx);
};

} /* namespace adventure */

#endif /* PLAYERINTERACTIVE_H_ */
