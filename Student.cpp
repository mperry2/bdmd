#include <fstream>
#include "Student.h"
#include "vkit.h"

using namespace std;

int AddTemplate::objCnt = 0;
int SubTemplate::objCnt = 0;
int MltTemplate::objCnt = 0;
int DivTemplate::objCnt = 0;

void Student::readUserDat(fstream & userdatFob)
{
	string readStrObj;
	string nameStrObj;
	char readStr[MAX_NAME + 5];
	int numUniqueAddTemplates;
	int numUniqueSubTemplates;
	int numUniqueMltTemplates;
	int numUniqueDivTemplates;
	nameStrObj = getName();
	readStrObj = nameStrObj;
	readStrObj += ".dat";
	strcpy(readStr, readStrObj.c_str());
	userdatFob.clear();
	userdatFob.open(readStr, ios::in);
	if(!userdatFob)
	{
		cout << endl << "Could not open userdatFob";
		cout << endl;
		userdatFob.clear();
	}
	else
	{
		userdatFob.getline(readStr, MAX_NAME + 1, '~');
		name = nameStrObj;
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
		numUniqueAddTemplates = (MAX_ADDEND + 1) * (MAX_ADDEND + 1);
		for(int i=0;i<numUniqueAddTemplates;i++)
		{
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			addTemplateArr[i].setFrequency(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			addTemplateArr[i].setFirstAddend(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			addTemplateArr[i].setSecondAddend(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			addTemplateArr[i].setSum(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			addTemplateArr[i].setAddTemplateNdx(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			addTemplateArr[i].setObjCnt(atoi(readStr));
		}
		numUniqueSubTemplates = (((MAX_MINUEND + 1) * (MAX_MINUEND + 1)) / 2) + (MAX_MINUEND / 2) + 1;
		for(int i=0;i<numUniqueSubTemplates;i++)
		{
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			subTemplateArr[i].setFrequency(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			subTemplateArr[i].setMinuend(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			subTemplateArr[i].setSubtrahend(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			subTemplateArr[i].setDifference(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			subTemplateArr[i].setSubTemplateNdx(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			subTemplateArr[i].setObjCnt(atoi(readStr));
		}
		numUniqueMltTemplates = (MAX_FACTOR + 1) * (MAX_FACTOR + 1);
		for(int i=0;i<numUniqueMltTemplates;i++)
		{
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			mltTemplateArr[i].setFrequency(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			mltTemplateArr[i].setFirstFactor(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			mltTemplateArr[i].setSecondFactor(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			mltTemplateArr[i].setProduct(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			mltTemplateArr[i].setMltTemplateNdx(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			mltTemplateArr[i].setObjCnt(atoi(readStr));
		}
		numUniqueDivTemplates = (MAX_FACTOR + 1) * (MAX_FACTOR); // no division by zero
		for(int i=0;i<numUniqueDivTemplates;i++)
		{
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			divTemplateArr[i].setFrequency(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			divTemplateArr[i].setFirstFactor(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			divTemplateArr[i].setSecondFactor(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			divTemplateArr[i].setProduct(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			divTemplateArr[i].setDivTemplateNdx(atoi(readStr));
			userdatFob.getline(readStr, MAX_NAME + 1, '~');
			divTemplateArr[i].setObjCnt(atoi(readStr));
		}
			userdatFob.clear();
			userdatFob.close();
		if(!userdatFob)
		{
			cout << endl << "Unable to close userdatFile in Student.cpp.";
		}
	}
		
}
void Student::writeUserDat(fstream & userdatFob)
{
	string writeStrObj;
	string nameStrObj;
	char writeStr[MAX_NAME + 5];
	int numUniqueAddTemplates;
	int numUniqueSubTemplates;
	int numUniqueMltTemplates;
	int numUniqueDivTemplates;
	
	nameStrObj = getName();
	writeStrObj = nameStrObj;
	writeStrObj += ".dat";
	strcpy(writeStr, writeStrObj.c_str());
	userdatFob.clear();
	userdatFob.open(writeStr, ios::out);
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
	numUniqueAddTemplates = (MAX_ADDEND + 1) * (MAX_ADDEND + 1);
	for(int i=0;i<numUniqueAddTemplates;i++)
	{
		userdatFob << addTemplateArr[i].getFrequency() << '~'
			<< addTemplateArr[i].getFirstAddend() << '~'
			<< addTemplateArr[i].getSecondAddend() << '~'
			<< addTemplateArr[i].getSum() << '~'
			<< addTemplateArr[i].getAddTemplateNdx() << '~'
			<< addTemplateArr[i].getObjCnt() << '~';
	}
	numUniqueSubTemplates = (((MAX_MINUEND + 1) * (MAX_MINUEND + 1)) / 2) + (MAX_MINUEND / 2) + 1;
	for(int i=0;i<numUniqueSubTemplates;i++)
	{
		userdatFob << subTemplateArr[i].getFrequency() << '~'
			<< subTemplateArr[i].getMinuend() << '~'
			<< subTemplateArr[i].getSubtrahend() << '~'
			<< subTemplateArr[i].getDifference() << '~'
			<< subTemplateArr[i].getSubTemplateNdx() << '~'
			<< subTemplateArr[i].getObjCnt() << '~';
	}
	numUniqueMltTemplates = (MAX_FACTOR + 1) * (MAX_FACTOR + 1);
	for(int i=0;i<numUniqueMltTemplates;i++)
	{
		userdatFob << mltTemplateArr[i].getFrequency() << '~'
			<< mltTemplateArr[i].getFirstFactor() << '~'
			<< mltTemplateArr[i].getSecondFactor() << '~'
			<< mltTemplateArr[i].getProduct() << '~'
			<< mltTemplateArr[i].getMltTemplateNdx() << '~'
			<< mltTemplateArr[i].getObjCnt() << '~';
	}
	numUniqueDivTemplates = (MAX_FACTOR + 1) * (MAX_FACTOR);
	for(int i=0;i<numUniqueDivTemplates;i++)
	{
		userdatFob << divTemplateArr[i].getFrequency() << '~'
			<< divTemplateArr[i].getFirstFactor() << '~'
			<< divTemplateArr[i].getSecondFactor() << '~'
			<< divTemplateArr[i].getProduct() << '~'
			<< divTemplateArr[i].getDivTemplateNdx() << '~'
			<< divTemplateArr[i].getObjCnt() << '~';
	}
	userdatFob.clear();
	userdatFob.close();
	if(!userdatFob)
	{
		cout << endl << "Unable to close userdatFile in Student.cpp.";
	}
}
