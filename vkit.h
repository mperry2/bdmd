#ifndef VKIT_H
#define VKIT_H
#include <fstream>
#include "Student.h"
using namespace std;

// debugging

void fobState(fstream & fob); // prints fob flags
void stringstreamState(stringstream & ss); // prints sstream status bits
void istreamState(istream & is); // prints istream status bits
void printStudent(Student & s);
void printAddTemplateArr(Student & s);
void printSubTemplateArr(Student & s);
void printMltTemplateArr(Student & s);
void printDivTemplateArr(Student & s);
void printAddBagArr(Student & s, AddTemplate * addBagArr);

// utility

void clearScreen(); // clears screen under Win or Lin

#endif
