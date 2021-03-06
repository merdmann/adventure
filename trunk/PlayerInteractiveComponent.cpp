/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * PlayerInteractiveComponent.cpp is part of adv.
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
 *  Created on: Jan 11, 2015
 *      Author: MIchael
 */

#include "PlayerFactory.h"
#include "PlayerInteractive.h"
#include "PlayerInteractiveComponent.h"


namespace adventure {

const std::string PlayerInteractiveComponent::INTERACTIVE_PLAYER = "Interactive";

PlayerInteractiveComponent::PlayerInteractiveComponent() {
	// TODO Auto-generated constructor stub

}

PlayerInteractiveComponent::~PlayerInteractiveComponent() {
	// TODO Auto-generated destructor stub
}


IPlayable* PlayerInteractiveComponent::createInstance(FlexArguments *args) {
	IGameContext* ctx = (IGameContext*)args->getValue(PlayerFactory::CONTEXT);
	const std::string* name = (std::string*)args->getValue(PlayerFactory::NAME);

	IPlayable* result = (IPlayable*) new PlayerInteractive(*name,ctx);
	return result;
}

} /* namespace adventure */
