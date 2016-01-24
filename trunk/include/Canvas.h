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
 *  Created on: Nov 12, 2014
 *      Author: MIchael
 */

/**
 * A canvas consists of pixesl which arer organized in quadratic cells
 * with a size of 2*cellSize where the cells are expected to drop there
 * contents.
 */

#ifndef INCLUDE_CANVAS_H_
#define INCLUDE_CANVAS_H_

#include <boost/multi_array.hpp>
#include "CoordinateType.h"
#include "CellCoordinateType.h"

namespace adventure {

class Canvas {

private:
	unsigned width_;
	unsigned heigth_;
	unsigned cellSpace_;

	// cursor position
	Coordinate_Type x0_;
	Coordinate_Type y0_;

	// the canvas is a two dimensional array of chars (glyphs)
	typedef boost::multi_array<char, 2> canvas_type;

	canvas_type points_;

	void cliping(Coordinate_Type&,Coordinate_Type&);

	typedef enum { E_Above, E_Below } Placement_Type;
	void drawXruler(Placement_Type);

	Coordinate_Type cell2grid(CellCoordinate_Type x);
	unsigned cellPeriod();

	unsigned nbrOfXPixels();
	unsigned nbrOfYPixels();

public:
	Canvas() : Canvas(20,20,3) {}
	Canvas(CellCoordinate_Type,CellCoordinate_Type,unsigned);
	virtual ~Canvas();

	void clear();
	void grid();
	void show();

	unsigned getCellSize();
	void getGeometry(unsigned&, unsigned&);

	void setAt(Coordinate_Type,Coordinate_Type,char);
	void setCursor(Coordinate_Type,Coordinate_Type);
	bool isAt(Coordinate_Type x, Coordinate_Type y, char);
	void setCursorToCell( CellCoordinate_Type, CellCoordinate_Type);
	bool isAtCell(CellCoordinate_Type, CellCoordinate_Type, char);

	void WallX();
	void WallY();

	static unsigned BorderSize;
	static unsigned CoreSize;
	static unsigned LeftFill;


} /* Canvas */;

} /* namespace adventure */

#endif /* INCLUDE_CANVAS_H_ */
