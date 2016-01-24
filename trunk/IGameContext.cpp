#include <string>
#include <boost/array.hpp>

#include <vector>

#include "IGameContext.h"
#include "IPLayable.h"
#include "CellCoordinateType.h"

namespace adventure {

IGameContext::IGameContext(unsigned width, unsigned height)  {
	boost::array<unsigned, 2> extents;

	extents[1] = width;
	extents[0] = height;
	this->cell_.resize(extents);

	for(unsigned y=0; y<height; ++y ) {
		for(unsigned x=0; x<width; ++x) {
			this->cell_[y][x] = new Cell();
		}
	}

	this->height_ = height;
	this->width_ = width;

	this->factory_ = new PlayerFactory();
}

IGameContext::~IGameContext() {
	delete this->factory_;
}

// -------------------------------------------------------------------------------
PlayerFactory* IGameContext::getPlayerFactory() {
	return this->factory_;
}

// -----------------------------------------------------------------------
unsigned IGameContext::getWidth() { return this->width_; }
unsigned IGameContext::getHeight() {  return this->height_; }

// --------------------------------------------------------------------------------

Cell* IGameContext::getCellAt(CellCoordinate_Type x, CellCoordinate_Type y) {
	return this->cell_[y % this->height_][x % this->width_];
}

void IGameContext::setCellAt(CellCoordinate_Type x, CellCoordinate_Type y, Cell* cell) {
	this->cell_[y % this->height_][x % this->width_] = cell;
}


// --------------------------------------------------------------------------------
bool IGameContext::playTurn() {
	const std::vector<std::string> players = this->factory_->getAllPlayers();
	bool result = true;

	for(std::vector<std::string>::size_type i=0; i != players.size(); ++i ) {
		IPlayable* p = this->factory_->getPlayerByName( players[i] );

		result &= p->Play((IGameContext*)this);

	}
	return result;
}

} // end namespace Adventure
