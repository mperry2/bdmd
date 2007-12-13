#ifndef VKIT_H
#define VKIT_H
#include <fstream>
#include "Student.h"
using namespace std;

// debugging

void fobState(fstream & fob); // prints fob flags
void printStudent(Student & s);
void printAddTemplateArr(Student & s);
void printSubTemplateArr(Student & s);
void printMltTemplateArr(Student & s);

// utility

void clearScreen(); // clears screen under Win or Lin

#endif
