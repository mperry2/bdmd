// Big Daddy's Math Drills
// Copyright (C) 1998, 2003, 2007 Vincent DiCarlo
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef VKIT_H
#define VKIT_H
#include <fstream>
#include "Student.h"
using namespace std;

// [utility]

void clearScreen(); // clears screen under Win or Lin

// [general testing]

void fobState(fstream & fob); // prints fob flags
void stringstreamState(stringstream & ss); // prints sstream status bits
void istreamState(istream & is); // prints istream status bits

// [testing this program]

void printStudent(Student & s);
void printAddTemplateArr(Student & s);
void printSubTemplateArr(Student & s);
void printMltTemplateArr(Student & s);
void printDivTemplateArr(Student & s);
void printAddBagArr(Student & s, AddTemplate * addBagArr);

#endif

