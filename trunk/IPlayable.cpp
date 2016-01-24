/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * Player.cpp is part of Adventure.
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

#include <strings.h>

#include "IPlayable.h"

namespace adventure {

IPlayable::IPlayable(std::string name, Coordinate_Type width, Coordinate_Type heigth) {
	this->name_ = name;
	this->location_ = new Location(width, heigth);
}

IPlayable::~IPlayable() {
	//TODO:
}

void IPlayable::setAt(Coordinate_Type x, Coordinate_Type y) {
	this->location_->setAt(x,y);
}

Location* IPlayable::getLocation() {
	return this->location_;
}

void IPlayable::setName(std::string name) {
	this->name_ = name;
}

std::string IPlayable::getName() {
	return this->name_;
}


} /* namespace adventure */
