// CISP400 Ch15pc1
// Term Project Big Daddy's Math Drills
// Professor Tim Wei
// Team Charlie
//
// Files needed to build project:
//	 	bdmd.cpp - Contains main().
// 		Student.h - This file.  Specificiation and implementation
// 				of the Student class.
// 		add.cpp - The entrypoint for the addition module.
// 		sub.cpp - The entrypoint for the subtraction module.
// 		mlt.cpp - The entrypoint for the multiplication module.
//
// Revision History:
//		Begun 20071117
// 		Finished, tested, and turned in ---

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Student;
class ProblemTemplate;
class AddTemplate;
class SubTemplate;
class MltTemplate;
class DivTemplate;

const int MAX_ADDEND = 100;
const int MAX_MINUEND = 100;
const int MAX_FACTOR = 20;
const int MAX_NUMERATOR = 400;

class ProblemTemplate
{
	protected:
		int frequency;
	public:
		ProblemTemplate()
		{
			frequency = 10;
		}
		int getFrequency()
		{
			return frequency;
		}
		void setFrequency(int freq)
		{
			frequency = freq;
		}
};

class AddTemplate : public ProblemTemplate
{
	protected:
		int firstAddend;
		int secondAddend;
		int sum;
		static int objCnt;
	public:
		AddTemplate()
		{
			objCnt++;
			firstAddend = -1;
			secondAddend = -1;
			sum = firstAddend + secondAddend;
		}
		AddTemplate(int fa, int sa)
		{
			objCnt++;
			firstAddend = fa;
			secondAddend = sa;
			sum = firstAddend + secondAddend;
		}
		int getFirstAddend()
		{
			return firstAddend;
		}
		int getSecondAddend()
		{
			return secondAddend;
		}
		int getSum()
		{
			return sum;
		}
		int getObjCnt()
		{
			return objCnt;
		}
		void setFirstAddend(int fa)
		{
			firstAddend = fa;
		}
		void setSecondAddend(int sa)
		{
			secondAddend = sa;
		}
		void setSum(int s)
		{
			sum = s;
		}
};
int AddTemplate::objCnt = 0;

class SubTemplate : public ProblemTemplate
{
	protected:
		static int objCnt;
		int minuend;
		int subtrahend;
		int difference;
	public:
		SubTemplate()
		{
			objCnt++;
			minuend = -1;
			subtrahend = -1;
			difference = minuend - subtrahend;
		}
		SubTemplate(int m, int s)
		{
			objCnt++;
			minuend = m;
			subtrahend = s;
			difference = minuend - subtrahend;
		}
};
int SubTemplate::objCnt = 0;

class MltTemplate : public ProblemTemplate
{
	protected:
		static int objCnt;
		int firstFactor;
		int secondFactor;
		int product;
	public:
		MltTemplate()
		{
			objCnt++;
			firstFactor = -1;
			secondFactor = 500;
			product = firstFactor * secondFactor;
		}
		MltTemplate(int ff, int sf)
		{
			objCnt++;
			firstFactor = ff;
			secondFactor = sf;
			product = firstFactor * secondFactor;
		}
};
int MltTemplate::objCnt = 0;
		
class DivTemplate : public ProblemTemplate
{
	protected:
		static int objCnt;
		int numerator;
		int denominator;
		int quotient;
	public:
		DivTemplate()
		{
			objCnt++;
			numerator = -1;
			denominator = 500;
			quotient = numerator / denominator;
		}

		DivTemplate(int n, int d)
		{
			objCnt++;
			numerator = n;
			denominator = d;
			quotient = numerator / denominator;
		}
};
int DivTemplate::objCnt = 0;

class Student
{
	protected:
		string name;
		int addLevel;
		int subLevel;
		int mltLevel;
		int divLevel;
		int addSpeed;
		int subSpeed;
		int mltSpeed;
		int divSpeed;
		AddTemplate * addTemplateArr;
		SubTemplate * subTemplateArr;
		MltTemplate * mltTemplateArr;
		DivTemplate * divTemplateArr;
	public:
		Student()
		{
			name = "Harry";
			addLevel = 11;
			subLevel = 4;
			mltLevel = 2;
			divLevel = 4;
			addSpeed = 6;
			subSpeed = 6;
			mltSpeed = 6;
			divSpeed = 6;
		}
		Student(string ns, int al, int sl, int ml, int dl, int as, int ss, int ms, int ds)
		{
			name = ns;
			addLevel = al;
			subLevel = sl;
			mltLevel = ml;
			divLevel = dl;
			addSpeed = as;
			subSpeed = ss;
			mltSpeed = ms;
			divSpeed = ds;
		}
		Student(fstream & f)
		{
		}
		string getName()
		{
			return name;
		}
		int getAddLevel()
		{
			return addLevel;
		}
		int getSubLevel()
		{
			return subLevel;
		}
		int getMltLevel()
		{
			return mltLevel;
		}
		int getDivLevel()
		{
			return divLevel;
		}
		int getAddSpeed()
		{
			return addSpeed;
		}
		int getSubSpeed()
		{
			return subSpeed;
		}
		int getMltSpeed()
		{
			return mltSpeed;
		}
		int getDivSpeed()
		{
			return divSpeed;
		}
		AddTemplate * getAddTemplateArr()
		{
			return addTemplateArr;
		}
		SubTemplate * getSubTemplateArr()
		{
			return subTemplateArr;
		}
		MltTemplate * getMltTemplateArr()
		{
			return mltTemplateArr;
		}
		DivTemplate * getDivTemplateArr()
		{
			return divTemplateArr;
		}
		void setAddLevel(int al)
		{
			addLevel = al;
		}
		void setSubLevel(int sl)
		{
			subLevel = sl;
		}
		void setMltLevel(int ml)
		{
			mltLevel = ml;
		}
		void setDivLevel(int dl)
		{
			divLevel = dl;
		}
		void setAddSpeed(int as)
		{
			addSpeed = as;
		}
		void setSubSpeed(int ss)
		{
			subSpeed = ss;
		}
		void setMltSpeed(int ms)
		{
			mltSpeed = ms;
		}
		void setDivSpeed(int ds)
		{
			divSpeed = ds;
		}
		void makeAddTemplateArr()
		{
			int numUniqueProblems = (MAX_ADDEND + 1) * (MAX_ADDEND + 1);
			addTemplateArr = new AddTemplate[numUniqueProblems];
			int ndx = 0;
			for(int fa=0;fa<=addLevel;fa++)
			{
				for(int sa=0;sa<=addLevel;sa++)
				{
					int s = fa + sa;
					addTemplateArr[ndx].setFirstAddend(fa);
					addTemplateArr[ndx].setSecondAddend(sa);
					addTemplateArr[ndx].setSum(s);
					ndx++;
				}
			}
		}
		void addModule(Student & s)
		{
			//add(s);
		}
		void subModule(Student & s)
		{
		}
		void mltModule(Student & s)
		{
		}
		void divModule(Student & s)
		{
		}
		void writeStudent(Student & s)
		{
		}
};


#endif

