/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 *
 * Cell.cpp is part of Adventure.
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
#include <cstdlib>
#include <vector>

#include "Cell.h"
#include "DirectionType.h"

namespace adventure {
// --------------------------------------------------------------------------------
Cell::Cell(int cellSize) {
  this->isVisited_ = false;

  for (int i = 0; i < 4; ++i) this->connector_[i] = NULL;
}

Cell::~Cell() {
  // TODO Auto-generated destructor stub
}

// --------------------------------------------------------------------------------
char Cell::show() {
  if (this->isVisited_) return '.';
  else    return ' ';
}

void Cell::visit() {
  this->isVisited_ = true;
}

bool Cell::isConnectionOpen(Direction_Type dir) {
  return this->connector_[dir]->isOpen();
}

void Cell::openConnection(Direction_Type dir) {
  this->connector_[dir]->open();
}

void Cell::closeConnection(Direction_Type dir) {
  this->connector_[dir]->close();
}

void Cell::draw(Canvas *canvas) {
  Direction_Type const dirs[] = { E_Left, E_Right, E_Up, E_Down };

  for (int i = 0; i < 4; ++i) {
    IConnector *connector = this->connector_[i];

    if (connector == NULL) continue;

    switch (dirs[i]) {
    case E_Left:
      canvas->setAt(-1, 0, connector->isOpen() ? ' ' : '|');
      break;

    case E_Right:
      canvas->setAt(1, 0, connector->isOpen() ? ' ' : '|');
      break;

    case E_Up:
      canvas->setAt(0, 1, connector->isOpen() ? ' ' : '-');
      break;

    case E_Down:
      canvas->setAt(0, -1, connector->isOpen() ? ' ' : '-');
      break;
    }
  }
}

void Cell::connectTo(Direction_Type dir, Cell *to, IConnector *connector) {
  switch (dir) {
  case E_Left:

    if (this->connector_[0] == NULL) {
      this->connector_[0] = connector;
      to->connector_[1]   = connector;
    }
    break;

  case E_Right:

    if (this->connector_[1] == NULL) {
      this->connector_[1] = connector;
      to->connector_[0]   = connector;
    }
    break;

  case E_Up:

    if (this->connector_[2] == NULL) {
      this->connector_[2] = connector;
      to->connector_[3]   = connector;
    }
    break;

  case E_Down:

    if (this->connector_[3] == NULL) {
      this->connector_[3] = connector;
      to->connector_[2]   = connector;
    }
    break;
  }
}
} /* namespace adventure */
