/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * FlexArguments.cpp is part of adv.
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

#include "FlexArguments.h"

namespace adventure {

FlexArguments::FlexArguments() {
	this->attribute_.clear();
}

FlexArguments::~FlexArguments() {
	// TODO Auto-generated destructor stub
}

// ----------------------------------------------------------------------------------------

void FlexArguments::clear() {
	this->attribute_.clear();
}

void FlexArguments::addValue(std::string name, void* value) {
	this->attribute_[name] = value;
}

void* FlexArguments::getValue(std::string name) {
	return this->attribute_[name];
}

} /* namespace adventure */
