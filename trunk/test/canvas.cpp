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
#include <time.h>

#include <igloo/igloo_alt.h>
#include "MyTestListener.h"

#include "../include/Canvas.h"

using namespace igloo;
using namespace std;
using namespace adventure;

// ----------------------------------------------------------------------------


Describe(CAN01000_Canvas_Test) {

	void SetUp() {
	}

	Describe(CNV01000_Direct_Coordinate_Operations) {

		void SetUp() {
			srand (time(NULL));
		}

		It(CNV01000_Can_Query_Geomerty) {
			unsigned width, height;

			canvas->getGeometry(width,height);

			Assert::That(width == 10 && height == 10 );
		}

		It(CNV01001_Can_set_and_test_any_pixel) {
			Coordinate_Type x,y;

			unsigned width, height;

			canvas->getGeometry(width,height);
			width = width * canvas->getCellSize();
			height = height * canvas->getCellSize();

			x = rand() % width;
			y = rand() % height;

			canvas->setAt(0,0,'1');
			canvas->setAt(width-1,0,'2');
			canvas->setAt(0,height-1,'3');
			canvas->setAt(width-1,height-1,'4');

			//canvas->show();

			Assert::That(canvas->isAt(0,0,'1'), Equals(true));
			Assert::That(canvas->isAt(width-1,0,'2'), Equals(true));
			Assert::That(canvas->isAt(0,height-1,'3'), Equals(true));
			Assert::That(canvas->isAt(width-1,height-1,'4'), Equals(true));
		}

		It(CNV01002_Can_Clear_Screen) {
			Coordinate_Type x,y;
			unsigned width, height;

			canvas->getGeometry(width,height);

			x = rand() % width;
			y = rand() % height;

			canvas->setAt(0,0,'1');
			canvas->clear();

			Assert::That(canvas->isAt(x,y,'1'), Equals(false));
		}

		Canvas *canvas = new Canvas(10,10,3);
	};

	// handle cells

	Describe(CNV01000_Provides_Cell_Coordinate) {
		void SetUp() {
			srand (time(NULL));
		}

		It(CNV01100_Allows_Cell_Setting) {
			CellCoordinate_Type x,y;
			unsigned width, height;

			// get size in cells
			canvas->getGeometry(width,height);

			x = rand() % width;
			y = rand() % height;

			//x = x + width;
			canvas->setCursorToCell(x,y);
			canvas->setAt(0,0, 'Q');
			Assert::That(canvas->isAtCell(x,y, 'Q') );
		}

		It(CNV01101_Does_Rollover_Clipping_for_positivecoordinate) {
			CellCoordinate_Type x,y;
			CellCoordinate_Type x0,y0;
			unsigned width, height;

			// get size in cells
			canvas->getGeometry(width,height);

			x0 = rand() % width;
			y0 = rand() % height;

			x = x0 + width;
			y = y0;
			canvas->setCursorToCell(x,y);
			canvas->setAt(0,0, 'Q');
			Assert::That(canvas->isAtCell(x0,y, 'Q') );
		}

		It(CNV01102_Does_Rollover_Clipping_for_negative_coordinate) {
			CellCoordinate_Type x,y;
			CellCoordinate_Type x0,y0;
			unsigned width, height;

			// get size in cells
			canvas->getGeometry(width,height);

			x0 = -1 * rand() % width;
			y0 = rand() % height;

			x = x0 + width;
			y = y0;
			canvas->setCursorToCell(x,y);
			canvas->setAt(0,0, 'Q');
			Assert::That(canvas->isAtCell(x0,y, 'Q') );
		}

		Canvas *canvas = new Canvas(10,10,3);
	};

	/*
	 * The smalest cell contains just to core of the cell which carries the
	 * player identifier.
	 */
	Describe(CNV02000_Smallest_cell) {
		void SetUp() {
			srand (time(NULL));

			canvas = new Canvas(10,10,0);
		}

		It(CNV02100_Returns_cell_size_of_0) {
			Assert::That( canvas->getCellSize(), Equals(0));
		}

		It(CNV02101_Check_gird_poistion_of_cell_0_0) {
			CellCoordinate_Type x,y;

			canvas->setCursorToCell(0,0);
			canvas->setAt(0,0, 'Q');
			Assert::That(canvas->isAt(1,1, 'Q') );
		}

		It(CNV02102_Mark_Border_Cells) {
			CellCoordinate_Type x,y;
			unsigned width, height;

			// get size in cells
			canvas->getGeometry(width,height);

			canvas->setCursorToCell(0,0);
			canvas->setAt(0,0, 'A');

			canvas->setCursorToCell(width-1, 0);
			canvas->setAt(0,0, 'B');

			canvas->setCursorToCell(0,height-1);
			canvas->setAt(0,0, 'C');

			canvas->setCursorToCell(width-1,height-1);
			canvas->setAt(0,0, 'D');

			canvas->show();

			Assert::That(canvas->isAt(1,1, 'A') );
		}


		Canvas *canvas ;
	};

	Describe(CNV03000_bigger_cell) {
		void SetUp() {
			srand (time(NULL));

			canvas = new Canvas(10,10,2);
		}

		It(CNV03100_Returns_cell_size_of_2) {
			Assert::That( canvas->getCellSize(), Equals(2));
		}

		It(CNV03101_Check_gird_poistion_of_cell_0_0) {
			CellCoordinate_Type x,y;

			canvas->setCursorToCell(0,0);
			canvas->setAt(0,0, 'Q');
			Assert::That(canvas->isAt(3,3, 'Q') );
		}

		Canvas *canvas ;
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
