#ifndef LoadFromCollection
#define LoadFromCollection

/*
*	Here's a class which is used to store current colllection of books in the library
*	In the programme the Collection is a class
*	but the collection is of type "Collection". It is often abbrievieted to col or c in when used in functions
*	The implementation of it is quite poor as of now because it looks like:
*		1. The collection is loaded to the Collection coll using the constructor Collection() which uses
*   function map<string, Book> LoadCollection(map<string, Book>& d);
*		2. Using the Collection class the map<string,Book> StudentBook  is loaded
*		3. Another definition of Collection takes over - Collection collection and it uses the data from StudentBook map and
*		Collection coll to compare it check which books are checked
*/

#include "LoadFromCollection.h"

using namespace start;

//Function LoadFromCollection loads Whole collection of books from Data.txt 
map<string, Book> LoadCollection(map<string, Book>& d)
{
	vector<string> input;
	string inp;
	fstream data("Data.txt");
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
		//cout << "error mepty file - reservation" << endl;
		return d;
	}
	else
	{
		char pom;
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
			d[input[0]].Set_Isbn(input[0]);
			d[input[0]].Set_Title(input[1]);
			d[input[0]].Set_Pages(input[2]);
		}
		d.erase(d.find(""));
		data.close();
		return d;
	}
}

map<string, Book> LoadCollection(map<string, Book>& d, map<string, Book> sb)
{
	vector<string> input;
	string inp;
	fstream data("Data.txt");
	try
	{
		if (!(data.is_open()))
			throw "not open";
	}
	catch (...) {
		cout << "ERROR - The file hasn't been opened properly!" << endl;
		return d;
	}
	char pom;
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
		d[input[0]].Set_Isbn(input[0]);
		d[input[0]].Set_Title(input[1]);
		d[input[0]].Set_Pages(input[2]);
	}
	//d.erase(d.find(""));
	//Comparing StudentBook map with Collection map in order to find books that were checked out
	for (auto item : sb)
	{
		string isbn =item.second.Get_Isbn();
		d[isbn].Set_Is_checked("Yes");
	}


	data.close();
	return d;
}

//The definition of a class that hold all of the info about book collection of the library
	Collection::Collection() {
		col = LoadCollection(col);
	}
	Collection::Collection(map<string,Book> sb) {
		col = LoadCollection(col, sb);
	}
	map<string, Book> Collection::GetCollection()
	{
		return col;
	}
	void Collection::SetChecked(string isbn, string ic) {
		col[isbn].Set_Is_checked(ic);
	}
	void Collection::SetReserved(string isbn, string res) {
		col[isbn].Set_Reserved(res);
	}
	void Collection::SetDayReserved(string isbn, string res) {
		col[isbn].Set_DayOfReservation(res);
	}
#endif
