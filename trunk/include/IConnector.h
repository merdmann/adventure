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
 * Connector between to rooms
 */

#ifndef ICONNECTOR_H_
#define ICONNECTOR_H_

namespace adventure {

class IConnector {

public:
	virtual ~IConnector() {};

	virtual void open() = 0;
	virtual void close() = 0;
	virtual bool isOpen() = 0;
};

} /* namespace adventure */

#endif /* ICONNECTOR_H_ */
