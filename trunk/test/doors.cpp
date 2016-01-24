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
#include <iostream>
#include <iomanip>
#include <strings.h>
#include <time.h>

#include <igloo/igloo_alt.h>
#include "MyTestListener.h"

#include "../include/Door.h"

using namespace igloo;
using namespace std;
using namespace adventure;


// ----------------------------------------------------------------------------

Describe(Doors_Behaviour) {

	void SetUp() {
		srand (time(NULL));
	}

	Describe(DOR1000_Door_States) {
		void SetUp() {
		}

		It(DOR1001_Door_can_be_open) {
			door = new Door(E_Open);

			Assert::That( door->isOpen() );

			delete(door);
		}

		It(DOR1002_Door_can_be_closed) {
			door = new Door(E_Closed);

			Assert::That( !door->isOpen() );

			delete(door);
		}


		Door *door;
	};

	Describe(DOR2000_Door_Actions) {
		void SetUp() {

		}

		It(DOR2001_open_doors_can_be_closed) {
			door = new Door(E_Open);

			Assert::That( door->isOpen() );
			door->close();
			Assert::That( !door->isOpen() );

			delete(door);
		}

		It(DOR2002_closed_door_can_be_opened) {
			door = new Door(E_Closed);

			Assert::That( !door->isOpen() );
			door->open();
			Assert::That( door->isOpen() );

			delete(door);
		}

		Door *door;
	};

	Describe(DOR3000_Random) {

		It(DOR3000_one_third_is_open) {
			Door *door;

			unsigned open = 0;
			unsigned closed = 0;

			for(int i=0; i<90; ++i) {
				door = new Door();

				if( door->isOpen() )
					open++;
				else
					closed++;

				delete(door);
			}

			// std::cout << open << " " << closed << std::endl;

			Assert::That(open < 40 && closed > 40 );
		}
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
