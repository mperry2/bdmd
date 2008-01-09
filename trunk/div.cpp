#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Student.h"
#include "vkit.h"
using namespace std;

void divModule(Student & s)
{
	DivTemplate * divBagArr;
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
	int divTemplateNdx;
	int currDivTemplateNdx;
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
		divBagArr = new DivTemplate[1];

		level = s.getDivLevel();
		numSeconds = s.getDivSpeed();
		cumRight = 0;
		cumWrong = 0;
		cumProblems = 0;
		templatesUsed = (s.getDivLevel() + 1) * s.getDivLevel();


		for(int i = 0; i < SET_SIZE; i++)
		{
			numProblems = 0;
			tooLong = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				numProblems += s.getDivTemplateArr()[i].getFrequency();
			}
			delete [] divBagArr;
			divBagArr = new DivTemplate[numProblems];
			int ndx = 0;
			for(int i = 0; i < templatesUsed; i++)
			{
				freq = s.getDivTemplateArr()[i].getFrequency();
				for(int j = 0; j <  freq; j++)
				{
					firstFactor = s.getDivTemplateArr()[i].getFirstFactor(); // denominator
					secondFactor = s.getDivTemplateArr()[i].getSecondFactor(); // quotient
					product = s.getDivTemplateArr()[i].getProduct(); // numerator
					frequency = s.getDivTemplateArr()[i].getFrequency();
					divTemplateNdx = s.getDivTemplateArr()[i].getDivTemplateNdx();
					divBagArr[ndx + j].setFirstFactor(firstFactor);
					divBagArr[ndx + j].setSecondFactor(secondFactor);
					divBagArr[ndx + j].setProduct(product);
					divBagArr[ndx + j].setFrequency(frequency);
					divBagArr[ndx + j].setDivTemplateNdx(divTemplateNdx);
				}
				ndx += freq;
			}
			ndxSelectedProblem = rand() % numProblems;
			startTime = time(NULL);
			cout << endl
				<< "     " << divBagArr[ndxSelectedProblem].getProduct() << "  /  "
				<< divBagArr[ndxSelectedProblem].getFirstFactor() << "  =  ";
			getline(cin, userInputStrob);
			endTime = time(NULL);
			timeElapsed = (endTime - startTime);
			if(timeElapsed > s.getDivSpeed())
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
			if(userAnswer == divBagArr[ndxSelectedProblem].getSecondFactor())
			{
				cout << endl
					<< "     Correct!" << endl;
				if(tooLong)
				{ 
					cumWrong++;
					oldFreq = divBagArr[ndxSelectedProblem].getFrequency();
					currDivTemplateNdx = divBagArr[ndxSelectedProblem].getDivTemplateNdx();
					newFreq = oldFreq * 2;
					if(newFreq > 10)
					{
						newFreq = 10;
					}
					s.getDivTemplateArr()[currDivTemplateNdx].setFrequency(newFreq);
					cout << endl
					<< "     But you did not answer within " << s.getDivSpeed() << " seconds." << endl;
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
					oldFreq = divBagArr[ndxSelectedProblem].getFrequency();
					if(oldFreq > 1)
					{
						currDivTemplateNdx = divBagArr[ndxSelectedProblem].getDivTemplateNdx();
						newFreq = oldFreq / 2;
						s.getDivTemplateArr()[currDivTemplateNdx].setFrequency(newFreq);
					}
				}
			} else
			{
				cumWrong++;
				cout << endl
					<< "     Sorry, the correct answer is " << divBagArr[ndxSelectedProblem].getProduct()
					<< "."
					<< endl;
				delayTimer = 0;
				startTime = time(NULL);
				while (delayTimer < 4)
				{
					endTime = time(NULL);
					delayTimer = (endTime - startTime);
				}
				oldFreq = divBagArr[ndxSelectedProblem].getFrequency();
				currDivTemplateNdx = divBagArr[ndxSelectedProblem].getDivTemplateNdx();
				newFreq = oldFreq * 2;
				if(newFreq > 10)
				{
					newFreq = 10;
				}
				s.getDivTemplateArr()[currDivTemplateNdx].setFrequency(newFreq);
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
					s.setDivLevel(level + 1);
					s.setDivSpeed(6);
					cout << endl << "     Congratulations.  You have moved up to denominators and quotients up to " 
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
						s.setDivSpeed(2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have" << endl
							<< "     two seconds to answer each question."  << endl;
					}
					else
					{
						s.setDivSpeed(numSeconds - 2);
						cout << endl 
							<< "     Congratulations.  Due to your very high accuracy, you will now have "	
							<< endl
							<< "     " << numSeconds - 2 << " seconds to answer each question."  
							<< endl;
					}
				}
				else
				{
					s.setDivSpeed(s.getDivSpeed() - 1);
					if(s.getDivSpeed() < 1)
					{
						s.setDivSpeed(1);
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
