#ifndef TimerH
#define TimerH

/*
*   Here's a definition of a main segment which manages time 
*   In another words everything concerning chrono
* This page consists of a class Date which is able to handle most of you needs concerning time
* This class has a constructor and methods which return e.g. Day, Hours, Months etc depending on the input d (d is an integer)
* d determines whether is it:
*   past    date -> d < 0;     
*   current date -> d = 0;
*   future  date -> d > 0;
*   You can think of d as days past today e.g. 
*   tomorrow  is *one* day *after*  today --> d = 1
*   yesterday is *one* day *before* today --> d = -1
*   after ---> + ;
*   before --> -;
*/

#include "Namespace&Includes.h"

using namespace start;

class Date {
public:
    Date();
    string All(int d);
    string Months(int d);
    string Days(int d);
    string Hours(int d);
    string DoW(int d);
    string DayofReturning();
    string Years(int d);
    string DaysOverdue(string iss, Date d);
private:
    string month;
    string dayofweek;
    int    day;
    string hours;
    string year;
    string dayofreturning;
};
#endif