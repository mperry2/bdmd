// This is version 1.2 of Big Daddy's Multiplication Drills,
// the standalone addition program
// that I wrote several years ago in qbasic
// and translated into c++ translation without improvements.
// I have uploaded it to the repository so you 
// can look at it if you want for ideas.
// You can check it out, but don't commit any changes to this file to
// the repository.  Instead, please check out trunk/mlt.cpp
// and put your new code in there.
// Since each module (addition, multiplication, subtraction,
// main) will be the sole responsibility of one of us,
// I think it will simplify matters if all of the code
// relating to that module (including prototypes and classes)
// goes into a single file (add.cpp, mlt.cpp, sub.cpp, 
// or bdmd.cpp).  If someone writes a class or function 
// that is useful for more than one module, we have the option of 
// breaking that out into a separate header or implementation 
// file later if we want.

#include <iostream.h>
#include <time.h>
#include <stdlib.h>

int getBiggestFactor(void);
int getSeconds(int &percentRight, int &numSeconds, const int &SET_SIZE, int &biggestFactor);
void inTime(int &firstFactor, int &secondFactor,
	int &userAnswer, int &numRight, int &numWrong, int &cumRight, int &cumWrong,
	int &cumProblems);
void rightAnswer(int &numRight, int &cumRight, int &cumProblems);
void wrongAnswer(int &numWrong, int &cumWrong, int &cumProblems,
	int &firstFactor, int &secondFactor);
void displayRightAnswer(int &firstFactor, int &secondFactor);
void doSet(int &biggestFactor, int &numSeconds, int &cumRight, int &cumWrong,
	int &cumProblems, int &percentRight, const int &SET_SIZE);
void tooLong(int &numSeconds, int &numWrong, int &cumWrong, int &cumProblems,
	int &firstFactor, int &secondFactor, int &userAnswer);
void wantMore(int &biggestFactor, int &numSeconds, int &cumRight, int &cumWrong,
	int &cumProblems, int &percentRight, const int &SET_SIZE);

main(){
	int biggestFactor, numSeconds = 6;
	int cumRight = 0,	cumWrong = 0, cumProblems = 0;
	float percentRight = 0;
	const int SET_SIZE = 50;

	randomize();
	char moreProblems = 'y';
	cout	<< "  Hello.  This is Big Daddy DiCarlo's Multiplication Drill, version 1.2\n"
			<< "  Version 1.2 has been re-written in C++ and runs in a window\n"
			<< "  under Windows XP and, presumably, other versions of Windows.\n\n"

			<< "  There are 50 multiplication problems in each set.\n"
			<<	"  You start with 6 seconds for each problem, but when your\n"
			<< "  accuracy reaches 94 or 96 percent for a set, the allowed time is\n"
			<< "  reduced by one or two seconds respectively.\n"
			<< "  When you see each problem, just type the answer and press return.\n\n"

			<< "  If, when the program asks you for a number, you try to enter\n"
			<< "  a noninteger character, the program may look\n"
			<< "  like it's going bazoo. To quit then or at any time\n"
			<< "  press alt-F4 or close the window with your mouse.\n\n";

	biggestFactor = getBiggestFactor();
	doSet(biggestFactor, numSeconds, cumRight, cumWrong, cumProblems, percentRight, SET_SIZE);
	cout	<< "  Thank you for playing Big Daddy DiCarlo's Multiplication Drill.\n\n"
			<< "  You can get updates and other shareware, including\n"
			<< "  Big Daddy DiCarlo's addition and subtraction drills,\n"
			<< "  at www.dicarlolaw.com/shareware.html";
return 0;
}

getBiggestFactor(){
	int valid = 0;
	int biggestFactor;
	cout	<< "  In a multiplication problem, the numbers that are multiplied\n"
			<< "  by each other are called 'factors.'\n"
			<< "  The answer to a multiplication problem is called the 'product.'\n\n";
	while (valid == 0){
		cout	<< "  How big (from 2 to 20) is the largest factor you wish to multiply? ";
		cin >> biggestFactor;
		cout << "\n";
		if ((biggestFactor < 21)  && (biggestFactor  > 1)){
			valid = 1;
		}
		else {
			cout	<< "  Please select a number from 2 to 20 as the largest \n"
					<< "  factor.\n\n";
		}
		continue;
	}
	return biggestFactor;
}

getSeconds(int &percentRight, int &numSeconds, const int &SET_SIZE, int &biggestFactor){
	if ((numSeconds == 2) && (percentRight >= 94)){
		cout 	<< "  Terrific!!!\n\n"
				<< "  You got " << percentRight << " % right with only 2 seconds\n"
				<< "  per problem.\n\n"
				<< "  You are ready to move on to factors up to "
				<< (biggestFactor + 1) << ".\n\n"
				<< "  If you want to start right now, press alt-F4 or close this\n"
				<< "  window and restart.\n\n";
		}
	if ((percentRight >= 94) && (numSeconds >= 3)){
		numSeconds = numSeconds - 1;
	}
	if ((percentRight >= 98) && (numSeconds >= 3)){
		numSeconds = numSeconds - 1;
	}
	return numSeconds;
}

void doSet(int &biggestFactor, int &numSeconds, int &cumRight, int &cumWrong,
	int &cumProblems, int &percentRight, const int &SET_SIZE){
	int numRight = 0, numWrong = 0;
	int randomNum, firstFactor, secondFactor, userAnswer;
	float timeElapsed;

	numSeconds = getSeconds(percentRight, numSeconds, SET_SIZE, biggestFactor);
	cout << "You will have " << numSeconds << " seconds to answer each problem in this set.\n\n";
	for (int i = 1; i <= SET_SIZE; i++){
		randomNum = random(biggestFactor + 1);
		firstFactor = randomNum;
		randomNum = random(firstFactor + 1);
		secondFactor = randomNum;
		cout	<< "    " << firstFactor << "  *  " << secondFactor << "  =  " ;
		clock_t startTime, endTime;
		startTime = clock();
		cin >> userAnswer;
		cout << "\n";
		endTime = clock();
		timeElapsed = (endTime - startTime) / CLK_TCK;
		if (timeElapsed > numSeconds){
			tooLong(numSeconds, numWrong, cumWrong, cumProblems, firstFactor,
				secondFactor, userAnswer);
		}
		else {
			inTime(firstFactor, secondFactor, userAnswer, numRight,
				numWrong, cumRight, cumWrong, cumProblems);
		}
	}
	cout	<< "  Out of the Last Set of Fifty\n\n"
			<< "  Number correct: " << numRight << "\n\n"
			<< "  Number wrong or too late: " << numWrong << "\n\n"
			<< "  Percentage right: " <<  (numRight * (100 / SET_SIZE)) << " %\n\n"
			<< "  Since the Start of this Game\n\n";
	percentRight = (numRight * (100 / SET_SIZE));
	double dubCumProblems = cumProblems;
	double dubCumRight = cumRight;
	cout	<< "  Total number of questions: " << cumProblems << "\n\n"
			<< "  Cumulative number correct: " << cumRight << "\n\n"
			<< "  Cumulative number wrong or late: " << cumWrong << "\n\n"
			<< "  Cumulative percentage right: " << ((dubCumRight / dubCumProblems) * 100)	<< " %\n\n";
	wantMore(biggestFactor, numSeconds, cumRight, cumWrong, cumProblems, percentRight, SET_SIZE);
}

void wantMore(int &biggestFactor, int &numSeconds, int &cumRight, int &cumWrong,
	int &cumProblems, int &percentRight, const int &SET_SIZE){
	char moreProblems;
	cout << "  Do you want to add another 50 problems (y or n)? ";
	cin >> moreProblems;
	cout << "\n\n";
	if (moreProblems == 'y'){
		doSet(biggestFactor, numSeconds, cumRight, cumWrong, cumProblems, percentRight, SET_SIZE);
	}
}

void tooLong(int &numSeconds, int &numWrong, int &cumWrong, int &cumProblems,
	int &firstFactor, int &secondFactor, int &userAnswer){
	// User took too long.
	cout << "  Sorry, you didn't answer within " << numSeconds << " seconds.\n\n";
	numWrong = numWrong + 1;
	cumWrong = cumWrong + 1;
	cumProblems = cumProblems + 1;
	if (userAnswer != (firstFactor * secondFactor)){
		// user also got it wrong
		cout 	<< "  Also, " << firstFactor << " times " << secondFactor
			<< " equals " << (firstFactor * secondFactor) << "\n\n";
		clock_t startTime = clock();
		int delayTimer = 0;
		while (delayTimer < 4){
			clock_t endTime = clock();
			delayTimer = (endTime - startTime) / CLK_TCK;
		}
	}
	else {
	cout << "  However, you did get the correct answer.\n\n";
	}
}

void displayRightAnswer(int &firstFactor, int &secondFactor){
	cout 	<< "  " << firstFactor << "    times " << secondFactor
			<< "      equals " << (firstFactor * secondFactor) << "\n\n";
	clock_t startTime = clock();
	int delayTimer = 0;
	while (delayTimer < 4){
		clock_t endTime = clock ();
		delayTimer = (endTime - startTime) / CLK_TCK;
	}
}

void inTime(int &firstFactor, int &secondFactor,
	int &userAnswer, int &numRight, int &numWrong, int &cumRight, int &cumWrong,
	int &cumProblems){
	// user answered in time
	if (userAnswer == (firstFactor * secondFactor)){
	rightAnswer(numRight, cumRight, cumProblems);
	}
	else {
		wrongAnswer(numWrong, cumWrong, cumProblems, firstFactor, secondFactor);
	}
}

void rightAnswer(int &numRight, int &cumRight, int &cumProblems){
	// user gets credit for correct answer
	cout << "  Right!\n\n";
	numRight = numRight + 1;
	cumRight = cumRight + 1;
	cumProblems = cumProblems + 1;
}

void wrongAnswer(int &numWrong, int &cumWrong, int &cumProblems,
	int &firstFactor, int &secondFactor){
	// user got it wrong
	numWrong = numWrong + 1;
	cumWrong = cumWrong + 1;
	cumProblems = cumProblems + 1;
	cout 	<< "  Sorry, " << firstFactor << " times " << secondFactor
			<< " equals " << (firstFactor * secondFactor) << "\n\n";
	clock_t startTime = clock();
	int delayTimer = 0;
	while (delayTimer < 4){
		clock_t endTime = clock();
		delayTimer = (endTime - startTime) / CLK_TCK;
	}
}
