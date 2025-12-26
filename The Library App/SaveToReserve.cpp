#ifndef SaveToRes
#define SaveToRes

/*
*	Function simmilar to what you can find in SaveToDatabase.h
*	It's used to save the info about reservation to ReserveData.txt
*/


#include "SaveToReserve.h"

using namespace start;



void SaveToReserve(Collection c, Date d) {
	fstream dataSave("ReserveData.txt");
	try
	{
		if (!(dataSave.is_open()))
			throw "not open";
	}
	catch (...) {
		cout << "The file hasn't been opened properly!" << endl;
	}
	for (auto item : c.GetCollection())
	{
		if (item.second.Get_Reserved() != "No" && (item.first != ""))
		{
			auto isbn = item.first;
			//Format - Reservation ; ISBN : Date_of_Reservation @
			dataSave << c.GetCollection()[isbn].Get_Reserved() << ";" << item.second.Get_Isbn() << ";";
			dataSave << c.GetCollection()[isbn].Get_DayOfReservation() <<"@\n";
		}
	}
	dataSave.close();
}
#endif