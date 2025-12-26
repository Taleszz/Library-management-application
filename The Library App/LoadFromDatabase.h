#ifndef LoadFromDatabaseH
#define LoadFromDatabaseH

/*
*	This function is used to load information from DataSave.txt to map<string,Book> StudentBook
*/

#include "Book.h"
#include "LoadFromCollection.h"

using namespace start;
map<string, Book> LoadFromFile(map<string, Book> d, string file, Collection c);

#endif
