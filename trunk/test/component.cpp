/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 *
 * db.cpp is part of muon_reloaded.
 *
 * muon_reloaded is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * muon_reloaded is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with muon_reloaded. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: Nov 2, 2014
 *      Author: MIchael
 */
#include <stdlib.h>
#include <string>
#include <vector>

#include <igloo/igloo_alt.h>
#include "MyTestListener.h"

#include "../include/Location.h"
#include "../include/TheMatrix.h"
#include "../include/cell.h"

#include "../include/PlayerFactory.h"
#include "../include/IComponent.h"
#include "../include/ComponentException.h"
#include "../include/PlayerInteractiveComponent.h"
#include "../include/FlexArguments.h"
#include "../include/TheMatrix.h"

using namespace igloo;
using namespace std;
using namespace adventure;


// ----------------------------------------------------------------------------

Describe(LOC01000_TheMatrix_Test) {

	void SetUp() {
	}

	Describe(MAT1000_Players) {

		void SetUp() {
			IComponent::registerComponent(
					PlayerInteractiveComponent::INTERACTIVE_PLAYER,
					(IComponent*) new PlayerInteractiveComponent()
			);
		}

		// get the board dimensions
		It(COM0001_can_get_a_component_id) {
			IComponent* comp = IComponent::getComponentByType(PlayerInteractiveComponent::INTERACTIVE_PLAYER);

			Assert::That( comp != NULL );
		}

		// get the board dimensions
		It(COM0001_can_create_an_instance) {
			IPlayable* result;
			FlexArguments args;
			const std::string name = "Michael";

			IComponent* comp = IComponent::getComponentByType(PlayerInteractiveComponent::INTERACTIVE_PLAYER);

			args.addValue(PlayerFactory::PLAYER_TYPE, (void*)&PlayerInteractiveComponent::INTERACTIVE_PLAYER);
			args.addValue(PlayerFactory::CONTEXT, (void*) new TheMatrix(10,10) );
			args.addValue(PlayerFactory::NAME, (void*) &name );

			result = comp->createInstance(&args);

			Assert::That( result != NULL );
		}

	};
};


// ----------------------------------------------------------------------------

int main()
{
	std::cout << "Start of Test" << std::endl;
	DefaultTestResultsOutput output;
	TestRunner runner(output);

	MyTestListener listener;
	runner.AddListener(&listener);

	runner.Run();
}
