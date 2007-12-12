// implementation of subtraction module by vd

#include <iostream>
#include <time.h>
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
	clock_t startTime, endTime;
	float timeElapsed;
	int numSeconds;
	int cumRight;
	int cumWrong;
	int cumProblems;
	int percentRight;
	const int SET_SIZE = 50;
	string wantsAnotherSet = "y";

	while(wantsAnotherSet == "y" || wantsAnotherSet == "Y")
	{
		srand(time(0));
		subBagArr = new SubTemplate[1];

		level = s.getSubLevel();
		numSeconds = s.getSubSpeed();
		//debug
		cout << endl
			<< "level: " << level << endl
			<< "numSeconds: " << numSeconds << endl;
		templatesUsed = (((level + 1) * (level + 1)) / 2) + (level / 2) + 1;


		for(int i = 0; i < SET_SIZE; i++)
		{
			numProblems = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				numProblems += s.getSubTemplateArr()[i].getFrequency();
				cout << endl
					<< "s.getSubTemplateArr()[" << i << "].getFrequency(): " << s.getSubTemplateArr()[i].getFrequency();
			}
			//debug
			cout << endl
				<< "numProblems: " << numProblems << endl
				<< endl;
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
			cout << endl
				<< "templatesUsed: " << templatesUsed << endl;
			cout << "numProblems: " << numProblems << endl;
			ndxSelectedProblem = rand() % numProblems;
			cout << "ndxSelectedProblem: " << ndxSelectedProblem << endl;
			cout << endl
				<< "     " << subBagArr[ndxSelectedProblem].getMinuend() << "  -  "
				<< subBagArr[ndxSelectedProblem].getSubtrahend() << "  =  ";
			startTime = clock();
			getline(cin, userInputStrob);
			endTime = clock();
			timeElapsed = (endTime - startTime) / CLOCKS_PER_SEC;
			ss.clear();
			ss << userInputStrob;
			ss >> userAnswer;
			if(userAnswer == subBagArr[ndxSelectedProblem].getDifference())
			{
				cout << endl
					<< "     Correct!" << endl;
				oldFreq = subBagArr[ndxSelectedProblem].getFrequency();
				cout << endl 
					<< "oldFreq: " << oldFreq << endl;
				if(oldFreq > 1)
				{
					currSubTemplateNdx = subBagArr[ndxSelectedProblem].getSubTemplateNdx();
					cout << "currSubTemplateNdx: " << currSubTemplateNdx << endl;
					newFreq = oldFreq / 2;
					s.getSubTemplateArr()[currSubTemplateNdx].setFrequency(newFreq);
				}
			} else
			{
				cout << "     Sorry, the correct answer is " << subBagArr[ndxSelectedProblem].getDifference() << "."
					<< endl;
			}
		}
		percentRight = cumRight / SET_SIZE;
		cout << endl
			<< "     You got " << cumRight << " out of " << SET_SIZE << "correct on this set"
			<< "     for a score of "  << percentRight << "%." << endl;
		if(percentRight >= 96)
		{
			if(numSeconds = 2)
			{
				s.setSubLevel(level + 1);
				s.setSubSpeed(6);
				cout << "     Congratulations, you have moved up to minuends up to " << level + 1 << "." << endl
					<< "     You will start this level with six seconds to answer each question." << endl << endl;
			}
			else
			{
				if(percentRight >= 98)
				{
					if(numSeconds <= 4)
					{
						s.setSubSpeed(2);
						cout << "     Congratulations.  Due to your very high accuracy, you will now have" << endl
							<< "     two seconds to answer each question."  << endl << endl;
					}
					else
					{
						s.setSubSpeed(numSeconds - 2);
						cout << "     Congratulations.  Due to your very high accuracy, you will now have " << endl
							<< numSeconds - 2 << " to answer each question."  << endl << endl;
					}
				}
				else
				{
					s.setSubSpeed(numSeconds -1);
					cout << "     Congratulations.  Due to your high accuracy, you will now have " << endl
						<< numSeconds -1 << " to answer each question." << endl << endl;
				}
			}
		}
		cout << "     Would you like to do another set of " << SET_SIZE << " subtraction problems now (y or n)?  ";
		ss.clear();
		ss << userInputStrob;
		ss >> wantsAnotherSet;
		cout << endl;
	}
}}}
//--------------------------------------------------
// void makeBag(Student s, int templatesUsed, SubTemplate * subBagArr, int & numProblems)
// {{{
// }}}
//-------------------------------------------------- 

			//--------------------------------------------------
			// //debug
			// for(int j = 0; j < numProblems; j++)
			// {
			// 	cout << "subBagArr[" << j << "].getMinuend(): " << subBagArr[j].getMinuend() << endl;
			// 	cout << "subBagArr[" << j << "].getSubtrahend(): " << subBagArr[j].getSubtrahend() << endl;
			// 	cout << "subBagArr[" << j << "].getDifference(); " << subBagArr[j].getDifference() << endl;
			// 	cout << "subBagArr[" << j << "].getFrequency(); " << subBagArr[j].getFrequency() << endl;
			// }
			//-------------------------------------------------- 


