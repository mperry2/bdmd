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
#include <fstream>
using namespace std;

class Student;
class ProblemTemplate;
class AddTemplate;
class SubTemplate;
class MltTemplate;
class DivTemplate;

void writeUserDat(fstream & userdatFob);

const int MAX_ADDEND = 100;
const int MAX_MINUEND = 100;
const int MAX_FACTOR = 20;
const int MAX_NUMERATOR = 400;
const int MAX_NAME = 40;

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
		int minuend;
		int subtrahend;
		int difference;
		static int objCnt;
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
		int getMinuend()
		{
			return minuend;
		}
		int getSubtrahend()
		{
			return subtrahend;
		}
		int getDifference()
		{
			return difference;
		}
		int getObjCnt()
		{
			return objCnt;
		}
		void setMinuend(int m)
		{
			minuend = m;
		}
		void setSubtrahend(int s)
		{
			subtrahend = s;
		}
		void setDifference(int d)
		{
			difference = d;
		}
};
int SubTemplate::objCnt = 0;

class MltTemplate : public ProblemTemplate
{
	protected:
		int firstFactor;
		int secondFactor;
		int product;
		static int objCnt;
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
		int getFirstFactor()
		{
			return firstFactor;
		}
		int getSecondFactor()
		{
			return secondFactor;
		}
		int getProduct()
		{
			return product;
		}
		int getObjCnt()
		{
			return objCnt;
		}
		void setFirstFactor(int ff)
		{
			firstFactor = ff;
		}
		void setSecondFactor(int sf)
		{
			secondFactor = sf;
		}
		void setProduct(int p)
		{
			product = p;
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
		int prevAddLevel;
		int subLevel;
		int prevSubLevel;
		int mltLevel;
		int prevMltLevel;
		int divLevel;
		int prevDivLevel;
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
			name = "Vincent";
			addLevel = 2;
			prevAddLevel = 0;
			subLevel = 4;
			prevSubLevel = 0;
			mltLevel = 2;
			prevMltLevel = 0;
			divLevel = 4;
			prevDivLevel = 0;
			addSpeed = 6;
			subSpeed = 6;
			mltSpeed = 6;
			divSpeed = 6;
		}
		Student(string ns, int al = 2, int sl = 4, int ml = 2, int dl = 4, int as = 6, int ss = 6, int ms = 6, int ds = 6)
		{
			name = ns;
			addLevel = al;
			prevAddLevel = 0;
			subLevel = sl;
			prevSubLevel = 0;
			mltLevel = ml;
			prevMltLevel = 0;
			divLevel = dl;
			prevDivLevel = 0;
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
		void makeAddTemplateArr(Student & s)
		{
			int numUniqueProblems = (MAX_ADDEND + 1) * (MAX_ADDEND + 1);
			addTemplateArr = new AddTemplate[numUniqueProblems];
			int ndx = 0;
			for(int l=0; l<=MAX_ADDEND;l++)
			{
				int fa = l;
				for(int sa=0;sa<=l;sa++)
				{
					int s = fa + sa;
					addTemplateArr[ndx].setFirstAddend(fa);
					addTemplateArr[ndx].setSecondAddend(sa);
					addTemplateArr[ndx].setSum(s);
					ndx++;
				}
				int sa = l;
				for(int fa=0;fa<l;fa++)
				{
					int s = fa + sa;
					addTemplateArr[ndx].setFirstAddend(fa);
					addTemplateArr[ndx].setSecondAddend(sa);
					addTemplateArr[ndx].setSum(s);
					ndx++;
				}
			}
		}
		void makeSubTemplateArr(Student & s)
		{
			int numUniqueProblems = (((MAX_MINUEND + 1) * (MAX_MINUEND + 1)) / 2) + (MAX_MINUEND / 2) + 1;
			subTemplateArr = new SubTemplate[numUniqueProblems];
			int ndx = 0;
			for(int l=0; l<=MAX_MINUEND;l++)
			{
				int m = l;
				for(int s=0;s<=m;s++)
				{
					int d = m - s;
					subTemplateArr[ndx].setMinuend(m);
					subTemplateArr[ndx].setSubtrahend(s);
					subTemplateArr[ndx].setDifference(d);
					ndx++;
				}
			}
		}
		void makeMltTemplateArr(Student & s)
		{
			int numUniqueProblems = (MAX_FACTOR + 1) * (MAX_FACTOR + 1);
			mltTemplateArr = new MltTemplate[numUniqueProblems];
			int ndx = 0;
			for(int l=0; l<=MAX_FACTOR;l++)
			{
				int ff = l;
				for(int sf=0;sf<=l;sf++)
				{
					int p = ff + sf;
					mltTemplateArr[ndx].setFirstFactor(ff);
					mltTemplateArr[ndx].setSecondFactor(sf);
					mltTemplateArr[ndx].setProduct(p);
					ndx++;
				}
				int sf = l;
				for(int ff=0;ff<l;ff++)
				{
					int p = ff + sf;
					mltTemplateArr[ndx].setFirstFactor(ff);
					mltTemplateArr[ndx].setSecondFactor(sf);
					mltTemplateArr[ndx].setProduct(p);
					ndx++;
				}
			}
		}
		void writeUserDat(fstream & userdatFob)
		{
			userdatFob.open("vincent.dat", ios::out);
			userdatFob << name << '~'
				<< addLevel << '~'
				<< prevAddLevel << '~'
				<< subLevel << '~'
				<< prevSubLevel << '~'
				<< mltLevel << '~'
				<< prevMltLevel << '~'
				<< divLevel << '~'
				<< prevDivLevel << '~'
				<< addSpeed << '~'
				<< subSpeed << '~'
				<< mltSpeed << '~'
				<< divSpeed << '~';
			for(int i=0;i<addTemplateArr[0].getObjCnt();i++)
			{
				userdatFob << addTemplateArr[i].getFrequency() << '~'
					<< addTemplateArr[i].getFirstAddend() << '~'
					<< addTemplateArr[i].getSecondAddend() << '~'
					<< addTemplateArr[i].getSum() << '~'
					<< addTemplateArr[i].getObjCnt() << '~';
			}
			for(int i=0;i<subTemplateArr[0].getObjCnt();i++)
			{
				userdatFob << subTemplateArr[i].getFrequency() << '~'
					<< subTemplateArr[i].getMinuend() << '~'
					<< subTemplateArr[i].getSubtrahend() << '~'
					<< subTemplateArr[i].getDifference() << '~'
					<< subTemplateArr[i].getObjCnt() << '~';
			}
			for(int i=0;i<mltTemplateArr[0].getObjCnt();i++)
			{
				userdatFob << mltTemplateArr[i].getFrequency() << '~'
					<< mltTemplateArr[i].getFirstFactor() << '~'
					<< mltTemplateArr[i].getSecondFactor() << '~'
					<< mltTemplateArr[i].getProduct() << '~'
					<< mltTemplateArr[i].getObjCnt() << '~';
			}
			userdatFob.clear();
			userdatFob.close();
		}
		void readUserDat(fstream & userdatFob)
		{
			string readStrObj;
			char readStr[MAX_NAME + 1];
			userdatFob.open("vincent", ios::in);
			if(!userdatFob)
			{
				cout << endl << "Could not open userdatFob";
				cout << endl;
				userdatFob.clear();
			}
			else
			{
				while(!userdatFob.eof())
				{
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					name = readStr;
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					addLevel = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					prevAddLevel = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					subLevel = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					prevSubLevel = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					mltLevel = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					prevMltLevel = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					divLevel = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					prevDivLevel = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					addSpeed = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					subSpeed = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					mltSpeed = atoi(readStr);
					userdatFob.getline(readStr, MAX_NAME + 1, '~');
					divSpeed = atoi(readStr);
				}
			}
		}
};
#endif

