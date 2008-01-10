// Big Daddy's Math Drills
// Version 2.0 released January 2008
//
// Big Daddy's Math Drills Copyright 1998, 2003, 2007 Vincent DiCarlo
//
// Files inluded in the sourcecode distribution:
// 		add.cpp - The the addition module.
//	 	bdmd.cpp - This file. Contains main().
//		copying.txt - The Gnu general public license.
// 		div.cpp - The division module.
// 		makefile - The gcc makefile.
// 		mlt.cpp - The multiplication module.
// 		Student.h - Specificiation and implementation
// 				of the Student class.
// 		Student.cpp - Implementation for Student class
// 		sub.cpp - The subtraction module.
// 		vkit.h - Header for vkit.cpp.
// 		vkit.cpp - Utilities.
//
// 	Binaries released:
//		bdmd - Linux executable.
//		bdmd.exe - MS Windows executable.
//
// Revision History:
// 		Version 1.0 released March 1998
// 		Version 1.2 released December 2003
//
// 	Version notes:
// 		This version has very little in the way
// 		of input validation and error checking
// 		and uses more memory and disk space
// 		than it would if it were modified so
// 		that it only created and saved templates
// 		needed for the current level of the user,
// 		but it is feature complete.  It was
// 		compiled with gcc and tested under Suse 
// 		Linux 10.3 and compiled with MS Visual
// 		Studio and tested under WinXP.
//
//	License:
//		This file, and all the other files in this
//		distribution as described above, including 
//		the binaries released, are part of Big 
//		Daddy's Math Drills.  Big Daddy's Math Drills 
//		is free software: you can redistribute it 
//		and/or modify it under the terms of the GNU 
//		General Public License as published by the 
//		Free Software Foundation, either version 3
//		of the License, or (at your option) any 
//		later version.
//
//		Big Daddy's Math Drills is distributed
//		in the hope that it will be useful,	but 
//		WITHOUT ANY WARRANTY; without even the 
//		implied warranty of MERCHANTABILITY or 
//		FITNESS FOR A PARTICULAR PURPOSE.  See 
//		the GNU General Public License for more 
//		details.
//
//		You should have received a copy of the GNU
//		General Public License along with Big 
//		Daddy's Math Drills.  If not, see 
//		<http://www.gnu.org/licenses/>.

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
void divModule(Student & s);
void displayReport(Student & s);
void displayHelp();
void printAddTemplateArr(Student & s);
void printSubTemplateArr(Student & s);
void printMltTemplateArr(Student & s);
void writeUserDat(fstream & userdatFob);

int main()
{{{
	fstream userdatFob;
	Student s;

	// make template arrays
	s.makeAddTemplateArr(s);
	s.makeSubTemplateArr(s);
	s.makeMltTemplateArr(s);
	s.makeDivTemplateArr(s);

	loginUser(s, userdatFob);
	displayMainMenu(s, userdatFob);	
	return 0;
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
	cout << "     Welcome to Big Daddy's Math Drills." << endl << endl
		<< "     Please sign in using a one-word username" << endl
		<< "     that is case sensitive, has no spaces," << endl
		<< "     and uses only letters or numbers.  ";
	getline(cin, userNameStrob);
	while(userNameStrob == "")
	{
		cout << endl
			<< "     You pressed Enter without typing a" << endl
			<< "     username." << endl << endl
			<< "     Please sign in using a one-word username" << endl
			<< "     that is case sensitive, has no spaces," << endl
			<< "     and uses only letters or numbers.  ";
		getline(cin, userNameStrob);
	}
	s.setName(userNameStrob);
	strcpy(userNameStr, userNameStrob.c_str());
	userFileNameStrob = userNameStrob + ".dat";
	strcpy(userFileNameStr, userFileNameStrob.c_str());
	userdatFob.open(userFileNameStr, ios::in);
	if (userdatFob.good())
	{
		userdatFob.close();
		s.readUserDat(userdatFob);
		userdatFob.clear();
		userdatFob.close();
		cout << endl
			<< "     A profile for " << userNameStr << endl
			<< "     has been found and loaded." << endl
			<< endl
			<< "     Press Enter to continue.  ";
		getchar();

	}
	else
	{
		cout << endl
			<< "     No profile for " << userNameStr << endl
			<< "     has been found." << endl
			<< endl
			<< "     A new one will be created based on"  << endl
			<< "     your preferences." << endl;
		cout << endl
			<< "     Press Enter to continue.  ";
		getchar();
		cout << endl
			<< "     In the addition drill, you practice" << endl
			<< "     problems in which you add two numbers" << endl 
			<< "     each of which is called an 'addend.'" << endl
			<< "     As you gain speed and accuracy, the" << endl
			<< "     maximum size of the addends you are" << endl
			<< "     given is automatically increased." << endl
			<< "     We recommend that you start with the" << endl
			<< "     default, which uses addends of 0-2," << endl
			<< "     and work your way up, but you may choose" << endl
			<< "     a maximum addend of from 0 to 100."  << endl
			<<  endl;
		cout << "     Do you want to start with the default" << endl
			<< "     maximum addend of 2 (y or n)?  ";
		getline(cin, inputStrObj);
		if(inputStrObj == "n")
		{
			cout << endl
				<< "     What is the maximum addend you want" << endl
				<< "     to use to begin with?  ";
			getline(cin, inputStrObj);
			ss.clear();
			ss << inputStrObj;
			ss >> levelChosen;
			s.setAddLevel(levelChosen);
			cout << endl
				<< "     You have chosen to start by with addends" << endl
				<< "     up to " << levelChosen << "." << endl
				<< endl
				<< "     Press Enter to continue.  ";
			getchar();
		}
		else
		{
			cout << endl
				<< "     Good choice.  You will start with the" << endl
				<< "     default maximum addend of 2." << endl
				<< endl
				<< "     Press Enter to continue.  ";
			getchar();
		}
		cout << endl
			<< "     In the subtraction drill, you practice" << endl
			<< "     problems in which you subtract a number" << endl
			<< "     called a 'subtrahend' from another" << endl
			<< "     number called a 'minuend.'  In this" << endl
			<< "     drill, the minuend will always be equal" << endl
			<< "     to or larger than the subtrahend."  << endl
			<< "     As you gain speed and accuracy, the" << endl
			<< "     maximimum size of the minuends you" << endl
			<< "     are given is automatically increased." << endl
			<< "     We recommend that you start with the" << endl
			<< "     default, which uses minuends of 0-4," << endl
			<< "     and work your way up, but you may choose" << endl
			<< "     a maximum minuend of from 0 to 200."  << endl		
			<<  endl;
		cout << "     Do you want to start with the default" << endl
			<< "     maximum minuend of 4 (y or n)?  ";
		getline(cin, inputStrObj);
		if(inputStrObj == "n")
		{
			cout << endl
				<< "     What is the maximum minuend you want" << endl
				<< "     to use to begin with?  ";
			getline(cin, inputStrObj);
			ss.clear();
			ss << inputStrObj;
			ss >> levelChosen;
			s.setSubLevel(levelChosen);
			cout << endl
				<< "     You have chosen to start subtracting" << endl
				<< "     from minuends of up to " << levelChosen << "." << endl
				<< endl
				<< "     Press Enter to continue.  ";
			getchar();
		}
		else
		{
			cout << endl
				<< "     Good choice.  You will start with the" << endl
				<< "     default maximum minuend of 4." << endl
				<< endl
				<< "     Press Enter to continue.  ";
			getchar();
		}
		cout << endl
			<< "     In the multiplication drill, you practice" << endl
			<< "     problems in which you multiply two" << endl
			<< "     numbers called 'factors.'  As you gain" << endl
			<< "     speed and accuracy, the maximimum size" << endl
			<< "     of the factors you are given is automatically" << endl
			<< "     increased.  We recommend that you start" << endl
			<< "     with the default, which uses factors" << endl
			<< "     of 0-2, and work your way up, but you" << endl
			<< "     may choose a maximum factor of from 0 to 200."  << endl		
			<<  endl;
		cout << "     Do you want to start with the default" << endl
			<< "     maximum factor of 2 (y or n)?  ";
		getline(cin, inputStrObj);
		if(inputStrObj == "n")
		{
			cout << endl
				<< "     What is the maximum factor you want" << endl
				<< "     to use to begin with?  ";
			getline(cin, inputStrObj);
			ss.clear();
			ss << inputStrObj;
			ss >> levelChosen;
			s.setMltLevel(levelChosen);
			cout << endl
				<< "     You have chosen to start by multiplying" << endl
				<< "     factors up to " << levelChosen << "." << endl
				<< endl
				<< "     Press Enter to continue.  ";
			getchar();
		}
		else
		{
			cout << endl
				<< "     Good choice.  You will start with the" << endl
				<< "     default maximum factor of 2." << endl
				<< endl
				<< "     Press Enter to continue.  ";
			getchar();
		}
		cout << endl
			<< "     In the division drill, you practice" << endl
			<< "     problems in which you divide a numerator" << endl
			<< "     by a denominator to get a quotient." << endl
			<< "     As you gain speed and accuracy, the" << endl
			<< "     maximimum size of the numbers you are" << endl
			<< "     given is automatically increased." << endl
			<< "     We recommend that you start with the" << endl
			<< "     default, which uses numerators from 0-2," << endl
			<< "     and denominators of 1-2, and work your" << endl
			<< "     way up, but you may choose a maximum" << endl
			<< "     for numerators and denominators of" << endl
			<< "     from 1 to 200."  << endl		
			<<  endl;
		cout << "     Do you want to start with the default" << endl
			<< "     maximum for numerators and denominators" << endl
			<< "     of 2 (y or n)?  ";
		getline(cin, inputStrObj);
		if(inputStrObj == "n")
		{
			cout << endl
				<< "     What is the maximum numerator or denominator" << endl
				<< "     you want to use to begin with?  ";
			getline(cin, inputStrObj);
			ss.clear();
			ss << inputStrObj;
			ss >> levelChosen;
			s.setDivLevel(levelChosen);
			cout << endl
				<< "     You have chosen to start by dividing" << endl
				<< "     with numerators and denominators" << endl
				<< "     up to " << levelChosen << "." << endl
				<< endl
				<< "     Press Enter to continue.  ";
			getchar();
		}
		else
		{
			cout << endl
				<< "     Good choice.  You will start with the" << endl
				<< "     default maximum for numerators and" << endl
				<< "     denominators of 2." << endl
				<< endl
				<< "     Press Enter to continue.  ";
			//debug
			cout << "divLevel: " << s.getDivLevel() << endl;
			getchar();
		}
	}
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
			clearScreen();
			addModule(s);
		}
		if(mainMenu == 2)
		{
			clearScreen();
			subModule(s);
		}
		if(mainMenu == 3)
		{
			clearScreen();
			mltModule(s);
		}
		if(mainMenu == 4)
		{
			clearScreen();
			divModule(s);
		}
		if(mainMenu == 5)
		{
			clearScreen();
			displayReport(s);
		}
		if (mainMenu == 6)
		{
			clearScreen();
			displayHelp();
		}
		if(mainMenu == 7)
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
	cout << "\t    BIG DADDY'S MATH DRILLS" << endl << endl;
	cout << "\t           MAIN MENU" << endl << endl << endl;
	cout 	<< "\t1 Do Addition Drill" << endl 
			<< "\t2 Do Subtraction Drill" << endl
			<< "\t3 Do Multiplication Drill" << endl
			<< "\t4 Do Division Drill" << endl
			<< "\t5 Progress Report" << endl
			<< "\t6 Help, Information, and Licensing" << endl
			<< "\t7 Quit" << endl
			<< endl 
			<< "\tPlease enter the number corresponding" << endl
			<< "\tto your choice or q to quit: ";
		getline(cin, inputStrObj);
		if(inputStrObj == "q")
		{
			userInput = 7;
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
	clearScreen();
	cout << endl << endl;
	cout << "\t      BIG DADDY'S MATH DRILLS" << endl << endl;
	cout << "\t          PROGRESS REPORT" << endl << endl << endl;
	cout	<< "\tReport for: " << s.getName() << endl << endl << endl	
			<< "\tAddition Drill" << endl << endl
			<< "\t   Current Level: addends up to " << s.getAddLevel() << "." << endl
			<< "\t   Current time to answer: " << s.getAddSpeed() << " seconds." << endl << endl << endl
			<< "\tSubtraction Drill" << endl << endl
			<< "\t   Current Level: minuends up to " << s.getSubLevel() << "." << endl
			<< "\t   Current time to answer: " << s.getSubSpeed() << " seconds." << endl << endl << endl
			<< "\tMultiplication Drill" << endl << endl
			<< "\t   Current Level: factors up to " << s.getMltLevel() << endl
			<< "\t   Current time to answer: " << s.getMltSpeed() << " seconds." << endl << endl << endl
			<< "\tDivision Drill" << endl << endl
			<< "\t   Current Level: numerators and denominators up to " << s.getDivLevel() << endl
			<< "\t   Current time to answer: " << s.getDivSpeed() << " seconds." << endl
			<< endl  << endl
			<< "\tPress Enter to return to main menu.  ";
	getchar();
}}}

void displayHelp()
{{{
	cout << endl << endl
	<< "             Introduction" << endl << endl

	<< "     Big Daddy's Math Drills is a simple," << endl
	<< "     effective, free, opensource program" << endl
	<< "     for drilling basic addition, subtraction," << endl
	<< "     multiplication, and division facts." << endl
	<< "     Compiled binary files are available" << endl
	<< "     for Windows XP and Linux compatible" << endl
	<< "     systems." << endl << endl

	<< "           Table of Contents" << endl << endl

	<< "     1. Installing and Uninstalling" << endl
	<< "     2. Operation" << endl
	<< "     3. Credits, Downloads, and Feedback" << endl
	<< "     4. License and Disclaimer of Warranty" << endl << endl

	<< "     Press Enter until you reach the page you want. " ;

	getchar();
	clearScreen();
	cout << endl << endl
		<< "          Installing and Uninstalling" << endl << endl

	<< "    For Linux and Windows users, just put the" << endl
	<< "    executable binary file in a folder by itself" << endl
	<< "    where the user has read, write, and execute" << endl
	<< "    permissions.  There are no hooks into the" << endl
	<< "    operating system, so no worries.  To uninstall" << endl
	<< "    both program and data, delete the folder." << endl << endl

	<< "    Press Enter to continue. " ;

	getchar();
	clearScreen();
	cout << endl << endl
	<< "                   Operation" << endl << endl

	<< "     Just start the program and follow the" << endl
	<< "     prompts.  The program works like flash" << endl
	<< "     cards, but it's more effective because:" << endl << endl

	<< "     1. The program starts out easy, with" << endl
	<< "        a limited set of small numbers first." << endl
	<< "        It progressively decreases the frequency" << endl
	<< "        of drill for problems that you answer" << endl
	<< "        correctly, and increases the frequency" << endl
	<< "        of drill for problems you answer wrong." << endl << endl

	<< "     2. As you gain in accuracy at a given" << endl
	<< "        level, the program reduces the amount" << endl
	<< "        of time allowed for each answer." << endl << endl

	<< "     3. When you have mastered the problems" << endl
	<< "        at a lower level, the program automatically" << endl
	<< "        moves you up to the next level," << endl
	<< "        where you again start out with more" << endl
	<< "        time to answer each question.  The" << endl
	<< "        problems from old levels still appear" << endl
	<< "        from time to time, but you get more" << endl
	<< "        intensive drill in the newer material." << endl << endl

	<< "     Press Enter to continue. " ;

	getchar();
	clearScreen();
	cout << endl << endl
		
	<< "     4. When you get tired of doing one" << endl
	<< "        kind of problem, you can work on" << endl
	<< "        another module." << endl << endl

	<< "     5. When you quit, the program saves" << endl
	<< "        your profile, so when you restart" << endl
	<< "        with the same username you pick" << endl
	<< "        up right where you left off.  If" << endl
	<< "        you want to start over, just change" << endl
	<< "        your username or delete your profile," << endl
	<< "        which is in the same folder as the" << endl
	<< "        executable, and is named with the" << endl
	<< "        username plus a '.dat' extension." << endl << endl

	<< "     6. We recommend that, when you start" << endl
	<< "        using the program, you set your" << endl
	<< "        NumLock on and use the number pad on" << endl
	<< "        your keyboard, if you have one.  Use" << endl
	<< "        correct touch fingering, and it will not" << endl
	<< "        only improve your speed doing the drills," << endl
	<< "        but when you're done you will be" << endl
	<< "        handy with adding machines and numerical" << endl
	<< "        data entry, too.  The right middle" << endl
	<< "        finger uses the 5 for a home key." << endl 
	<< "        Use your thumb for 0, and little" << endl
	<< "        finger for Enter."<< endl << endl


	<< "     Press Enter to continue. " ;
	getchar();
	clearScreen();
	cout << endl << endl
		
	<< "     Credits, Downloads, and Feedback" << endl << endl

	<< "     Previous versions of this software" << endl
	<< "     were written by Vincent DiCarlo to" << endl
	<< "     help his children learn their basic" << endl
	<< "     arithmetic and made available under" << endl
	<< "     license as freeware.  Version 2.0," << endl
	<< "     which added the adaptive learning" << endl
	<< "     features and the persistent user profiles," << endl
	<< "     was begun by DiCarlo, Vladimir Giyenko," << endl
	<< "     and David Phong as a class project" << endl
	<< "     for Professor Tim Wei at Sacramento" << endl
	<< "     Community College and completed by" << endl
	<< "     DiCarlo, who wrote all the code in" << endl
	<< "     the final release." << endl << endl

	<< "     You can post questions, requests," << endl
	<< "     bug reports, or comments about Big Daddy's" << endl
	<< "     Math Drills(TM) at the project's home at" << endl
	<< "     http://sourceforge.net/projects/bdmd," << endl
	<< "     where you can also volunteer to work on" << endl
	<< "     further development, download the complete" << endl
	<< "     sourcecode and other files necessary to" << endl
	<< "     modify it and to build the executables." << endl
	<< "     You can also download both the current" << endl
	<< "     as previous versions of the program at" << endl
	<< "     www.dicarlolaw.com/shareware.html." << endl << endl

	<< "     Press Enter to continue. " ;
	getchar();
	clearScreen();
	cout << endl << endl

	<< "        License and Disclaimer of Warranty" << endl << endl

	<< "     Big Daddy's Math Drills is free" << endl
	<< "     software: you can redistribute it" << endl
	<< "     and/or modify it under the terms of the GNU" << endl
	<< "     General Public License as published by the" << endl
	<< "     Free Software Foundation, either version 3" << endl
	<< "     of the License, or (at your option) any" << endl
	<< "     later version." << endl << endl

	<< "     Big Daddy's Math Drills is distributed" << endl

	<< "     in the hope that it will be useful, but" << endl
	<< "     WITHOUT ANY WARRANTY; without even the" << endl
	<< "     implied warranty of MERCHANTABILITY or" << endl
	<< "     FITNESS FOR A PARTICULAR PURPOSE.  See" << endl
	<< "     the GNU General Public License for more" << endl
	<< "     details." << endl << endl

	<< "     You should have received a copy of the GNU" << endl
	<< "     General Public License along with Big" << endl
	<< "     Daddy's Math Drills.  If not, see" << endl
	<< "     <http://www.gnu.org/licenses/>." << endl
	<< "     or support of any kind." << endl << endl
	<< "     Big Daddy's Math Drills" << endl
	<< "     Copyright 1998, 2003, 2007 Vincent DiCarlo." << endl << endl

		<< "     Press Enter to return to the main menu.  ";
	getchar();
	clearScreen();
}}}

