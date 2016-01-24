/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 *
 * Location.cpp is part of Adventure.
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

#include <boost/lexical_cast.hpp>

#include <iostream>
#include <vector>
#include <map>

#include "Location.h"
#include "DirectionType.h"

namespace adventure {
/* this is to provide the movement vector and the direction type */
typedef struct { int x; int y; } displacement_type;

static const displacement_type up_    = { 0, 1 };
static const displacement_type down_  = { 0, -1 };
static const displacement_type right_ = { 1, 0 };
static const displacement_type left_  = { -1, 0 };

static std::map<Direction_Type, displacement_type> dirMap_ = {
  { E_Up,    up_       },
  { E_Down,  down_     },
  { E_Left,  left_     },
  { E_Right, right_    }
};

// ---------------------------------------------------------------

Location::Location(Coordinate_Type width, Coordinate_Type height) {
  this->width_  = width;
  this->height_ = height;

  this->x_ = 0;
  this->y_ = 0;
}

Location::~Location() {
  // TODO Auto-generated constructor stub
}

// ---------------------------------------------------------------

unsigned Location::currentX() {
  return this->x_;
}

unsigned Location::currentY() {
  return this->y_;
}

void Location::setAt(Coordinate_Type x, Coordinate_Type y) {
  this->x_ = x;
  this->y_ = y;
}

// ---------------------------------------------------------------

void Location::setRange(Coordinate_Type width, Coordinate_Type height) {
  this->width_  = width;
  this->height_ = height;
}

// ----------------------------------------------------------------

void Location::calculateMove(Direction_Type   dir,
                             Coordinate_Type& x_,
                             Coordinate_Type& y_) {
  const displacement_type d = dirMap_[dir];
  const unsigned width      = this->width_;
  const unsigned height     = this->height_;

  const int x = (int)this->x_ + d.x;
  const int y = (int)this->y_ + d.y;

  // quietly we are assuming movements to take place only in single steps; there
  // for we check
  // for the boarder only which is potentially unsafe.

  if (x == width) x_ = 0;
  else if (x == -1) x_ = width - 1;
  else    x_ = x;

  if (y == height) y_ = 0;
  else if (y < 0) y_ = height - 1;
  else    y_ = y;
}

void Location::move(Direction_Type dir) {
  this->calculateMove(dir, this->x_, this->y_);
}

// -----------------------------------------------------------------
std::string Location::toString() {
  return boost::lexical_cast<std::string>(this->currentX())
         + "/"
         + boost::lexical_cast<std::string>(this->currentY());
}
} /* namespace adventure */
