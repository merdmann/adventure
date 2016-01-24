/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * FlexArguments.h is part of adv.
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
 *  Created on: Jan 17, 2015
 *      Author: MIchael
 */

#ifndef FLEXARGUMENTS_H_
#define FLEXARGUMENTS_H_

#include <string>
#include <map>
namespace adventure {

class FlexArguments {

private:
	std::map<std::string, void*> attribute_;

public:
	FlexArguments();
	virtual ~FlexArguments();

	void clear();
	void addValue(std::string, void*);
	void *getValue(std::string);
};

} /* namespace adventure */

#endif /* FLEXARGUMENTS_H_ */
