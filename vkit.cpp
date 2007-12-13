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

void printStudent(Student & s)
{{{
	int level;
	// print data members of Student.h class
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
	//--------------------------------------------------
	// cout << endl
	// 	<< "addLevel: ";
	// cin >> level;
	// s.setAddLevel(level);		
	//-------------------------------------------------- 
	printAddTemplateArr(s);

	//--------------------------------------------------
	// cout << endl
	// 	<< "subLevel: ";
	// cin >> level;
	// s.setSubLevel(level);		
	//-------------------------------------------------- 
	printSubTemplateArr(s);
	
	//--------------------------------------------------
	// cout << endl
	// 	<< "mltLevel: ";
	// cin >> level;
	// s.setMltLevel(level);		
	//-------------------------------------------------- 
	printMltTemplateArr(s);
}}}

void printAddTemplateArr(Student & s)
{{{
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
}}}

void printSubTemplateArr(Student & s)
{{{
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
}}}

void printMltTemplateArr(Student & s)
{{{
	int numUsed = (s.getMltLevel() + 1) * (s.getMltLevel() + 1);
	for(int i=0;i<numUsed;i++)
	{
		cout << endl 
			<< "s.getMltTemplateArr()[" << i << "].getFrequency(): " 
			<< s.getMltTemplateArr()[i].getFrequency()
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

