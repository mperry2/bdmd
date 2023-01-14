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

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Student.h"
#include "vkit.h"
using namespace std;

void mltModule(Student & s)
{
	MltTemplate * mltBagArr;
	int templatesUsed;
	int numProblems;
	int level;
	int ndxSelectedProblem;
	int freq;
	int firstFactor;
	int secondFactor;
	int product;
	int frequency;
	string userInputStrob;
	string junkString;
	stringstream ss;
	int userAnswer;
	int oldFreq;
	int newFreq;
	int mltTemplateNdx;
	int currMltTemplateNdx;
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
		mltBagArr = new MltTemplate[1];

		level = s.getMltLevel();
		numSeconds = s.getMltSpeed();
		cumRight = 0;
		cumWrong = 0;
		cumProblems = 0;
		templatesUsed = (s.getMltLevel() + 1) * (s.getMltLevel() + 1);


		for(int i = 0; i < SET_SIZE; i++)
		{
			numProblems = 0;
			tooLong = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				numProblems += s.getMltTemplateArr()[i].getFrequency();
			}
			delete [] mltBagArr;
			mltBagArr = new MltTemplate[numProblems];
			int ndx = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				freq = s.getMltTemplateArr()[i].getFrequency();
				for(int j = 0; j <  freq; j++)
				{
					firstFactor = s.getMltTemplateArr()[i].getFirstFactor();
					secondFactor = s.getMltTemplateArr()[i].getSecondFactor();
					product = s.getMltTemplateArr()[i].getProduct();
					frequency = s.getMltTemplateArr()[i].getFrequency();
					mltTemplateNdx = s.getMltTemplateArr()[i].getMltTemplateNdx();
					mltBagArr[ndx + j].setFirstFactor(firstFactor);
					mltBagArr[ndx + j].setSecondFactor(secondFactor);
					mltBagArr[ndx + j].setProduct(product);
					mltBagArr[ndx + j].setFrequency(frequency);
					mltBagArr[ndx + j].setMltTemplateNdx(mltTemplateNdx);
				}
				ndx += freq;
			}
			ndxSelectedProblem = rand() % numProblems;
			startTime = time(NULL);
			cout << endl
				<< "     " << mltBagArr[ndxSelectedProblem].getFirstFactor() << "  *  "
				<< mltBagArr[ndxSelectedProblem].getSecondFactor() << "  =  ";
			getline(cin, userInputStrob);
			endTime = time(NULL);
			timeElapsed = (endTime - startTime);
			if(timeElapsed > s.getMltSpeed())
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
			if(userAnswer == mltBagArr[ndxSelectedProblem].getProduct())
			{
				cout << endl
					<< "     Correct!" << endl;
				if(tooLong)
				{ 
					cumWrong++;
					oldFreq = mltBagArr[ndxSelectedProblem].getFrequency();
					currMltTemplateNdx = mltBagArr[ndxSelectedProblem].getMltTemplateNdx();
					newFreq = 20;
					s.getMltTemplateArr()[currMltTemplateNdx].setFrequency(newFreq);
					cout << endl
					<< "     But you did not answer within " << s.getMltSpeed() << " seconds." << endl;
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
					oldFreq = mltBagArr[ndxSelectedProblem].getFrequency();
					if(oldFreq > 1)
					{
						currMltTemplateNdx = mltBagArr[ndxSelectedProblem].getMltTemplateNdx();
						newFreq = oldFreq / 2;
						s.getMltTemplateArr()[currMltTemplateNdx].setFrequency(newFreq);
					}
				}
			} else
			{
				cumWrong++;
				cout << endl
					<< "     Sorry, the correct answer is " << mltBagArr[ndxSelectedProblem].getProduct()
					<< "."
					<< endl;
				delayTimer = 0;
				startTime = time(NULL);
				while (delayTimer < 4)
				{
					endTime = time(NULL);
					delayTimer = (endTime - startTime);
				}
				oldFreq = mltBagArr[ndxSelectedProblem].getFrequency();
				currMltTemplateNdx = mltBagArr[ndxSelectedProblem].getMltTemplateNdx();
				newFreq = 20;
				s.getMltTemplateArr()[currMltTemplateNdx].setFrequency(newFreq);
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
						<< "     the entire set of multiplication drills." << endl
						<< endl
						<< "     Press enter to return to the main menu.  ";
					getchar();
				}
				else
				{
					s.setMltLevel(level + 1);
					s.setMltSpeed(6);
					cout << endl << "     Congratulations.  You have moved up to factors up to " 
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
						s.setMltSpeed(2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have" << endl
							<< "     two seconds to answer each question."  << endl;
					}
					else
					{
						s.setMltSpeed(numSeconds - 2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have "	
							<< endl
							<< "     " << numSeconds - 2 << " seconds to answer each question."  
							<< endl;
					}
				}
				else
				{
					s.setMltSpeed(s.getMltSpeed() - 1);
					if(s.getMltSpeed() < 1)
					{
						s.setMltSpeed(1);
					}
					cout << endl 
						<< "     Congratulations.  Due to your high accuracy, " << endl
						<< "     you will now have " << numSeconds -1 << " seconds to answer each question." << endl;
				}
			}
		}
		cout << endl
			<< "     Would you like to do another set of " << SET_SIZE << endl
			<< "     multiplication problems now (y or n)?  ";
		getline(cin, userInputStrob);
		ss.clear();
		ss << userInputStrob;
		ss >> wantsAnotherSet;
		cout << endl;
	}
}

