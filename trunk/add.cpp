// Valentin, this is the file where you should gradually add all your code for 
// the addition module. Commit the changes to the repository, 
// as code is added and tested.  Do not commit code that breaks 
// the project.  The project in trunk should always compile, build, and run.

// The stub function below just prints a message when called 
// by main, which is in bdmd.cpp

void randPool();
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Student.h"
#include "vkit.h"

void addModule(Student & s)
{{{
	AddTemplate * addBagArr;
	int templatesUsed;
	int numProblems;
	int level;
	int ndxSelectedProblem;
	int freq;
	int firstAddend;
	int secondAddend;
	int sum;
	string userInputStrob;
	stringstream ss;
	int userAnswer;
	int oldFreq;
	int newFreq;
	int AddTemplateNdx;
	int currAddTemplateNdx;
	float timeElapsed;
	int secElapsed;
	int correct;
	int incorrect;
	int total;
	int percentRight;
	const int SET_SIZE = 10;
	string wantsAnotherSet = "y";
	//char r[1];
	//r[0]='y';
	//gets_s(r);
	int timeout;
	int timer;
	time_t startTime;
	time_t endTime;



	while (wantsAnotherSet == "y" || wantsAnotherSet == "Y")

	{
//		srand(time(0));
		randPool();
		addBagArr = new AddTemplate[1];

		level = s.getAddLevel();
		secElapsed = s.getAddSpeed();
		correct = 0;
		incorrect = 0;
		total = 0;
		//--------------------------------------------------
		// //debug
		// cout << endl
		// 	<< "level: " << level << endl
		// 	<< "secElapsed: " << secElapsed << endl;
		//-------------------------------------------------- 
		templatesUsed = (((level + 1) * (level + 1)) / 2) + (level / 2) + 1;


		for(int i = 0; i < SET_SIZE; i++)
		{
			numProblems = 0;
			timeout = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				numProblems += s.getAddTemplateArr()[i].getFrequency();
				//--------------------------------------------------
				// cout << endl
				// 	<< "s.getAddTemplateArr()[" << i << "].getFrequency(): " 
				// 	<< s.getAddTemplateArr()[i].getFrequency();
				//-------------------------------------------------- 
			}
			//--------------------------------------------------
			// //debug
			// cout << endl
			// 	<< "numProblems: " << numProblems << endl
			// 	<< endl;
			//-------------------------------------------------- 
			delete [] addBagArr;
			addBagArr = new AddTemplate[numProblems];
			int ndx = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				freq = s.getAddTemplateArr()[i].getFrequency();
				for(int j = 0; j <  freq; j++)
				{
					firstAddend = s.getAddTemplateArr()[i].getFirstAddend();
					secondAddend = s.getAddTemplateArr()[i].getSecondAddend();
					sum = s.getAddTemplateArr()[i].getSum();
					freq = s.getAddTemplateArr()[i].getFrequency();
					AddTemplateNdx = s.getAddTemplateArr()[i].getAddTemplateNdx();
					addBagArr[ndx + j].setFirstAddend(firstAddend);
					addBagArr[ndx + j].setSecondAddend(secondAddend);
					addBagArr[ndx + j].setSum(sum);
					addBagArr[ndx + j].setFrequency(freq);
					addBagArr[ndx + j].setAddTemplateNdx(AddTemplateNdx);
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
			cout << endl
				<< "     " << addBagArr[ndxSelectedProblem].getFirstAddend() << "  +  "
				<< addBagArr[ndxSelectedProblem].getSecondAddend() << "  =  ";
			getline(cin, userInputStrob);
			endTime = time(NULL);
			//cout << "endTime: " << endTime << endl;
			timeElapsed = (endTime - startTime);
			//cout << "timeElapsed: " << timeElapsed << endl;
			if(timeElapsed > s.getAddSpeed())
			{
				timeout = 1;
			}
			ss.clear();
			ss << userInputStrob;
			ss >> userAnswer;
			total++;
			if(userAnswer == addBagArr[ndxSelectedProblem].getSum())
			{
				cout << endl
					<< "     Correct!" << endl;
				if(timeout)
				{ 
					incorrect++;
					oldFreq = addBagArr[ndxSelectedProblem].getFrequency();
					//--------------------------------------------------
					// cout << endl 
					// 	<< "oldFreq: " << oldFreq << endl;
					//-------------------------------------------------- 
					currAddTemplateNdx = addBagArr[ndxSelectedProblem].getAddTemplateNdx();
					//cout << "currAddTemplateNdx: " << currAddTemplateNdx << endl;
					newFreq = oldFreq * 2;
					if(newFreq > 10)
					{
						newFreq = 10;
					}
					s.getAddTemplateArr()[currAddTemplateNdx].setFrequency(newFreq);
					cout << endl
					<< "     But you did not answer within " << s.getAddSpeed() << " seconds." << endl;
					timer = 0;
					startTime = time(NULL);
					while (timer < 2)
					{
						endTime = time(NULL);
						timer = (endTime - startTime);
					}
				}
				else
				{
					correct++;
					oldFreq = addBagArr[ndxSelectedProblem].getFrequency();
					//--------------------------------------------------
					// cout << endl 
					// 	<< "oldFreq: " << oldFreq << endl;
					//-------------------------------------------------- 
					if(oldFreq > 1)
					{
						currAddTemplateNdx = addBagArr[ndxSelectedProblem].getAddTemplateNdx();
						//cout << "currAddTemplateNdx: " << currAddTemplateNdx << endl;
						newFreq = oldFreq / 2;
						s.getAddTemplateArr()[currAddTemplateNdx].setFrequency(newFreq);
					}
				}
			} else
			{
				incorrect++;
				cout << endl
					<< "     Sorry, the correct answer is " << addBagArr[ndxSelectedProblem].getSum()
					<< "."
					<< endl;
				timer = 0;
				startTime = time(NULL);
				while (timer < 4)
				{
					endTime = time(NULL);
					timer = (endTime - startTime);
				}
				oldFreq = addBagArr[ndxSelectedProblem].getFrequency();
				//--------------------------------------------------
				// cout << endl 
				// 	<< "oldFreq: " << oldFreq << endl;
				//-------------------------------------------------- 
				currAddTemplateNdx = addBagArr[ndxSelectedProblem].getAddTemplateNdx();
				//cout << "currAddTemplateNdx: " << currAddTemplateNdx << endl;
				newFreq = oldFreq * 2;
				if(newFreq > 10)
				{
					newFreq = 10;
				}
				s.getAddTemplateArr()[currAddTemplateNdx].setFrequency(newFreq);
			}
		}
		percentRight = (correct * 100) / SET_SIZE;
		cout << endl
			<< "     You got " << correct << " out of " << SET_SIZE 
			<< " correct on this set for a score of "  << percentRight << "%." << endl;
		if(percentRight >= 96)
		{
			if(secElapsed == 2)
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
					if(secElapsed <= 4)
					{
						s.setAddSpeed(2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have" << endl
							<< "     two seconds to answer each question."  << endl;
					}
					else
					{
						s.setAddSpeed(secElapsed - 2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have "	
							<< endl
							<< "     " << secElapsed - 2 << " seconds to answer each question."  
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
						<< "     you will now have " << secElapsed -1 << " seconds to answer each question." << endl;
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
		//gets_s(r);

		cout << endl;
	}
}}}

void randPool()
{
	Student s;
	srand((unsigned)time(0)); 
	int random_integer_1, random_integer_2, sum;
	int prob_num=0;
	int lowest=0, highest=0;
	


	int range=(highest-lowest)+1;  
	for(int i=0; i<prob_num; i++)
	{
		prob_num=s.getAddTemplateArr()[i].getFrequency();
		random_integer_1 = lowest+int(range*rand()/(RAND_MAX + 1.0));
		if (random_integer_1==random_integer_1)
		{
			random_integer_1 = lowest+int(range*rand()/(RAND_MAX + 1.0));
		}
		random_integer_2 = lowest+int(range*rand()/(RAND_MAX + 1.0));
		if (random_integer_2==random_integer_2)
		{
			random_integer_2 = lowest+int(range*rand()/(RAND_MAX + 1.0));
		}
	}
}

