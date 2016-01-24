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

#include <igloo/igloo_alt.h>
#include "MyTestListener.h"

#include "../include/PlayerFactory.h"
#include "../include/Location.h"
#include "../include/TheMatrix.h"
#include "../include/cell.h"

using namespace igloo;
using namespace std;
using namespace adventure;

// ----------------------------------------------------------------------------


Describe(LOC01000_Location_Test) {

	void SetUp() {
	}

	Describe(LOC01100_Movements) {

		void SetUp() {
			matrix = new TheMatrix(10,10);
		}

		It(LOC01101_can_move_up) {
			Location l(matrix->getWidth(), matrix->getHeight());
			l.setAt(0,0);

			unsigned x0 = l.currentX();
			unsigned y0 = l.currentY();

			l.move(E_Up);
			Assert::That( l.currentX() == x0 && l.currentY() == 1  );
		}

		It(LOC01103_can_move_down) {
			const unsigned height = matrix->getHeight();
			Location l(matrix->getWidth(), matrix->getHeight());
			l.setAt(0,0);

			unsigned x0 = l.currentX();
			unsigned y0 = l.currentY();

			l.move(E_Down);
			Assert::That( l.currentX() == x0 && l.currentY() == (height-1) );
		}


		It(LOC01104_can_move_left) {
			Location l(matrix->getWidth(), matrix->getHeight());
			l.setAt(0,0);

			unsigned x0 = l.currentX();
			unsigned y0 = l.currentY();

			l.move(E_Left);
			Assert::That( l.currentX() == (matrix->getWidth()-1) && l.currentY() == y0  );
		}

		It(LOC01106_can_move_right) {
			Location l(matrix->getWidth(), matrix->getHeight());
			l.setAt(0,0);

			unsigned x0 = l.currentX();
			unsigned y0 = l.currentY();

			l.move(E_Right);
			Assert::That( l.currentX() == (x0+1) && l.currentY() == y0  );
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
