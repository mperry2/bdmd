// Big Daddy's Math Drills
// Version 2.0 released January 2008
//
// Big Daddy's Math Drills Copyright 1998, 2003, 2007 Vincent DiCarlo
//
// Files inluded in the sourcecode distribution:
// 		add.cpp - The the addition module.
//	 	bdmd.cpp - Contains main().
//		copying.txt - The Gnu general public license.
// 		div.cpp - The division module.
// 		makefile - The gcc makefile.
// 		mlt.cpp - The multiplication module.
// 		readme - Instructions, notes, legal.
// 		Student.cpp - Implementation for Student class
// 		Student.h - Specificiation and implementation
// 				of the Student class.
// 		sub.cpp - The subtraction module.
// 		vkit.cpp - Utilities.
// 		vkit.h - Header for vkit.cpp.
//
// 	Binaries released:
//		bdmd - Linux executable.
//		bdmd.exe - MS Windows executable.
//
// Revision History:
// 		Version 1.0 released March 1998
// 		Version 1.2 released December 2003
//
// Version notes:
// 		This version has very little in the way
// 		of input validation and error checking
// 		and uses more memory and disk space
// 		than it would if it were modified so
// 		that it only created and saved templates
// 		needed for the current level of the user,
// 		but it is feature complete.  It was
// 		compiled with gcc and tested under Suse 
// 		Linux 10.3 and compiled with MS Visual
// 		Studio and tested under WinXP.
//
// License:
//		This file, and all the other files in this
//		distribution as described above, including 
//		the binaries released, are part of Big 
//		Daddy's Math Drills.  Big Daddy's Math Drills 
//		is free software: you can redistribute it 
//		and/or modify it under the terms of the GNU 
//		General Public License as published by the 
//		Free Software Foundation, either version 3
//		of the License, or (at your option) any 
//		later version.
//
//		Big Daddy's Math Drills is distributed
//		in the hope that it will be useful,	but 
//		WITHOUT ANY WARRANTY; without even the 
//		implied warranty of MERCHANTABILITY or 
//		FITNESS FOR A PARTICULAR PURPOSE.  See 
//		the GNU General Public License for more 
//		details.
//
//		You should have received a copy of the GNU
//		General Public License along with Big 
//		Daddy's Math Drills.  If not, see 
//		<http://www.gnu.org/licenses/>.

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
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
const int MAX_NAME = 40;

class ProblemTemplate
{
	protected:
		int frequency;
	public:
		ProblemTemplate()
		{
			frequency = 20; // how many copies to put in the bag
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
		int addTemplateNdx;
		static int objCnt; // improve in revision
	public:
		AddTemplate()
		{
			objCnt++;
			firstAddend = -1;
			secondAddend = -1;
			sum = firstAddend + secondAddend;
			addTemplateNdx = objCnt -1; // improve in revision
		}
		AddTemplate(int fa, int sa) // not used
		{
			objCnt++;
			firstAddend = fa;
			secondAddend = sa;
			sum = firstAddend + secondAddend;
			addTemplateNdx = objCnt -1;
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
		int getAddTemplateNdx()
		{
			return addTemplateNdx;
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
		void setAddTemplateNdx(int n)
		{
			addTemplateNdx = n;
		}
		void setObjCnt(int o)
		{
			objCnt = o;
		}
};

class SubTemplate : public ProblemTemplate
{
	protected:
		int minuend;
		int subtrahend;
		int difference;
		int subTemplateNdx;
		static int objCnt;
	public:
		SubTemplate()
		{
			objCnt++;
			minuend = -1;
			subtrahend = -1;
			difference = minuend - subtrahend;
			subTemplateNdx = objCnt - 1;
		}
		SubTemplate(int m, int s)
		{
			objCnt++;
			minuend = m;
			subtrahend = s;
			difference = minuend - subtrahend;
			subTemplateNdx = objCnt - 1;
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
		int getSubTemplateNdx()
		{
			return subTemplateNdx;
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
		void setSubTemplateNdx(int n)
		{
			subTemplateNdx = n;
		}
		void setObjCnt(int o)
		{
			objCnt = o;
		}
};

class MltTemplate : public ProblemTemplate
{
	protected:
		int firstFactor;
		int secondFactor;
		int product;
		int mltTemplateNdx;
		static int objCnt;
	public:
		MltTemplate()
		{
			objCnt++;
			firstFactor = -1;
			secondFactor = 500;
			product = firstFactor * secondFactor;
			mltTemplateNdx = objCnt - 1;
		}
		MltTemplate(int ff, int sf)
		{
			objCnt++;
			firstFactor = ff;
			secondFactor = sf;
			product = firstFactor * secondFactor;
			mltTemplateNdx = objCnt - 1;
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
		int getMltTemplateNdx()
		{
			return mltTemplateNdx;
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
		void setMltTemplateNdx(int n)
		{
			mltTemplateNdx = n;
		}
		void setObjCnt(int o)
		{
			objCnt = o;
		}
};
		
class DivTemplate : public ProblemTemplate
{
	protected:
		int firstFactor; // used for denominator
		int secondFactor; // quotient
		int product; // numerator
		int divTemplateNdx;
		static int objCnt;
	public:
		DivTemplate()
		{
			objCnt++;
			firstFactor = -1;
			secondFactor = 500;
			product = firstFactor * secondFactor;
			divTemplateNdx = objCnt - 1;
		}
		DivTemplate(int ff, int sf)
		{
			objCnt++;
			firstFactor = ff;
			secondFactor = sf;
			product = firstFactor * secondFactor;
			divTemplateNdx = objCnt - 1;
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
		int getDivTemplateNdx()
		{
			return divTemplateNdx;
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
		void setDivTemplateNdx(int n)
		{
			divTemplateNdx = n;
		}
		void setObjCnt(int o)
		{
			objCnt = o;
		}
};

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
			name = "vincent";
			addLevel = 2;
			prevAddLevel = 0;
			subLevel = 4;
			prevSubLevel = 0;
			mltLevel = 2;
			prevMltLevel = 0;
			divLevel = 2;
			prevDivLevel = 0;
			addSpeed = 6;
			subSpeed = 6;
			mltSpeed = 6;
			divSpeed = 6;
		}
		Student(string ns, int al = 2, int sl = 4, int ml = 2, int dl = 2, int as = 6, int ss = 6, int ms = 6, int ds = 6) // not used
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
		void setName(string n)
		{
			name = n;
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
			for(int l=0; l<=MAX_ADDEND;l++) // for the row (fa) corresponding to each level
			{
				int fa;
				int sa;
				fa = l;
				for(sa=0;sa<=l;sa++) // fill in the row to the col for the current level
				{
					int s = fa + sa;
					addTemplateArr[ndx].setFirstAddend(fa);
					addTemplateArr[ndx].setSecondAddend(sa);
					addTemplateArr[ndx].setSum(s);
					ndx++;
				}
				sa = l;
				for(fa=0;fa<l;fa++) // fill in the column for the current level to the current row
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
			// puts vals in arr for each level sequentially
			int numUniqueProblems = (MAX_FACTOR + 1) * (MAX_FACTOR + 1);
			mltTemplateArr = new MltTemplate[numUniqueProblems];
			int ndx = 0;
			for(int l=0; l<=MAX_FACTOR;l++)
			{
				int ff;
				int sf;
				ff = l;
				for(sf=0;sf<=l;sf++)
				{
					int p = ff * sf;
					mltTemplateArr[ndx].setFirstFactor(ff);
					mltTemplateArr[ndx].setSecondFactor(sf);
					mltTemplateArr[ndx].setProduct(p);
					ndx++;
				}
				sf = l;
				for(ff=0;ff<l;ff++)
				{
					int p = ff * sf;
					mltTemplateArr[ndx].setFirstFactor(ff);
					mltTemplateArr[ndx].setSecondFactor(sf);
					mltTemplateArr[ndx].setProduct(p);
					ndx++;
				}
			}
		}
		void makeDivTemplateArr(Student & s)
		{
			// puts vals in arr for each level sequentially
			int numUniqueProblems = (MAX_FACTOR + 1) * (MAX_FACTOR); // no zero denominators
			divTemplateArr = new DivTemplate[numUniqueProblems];
			int ndx = 0;
			for(int l=1; l<=MAX_FACTOR;l++)
			{
				int ff;
				int sf;
				ff = l;
				for(sf=0;sf<=ff;sf++)
				{
					int p = ff * sf;
					divTemplateArr[ndx].setFirstFactor(ff); // firstFactor = denominator
					divTemplateArr[ndx].setSecondFactor(sf); // secondFactor = quotient
divTemplateArr[ndx].setProduct(p); // product = numerator
					ndx++;
				}
				sf = ff;
				for(ff=1;ff<l;ff++) // denominator can't be zero
				{
					int p = ff * sf;
					divTemplateArr[ndx].setFirstFactor(ff);
					divTemplateArr[ndx].setSecondFactor(sf);
					divTemplateArr[ndx].setProduct(p);
					ndx++;
				}
			}
		}
		void readUserDat(fstream & userdatFob);
		void writeUserDat(fstream & userdatFob);
};
#endif

