#ifndef LoadFromCollectionH
#define LoadFromCollectionH

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


#include "Book.h"
using namespace start;

map<string, Book> LoadCollection(map<string, Book>& d, map < string, Book> sb);
map<string, Book> LoadCollection(map<string, Book>& d);
class Collection {
public:
	Collection(map<string,Book>sb);
	Collection();
	map<string, Book> GetCollection();
	void SetChecked(string isbn, string ic);
	void SetReserved(string isbn, string res);
	void SetDayReserved(string isbn, string res);
private:
	map<string, Book> col;
};
#endif