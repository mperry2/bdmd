// CISP400 Ch15pc1
// Term Project Big Daddy's Math Drills
// Professor Tim Wei
// Team Charlie
//
// Files needed to build project:
//	 	bdmd.cpp - This file. Contains main().
// 		Student.h - Specificiation and implementation
// 				of the Student class.
// 		add.cpp - The entrypoint for the addition module.
// 		sub.cpp - The entrypoint for the subtraction module.
// 		mlt.cpp - The entrypoint for the multiplication module.
//
// Revision History:
//		Begun 20071117
// 		Finished, tested, and turned in ---

#include "Student.h"
using namespace std;

void printAddTemplateArr(Student & s);

int main()
{
	Student s;
	cout << endl
		<< "s.name: " << s.getName() << endl
		<< "s.addLevel: " << s.getAddLevel() << endl
		<< "s.subLevel: " << s.getSubLevel() << endl
		<< "s.mltLevel: " << s.getMltLevel() << endl
		<< "s.divLevel: " << s.getDivLevel() << endl
		<< "s.addSpeed: " << s.getAddSpeed() << endl
		<< "s.subSpeed: " << s.getSubSpeed() << endl
		<< "s.mltSpeed: " << s.getMltSpeed() << endl
		<< "s.divSpeed: " << s.getDivSpeed() << endl
		<< "s.addTemplateArr: " << s.getAddTemplateArr() << endl
		<< "s.subTemplateArr: " << s.getSubTemplateArr() << endl
		<< "s.mltTemplateArr: " << s.getMltTemplateArr() << endl
		<< "s.divTemplateArr: " << s.getDivTemplateArr() << endl;
	s.makeAddTemplateArr();
	cout << endl
		<< "Any key to print or q to quit: " << endl;
	char wantPrint = 'y';
	wantPrint = getchar();
	while(wantPrint != 'q')
	{	
		cout << endl
			<< "Addlevel: " << endl;
		int level;
		cin >> level;
		s.setAddLevel(level);		
		printAddTemplateArr(s);
	}
	return 0;
}

void printAddTemplateArr(Student & s)
{
	cout << endl
		<< "addTemplateArr.objCnt: " << s.getAddTemplateArr()[0].getObjCnt() << endl;
	//for(int i=0;i<s.getAddTemplateArr()[0].getObjCnt();i++)
	int numUsed = (s.getAddLevel() + 1) * (s.getAddLevel() + 1);
	for(int i=0;i<numUsed;i++)
	{
		cout << "s.addTemplateArr[" << i << "].firstAddend: " << s.getAddTemplateArr()[i].getFirstAddend() << endl;
		cout << "s.addTemplateArr[" << i << "].secondAddend: " << s.getAddTemplateArr()[i].getSecondAddend() << endl;
		cout << "s.addTemplateArr[" << i << "].sum: " << s.getAddTemplateArr()[i].getSum() << endl;
	}
}


