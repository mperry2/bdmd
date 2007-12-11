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
// 		to read the comments, bdmd.txt, and the team notes
// 		in the body of the teamNotes() dummy function below.  
// 		Then, if you still
// 		have any questions, please call, or write.


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include "Student.h"
#include "vkit.h"

using namespace std;

void loginUser(Student & s, fstream & userdatFob);
void displayMainMenu(Student & s, fstream & userdatFob);
unsigned short getChoice();
void addModule(Student & s);
void subModule(Student & s);
void mltModule(Student & s);
void displayReport(Student & s);
void displayHelp();
void printAddTemplateArr(Student & s);
void printSubTemplateArr(Student & s);
void printMltTemplateArr(Student & s);
void printStudent(Student & s);
void writeUserDat(fstream & userdatFob);

int main()
{{{
	fstream userdatFob;
	Student s;

	//make template arrays
	s.makeAddTemplateArr(s);
	s.makeSubTemplateArr(s);
	s.makeMltTemplateArr(s);	

	loginUser(s, userdatFob);

	displayMainMenu(s, userdatFob);	

	return 0;
}}}

//Notes for team
void teamNotes()
{{{
	// Notes to Team:
	//
	// This is what the prototypes (for your files) of and calls to (from here) your addition,
	// subtraction, multiplication, and division modules should look like.
	// 
	// Function prototype and call to addition module:
	// void addModule(Student & s);
	// addModule(s);

	// Function prototype and call to subtraction module:
	// void subModule(Student & s);
	// subModule(s);

	// Function prototype and call to multiplication module:
	// void mltModule(Student & s);
	// mltModule(s);

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
	// same designm.
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
	// While you are working on your modules, I will work the user interface
	// for the main module and on saving and retreiving the Student objects. 
	// I will need your modules, completed to specifications, together with 
	// your documentation as specified in the proposal, by Monday at noon, 
	// in order to integrate, test, confer with you about any problems, and 
	// be ready to demonstrate and turn in the project by Thursday.
	//
	// Whew!
}}}

void loginUser(Student & s, fstream & userdatFob)
{{{
	string userNameStrob;
	string userFileNameStrob;
	char userNameStr[MAX_NAME+1];
	char userFileNameStr[MAX_NAME+5];
	char wantsDefaultLevel = 'y';
	string inputStrObj;
	stringstream ss;
	int levelChosen;

	clearScreen();
	cout << "   Welcome to Big Daddy's Math Drills." << endl << endl
		<< "   Please sign in using a one-word username" << endl
		<< "   that is case sensitive, has no spaces, and" << endl
		<< "   uses only letters or numbers.  ";
	getline(cin, userNameStrob);
	s.setName(userNameStrob);
	strcpy(userNameStr, userNameStrob.c_str());
	userFileNameStrob = userNameStrob + ".dat";
	strcpy(userFileNameStr, userFileNameStrob.c_str());
	userdatFob.open(userFileNameStr, ios::in);
	if (userdatFob)
	{
		userdatFob.close();
		s.readUserDat(userdatFob);
		cout << "   Profile for " << userNameStr << " has been found"  << endl
			<< "   and loaded." << endl;
		userdatFob.clear();
		userdatFob.close();
	}
	else
	{
		cout << endl
			<< "   No profile for " << userNameStr << " has been found." << endl
			<< endl
			<< "   A new one will be created based on your preferences." << endl;
		cout << endl
			<< "   Press enter to continue.  ";
		getchar();
		cout << endl
			<< "   In the addition drill, you practice" << endl
			<< "   problems in which you add two numbers" << endl 
			<< "   each of which is called an 'addend.'" << endl
			<< "   As you gain speed and accuracy, the maximum" << endl
			<< "   size of the addends you are given is automatically" << endl
			<< "   increased.  We recommend that you start with the default," << endl
			<< "   which uses addends of 0-2, and work your way up, but you" << endl
			<< "   may choose a maximum addend of from 0 to 100."  << endl
			<<  endl;
		cout << "   Do you want to start with the default maxumum" << endl
			<< "   addend of 2 (y or n)?  ";
		getline(cin, inputStrObj);
		if(inputStrObj == "n")
		{
			cout << endl
				<< "   What is the maximum addend you want to use" << endl
				<< "   to begin with?  ";
			getline(cin, inputStrObj);
			ss.clear();
			ss << inputStrObj;
			ss >> levelChosen;
			s.setAddLevel(levelChosen);
			cout << endl
				<< "   You have chosen to start by with" << endl
				<< "   addends up to " << levelChosen << "." << endl
				<< endl
				<< "   Press enter to continue.  ";
			getchar();
		}
		else
		{
			cout << endl
				<< "   Good choice.  You will start with the default" << endl
				<< "   maximum addend of 2." << endl
				<< endl
				<< "   Press enter to continue.  ";
			getchar();
		}
		cout << endl
			<< "   In the subtraction drill, you practice" << endl
			<< "   problems in which you subtract a number" << endl
			<< "   called a 'subrahend' from another number" << endl
			<< "   called a 'minuend.'  In this drill, the" << endl
			<< "   minuend will always be equal to or larger" << endl
			<< "   than the subtrahend.  As you gain speed" << endl
			<< "   accuracy, the maximimum size of the" << endl
			<< "   minuends you are given is automatically" << endl
			<< "   increased.  We recommend that you start" << endl
			<< "   with the default which uses minuends of" << endl
			<< "   0-4, and work your way up, but you" << endl
			<< "   may choose a maximum minuend of from 0 to 200."  << endl		
			<<  endl;
		cout << "   Do you want to start with the default maxumum" << endl
			<< "   minuend of 4 (y or n)?  ";
		getline(cin, inputStrObj);
		if(inputStrObj == "n")
		{
			cout << endl
				<< "   What is the maximum addend you want to use" << endl
				<< "   to begin with?  ";
			getline(cin, inputStrObj);
			ss.clear();
			ss << inputStrObj;
			ss >> levelChosen;
			s.setSubLevel(levelChosen);
			cout << endl
				<< "   You have chosen to start by with" << endl
				<< "   minuends up to " << levelChosen << "." << endl
				<< endl
				<< "   Press enter to continue.  ";
			getchar();
		}
		else
		{
			cout << endl
				<< "   Good choice.  You will start with the default" << endl
				<< "   maximum minuend of 4." << endl
				<< endl
				<< "   Press enter to continue.  ";
			getchar();
		}
		cout << endl
			<< "   In the multiplication drill, you practice" << endl
			<< "   problems in which you multiply two numbers" << endl
			<< "   'factors.  As you gain speed" << endl
			<< "   accuracy, the maximimum size of the" << endl
			<< "   factors you are given is automatically" << endl
			<< "   increased.  We recommend that you start" << endl
			<< "   with the default, which uses factors of" << endl
			<< "   0-2, and work your way up, but you" << endl
			<< "   may choose a maximum factor of from 0 to 200."  << endl		
			<<  endl;
		cout << "   Do you want to start with the default maxumum" << endl
			<< "   factor of 2 (y or n)?  ";
		getline(cin, inputStrObj);
		if(inputStrObj == "n")
		{
			cout << endl
				<< "   What is the maximum factor you want to use" << endl
				<< "   to begin with?  ";
			getline(cin, inputStrObj);
			ss.clear();
			ss << inputStrObj;
			ss >> levelChosen;
			s.setMltLevel(levelChosen);
			cout << endl
				<< "   You have chosen to start by with" << endl
				<< "   minuends up to " << levelChosen << "." << endl
				<< endl
				<< "   Press enter to continue.  ";
			getchar();
		}
		else
		{
			cout << endl
				<< "   Good choice.  You will start with the default" << endl
				<< "   maximum factor of 2." << endl
				<< endl
				<< "   Press enter to continue.  ";
			getchar();
		}
	}
	printStudent(s);
}}}

void displayMainMenu(Student & s, fstream & userdatFob)
{{{
	unsigned short keepGoing = 1;
	unsigned short mainMenu = 1;
	clearScreen();
	while(keepGoing == 1)
	{
		mainMenu = getChoice();
		if(mainMenu == 1)
		{
			addModule(s);
		}
		if(mainMenu == 2)
		{
			subModule(s);
		}
		if(mainMenu == 3)
		{
			subModule(s);
		}
		if(mainMenu == 4)
		{
			displayReport(s);
		}
		if (mainMenu == 5)
		{
			displayHelp();
		}
		if(mainMenu == 6)
		{
			s.writeUserDat(userdatFob);
			keepGoing = 0;
			clearScreen();
		}
	}
}}}

unsigned short getChoice()
{{{
	unsigned short userInput = 10;
	string inputStrObj = "q";
	stringstream ss;

	clearScreen();
	cout << endl << endl << endl;
	cout << "\t                BIG DADDY'S MATH DRILLS" << endl << endl;
	cout << "\t                        MAIN MENU" << endl << endl;
	cout 	<< "\t1 Do Addition Drill" << endl 
			<< "\t2 Do Subtraction Drill" << endl
			<< "\t3 Do Multiplication Drill" << endl
			<< "\t4 Progress Report" << endl
			<< "\t5 Help" << endl
			<< "\t6 Quit" << endl
			<< endl 
			<< "\tPlease enter the number corresponding to your choice or q to quit: ";
		getline(cin, inputStrObj);
		if(inputStrObj == "q")
		{
			userInput = 6;
		}
		else
		{
			stringstream ss;
			ss << inputStrObj;
			ss >> userInput;
		}
	return userInput;
}}}

void displayReport(Student & s)
{{{
	cout << endl
		<< "Progress report will go here." << endl
		<< endl
		<< "Press enter to return to the main menu.  ";
	getchar();
	cout << endl;
}}}

void displayHelp()
{{{
	cout << endl
		<< "Help text will go here." << endl
		<< endl
		<< "Press enter to return to the main menu.  ";
	getchar();
	cout << endl;
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
		<< "s.divSpeed: " << s.getDivSpeed() << endl
		<< "s.getAddTemplateArr()[0].getFrequency(): " << s.getAddTemplateArr()[0].getFrequency() << endl
		<< "s.getMltTemplateArr()[440].getFrequency(): " << s.getMltTemplateArr()[440].getFrequency();
	cout << "   Press enter to continue.  ";
	getchar();

	//--------------------------------------------------
	// //print template arrays
	// cout << endl
	// 	<< "addLevel: ";
	// cin >> level;
	// s.setAddLevel(level);		
	// printAddTemplateArr(s);
	//-------------------------------------------------- 

	//--------------------------------------------------
	// cout << endl
	// 	<< "subLevel: ";
	// cin >> level;
	// s.setSubLevel(level);		
	// printSubTemplateArr(s);
	// 
	// cout << endl
	// 	<< "mltLevel: ";
	// cin >> level;
	// s.setMltLevel(level);		
	// printMltTemplateArr(s);
	//-------------------------------------------------- 
}}}

void printAddTemplateArr(Student & s)
{{{
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
}}}

void printSubTemplateArr(Student & s)
{{{
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
}}}

void printMltTemplateArr(Student & s)
{{{
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
}}}

