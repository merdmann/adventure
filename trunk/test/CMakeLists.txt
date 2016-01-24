##
## Copyright (C) 2014 Michael Erdmann <michael.erdmann@snafu.de>
##
## CMakeLists.txt is part of adventure.
##
## Adventure is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## Adventure is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with muon_reloaded. If not, see <http://www.gnu.org/licenses/>.
##
##  Created on: Nov 2, 2014
##      Author: MIchael
## 


add_executable(test-component component.cpp)
add_dependencies(test-component advcore)
target_link_libraries (test-component advcore advtest)

add_executable(test-location location.cpp)
add_dependencies(test-location advcore)
target_link_libraries (test-location advcore advtest)

add_executable(test-matrix thematrix.cpp)
add_dependencies(test-matrix advcore)
target_link_libraries (test-matrix advcore advtest)

add_executable(test-canvas canvas.cpp)
add_dependencies(test-canvas advcore)
target_link_libraries (test-canvas advcore advtest)

add_executable(test-doors doors.cpp)
add_dependencies(test-doors advcore)
target_link_libraries (test-doors advcore advtest)
 		  
add_test(NAME LOC01000_Location COMMAND test-location)
add_test(NAME MAT01000_TheMarix COMMAND test-matrix)
add_test(NAME CAN01000_Canvas COMMAND test-canvas)
add_test(NAME DOR01000_Canvas COMMAND test-doors)
    
add_library(testobjects OBJECT MyTestListener.cpp)
add_library(advtest STATIC $<TARGET_OBJECTS:testobjects>)
    
    