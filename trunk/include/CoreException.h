/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * CoreExcepion.h is part of Hallo.
 *
 * Hallo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Hallo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Hallo. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: Nov 7, 2014
 *      Author: MIchael
 */

#ifndef INCLUDE_COREEXCEPTION_H_
#define INCLUDE_COREEXCEPTION_H_

#include <boost/exception/all.hpp>


namespace core {

class CoreException:  public boost::exception, public std::exception
{
private:
	int errorCode_;

protected:

public:
	CoreException();
	CoreException(int);

	virtual ~CoreException() throw();
};


} /* namespace core */

#endif /* INCLUDE_COREEXCEPTION_H_ */
