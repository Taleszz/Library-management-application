#ifndef LoadFromReserve
#define LoadFromReserve

/*
*	This function is used to load information from ReserveData.txt to Collection collection in oreder 
*	to enrich it by adding info about reservation
*/

#include "LoadFromReserve.h"

using namespace start;
Collection LoadReserve(Collection c)
{

	vector<string> input = { "o","o","o","o" };
	string inp = "o";
	fstream data("ReserveData.txt");
	try
	{
		if (!(data.is_open()))
			throw "not open";
	}
	catch (...)
	{
		cout << "ERROR - The file hasn't been opened properly!" << endl;
		return c;
	}

	if (!data.peek())
	{
		//cout << "error mepty file - reservation" << endl;
		return c;
	}
	else
	{
		char pom = 'o';
		while (!data.eof()) {
			inp.clear();
			input.clear();
			for (int i = 0; i < 3; i++)
			{
				do
				{
					data >> pom;
					if (pom)
						inp.push_back(pom);
				} while (pom != ';' && pom != '@');
				inp.pop_back();
				input.push_back(inp);

				inp.clear();

			}

			string reservation = input[0];
			string isbn = input[1];
			string DateOfReservation = input[2];
			c.SetDayReserved(isbn,DateOfReservation);
			//c.GetCollection()[isbn].Set_DayOfReservation(DateOfReservation);
			c.SetReserved(isbn,reservation);
		}
		data.close();
		return c;
	}
}
#endif
