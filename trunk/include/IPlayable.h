/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * IPlayable.h is part of adv.
 *
 * adv is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * adv is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with adv. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: Dec 25, 2014
 *      Author: MIchael
 */

#ifndef IPLAYABLE_H_
#define IPLAYABLE_H_

//#include "IGameContext.h"
#include "Location.h"

namespace adventure {

class IGameContext;

class IPlayable {

private:
	Location *location_;
	std::string name_;

public:
	IPlayable(std::string, Coordinate_Type, Coordinate_Type );
	virtual ~IPlayable();

	void setAt(Coordinate_Type, Coordinate_Type);
	Location* getLocation() ;

	void setName(std::string);
	std::string getName();

	void setRange(Coordinate_Type, Coordinate_Type);

	virtual bool Play(IGameContext*) = 0;
	virtual char Glyph() = 0;
};

} /* namespace adventure */

#endif /* IPLAYABLE _H_ */




