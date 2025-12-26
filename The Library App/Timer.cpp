#ifndef Timer
#define Timer

/*
*   Here's an implementation of a main segment which manages time
*   In another words everything concerning chrono
*   This page consists of a class Date which is able to handle most of you needs concerning time
* * This class has a constructor and methods which return e.g. Day, Hours, Months etc depending on the input d (d is an integer)
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

#include "Timer.h"
Date::Date() {
    month = Date::Months(0);
    dayofweek = Date::DoW(0);
    day = stoi(Date::Days(0));
    hours = Date::Hours(0);
    dayofreturning = Date::DayofReturning();
    year = Date::Years(0);
}
string Date::All(int d) {
    const time_t now = time(0) + d * 24 * 60 * 60;
    char str[26];
    ctime_s(str, sizeof(str), &now);
    return string(str);
}
string Date::Months(int d) {
    string str = Date::All(d);
    char pom[3];
    pom[0] = str[4];
    pom[1] = str[5];
    pom[2] = str[6];
    string pomoc;
    for (int i = 0; i < 3; i++)
    {
        pomoc.push_back(pom[i]);
    }
    return pomoc;
}
string Date::Days(int d) {
    string str = Date::All(d);
    char pom[2];
    pom[0] = str[8];
    pom[1] = str[9];
    string pomoc;
    for (int i = 0; i < 2; i++)
    {
        pomoc.push_back(pom[i]);
    }
    return pomoc;
}
string Date::Hours(int d) {
    string str = Date::All(d);
    char pom[8];
    for (int i = 0; i < 8; i++)
    {
        pom[i] = str[11 + i];
    }
    string pomoc;
    for (int i = 0; i < 8; i++)
    {
        pomoc.push_back(pom[i]);
    }
    return pomoc;
}
string Date::DoW(int d) {
    string str = Date::All(d);
    char pom[3];
    pom[0] = str[0];
    pom[1] = str[1];
    pom[2] = str[2];
    string pomoc;
    for (int i = 0; i < 3; i++)
    {
        pomoc.push_back(pom[i]);
    }
    return pomoc;
}
string Date::Years(int d) {
    string str = Date::All(d);
    char pom[4];
    for (int i = 0; i < 4; i++)
    {
        pom[i] = str[20 + i];
    }
    string pomoc;
    for (int i = 0; i < 4; i++)
    {
        pomoc.push_back(pom[i]);
    }
    return pomoc;
}
string Date::DayofReturning() {
    const time_t now = time(0) + 15 * 24 * 60 * 60;
    char str[26];
    ctime_s(str, sizeof(str), &now);
    return string(str);
}
string Date::DaysOverdue(string is, Date d) {
    //TO DO - Add some kind of an improvement e.g. if the months dont match or sth
    //To DO New Date formating fix the function
    int i = 0;
    string c = "0";
    c = Date::DoW(0) + "_" + Date::Hours(0) + "_" + Date::Days(0) + "_" + Date::Months(0) + "_" + Date::Years(0) + "\n";
    string cur;
    string iss;
    iss.erase(std::remove_if(iss.begin(), iss.end(), ::isspace), iss.end());
    for (int i = 0; i < 4; i++)
    {
        cur.push_back(c[i]);
    }
    for (int i = 0; i < 11; i++)
    {
        cur.push_back(c[i + 13]);
    }
    for (int i = 0; i < 4; i++)
    {
        iss.push_back(is[i]);
    }
    for (int i = 0; i < 11; i++)// was <11
    {
        iss.push_back(is[i + 13]);
    }
   
    cur.erase(std::remove_if(cur.begin(), cur.end(), ::isspace), cur.end());
    // 
    //cur = cur + " ";
    
    //cout << "13: " << is[13] << endl << "14: " << is[14] << endl;
    if (is[14] == '_')
        iss.pop_back();
   /*
    cout << "Current: " << cur << endl << "Issued : " << iss << endl <<"-----------------" << endl;
    cout  << cur << iss << endl;
    cout  << iss << cur << endl;
    cout << endl << "iss[14] " << iss[14] << endl;
    bool test;
    test = (cur.compare(iss));
    cout <<"Is equal? - " <<  (iss == cur) << endl;
    cout <<"Is equal using bool test - " <<  test << endl;
    cout << "test cur: " << endl;
    
    for (int i = 0; i < cur.size(); i++) {
        bool a;
        a = (cur[i] == iss[i]);
        cout << "a"<<i << ". " << a << "| ";
    }
    cout << endl << "test iss " << endl;
    for (int i = 0; i < iss.size(); i++) {
        bool b;
        b = (cur[i] == iss[i]);
        cout <<"b" << i << ". " << b << "| ";
    }
    cout << endl;
    */


    while ((iss != cur))
    {
        --i;
        cur.erase();
        string pom = Date::DoW(i) + "_" + Date::Hours(i) + "_" + Date::Days(i) + "_" + Date::Months(i) + "_" + Date::Years(i) + "\n";
        for (int i = 0; i < 4; i++)
        {
            cur.push_back(pom[i]);
        }
        for (int i = 0; i < 13; i++)
        {
            cur.push_back(pom[i + 13]);
        }
        cur.erase(std::remove_if(cur.begin(), cur.end(), ::isspace), cur.end());
        cur.pop_back();
       /*
        cout << "Issued: " << iss << "  Current:" << cur << " i:" << i << endl;
        cout << endl << "test curr " << endl;
        for (int i = 0; i < cur.size(); i++) {
            bool a;
            a = (cur[i] == iss[i]);
            cout << "a" << i << ". " << a << "| ";
        }
        cout << endl << "test iss " << endl;
        for (int i = 0; i < iss.size(); i++) {
            bool b;
            b = (cur[i] == iss[i]);
            cout << "b" << i << ". " << b << "| ";
        }
        cout << endl;
        */
    }
    int j = 15 + i;
    //cout << endl << j << endl;
    string out;
    if (j > 0)
    {
        return "0";
    }
    else
    {
        //cout << endl << -j << endl;
        return std::to_string(-j);
    }
}
#endif