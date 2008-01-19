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
// Binaries released:
//		bdmd - Linux executable.
//		bdmd.exe - MS Windows executable.
//
// Revision History:
// 		Version 1.0 released March 1998
// 		Version 1.2 released December 2003
//
// Version notes:
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
// License:
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

void subModule(Student & s)
{
	SubTemplate * subBagArr;
	int templatesUsed;
	int numProblems;
	int level;
	int ndxSelectedProblem;
	int freq;
	int minuend;
	int subtrahend;
	int difference;
	int frequency;
	string userInputStrob;
	string junkString;
	stringstream ss;
	int userAnswer;
	int oldFreq;
	int newFreq;
	int subTemplateNdx;
	int currSubTemplateNdx;
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
		subBagArr = new SubTemplate[1];

		level = s.getSubLevel();
		numSeconds = s.getSubSpeed();
		cumRight = 0;
		cumWrong = 0;
		cumProblems = 0;
		templatesUsed = (((level + 1) * (level + 1)) / 2) + (level / 2) + 1;


		for(int i = 0; i < SET_SIZE; i++)
		{
			numProblems = 0;
			tooLong = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				numProblems += s.getSubTemplateArr()[i].getFrequency();
			}
			delete [] subBagArr;
			subBagArr = new SubTemplate[numProblems];
			int ndx = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				freq = s.getSubTemplateArr()[i].getFrequency();
				for(int j = 0; j <  freq; j++)
				{
					minuend = s.getSubTemplateArr()[i].getMinuend();
					subtrahend = s.getSubTemplateArr()[i].getSubtrahend();
					difference = s.getSubTemplateArr()[i].getDifference();
					frequency = s.getSubTemplateArr()[i].getFrequency();
					subTemplateNdx = s.getSubTemplateArr()[i].getSubTemplateNdx();
					subBagArr[ndx + j].setMinuend(minuend);
					subBagArr[ndx + j].setSubtrahend(subtrahend);
					subBagArr[ndx + j].setDifference(difference);
					subBagArr[ndx + j].setFrequency(frequency);
					subBagArr[ndx + j].setSubTemplateNdx(subTemplateNdx);
				}
				ndx += freq;
			}
			ndxSelectedProblem = rand() % numProblems;
			startTime = time(NULL);
			cout << endl
				<< "     " << subBagArr[ndxSelectedProblem].getMinuend() << "  -  "
				<< subBagArr[ndxSelectedProblem].getSubtrahend() << "  =  ";
			getline(cin, userInputStrob);
			endTime = time(NULL);
			timeElapsed = (endTime - startTime);
			if(timeElapsed > s.getSubSpeed())
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
			if(userAnswer == subBagArr[ndxSelectedProblem].getDifference())
			{
				cout << endl
					<< "     Correct!" << endl;
				if(tooLong)
				{ 
					cumWrong++;
					oldFreq = subBagArr[ndxSelectedProblem].getFrequency();
					currSubTemplateNdx = subBagArr[ndxSelectedProblem].getSubTemplateNdx();
					newFreq = 20;
					s.getSubTemplateArr()[currSubTemplateNdx].setFrequency(newFreq);
					cout << endl
					<< "     But you did not answer within " << s.getSubSpeed() << " seconds." << endl;
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
					oldFreq = subBagArr[ndxSelectedProblem].getFrequency();
					if(oldFreq > 1)
					{
						currSubTemplateNdx = subBagArr[ndxSelectedProblem].getSubTemplateNdx();
						newFreq = oldFreq / 2;
						s.getSubTemplateArr()[currSubTemplateNdx].setFrequency(newFreq);
					}
				}
			} else
			{
				cumWrong++;
				cout << endl
					<< "     Sorry, the correct answer is " << subBagArr[ndxSelectedProblem].getDifference()
					<< "."
					<< endl;
				delayTimer = 0;
				startTime = time(NULL);
				while (delayTimer < 4)
				{
					endTime = time(NULL);
					delayTimer = (endTime - startTime);
				}
				oldFreq = subBagArr[ndxSelectedProblem].getFrequency();
				currSubTemplateNdx = subBagArr[ndxSelectedProblem].getSubTemplateNdx();
				newFreq = 20;
				s.getSubTemplateArr()[currSubTemplateNdx].setFrequency(newFreq);
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
						<< "     the entire set of subtraction drills." << endl
						<< endl
						<< "     Press enter to return to the main menu.  ";
					getchar();
				}
				else
				{
					s.setSubLevel(level + 1);
					s.setSubSpeed(6);
					cout << endl << "     Congratulations.  You have moved up to minuends up to " 
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
						s.setSubSpeed(2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have" << endl
							<< "     two seconds to answer each question."  << endl;
					}
					else
					{
						s.setSubSpeed(numSeconds - 2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have "	
							<< endl
							<< "     " << numSeconds - 2 << " seconds to answer each question."  
							<< endl;
					}
				}
				else
				{
					s.setSubSpeed(s.getSubSpeed() - 1);
					if(s.getSubSpeed() < 1)
					{
						s.setSubSpeed(1);
					}
					cout << endl 
						<< "     Congratulations.  Due to your high accuracy, " << endl
						<< "     you will now have " << numSeconds -1 << " seconds to answer each question." << endl;
				}
			}
		}
		cout << endl
			<< "     Would you like to do another set of " << SET_SIZE << endl
			<< "     subtraction problems now (y or n)?  ";
		getline(cin, userInputStrob);
		ss.clear();
		ss << userInputStrob;
		ss >> wantsAnotherSet;
		cout << endl;
	}
}

