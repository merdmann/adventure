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
using namespace igloo;
using namespace std;
using namespace adventure;


// ----------------------------------------------------------------------------

Describe(LOC01000_TheMatrix_Test) {

	void SetUp() {
		IComponent::registerComponent(
						PlayerInteractiveComponent::INTERACTIVE_PLAYER,
						(IComponent*) new PlayerInteractiveComponent()
				);

	}

	Describe(MAT1000_Players) {

		void SetUp() {
			matrix = new TheMatrix(10,10);
		}

		// get the board dimensions
		It(MAT0001_can_get_the_board_height) {
			Assert::That( matrix->getHeight() == 10 );
		}

		It(MAT0001_can_get_the_board_width) {
			Assert::That( matrix->getWidth() == 10 );
		}

		// handler players
		It(MAT1001_can_add_players_to_matrix) {
			try {
				PlayerFactory *f = matrix->getPlayerFactory();

				matrix->addPlayer("Michael", PlayerInteractiveComponent::INTERACTIVE_PLAYER);
				Assert::That(true);
			}
			catch(ComponentException& ex) {
				Assert::That(false);
			}
		}

		It(MAT1002_can_get_players_from_matrix) {
			PlayerFactory *f = matrix->getPlayerFactory();
			matrix->addPlayer("Michael", PlayerInteractiveComponent::INTERACTIVE_PLAYER);

			// get the player
			vector<string> result = f->getAllPlayers();

			if( result[0].compare("Michael") )
				Assert::That(true);
			else
				Assert::That(true);
		}

		It(MAT1001_can_print_the_matrix) {
			try {
				PlayerFactory *f = matrix->getPlayerFactory();

				matrix->addPlayer("Michael", PlayerInteractiveComponent::INTERACTIVE_PLAYER);
				matrix->show();

				Assert::That(true);
			}
			catch(ComponentException& ex) {
				Assert::That(false);
			}
		}

		TheMatrix* matrix;
	};

};


// ----------------------------------------------------------------------------

int main()
{
	DefaultTestResultsOutput output;
	TestRunner runner(output);

	MyTestListener listener;
	runner.AddListener(&listener);

	runner.Run();
}
