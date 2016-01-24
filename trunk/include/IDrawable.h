/*
 * Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
 * 
 * Drawable.h is part of Adventure.
 *
 * Adventure is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Adventure is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Adventure. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: Nov 12, 2014
 *      Author: MIchael
 */

#ifndef INCLUDE_IDRAWABLE_H_
#define INCLUDE_IDRAWABLE_H_

#include <Canvas.h>

namespace adventure {

class Canvas;

class IDrawable {
public:
	virtual ~IDrawable() {};
	virtual void draw(Canvas*) = 0;

};

} /* namespace adventure */

#endif /* INCLUDE_DRAWABLE_H_ */
