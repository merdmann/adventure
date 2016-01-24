/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 *
 * MyTestListener.cpp is part of muon_reloaded.
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
#include	<iomanip>
#include	<fstream>
#include 	<string>
#include 	"MyTestListener.h"

using namespace std;

namespace igloo {

	void MyTestListener::Format_Test_Result(
			const std::string& section, const std::string& name, const std::string& verdict)
	{
		if( this->last != section ) {
			this->last = section;

	    	std:cout << section << endl;
	    }

	    std::cout << left << setw(8) << " " << left << setw(70) << name << verdict << endl;
	}

	void MyTestListener::TestRunStarting() {
		std::cout << "----+++ Testing start" << endl << endl;

		this->last = "";
	}

	void MyTestListener::TestRunEnded(const TestResults& result) {
		std::cout << endl << "----+++ Test Completed" << endl << endl;
	}

    void MyTestListener::SpecSucceeded(const ContextBase& ctx, const std::string& name) {
    	Format_Test_Result( ctx.Name(), name, "success");
    }

	void MyTestListener::SpecFailed(const ContextBase& ctx , const std::string& name) {
    	Format_Test_Result( ctx.Name(), name, "failed");
	}

} /* end of namespace */
