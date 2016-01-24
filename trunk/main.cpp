/*
 * main.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: MIchael
 */

#include <iostream>

#include "TheMatrix.h"
#include "PlayerFactory.h"
#include "IGameContext.h"
#include "IComponent.h"
#include "PlayerInteractiveComponent.h"
#include "PlayerWombatComponent.h"

using namespace adventure;

int main( int argc, char **argv) {
	IComponent::registerComponent(
			PlayerInteractiveComponent::INTERACTIVE_PLAYER,
			(IComponent*) new PlayerInteractiveComponent()
	);

	IComponent::registerComponent(
			PlayerWombatComponent::WOMBAT_PLAYER,
			(IComponent*) new PlayerWombatComponent()
	);

	std::cout << "The Adventure Game Version 0.1" << std::endl;
	std::cout << "Copyright (C) 2014, 2015 Michael Erdmann" << std::endl;
	std::cout << std::endl;

	TheMatrix* matrix = new TheMatrix(10,10);


	matrix->addPlayer("Michael", PlayerInteractiveComponent::INTERACTIVE_PLAYER );
	matrix->addPlayer("Wombat1", PlayerWombatComponent::WOMBAT_PLAYER );
	matrix->addPlayer("Wombat2", PlayerWombatComponent::WOMBAT_PLAYER );


	while( matrix->playTurn() ) {
	}

	std::cout << "Exiting ...." << std::endl;

}



