#ifndef LoadFromDatabase
#define LoadFromDatabase

/*
*	This function is used to load information from DataSave.txt to map<string,Book> StudentBook
*/

#include "LoadFromDatabase.h"
using namespace start;

map<string, Book> LoadFromFile(map<string, Book> d, string file, Collection c)
{
	vector<string> input = {"o","o","o","o"};
	string inp = "o";
	fstream data(file);
	try
	{
		if (!(data.is_open()))
			throw "not open";
	}
	catch (...)
	{
		cout << "ERROR - The file hasn't been opened properly!" << endl;
		return d;
	}
	if (!data.peek())
	{
		cout << "error mepty file - database" << endl;
		return d;
	}
	else
	{
		char pom = 'o';
		while (!data.eof()) {
			inp.clear();
			input.clear();
			for (int i = 0; i < 4; i++)
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
			string id = input[0];
			string isbn = input[1];
			string DOI = input[2];
			string DOR = input[3];
			d[id].Set_Isbn(isbn);
			d[id].Set_Pages(c.GetCollection()[isbn].Get_Pages());
			d[id].Set_Title(c.GetCollection()[isbn].Get_Title());
			d[id].Set_DateOfIssuing(DOI + "\n");
			d[id].Set_DateToReturnBy(DOR + "\n");
			d[id].Set_Is_checked("Yes");
		}
		d.erase(d.find(""));
		data.close();
		return d;
	}
}
#endif