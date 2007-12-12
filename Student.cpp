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
	readStrObj = getName();
	readStrObj += ".dat";
	char readStr[MAX_NAME + 5];
	strcpy(readStr, readStrObj.c_str());
	userdatFob.open(readStr, ios::in);
	if(!userdatFob)
	{
		cout << endl << "Could not open userdatFob";
		cout << endl;
		userdatFob.clear();
	}
	else
	{
		int ctr = 0;
		userdatFob.getline(readStr, MAX_NAME + 1, '~');
		name = readStrObj;
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
		for(int i=0;i<addTemplateArr[0].getObjCnt();i++)
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
			addTemplateArr[i].setObjCnt(atoi(readStr));
		}
		for(int i=0;i<subTemplateArr[0].getObjCnt();i++)
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
			subTemplateArr[i].setObjCnt(atoi(readStr));
		}
		for(int i=0;i<mltTemplateArr[0].getObjCnt();i++)
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
			mltTemplateArr[i].setObjCnt(atoi(readStr));
		}
			userdatFob.clear();
			userdatFob.close();
	}
		
}
void Student::writeUserDat(fstream & userdatFob)
{
	string writeStrObj;
	writeStrObj = getName();
	writeStrObj += ".dat";
	char writeStr[MAX_NAME + 5];
	strcpy(writeStr, writeStrObj.c_str());
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
