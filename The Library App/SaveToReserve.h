#ifndef SaveToRes_H
#define SaveToRes_H

/*
*	Function simmilar to what you can find in SaveToDatabase.h
*	It's used to save the info about reservation to ReserveData.txt
*/

#include "Book.h"
#include "Timer.h"
#include "LoadFromDatabase.h"

using namespace start;

void SaveToReserve(Collection c, Date d);

#endif