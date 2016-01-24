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

#ifndef INCLUDE_IGAMECONTEXT_H_
#define INCLUDE_IGAMECONTEXT_H_

#include <string>
#include <boost/multi_array.hpp>

#include "PlayerFactory.h"
#include "Cell.h"
#include "CellCoordinateType.h"

namespace adventure {

class PlayerFactory;

typedef boost::multi_array<Cell*, 2> CellArray_Type;

/**
 * This is the playing field where the complete game happens. Players of the
 * game are moving between different cells.
 */
class IGameContext {

protected:
	PlayerFactory* factory_;
	CellArray_Type cell_;

	unsigned width_;
	unsigned height_;

public:
	IGameContext(unsigned, unsigned);
	virtual ~IGameContext();

	PlayerFactory* getPlayerFactory();
	bool playTurn();

	Cell* getCellAt(CellCoordinate_Type, CellCoordinate_Type);
	void  setCellAt(CellCoordinate_Type, CellCoordinate_Type, Cell*);

	// get dimension
	unsigned getWidth();
	unsigned getHeight();

	virtual void addPlayer(std::string, std::string) = 0;
};

} /* namespace adventure */

#endif /* INCLUDE_IGAMECONTEXT_H_ */
