#ifndef SaveToDataBase
#define SaveToDataBase

/*
*	Here's a function which is used to save info form StudentBook map to DataSave.txt 
*	The format of a save is as follows:
*	ID    ; ISBN          ; Date of Issuing          ; Date to Return by        @ 
*	e.g
*	12345 ; 9780553283686 ; Fri_17:16:38_7_Jun_2024  ; Sat_17:16:38_22_Jun_2024 @
*	87655 ; 9780812511819 ; Mon_17:05:45_12_Feb_2024 ; Tue_17:06:36_27_Feb_2024 @
*/

#include "SaveToDatabase.h"
using namespace start;

void SaveToDatabase(map<string, Book> sb) {
	if (sb.find("") != sb.end())
		sb.erase(sb.find(""));
	fstream dataSave("DataSave.txt");
	try
	{
		if (!(dataSave.is_open()))
			throw "not open";
	}
	catch (...) {
		cout << "The file hasn't been opened properly!" << endl;
	}
	for (auto item : sb)
	{
		if (item.second.Get_Title() == "---")
		{
		}
		else
		{
			dataSave << item.first << ";" << item.second.Get_Isbn() << ";";
			string pom = item.second.Get_DateOfIssuing();
			pom.erase(pom.end() - 1);
			dataSave << pom << ";";
			pom = item.second.Get_DateToReturnBy();
			pom.erase(pom.end() - 1);
			dataSave << pom << "@\n";
		}
	}
	dataSave.close();
}
#endif