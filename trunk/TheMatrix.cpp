/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * TheMatrix.cpp is part of Adventure.
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

#include <iostream>
#include <iomanip>
#include <strings.h>
#include <time.h>
#include <boost/array.hpp>

#include "TheMatrix.h"
#include "Door.h"
#include "IPlayable.h"
#include "MovementException.h"
#include "PlayerFactory.h"
#include "IComponent.h"
#include "ComponentException.h"
#include "PlayerInteractiveComponent.h"

namespace adventure {

class PlayerFactory;

const unsigned CELL_SIZE = 1;

// -----------------------------------------------------------------------

TheMatrix::TheMatrix(unsigned width, unsigned height) : IGameContext(width,height) {
	for(CellCoordinate_Type y=0; y<this->height_; ++y ) {
		for(CellCoordinate_Type x=0; x<this->width_; ++x) {
			Cell* here = this->getCellAt(x,y);

			here->connectTo(E_Right, this->getCellAt(x,y+1), (IConnector*) new Door() );
			here->connectTo(E_Up, this->getCellAt(x+1,y), (IConnector*) new Door() );
		}
	}

	// the canvas takes width and height in number of cells with one common cell size
	this->canvas_ = new Canvas(width,height, CELL_SIZE);

	srand (time(NULL));
}

TheMatrix::~TheMatrix() {
	for(CellCoordinate_Type x=0; x<this->width_; ++x ) {
		for(CellCoordinate_Type y=0; y<this->height_; ++y) {
			Cell* c = this->getCellAt(x,y);

			if( c != NULL )
				delete c;
		}
	}
}

// -----------------------------------------------------------------------

void TheMatrix::show() {
	// draw all cells
	this->canvas_->clear();

	for(CellCoordinate_Type y=0; y<this->height_; ++y ) {
		for(CellCoordinate_Type x=0; x<this->width_; ++x) {
			Cell* cell = this->getCellAt(x,y);

			this->canvas_->setCursorToCell(x,y);

			// draw the connecting gates
			if( cell->isConnectionOpen(E_Right))
				this->canvas_->WallY();
			if( cell->isConnectionOpen(E_Up))
				this->canvas_->WallX();

			// draw the actual cell contents
			cell->draw(this->canvas_);
		}
	}
	this->canvas_->setCursor(0,0);

	// draw the position of all players
	const std::vector<std::string> players = this->factory_->getAllPlayers();

	for(std::vector<std::string>::size_type i=0; i != players.size(); ++i ) {
		IPlayable* p = this->factory_->getPlayerByName( players[i] );
		Location* l = p->getLocation();
		std::string name = p->getName();

		this->canvas_->setCursorToCell((CellCoordinate_Type)l->currentX(), (CellCoordinate_Type)l->currentY());
		this->canvas_->setAt( (CellCoordinate_Type)0, (CellCoordinate_Type)0, p->Glyph());
	}

	// show the result of the drawing process
	this->canvas_->show();
}

// ------------------------------------------------------------------------

void TheMatrix::addPlayer(std::string name, std::string type) {
	FlexArguments args;

	CellCoordinate_Type x0 = rand() % this->width_;
	CellCoordinate_Type y0 = rand() % this->height_;

	args.addValue(PlayerFactory::PLAYER_TYPE, (void*)&type);
	args.addValue(PlayerFactory::CONTEXT, (void*) this );
	args.addValue(PlayerFactory::NAME, (void*) &name );

	IPlayable *p = this->factory_->newPlayer(&args);

	p->setName(name);
	p->setAt(x0,y0);
}

void TheMatrix::move(IPlayable *player, Direction_Type dir) {
	Location* l = player->getLocation();
	Cell* cell = this->cell_[l->currentY()][l->currentX()];

	if( cell->isConnectionOpen(dir) )
		l->move(dir);
	else
		throw Movement_Exception() << Movement_Exception_Info(dir);

}

} /* namespace adventure */
