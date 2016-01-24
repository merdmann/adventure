/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * IComponent.h is part of adv.
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
 *  Created on: Jan 10, 2015
 *      Author: MIchael
 */

#ifndef COMPONENT_EXCEPTION_H_
#define COMPONENT_EXCEPTION_H_

#include <boost/exception/all.hpp>

#include "PlayerFactory.h"


namespace adventure {

typedef enum { Component_Not_Found } ComponentError_Type;

typedef boost::error_info<struct tag_componenterror_type,ComponentError_Type> ComponentException_Info;

struct ComponentException : virtual boost::exception, virtual std::exception { };


} /* namespace adventure */

#endif /* COMPONENT_EXCEPTION_H_ */
