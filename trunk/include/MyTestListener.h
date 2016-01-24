/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 *
 * MyTestListener.h is part of muon_reloaded.
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
#include <string>
#include <iostream>

#include <igloo/igloo.h>

#ifndef SRC_TEST_MYTESTLISTENER_H_
#define SRC_TEST_MYTESTLISTENER_H_

namespace igloo {

class MyTestListener : public TestListener
{
	protected:
		std::string last;

		void Format_Test_Result(
			const std::string& section,
			const std::string& name,
			const std::string& verdict);

	public:
		virtual void TestRunStarting();
		virtual void TestRunEnded(const TestResults&);

		virtual void ContextRunStarting(const ContextBase& ) {}
		virtual void ContextRunEnded(const ContextBase& ) {}
		virtual void SpecRunStarting(const ContextBase& , const std::string& ) {}
		virtual void SpecSucceeded(const ContextBase& , const std::string& );
		virtual void SpecFailed(const ContextBase& , const std::string& );
};

}

#endif /* SRC_TEST_MYTESTLISTENER_H_ */
