/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 *
 * Cell.h is part of Adventure.
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

#ifndef SOURCE_DIRECTORY__CELL_H_
#define SOURCE_DIRECTORY__CELL_H_

#include <CellCoordinateType.h>
#include <IConnector.h>
#include <map>
#include <string>

#include "DirectionType.h"
#include "IDrawable.h"
#include "IConnector.h"
#include "Canvas.h"

namespace adventure {

/**
 * This is the base class for all rooms in the adventure world.
 *
 */
class Cell : public IDrawable {

private:
	bool isVisited_;
	IConnector *connector_[4];

public:
	Cell();
	virtual ~Cell();

	virtual char show();
	virtual void visit();

	bool isConnectionOpen(Direction_Type);
	void openConnection(Direction_Type);
	void closeConnection(Direction_Type);
	void connectTo(Direction_Type,Cell*, IConnector*);

	// the cursor is expected to be set the the center of the cell on the canvas.
	virtual void draw(Canvas*);

	static std::string To_String(Direction_Type);
};

} /* namespace adventure */

#endif /* SOURCE_DIRECTORY__CELL_H_ */
