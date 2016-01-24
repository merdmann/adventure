/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * Location.h is part of Adventure.
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

#ifndef LOCATION_H_
#define LOCATION_H_

#include <boost/exception/all.hpp>
#include <iostream>

#include "DirectionType.h"
#include "Cell.h"
#include "CoordinateType.h"

namespace adventure {

class Location {

private:
	Coordinate_Type x_;
	Coordinate_Type y_;

	Coordinate_Type width_;
	Coordinate_Type height_;

public:
    Location(Coordinate_Type, Coordinate_Type);
	virtual ~Location();

	void setAt(Coordinate_Type, Coordinate_Type);
	void setRange(Coordinate_Type, Coordinate_Type);

	void move(Direction_Type dir);
	void calculateMove(Direction_Type dir, Coordinate_Type&, Coordinate_Type&);

	unsigned currentX();
	unsigned currentY();

	std::string toString();
};

} /* namespace adventure */

#endif /* LOCATION_H_ */
