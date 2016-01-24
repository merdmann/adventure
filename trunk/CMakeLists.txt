##
## Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
##
## CMakeList.txt is part of adventure.
##
## adventure is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## adventure is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with muon_reloaded. If not, see <http://www.gnu.org/licenses/>.
##
##  Created on: Nov 2, 2014
##      Author: MIchael
##
cmake_minimum_required(VERSION 3.0)

project(adventure)

## ---------------------------------------------------------------------------

## the path the some external libraries/include files
find_package(Boost 1.57.0 )
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
else()
  message( FATAL_ERROR "Boost not found")
endif()

SET(igloo $ENV{IGLOO_ROOT})

## setup compiler environment
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -g -ggdb" )
include_directories(${PROJECT_SOURCE_DIR}/include ${boost} ${igloo} )

## setup the build environment
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

## -----------------------------------------------------------------------------

SET(interfaces IGameContext.cpp IPlayable.cpp IComponent.cpp CoreException.cpp  )

## contents of the core library
SET(source Helpers.cpp ${interfaces}
    TheMatrix.cpp
    Canvas.cpp
    Door.cpp
    Cell.cpp
    Location.cpp
    PlayerFactory.cpp
    PlayerInteractive.cpp
    PlayerInteractiveComponent.cpp
    PlayerWombat.cpp
    PlayerWombatComponent.cpp
    FlexArguments.cpp
    DirectionType.cpp )

add_library(advobjects OBJECT ${source})
add_library(advcore STATIC $<TARGET_OBJECTS:advobjects>)

## the binary of the game
add_executable(adv main.cpp)
target_link_libraries(adv advcore)

enable_testing()
add_subdirectory(test)

## ------------------------------------------------------------------------------

SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")

SET(CMAKE_BUILD_TYPE "debug")

set(CPACK_GENERATOR WIX)
set(CPACK_PACKAGE_NAME "mydll")
set(CPACK_PACKAGE_VENDOR "Michaelslab")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Adv - The text based adventure")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Adventure")

INCLUDE(CPack)
