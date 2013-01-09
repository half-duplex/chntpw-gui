# Makefile
# This file is part of chntpw-gui, a graphical frontend to chntpw.
# Copyright (C) 2013 Trevor Bergeron
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#


CC = g++
CCFLAGS = -Wall -g -std=c++0x `pkg-config --cflags --libs gtkmm-3.0 blkid mount` # -static-libgcc -static-libstdc++ -static

all: main
clean:
	rm -rf *.core bin/
commonstuff:
	mkdir -p bin/object/

main: main.o Makefile commonstuff
	${CC} ${CCFLAGS} ${GTK} -o bin/chntpw-gui bin/object/main.o

main.o: Makefile commonstuff
	${CC} ${CCFLAGS} ${GTK} -o bin/object/main.o -c src/main.cpp

# vim: noexpandtab:

