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
	cout << endl
		<< "Executing function subModule() implemented" << endl
		<< "in file named sub.cpp." << endl
		<< endl;

	//void makeBag(Student s, int templatesUsed, SubTemplate * subBagArr, int & numProblems);

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

	srand(time(0));
	subBagArr = new SubTemplate[1];

	level = s.getSubLevel();
	//debug
	cout << endl
		<< "level: " << level << endl;
	templatesUsed = (((level + 1) * (level + 1)) / 2) + (level / 2) + 1;
	for(int i = 0; i < 10; i++)
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
				//cout << "subBagArr[ndx + j].getFrequency(frequency): " << subBagArr[ndx + j].getFrequency() << endl;
			}
			ndx += freq;
		}
		cout << endl
			<< "templatesUsed: " << templatesUsed << endl;
		cout << "numProblems: " << numProblems << endl;
		ndxSelectedProblem = rand() % numProblems;
		cout << "ndxSelectedProblem: " << ndxSelectedProblem << endl;
		cout << endl
			<< "     " << subBagArr[ndxSelectedProblem].getMinuend() << "  -  "  << subBagArr[ndxSelectedProblem].getSubtrahend() << "  =  ";
		getline(cin, userInputStrob);
		ss.clear();
		ss << userInputStrob;
		ss >> userAnswer;
		if(userAnswer == subBagArr[ndxSelectedProblem].getDifference())
		{
			cout << endl
				<< "     Correct!" << endl;
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
	cout << "Press enter to return to main().  ";
	getchar();
	cout << endl;
}}}
//--------------------------------------------------
// void makeBag(Student s, int templatesUsed, SubTemplate * subBagArr, int & numProblems)
// {{{
// }}}
//-------------------------------------------------- 

