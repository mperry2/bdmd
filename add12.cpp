// This is version 1.2 of Big Daddy's Addition Drills,
// the standalone addition program
// that I wrote several years ago in qbasic
// and translated into c++ translation without improvements.
// I have uploaded it to the repository so you 
// can look at it if you want for ideas.
// You can check it out, but don't commit any changes to this file to
// the repository.  Instead, please check out trunk/add.cpp
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

int getBiggestSum();
int getSeconds(int &percentRight, int &numSeconds, const int &SET_SIZE, int &biggestSum);
void inTime(int &firstAddend, int &secondAddend,
	int &userAnswer, int &numRight, int &numWrong, int &cumRight, int &cumWrong,
	int &cumProblems);
void rightAnswer(int &numRight, int &cumRight, int &cumProblems);
void wrongAnswer(int &numWrong, int &cumWrong, int &cumProblems,
	int &firstAddend, int &secondAddend);
void displayRightAnswer(int &firstAddend, int &secondAddend);
void doSet(int &biggestSum, int &numSeconds, int &cumRight, int &cumWrong,
	int &cumProblems, int &percentRight, const int &SET_SIZE);
void tooLong(int &numSeconds, int &numWrong, int &cumWrong, int &cumProblems,
	int &firstAddend, int &secondAddend, int &userAnswer);
void wantMore(int &biggestSum, int &numSeconds, int &cumRight, int &cumWrong,
	int &cumProblems, int &percentRight, const int &SET_SIZE);

main(){
	int biggestSum, numSeconds = 6;
	int cumRight = 0,	cumWrong = 0, cumProblems = 0;
	float percentRight = 0;
	const int SET_SIZE = 50;

	randomize();
	char moreProblems = 'y';
	cout	<< "  Hello.  This is Big Daddy DiCarlo's Addition Drill, version 1.2\n"
			<< "  Version 1.2 has been re-written in C++ and runs in a window\n"
			<< "  under Windows XP and, presumably, other versions of Windows.\n\n"

			<< "  There are 50 addition problems in each set.\n\n"

			<<	"  You start with 6 seconds for each problem, but when your\n"
			<< "  accuracy reaches 94 or 96 percent for a set, the allowed time is\n"
			<< "  reduced by one or two seconds respectively.\n\n"

			<< "  When you see each problem, just type the answer and press return.\n\n"

			<< "  If, when the program asks you for a number, you try to enter\n"
			<< "  a noninteger character, the program may look\n"
			<< "  like it's going bazoo. To quit then or at any time\n"
			<< "  press alt-F4 or close the window with your mouse.\n\n";

	biggestSum = getBiggestSum();
	doSet(biggestSum, numSeconds, cumRight, cumWrong, cumProblems, percentRight, SET_SIZE);
	cout	<< "  Thank you for playing Big Daddy DiCarlo's Addition Drill.\n\n"
			<< "  You can get updates and other shareware, including\n"
			<< "  Big Daddy DiCarlo's subtraction and multiplication drills,\n"
			<< "  at www.dicarlolaw.com/shareware.html";
return 0;
}

getBiggestSum(){
	int valid = 0;
	int biggestSum;
	while (valid == 0){
		cout	<< "  How big is the biggest sum you want to compute (4-99)? ";
		cin >> biggestSum;
		cout << "\n";
		if ((biggestSum < 100)  && (biggestSum  > 3)){
			valid = 1;
		}
		else {
			cout	<< "  Please select a number from 4 to 99 as the largest \n"
					<< "  sum to compute.\n\n";
		}
		continue;
	}
	return biggestSum;
}

getSeconds(int &percentRight, int &numSeconds, const int &SET_SIZE, int &biggestSum){
	if ((numSeconds == 2) && (percentRight >= 94)){
		cout 	<< "  Terrific!!!\n\n"
				<< "  You got " << percentRight << " % right with only 2 seconds\n"
				<< "  per problem.\n\n"
				<< "  You are ready to move on to sums up to "
				<< (biggestSum + 1) << ".\n\n"
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

void doSet(int &biggestSum, int &numSeconds, int &cumRight, int &cumWrong,
	int &cumProblems, int &percentRight, const int &SET_SIZE){
	int numRight = 0, numWrong = 0, maxLeft = biggestSum;
	int randomNum, firstAddend, secondAddend, userAnswer;
	float timeElapsed;

	numSeconds = getSeconds(percentRight, numSeconds, SET_SIZE, biggestSum);
	cout << "You will have " << numSeconds << " seconds to answer each problem in this set.\n\n";
	for (int i = 1; i <= SET_SIZE; i++){
		randomNum = random(maxLeft + 1);
		firstAddend = randomNum;
		maxLeft = biggestSum - firstAddend;
		randomNum = random(maxLeft + 1);
		secondAddend = randomNum;
		cout	<< "    " << firstAddend << "  +  " << secondAddend << "  =  " ;
		clock_t startTime, endTime;
		startTime = clock();
		cin >> userAnswer;
		cout << "\n";
		endTime = clock();
		timeElapsed = (endTime - startTime) / CLK_TCK;
		if (timeElapsed > numSeconds){
			tooLong(numSeconds, numWrong, cumWrong, cumProblems, firstAddend,
				secondAddend, userAnswer);
		}
		else {
			inTime(firstAddend, secondAddend, userAnswer, numRight,
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
	wantMore(biggestSum, numSeconds, cumRight, cumWrong, cumProblems, percentRight, SET_SIZE);
}

void wantMore(int &biggestSum, int &numSeconds, int &cumRight, int &cumWrong,
	int &cumProblems, int &percentRight, const int &SET_SIZE){
	char moreProblems;
	cout << "  Do you want to add another 50 problems (y or n)? ";
	cin >> moreProblems;
	cout << "\n\n";
	if (moreProblems == 'y'){
		doSet(biggestSum, numSeconds, cumRight, cumWrong, cumProblems, percentRight, SET_SIZE);
	}
}

void tooLong(int &numSeconds, int &numWrong, int &cumWrong, int &cumProblems,
	int &firstAddend, int &secondAddend, int &userAnswer){
	// User took too long.
	cout << "  Sorry, you didn't answer within " << numSeconds << " seconds.\n\n";
	numWrong = numWrong + 1;
	cumWrong = cumWrong + 1;
	cumProblems = cumProblems + 1;
	if (userAnswer != (firstAddend + secondAddend)){
		// user also got it wrong
		cout 	<< "  Also, " << firstAddend << " plus " << secondAddend
			<< " equals " << (firstAddend + secondAddend) << "\n\n";
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

void displayRightAnswer(int &firstAddend, int &secondAddend){
	cout 	<< "  " << firstAddend << "    plus " << secondAddend
			<< "      equals " << (firstAddend + secondAddend) << "\n\n";
	clock_t startTime = clock();
	int delayTimer = 0;
	while (delayTimer < 4){
		clock_t endTime = clock ();
		delayTimer = (endTime - startTime) / CLK_TCK;
	}
}

void inTime(int &firstAddend, int &secondAddend,
	int &userAnswer, int &numRight, int &numWrong, int &cumRight, int &cumWrong,
	int &cumProblems){
	// user answered in time
	if (userAnswer == (firstAddend + secondAddend)){
	rightAnswer(numRight, cumRight, cumProblems);
	}
	else {
		wrongAnswer(numWrong, cumWrong, cumProblems, firstAddend, secondAddend);
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
	int &firstAddend, int &secondAddend){
	// user got it wrong
	numWrong = numWrong + 1;
	cumWrong = cumWrong + 1;
	cumProblems = cumProblems + 1;
	cout 	<< "  Sorry, " << firstAddend << " plus " << secondAddend
			<< " equals " << (firstAddend + secondAddend) << "\n\n";
	clock_t startTime = clock();
	int delayTimer = 0;
	while (delayTimer < 4){
		clock_t endTime = clock();
		delayTimer = (endTime - startTime) / CLK_TCK;
	}
}

