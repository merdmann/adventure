/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * Canvas.cpp is part of Adventure.
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

#include <iostream>
#include <iomanip>
#include <string>

#include <Canvas.h>
#include <boost/lexical_cast.hpp>


/**
 * This class provide the infrastructure to draw the game field.
 */

namespace adventure {

/**
 *  A canvas provides a two dimensional arrays of glyph's which can addressed
 *  directly by using coordinates of type Coordinate_Type.
 *
 *  A cell consits of an border of the width of one canvas elements and a
 *  cell body. The cell width specifies the cell body which is normally
 *  drawn relative to the (0,0) point relative the the cellCoordinate position.
 *
 *  The total size of a cell is given by cellWidth:
 *
 *  cellWidth = borderSize(1) + coreSize (1) + 2*cellSpace (C).
 *
 *                                 : Next cell -...-->
 *             | | |   |   | S |   |   |
 *        -----+---+---+---+---+---+---+
 *             | | | X | X | G | X | X |
 *        -----+---+---+---+---+---+---+
 *             | | | X | C | C | C | X |
 *        -----+---+---+---+---+---+---+
 *           S | | | G | C | 0 | C | G |
 *        -----+---+---+---+---+---+---+
 *             | | | X | C | C | C | X |
 *        -----+---+---+---+---+---+---+
 *             | | | X | X | G | X | X |
 *
 *                           |<----- D ------>
 *
 *   X = Border
 *   D = Door
 *   C,0 - Cell inner
 *
 *  borderSize and coreSize are values which are not configurable outside of
 *  this class.
 *
 *  On top of these coordinates the CellCoordinate_Type is a coordinate system
 *  which addresses the cells. The period of this gird of cells is:
 *
 *  D = cellWidth - 1 ;
 *
 *  A cell in CellCoordinate_Type: cellX,cellY translates into Coordinate_Type
 *  using the following formula, assuming cellSize is an odd number.
 *
 *     x = cellX * D + borderSize + cellSpace + 1;
 *     y = cellY * D + borderSize + cellSpace + 1;
 *
 *
 */
unsigned Canvas::BorderSize = 1;
unsigned Canvas::CoreSize   = 1;
unsigned Canvas::LeftFill   = 5;


/*
 * This is the border to border size of a single cell
 */
static unsigned cellWidth(unsigned space) {
	return Canvas::CoreSize + 2*space + 2*Canvas::BorderSize;
}

/*
 * This is the cell period
 */
unsigned Canvas::cellPeriod() {
	return cellWidth(this->cellSpace_)-Canvas::BorderSize;
}

Coordinate_Type Canvas::cell2grid(CellCoordinate_Type x) {
	const unsigned D = this->cellPeriod();

	return x*D + Canvas::BorderSize + this->cellSpace_ ;
}

unsigned Canvas::getCellSize() { return this->cellSpace_; }

unsigned Canvas::nbrOfXPixels() { return this->width_*this->cellPeriod(); }
unsigned Canvas::nbrOfYPixels() { return this->width_*this->cellPeriod(); }


// ---------------------------------------------------------------------------
void Canvas::cliping(Coordinate_Type& x, Coordinate_Type& y) {
	const unsigned D = this->cellPeriod();

	x = x % this->nbrOfXPixels();
    y = y % this->nbrOfYPixels();
}

// ---------------------------------------------------------------------------

Canvas::Canvas(unsigned width, unsigned height, unsigned cellSpace) {
	const unsigned D = this->cellPeriod();

	this->width_ = width;
	this->heigth_ = height;
	this->cellSpace_ = cellSpace;

	this->x0_ = 0;
	this->y0_ = 0;

	boost::array<unsigned, 2> extents;
	extents[1] = this->nbrOfXPixels();
	extents[0] = this->nbrOfYPixels();

	this->points_.resize(extents);

	this->clear();
}

Canvas::~Canvas() {
	// TODO Auto-generated destructor stub
}

void Canvas::getGeometry(unsigned& width, unsigned& height) {
	width = this->width_;
	height = this->heigth_;
}

// ---------------------------------------------------------------------------

/*
 * clear all glyph's in the canvas.
 */
void Canvas::clear() {
	const unsigned NX = this->nbrOfXPixels();
	const unsigned NY = this->nbrOfYPixels();

	for(unsigned y=0; y<NY; ++y ) {
		for(unsigned x=0; x<NY; ++x) {
			this->points_[y][x] = ' ';
		}
	}
}

void Canvas::WallX() {
	const int length = this->cellSpace_ + Canvas::BorderSize;

	setAt( (Coordinate_Type) -length, (Coordinate_Type)  length, '+' );
	setAt( (Coordinate_Type)  length, (Coordinate_Type)  length, '+' );

	for(int i= -(length-1); i<=length-1; ++i)
		this->setAt( (Coordinate_Type)i, (Coordinate_Type)length, '-');
}

void Canvas::WallY() {
	const int length = this->cellSpace_ + Canvas::BorderSize;

	setAt( (Coordinate_Type) length, (Coordinate_Type) -length, '+' );
	setAt( (Coordinate_Type) length, (Coordinate_Type)  length, '+' );

	for(int i= -(length-1); i<=(length-1); ++i)
		this->setAt((Coordinate_Type)length, (Coordinate_Type)i, '|');
}

/*
 * Draw a grid
 */
void Canvas::grid() {
	const unsigned C = this->cellSpace_ + Canvas::CoreSize;

	for(CellCoordinate_Type x=0; x < this->width_; ++x)
		for(CellCoordinate_Type y = 0; y < this->heigth_; ++y) {
			this->setCursorToCell(x,y);

			this->setAt(-C,  C, '+' );
			this->setAt(-C, -C, '+' );
		}
}

/*
 *         <----------- width * D ----------------->
 *     L   <- D ->
 *  ------+------+------+ ..................+------+
 *        |
 */
void Canvas::drawXruler(Placement_Type where) {

	std::cout << std::setw(Canvas::LeftFill) << ".";
	std::cout << "+" << std::setfill('.');

	for(unsigned i=0; i<this->width_; ++i) {
		std::cout << std::setw(Canvas::BorderSize + this->cellSpace_ ) << ".";
		std::cout << boost::lexical_cast<std::string>(i%10);
	    std::cout << std::setw( this->cellSpace_ ) << ".";
	}
	std::cout << "+" << std::setfill(' ') << std::endl;
}

void Canvas::show() {
	const unsigned D = this->cellPeriod();
	const unsigned C = this->cell2grid(0);  // returns the core position

	this->drawXruler(E_Above);

	//this->grid();

	// dump the cells
	for(unsigned y=0; y<this->nbrOfYPixels(); ++y ) {
		if(  ((y+C) % D) == 0 )
			std::cout << std::setw(Canvas::LeftFill) << y/D << ".";
		else
			std::cout << std::setw(Canvas::LeftFill) << " " << ".";

		// write the line
		for(unsigned x=0;x<this->nbrOfXPixels(); ++x)
			std::cout << this->points_[y][x] ;
		std::cout << "." << std::endl;
	}
	this->drawXruler(E_Below);
}

// -------------------------------------------------------------------------------
void Canvas::setCursor(Coordinate_Type x, Coordinate_Type y) {
	this->cliping(x,y);

	this->x0_ = x;
	this->y0_ = y;
}

void Canvas::setCursorToCell( CellCoordinate_Type cellX, CellCoordinate_Type cellY) {
	const Coordinate_Type x = this->cell2grid(cellX);
	const Coordinate_Type y = this->cell2grid(cellY);

	this->setCursor(x,y);
}

/*
 * Set a glyph relative to the current cursor in pixel coordinates
 */
void Canvas::setAt(Coordinate_Type x,Coordinate_Type y,char glyph ) {
	x = x  + this->x0_;
	y = y  + this->y0_;

	this->cliping( x, y);

	this->points_[y][x] = glyph;
}

bool Canvas::isAt(Coordinate_Type x, Coordinate_Type y, char glyph) {
	return this->points_[y][x] == glyph;
}

bool Canvas::isAtCell(CellCoordinate_Type x, CellCoordinate_Type y, char glyph) {
	this->setCursorToCell(x, y);

	return this->points_[this->y0_][this->x0_] == glyph;
}

} /* namespace adventure */
