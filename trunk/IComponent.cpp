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

#include <string>
#include <map>

#include "IComponent.h"
#include "PlayerFactory.h"
#include "PlayerInteractiveComponent.h"

namespace adventure {

static std::map<std::string, IComponent*> component_;

// --------------------------------------------------------------------------------------
IComponent::IComponent() {
}

IComponent::~IComponent() {
}

// --------------------------------------------------------------------------------------

void IComponent::registerComponent(std::string name, IComponent* comp) {
	component_[name] = comp;
}


IComponent* IComponent::getComponentByType(std::string typeName) {
	IComponent* result = NULL;

	if(component_.count(typeName) > 0)
		result = component_[typeName];

	return result;
}

}
