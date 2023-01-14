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

#include "vkit.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

// [utility]

// clears screen under Win and Lin
void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// [general testing]

// prints fob status bits
void fobState(fstream & fob) 
{
	cout << endl;
	cout << "eof bit: " << fob.eof() << endl;
	cout << "fail bit: " << fob.fail() << endl;
	cout << "bad bit: " << fob.bad() << endl;
	cout << "good bit: " << fob.good() << endl;
	cout << endl;
	fob.clear();
}

// prints sstream status bits
void stringstreamState(stringstream & ss) 
{
	cout << endl;
	cout << "eof bit: " << ss.eof() << endl;
	cout << "fail bit: " << ss.fail() << endl;
	cout << "bad bit: " << ss.bad() << endl;
	cout << "good bit: " << ss.good() << endl;
	cout << endl;
	ss.clear();
}

// prints istream status bits
void istreamState(istream & is) 
{
	cout << endl;
	cout << "eof bit: " << is.eof() << endl;
	cout << "fail bit: " << is.fail() << endl;
	cout << "bad bit: " << is.bad() << endl;
	cout << "good bit: " << is.good() << endl;
	cout << endl;
	is.clear();
}

// [testing this program]

// print data members of Student.h class
void printStudent(Student & s)
{
	cout << endl
		<< "s.name: " << s.getName() << endl
		<< "s.addLevel: " << s.getAddLevel() << endl
		<< "s.subLevel: " << s.getSubLevel() << endl
		<< "s.mltLevel: " << s.getMltLevel() << endl
		<< "s.divLevel: " << s.getDivLevel() << endl
		<< "s.addSpeed: " << s.getAddSpeed() << endl
		<< "s.subSpeed: " << s.getSubSpeed() << endl
		<< "s.mltSpeed: " << s.getMltSpeed() << endl
		<< "s.divSpeed: " << s.getDivSpeed() << endl;
	cout << "   Press enter to continue.  ";
	getchar();

	//print template arrays
	printAddTemplateArr(s);
	printSubTemplateArr(s);
	printMltTemplateArr(s);
	printDivTemplateArr(s);
}

void printAddTemplateArr(Student & s)
{
	int numUsed = (s.getAddLevel() + 1) * (s.getAddLevel() + 1);
	for(int i=0;i<numUsed;i++)
	{
		cout << endl
			<< "s.getAddTemplateArr()[" << i << "].getFrequency(): " 
			<< s.getAddTemplateArr()[i].getFrequency() << endl
			<< "s.addTemplateArr[" << i << "].firstAddend: " 
			<< s.getAddTemplateArr()[i].getFirstAddend() << endl;
		cout << "s.addTemplateArr[" << i << "].secondAddend: " 
			<< s.getAddTemplateArr()[i].getSecondAddend() 
			<< endl;
		cout << "s.addTemplateArr[" << i << "].sum: " 
			<< s.getAddTemplateArr()[i].getSum() << endl;
		cout << "s.addTemplateArr[" << i << "].objCnt: " 
			<< s.getAddTemplateArr()[i].getObjCnt() << endl;
		cout << "s.addTemplateArr[" << i << "].addTemplateNdx: " 
			<< s.getAddTemplateArr()[i].getAddTemplateNdx() << endl;
	}
}

void printSubTemplateArr(Student & s)
{
	int numUsed = (((s.getSubLevel() + 1) * (s.getSubLevel() + 1)) / 2) + (s.getSubLevel() / 2) + 1;
	for(int i=0;i<numUsed;i++)
	{
		cout << endl
			<< "s.getSubTemplateArr()[" << i << "].getFrequency(): " 
			<< s.getSubTemplateArr()[i].getFrequency() << endl
			<< "s.subTemplateArr[" << i << "].minuend: " 
			<< s.getSubTemplateArr()[i].getMinuend() << endl;
		cout << "s.subTemplateArr[" << i << "].subtrahend: "
			<< s.getSubTemplateArr()[i].getSubtrahend() << endl;
		cout << "s.subTemplateArr[" << i << "].difference: "
			<< s.getSubTemplateArr()[i].getDifference() << endl;
		cout << "s.subTemplateArr[" << i << "].objCnt: " 
			<< s.getSubTemplateArr()[i].getObjCnt() << endl;
		cout << "s.subTemplateArr[" << i << "].ndxSub: " 
			<< s.getSubTemplateArr()[i].getSubTemplateNdx() << endl<< endl;

	}
}

void printMltTemplateArr(Student & s)
{
	int numUsed = (s.getMltLevel() + 1) * (s.getMltLevel() + 1); 
	for(int i=0;i<numUsed;i++)
	{
		cout << endl 
			<< "s.getMltTemplateArr()[" << i << "].getFrequency(): " 
			<< s.getMltTemplateArr()[i].getFrequency() << endl
			<< "s.mltTemplateArr[" << i << "].firstFactor: "
			<< s.getMltTemplateArr()[i].getFirstFactor() << endl
			<< "s.mltTemplateArr[" << i << "].secondFactor: " 
			<< s.getMltTemplateArr()[i].getSecondFactor() << endl
			<< "s.mltTemplateArr[" << i << "].product: "
			<< s.getMltTemplateArr()[i].getProduct() << endl
			<< "s.mltTemplateArr[" << i << "].objCnt: " 
			<< s.getMltTemplateArr()[i].getObjCnt()  << endl
			<< "s.mltTemplateArr[" << i << "].mltTemplateNdx: " 
			<< s.getMltTemplateArr()[i].getMltTemplateNdx() << endl;
	}
}

void printDivTemplateArr(Student & s)
{
	int numUsed = (s.getDivLevel() + 1) * s.getDivLevel(); 
	for(int i=0;i<numUsed;i++)
	{
		cout << endl 
			<< "s.getDivTemplateArr()[" << i << "].getFrequency(): " 
			<< s.getDivTemplateArr()[i].getFrequency() << endl
			<< "s.divTemplateArr[" << i << "].firstFactor: "
			<< s.getDivTemplateArr()[i].getFirstFactor() << endl
			<< "s.divTemplateArr[" << i << "].secondFactor: " 
			<< s.getDivTemplateArr()[i].getSecondFactor() << endl
			<< "s.divTemplateArr[" << i << "].product: "
			<< s.getDivTemplateArr()[i].getProduct() << endl
			<< "s.divTemplateArr[" << i << "].objCnt: " 
			<< s.getDivTemplateArr()[i].getObjCnt()  << endl
			<< "s.divTemplateArr[" << i << "].divTemplateNdx: " 
			<< s.getDivTemplateArr()[i].getDivTemplateNdx() << endl;
	}
}

void printAddBagArr(Student & s, AddTemplate * addBagArr)
{
	int numUsed = (s.getAddLevel() + 1) * (s.getAddLevel() + 1);
	int ndx = 0;
	for(int i=0;i<numUsed;i++)
	{
		cout << endl
			<< "new template" << endl;
		int freq = s.getAddTemplateArr()[i].getFrequency();
		for(int j = 0; j < freq; j++)
		{
			int firstAddend = s.getAddTemplateArr()[i].getFirstAddend();
			int secondAddend = s.getAddTemplateArr()[i].getSecondAddend();
			int sum = s.getAddTemplateArr()[i].getSum();
			cout <<	addBagArr[ndx + j].getFirstAddend() << " + "
				<< 	addBagArr[ndx + j].getSecondAddend() << " = " 
				<< 	addBagArr[ndx + j].getSum() << endl;
		}
		ndx += freq;
	}
}

