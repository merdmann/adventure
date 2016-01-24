##
## Makefile - Experiment driver for Muon CI Experiment
##
## Written in 2016 by Michael Erdmann <Michael.erdmann@snafu.de>
##
## To the extent possible under law, the author(s) have dedicated all copyright and
## related and neighboring rights to this software to the public domain worldwide.
##
## This software is distributed without any warranty.
##
## You should have received a copy of the CC0 Public Domain Dedication along with
## this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
##

##
## This makefile initiates the creation of the build directory and the
## correspondig makefiles.
##
## Artefacts of the build are:
##   - A tar file with all binaries and configuration files which have to
##     be deployed om the test computer.
##   - A test program which is deployed by the target "deploy" to the
##     target/test system.
##
##
##
include ./make.local

root=$(shell pwd)

all test:  ./build
	$(MAKE)  -C./build $@

## this build always the frontend and test code
./build:
	mkdir -p ./build;  \
	cd  build; \
	export BOOST_ROOT=$(BOOST_ROOT);  \
	export IGLOO_ROOT=$(IGLOO_ROOT);  \
	cmake -G "Unix Makefiles" $(root)/trunk

clean:
	rm -rf ./build
