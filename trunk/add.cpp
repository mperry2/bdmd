// Big Daddy's Math Drills
// Version 2.0 released January 2008
//
// Big Daddy's Math Drills Copyright 1998, 2003, 2007 Vincent DiCarlo
//
// Files inluded in the sourcecode distribution:
// 		add.cpp - The the addition module.
//	 	bdmd.cpp - Contains main().
//		copying.txt - The Gnu general public license.
// 		div.cpp - The division module.
// 		makefile - The gcc makefile.
// 		mlt.cpp - The multiplication module.
// 		readme - Instructions, notes, legal.
// 		Student.cpp - Implementation for Student class
// 		Student.h - Specificiation and implementation
// 				of the Student class.
// 		sub.cpp - The subtraction module.
// 		vkit.cpp - Utilities.
// 		vkit.h - Header for vkit.cpp.
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
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Student.h"
#include "vkit.h"
using namespace std;

void addModule(Student & s)
{
	AddTemplate * addBagArr;
	int templatesUsed;
	int numProblems;
	int level;
	int ndxSelectedProblem;
	int freq;
	int firstAddend;
	int secondAddend;
	int sum;
	int frequency;
	string userInputStrob;
	string junkString;
	stringstream ss;
	int userAnswer;
	int oldFreq;
	int newFreq;
	int addTemplateNdx;
	int currAddTemplateNdx;
	time_t startTime;
	time_t endTime;
	time_t timeElapsed;
	int numSeconds;
	int cumRight;
	int cumWrong;
	int cumProblems;
	int percentRight;
	const int SET_SIZE = 20;
	string wantsAnotherSet = "y";
	int tooLong;
	int delayTimer;

	while(wantsAnotherSet == "y" || wantsAnotherSet == "Y")
	{
		srand(time(0));
		level = s.getAddLevel();
		numSeconds = s.getAddSpeed();
		cumRight = 0;
		cumWrong = 0;
		cumProblems = 0;
		templatesUsed = (s.getAddLevel() + 1) * (s.getAddLevel() + 1); // num templates at user's level

		addBagArr = new AddTemplate[1]; // for the first delete
		for(int i = 0; i < SET_SIZE; i++) // make a bag of addition problems
		{
			numProblems = 0;
			tooLong = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				numProblems += s.getAddTemplateArr()[i].getFrequency(); // num problems to put in bag
			}
			delete [] addBagArr;
			addBagArr = new AddTemplate[numProblems];
			int ndx = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				freq = s.getAddTemplateArr()[i].getFrequency();
				for(int j = 0; j <  freq; j++) // put freq copies of each template in bag
				{
					firstAddend = s.getAddTemplateArr()[i].getFirstAddend();
					secondAddend = s.getAddTemplateArr()[i].getSecondAddend();
					sum = s.getAddTemplateArr()[i].getSum();
					frequency = s.getAddTemplateArr()[i].getFrequency();
					addTemplateNdx = s.getAddTemplateArr()[i].getAddTemplateNdx();
					addBagArr[ndx + j].setFirstAddend(firstAddend);
					addBagArr[ndx + j].setSecondAddend(secondAddend);
					addBagArr[ndx + j].setSum(sum);
					addBagArr[ndx + j].setFrequency(frequency);
					addBagArr[ndx + j].setAddTemplateNdx(addTemplateNdx);
				}
				ndx += freq;
			}
			ndxSelectedProblem = rand() % numProblems;
			startTime = time(NULL);
			cout << endl
				<< "     " << addBagArr[ndxSelectedProblem].getFirstAddend() << "  +  "
				<< addBagArr[ndxSelectedProblem].getSecondAddend() << "  =  ";
			getline(cin, userInputStrob);
			endTime = time(NULL);
			timeElapsed = (endTime - startTime);
			if(timeElapsed > s.getAddSpeed())
			{
				tooLong = 1;
			}
			ss.clear(); // prepare ss for input
			ss >> junkString;
			junkString = "";
			ss.clear();
			ss << userInputStrob;
			ss >> userAnswer;
			cumProblems++;
			if(userAnswer == addBagArr[ndxSelectedProblem].getSum())
			{
				cout << endl
					<< "     Correct!" << endl;
				if(tooLong)
				{ 
					cumWrong++;
					oldFreq = addBagArr[ndxSelectedProblem].getFrequency();
					currAddTemplateNdx = addBagArr[ndxSelectedProblem].getAddTemplateNdx();
					newFreq = 20;
					s.getAddTemplateArr()[currAddTemplateNdx].setFrequency(newFreq);
					cout << endl
					<< "     But you did not answer within " << s.getAddSpeed() << " seconds." << endl;
					delayTimer = 0;
					startTime = time(NULL);
					while (delayTimer < 2)
					{
						endTime = time(NULL);
						delayTimer = (endTime - startTime);
					}
				}
				else
				{
					cumRight++;
					oldFreq = addBagArr[ndxSelectedProblem].getFrequency();
					if(oldFreq > 1)
					{
						currAddTemplateNdx = addBagArr[ndxSelectedProblem].getAddTemplateNdx();
						newFreq = oldFreq / 2;
						s.getAddTemplateArr()[currAddTemplateNdx].setFrequency(newFreq);
					}
				}
			} else
			{
				cumWrong++;
				cout << endl
					<< "     Sorry, the correct answer is " << addBagArr[ndxSelectedProblem].getSum()
					<< "."
					<< endl;
				delayTimer = 0;
				startTime = time(NULL);
				while (delayTimer < 4)
				{
					endTime = time(NULL);
					delayTimer = (endTime - startTime);
				}
				oldFreq = addBagArr[ndxSelectedProblem].getFrequency();
				currAddTemplateNdx = addBagArr[ndxSelectedProblem].getAddTemplateNdx();
				newFreq = 20;
				s.getAddTemplateArr()[currAddTemplateNdx].setFrequency(newFreq);
			}
		}
		percentRight = (cumRight * 100) / SET_SIZE;
		cout << endl
			<< "     You got " << cumRight << " out of " << SET_SIZE 
			<< " correct on this set for a score of "  << percentRight << "%." << endl;
		if(percentRight >= 95)
		{
			if(numSeconds == 2)
			{
				if(level == 100)
				{
					cout << endl
						<< "     Congratulations.  You have completed successfully completed" << endl
						<< "     the entire set of addition drills." << endl
						<< endl
						<< "     Press enter to return to the main menu.  ";
					getchar();
				}
				else
				{
					s.setAddLevel(level + 1);
					s.setAddSpeed(6);
					cout << endl << "     Congratulations.  You have moved up to addends up to " 
						<< level + 1 << "." << endl
						<< "     You will start this level with six seconds to answer each question." 
						<< endl;
				}
			}
			else
			{
				if(percentRight >= 98)
				{
					if(numSeconds <= 4)
					{
						s.setAddSpeed(2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have" << endl
							<< "     two seconds to answer each question."  << endl;
					}
					else
					{
						s.setAddSpeed(numSeconds - 2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have "	
							<< endl
							<< "     " << numSeconds - 2 << " seconds to answer each question."  
							<< endl;
					}
				}
				else
				{
					s.setAddSpeed(s.getAddSpeed() - 1);
					if(s.getAddSpeed() < 1)
					{
						s.setAddSpeed(1);
					}
					cout << endl 
						<< "     Congratulations.  Due to your high accuracy, " << endl
						<< "     you will now have " << numSeconds -1 << " seconds to answer each question." << endl;
				}
			}
		}
		cout << endl
			<< "     Would you like to do another set of " << SET_SIZE << endl
			<< "     addition problems now (y or n)?  ";
		getline(cin, userInputStrob);
		ss.clear();
		ss << userInputStrob;
		ss >> wantsAnotherSet;
		cout << endl;
	}
}

