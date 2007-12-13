// implementation of subtraction module by vd

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Student.h"
#include "vkit.h"
using namespace std;

void subModule(Student & s)
{{{
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
	stringstream ss;
	int userAnswer;
	int oldFreq;
	int newFreq;
	int subTemplateNdx;
	int currSubTemplateNdx;
	time_t startTime;
	time_t endTime;
	float timeElapsed;
	int numSeconds;
	int cumRight;
	int cumWrong;
	int cumProblems;
	int percentRight;
	const int SET_SIZE = 10;
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
		//--------------------------------------------------
		// //debug
		// cout << endl
		// 	<< "level: " << level << endl
		// 	<< "numSeconds: " << numSeconds << endl;
		//-------------------------------------------------- 
		templatesUsed = (((level + 1) * (level + 1)) / 2) + (level / 2) + 1;


		for(int i = 0; i < SET_SIZE; i++)
		{
			numProblems = 0;
			tooLong = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				numProblems += s.getSubTemplateArr()[i].getFrequency();
				//--------------------------------------------------
				// cout << endl
				// 	<< "s.getSubTemplateArr()[" << i << "].getFrequency(): " 
				// 	<< s.getSubTemplateArr()[i].getFrequency();
				//-------------------------------------------------- 
			}
			//--------------------------------------------------
			// //debug
			// cout << endl
			// 	<< "numProblems: " << numProblems << endl
			// 	<< endl;
			//-------------------------------------------------- 
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
			//--------------------------------------------------
			// cout << endl
			// 	<< "templatesUsed: " << templatesUsed << endl;
			// cout << "numProblems: " << numProblems << endl;
			//-------------------------------------------------- 
			ndxSelectedProblem = rand() % numProblems;
			//cout << "ndxSelectedProblem: " << ndxSelectedProblem << endl;
			startTime = time(NULL);
			//cout << endl << endl << "startTime: " << startTime << endl;
			//cin.sync(); This doesn't seem to flush cin.
			//cin.flush();
			cin.clear();
			cout << endl
				<< "     " << subBagArr[ndxSelectedProblem].getMinuend() << "  -  "
				<< subBagArr[ndxSelectedProblem].getSubtrahend() << "  =  ";
			getline(cin, userInputStrob);
			endTime = time(NULL);
			//cout << "endTime: " << endTime << endl;
			timeElapsed = (endTime - startTime);
			//cout << "timeElapsed: " << timeElapsed << endl;
			if(timeElapsed > s.getSubSpeed())
			{
				tooLong = 1;
			}
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
					//--------------------------------------------------
					// cout << endl 
					// 	<< "oldFreq: " << oldFreq << endl;
					//-------------------------------------------------- 
					currSubTemplateNdx = subBagArr[ndxSelectedProblem].getSubTemplateNdx();
					//cout << "currSubTemplateNdx: " << currSubTemplateNdx << endl;
					newFreq = oldFreq * 2;
					if(newFreq > 10)
					{
						newFreq = 10;
					}
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
					//--------------------------------------------------
					// cout << endl 
					// 	<< "oldFreq: " << oldFreq << endl;
					//-------------------------------------------------- 
					if(oldFreq > 1)
					{
						currSubTemplateNdx = subBagArr[ndxSelectedProblem].getSubTemplateNdx();
						//cout << "currSubTemplateNdx: " << currSubTemplateNdx << endl;
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
				//--------------------------------------------------
				// cout << endl 
				// 	<< "oldFreq: " << oldFreq << endl;
				//-------------------------------------------------- 
				currSubTemplateNdx = subBagArr[ndxSelectedProblem].getSubTemplateNdx();
				//cout << "currSubTemplateNdx: " << currSubTemplateNdx << endl;
				newFreq = oldFreq * 2;
				if(newFreq > 10)
				{
					newFreq = 10;
				}
				s.getSubTemplateArr()[currSubTemplateNdx].setFrequency(newFreq);
			}
		}
		percentRight = (cumRight * 100) / SET_SIZE;
		cout << endl
			<< "     You got " << cumRight << " out of " << SET_SIZE 
			<< " correct on this set for a score of "  << percentRight << "%." << endl;
		if(percentRight >= 96)
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
}}}
