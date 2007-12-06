// CISP400 Ch15pc1
// Term Project Big Daddy's Math Drills
// Professor Tim Wei
// Team Charlie
//
// Files needed to build project:
//	 	bdmd.cpp - This file. Contains main().
// 		Student.h - Specificiation and implementation
// 				of the Student class.
// 		add.cpp - The entrypoint for the addition module.
// 		sub.cpp - The entrypoint for the subtraction module.
// 		mlt.cpp - The entrypoint for the multiplication module.
//
// Revision History:
//		Begun 20071117
// 		Finished, tested, and turned in ---
//
// 	Version notes:
// 		This version should compile and run without
// 		modification.  As written, it will demonstrate the 
// 		Student.h class and its member classes.  Make sure 
// 		to read the comments and bdmd.txt.  Then, if you 
// 		have any questions, please call, write, or 
// 		talk to me tonight at class.

#include "Student.h"
using namespace std;

void printAddTemplateArr(Student & s);
void printSubTemplateArr(Student & s);
void printMltTemplateArr(Student & s);

int main()
{
	// test data members of Student.h class
	Student s;
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
	while(1)
	{
		int level;
		// test member functions for addition in Student.h
		s.makeAddTemplateArr(s);
		cout << endl
			<< "addLevel: ";
		cin >> level;
		s.setAddLevel(level);		
		printAddTemplateArr(s);

		// test member functions for subtraction in Student.h
		s.makeSubTemplateArr(s);
		cout << endl
			<< "subLevel: ";
		cin >> level;
		s.setSubLevel(level);		
		printSubTemplateArr(s);
		
		// test member functions for multiplication in Student.h
		s.makeMltTemplateArr(s);
		cout << endl
			<< "mltLevel: ";
		cin >> level;
		s.setMltLevel(level);		
		printMltTemplateArr(s);

		// This is what the prototypes (for your files) of and calls to (from here) your addition,
		// subtraction, multiplication, and division modules should look like.
		// 
		// Function prototype and call to addition module:
		// void addModule(Student & s);
		// addModule(s);
		// 
		// Function prototype and call to subtraction module:
		// void subModule(Student & s);
		// subModule(s);
		//
		// Function prototype and call to multiplication module:
		// void mltModule(Student & s);
		// mltModule(s);
		//
		// Function prototype and call to division module:
		// void divModule(Student & s);
		// divModule(s);
		//
		// The source code for each module should implement the corresponding function,
		// which uses the classes defined and implemented in Student.h.
		// Your module should use the data and members of the Student object 
		// that is passed to it to do its work, and use the mutator functions 
		// in it and its members to changes such things 
		// as the maximum size of the problems the student is doing, the amount of time 
		// allowed for each problem, and so on.  Please read the specifications 
		// for the program in bdmd.txt carefully so we will all be following the 
		// same design.
		//
		// In particular, note that the Student object that is passed to your module 
		// has arrays of problem templates called addTemplateArr, subTemplateArr, 
		// mltTemplateArr, and divTemplateArr.  These arrays contain AddTemplate, 
		// SubTemplate, MltTemplate, and DivTemplate objects which represent one example of
		// each possible problem at a given level.  The problem templates are arranged 
		// in the array in order such that to get all the problems in which the addends 
		// (or factors, or the minuend, or the numerator, depending on the type of problem)
		// are from 0 to a given level, you can take the first numUsed items in the 
		// array.  numUsed for each level (defined in terms of 
		// maximum addend, factor, minuend, or numerator,
		// depending on the type of problem) can be calculated in accordance with 
		// the functions below (such as printAddTemplateArr(Student & s)) that 
		// print the set of problem templates for any given level.  You can see 
		// how this works by compiling, linking, and running this file
		// without changes.  You can input levels for addition, subtraction, and 
		// multiplication problems, and see how the right templates are retreived 
		// from the problem template arrays.
		//
		// The problem template arrays should be used by your module each time
		// you generate a problem set for the student.  Note that each problem
		// template in the array (each of which is an instantiation 
		// of AddTemplate, SubTemplate, MltTemplate, or DivTemplate, depending 
		// on the array) has a frequency data member.  First, you can 
		// use the problem array to generate a bag of problems that contains
		// the right number of copies of each of the eligible problems for that level.
		// The right number of copies depends on the frequency attribute of the 
		// problem template.
		//
		// For example, for an addition problem, the right number of copies of the 
		// first problem template in the array is
		// is s.addTemplateArr[0].frequency.  Because these attributes are 
		// protected, you have to use the get methods of the AddTemplate 
		// class: s.getAddTemplateArr()[0].getFrequency().
		// Then, you randomly draw 50 questions from the bag, which are used
		// as the problem set.  When a problem is answered correctly or incorrectly,
		// you use the get and set functions of the appropriate problem template class to 
		// adjust its frequency down or up by an appropriate amount. At the
		// end of the set, you can use the get and set functions in the 
		// Student class to adjust the time allowed, the level, or both.
		// Each time you do a new set, you should generate a new bag with
		// the adjusted frequencies from which to draw the problem set.
		//
		// The addModule(s), subModule(s), and mltModule(s) calls above 
		// should be fully functional once you have written your module
		// to specifications.  You should be able to uncomment the appropriate
		// one and add some cout statements to this file see how your module
		// is working.  I should have the code neede to make divModule(s) 
		// functional soon.
		// 

	}
	return 0;
}

void printAddTemplateArr(Student & s)
{
	cout << endl
		<< "addTemplateArr.objCnt: " << s.getAddTemplateArr()[0].getObjCnt() << endl;
	int numUsed = (s.getAddLevel() + 1) * (s.getAddLevel() + 1);
	for(int i=0;i<numUsed;i++)
	{
		cout << "s.addTemplateArr[" << i << "].firstAddend: " << s.getAddTemplateArr()[i].getFirstAddend() << endl;
		cout << "s.addTemplateArr[" << i << "].secondAddend: " << s.getAddTemplateArr()[i].getSecondAddend() << endl
			<< endl;
		//cout << "s.addTemplateArr[" << i << "].sum: " << s.getAddTemplateArr()[i].getSum() << endl;
	}
}

void printSubTemplateArr(Student & s)
{
	cout << endl
		<< "subTemplateArr.objCnt: " << s.getSubTemplateArr()[0].getObjCnt() << endl;
	int numUsed = (((s.getSubLevel() + 1) * (s.getSubLevel() + 1)) / 2) + (s.getSubLevel() / 2) + 1;
	for(int i=0;i<numUsed;i++)
	{
		cout << "s.subTemplateArr[" << i << "].minuend: " << s.getSubTemplateArr()[i].getMinuend() << endl;
		cout << "s.subTemplateArr[" << i << "].subtrahend: " << s.getSubTemplateArr()[i].getSubtrahend() << endl
			<< endl;
		//cout << "s.subTemplateArr[" << i << "].difference: " << s.getSubTemplateArr()[i].getDifference() << endl;
	}
}

void printMltTemplateArr(Student & s)
{
	cout << endl
		<< "mltTemplateArr.objCnt: " << s.getMltTemplateArr()[0].getObjCnt() << endl;
	int numUsed = (s.getMltLevel() + 1) * (s.getMltLevel() + 1);
	for(int i=0;i<numUsed;i++)
	{
		cout << "s.mltTemplateArr[" << i << "].firstFactor: " << s.getMltTemplateArr()[i].getFirstFactor() << endl
			<< "s.mltTemplateArr[" << i << "].secondFactor: " << s.getMltTemplateArr()[i].getSecondFactor() << endl
			//<< "s.mltTemplateArr[" << i << "].product: " << s.getMltTemplateArr()[i].getProduct() 
			<< endl;
	}
}

