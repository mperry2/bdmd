#include "vkit.h"
#include <fstream>
#include <iostream>

using namespace std;

// [debugging]

// prints fob status bits
void fobState(fstream & fob) 
{{{
	cout << endl;
	cout << "eof bit: " << fob.eof() << endl;
	cout << "fail bit: " << fob.fail() << endl;
	cout << "bad bit: " << fob.bad() << endl;
	cout << "good bit: " << fob.good() << endl;
	cout << endl;
	fob.clear();
}}}

// [utility]

// clears screen under Win and Lin
void clearScreen()
{{{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}}}

