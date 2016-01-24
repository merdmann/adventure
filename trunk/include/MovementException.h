/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * MovementException.h is part of adv.
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
 *  Created on: Dec 26, 2014
 *      Author: MIchael
 */

#ifndef MOVEMENTEXCEPTION_H_
#define MOVEMENTEXCEPTION_H_

#include <boost/exception/all.hpp>

namespace adventure {

typedef boost::error_info<struct tag_movement_info,Direction_Type> Movement_Exception_Info;
struct Movement_Exception : virtual boost::exception, virtual std::exception { };

}



#endif /* MOVEMENTEXCEPTION_H_ */
