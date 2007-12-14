// mlt.cpp

#include <iostream>
#include <ctime> 

#include <cstdlib>
#include "Student.h"
using namespace std;

const int NUM_PROBLEMS = 5;

void promptNewLevel(Student &s);
void randNumber(Student &s, int arr[]);
void endResult(Student &s, int correct, int wrong);

void Cls()

{

 #ifdef _WIN32

	system("cls");// for MS Windows

#else

	system("clear");//for Linux

#endif

}

void mltModule(Student & s)
{
	int userAnswer, right, wrong, answer=0, numProblems;
	int firstFactor, secondFactor;

	int product;

	int frequency;

	int mltTemplateNdx;
	int ndxSelectedProblem;
	int numSeconds=s.getMltSpeed();
	char again='y';
	int randArr[MAX_NUMERATOR];

	while(again=='y')
	{
		Cls();
		randNumber(s,randArr);

		//makeBag
	//MltTemplate * mltBagArr;
	//mltBagArr = new MltTemplate[1];
	//int templatesUsed = (s.getMltLevel() ) * (s.getMltLevel());

	//for(int i = 0; i < 10; i++)

	//{

	//	numProblems = 0;

	//	for(int i = 0; i < templatesUsed; i++)

	//	{

	//		numProblems += s.getMltTemplateArr()[i].getFrequency();

	//		cout << endl

	//			<< "s.getMltTemplateArr()[" << i << "].getFrequency(): " << s.getMltTemplateArr()[i].getFrequency();

	//	}

	//	//debug

	//	cout << endl

	//		<< "numProblems: " << numProblems << endl

	//		<< endl;

	//	delete [] mltBagArr;

	//	mltBagArr = new MltTemplate[numProblems];

	//	int ndx = 0;

	//	for(int i = 0; i < templatesUsed; i++)

	//	{

	//		int freq = s.getMltTemplateArr()[i].getFrequency();

	//		for(int j = 0; j <  freq; j++)

	//		{

	//			firstFactor = s.getMltTemplateArr()[i].getFirstFactor();

	//			secondFactor = s.getMltTemplateArr()[i].getSecondFactor();

	//			product = s.getMltTemplateArr()[i].getProduct();

	//			frequency = s.getMltTemplateArr()[i].getFrequency();

	//			mltTemplateNdx = s.getMltTemplateArr()[i].getMltTemplateNdx();

	//			mltBagArr[ndx + j].setFirstFactor(firstFactor);

	//			mltBagArr[ndx + j].setSecondFactor(secondFactor);

	//			mltBagArr[ndx + j].setProduct(product);

	//			mltBagArr[ndx + j].setFrequency(frequency);

	//			mltBagArr[ndx + j].setMltTemplateNdx(mltTemplateNdx);

	//			//cout << "mltBagArr[ndx + j].getFrequency(frequency): " << mltBagArr[ndx + j].getFrequency() << endl;

	//		}

	//		ndx += freq;

	//	}

	//}

	//	cout << endl

	//		<< "templatesUsed: " << templatesUsed << endl;

	//	cout << "numProblems: " << numProblems << endl;

	//	ndxSelectedProblem = rand() % numProblems;

	//	cout << "ndxSelectedProblem: " << ndxSelectedProblem << endl;

	//	cout << endl;

		right=wrong=0;
		cout << "\n You have "<< s.getMltSpeed()<<" seconds for each problem."<<endl<<endl;

	for(int i=0;i<NUM_PROBLEMS;i++)
	{   
		cout<< s.getMltTemplateArr()[randArr[i+1]].getFirstFactor()<< " X "<< s.getMltTemplateArr()[randArr[i+1]].getSecondFactor()<< " = ";
		time_t startTime, endTime, timeElapsed;

		startTime = time(NULL);
		cin>>userAnswer;
		endTime = time(NULL);

		//timeElapsed = (endTime - startTime) / CLK_TCK;
		timeElapsed = (endTime - startTime);

		if(userAnswer == s.getMltTemplateArr()[randArr[i+1]].getProduct())
		{
			cout << "Correct!"<<endl;
			right++;
		}
		else
		{
			cout << "Incorrect"<<endl;
			wrong++;
		}
		if(timeElapsed > numSeconds)
		{			
			cout << "You didn't answer the problem on time"<<endl<<endl;
		}
	}

	endResult(s,right,wrong);

	cout << "Want to go again? y or n?";
	cin >> again;
	}
}
void promptNewLevel(Student &s)
{
	int level;
	cout << endl << endl
	<< "Level? (max is 20) ";
	cin >> level;
	while((level<=0)||(level>20))
	{
		cout << endl << "Re enter Level (max is 20): ";
		cin >> level;
	}
	s.setMltLevel(level);
}

void randNumber(Student &s, int arr[])
{
    int numUsed = (s.getMltLevel() ) * (s.getMltLevel());
    srand((unsigned)time(0)); 

    int random_integer; 

    int lowest=0, highest=numUsed; 

    int range=(numUsed-lowest)+1; 

    for(int index=0; index<NUM_PROBLEMS+1; index++){ 

        random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0)); 

		arr[index]=random_integer;
	}
    //return arr;
}

void endResult(Student &s, int correct, int wrong)
{
	float score,bottom=NUM_PROBLEMS;
	int temp=s.getMltSpeed();
	score = (correct/bottom)*100;
    cout<<correct<<" out of "<<bottom<<endl;
	cout<<"You scored "<<score<<"%!"<<endl;
	cout<<"Number of incorrects: "<< wrong<<endl;
	
    if((score >= 96)&&(s.getMltSpeed() > 3))
	{ temp--; }
	if((score >= 98)&&(s.getMltSpeed() >= 3))
	{ temp--; }

	if((score >= 96)&&(s.getMltSpeed() > 3))
	{
	cout << "Since you scored "<< score <<"%, your new time to finish each problem "
		 << "is decreased from "<< s.getMltSpeed() << " to "
		 << temp << " seconds." <<endl;
	}
	if((score >= 98)&&(s.getMltSpeed() == 2))
	{
		temp=6;
		cout << "You have completed the sets of problems with a grade of "
			<< score << "% within 2 seconds each. You may select a new level. ";
		promptNewLevel(s);
	}
	s.setMltSpeed(temp);

}

 //test ***************
//int main()
//{
//	Student s;
//    s.makeMltTemplateArr(s);
//	promptNewLevel(s);
//	mltModule(s);
//
//	return 0;
//}

