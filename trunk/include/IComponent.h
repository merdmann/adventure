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

#ifndef ICOMPONENT_H_
#define ICOMPONENT_H_

#include <string>
#include <map>
#include <vector>

#include "PlayerFactory.h"
#include "ComponentException.h"
#include "FlexArguments.h"

namespace adventure {

class IComponent {

public:
	IComponent();
	virtual ~IComponent();

	static void Initialize();
	static IComponent* getComponentByType(std::string);
	static void registerComponent(std::string, IComponent*);

	//
	virtual IPlayable* createInstance(FlexArguments*) = 0;
};

} /* namespace adventure */

#endif /* ICOMPONENT_H_ */
