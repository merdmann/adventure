/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * Door.h is part of adv.
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
 *  Created on: Dec 7, 2014
 *      Author: MIchael
 */

/**
 * Maintains the door status
 */

#ifndef DOOR_H_
#define DOOR_H_

#include "IConnector.h"

namespace adventure {

typedef enum { E_Open, E_Closed, E_Locked } DoorState_Type;

class Door : public IConnector {

private:
	DoorState_Type state_;

public:
	Door(DoorState_Type);
	Door();
	virtual ~Door();

	void open();
	void close();
	bool isOpen();
};

} /* namespace adventure */

#endif /* DOOR_H_ */
