/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * Canvas.h is part of Adventure.
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

#ifndef INCLUDE_THEMATRIX_H_
#define INCLUDE_THEMATRIX_H_

#include <boost/multi_array.hpp>

#include "IPlayable.h"
#include "PlayerFactory.h"
#include "IGameContext.h"
#include "Canvas.h"

namespace adventure {

/**
 * This is the playing field where the complete game happens. Players of the
 * game are moving between different cells.
 */
class TheMatrix : public IGameContext {

private:
	Canvas* canvas_;

public:
	// the matrix with a given number of NxM cells.
	TheMatrix(unsigned,unsigned);
	virtual ~TheMatrix();

	void addPlayer(std::string name, std::string);

	// show the complete canvas
	void show();

	void move(IPlayable*, Direction_Type);

};

} /* namespace adventure */

#endif /* SOURCE_DIRECTORY__CANVAS_H_ */
