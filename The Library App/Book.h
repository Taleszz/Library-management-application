#ifndef BookH
#define BookH

/*
*	Here's The Base Block of the database
*	Here's info collected about a single book and then it's used in 
*	a) Collection  -> Book is sorted by isbn and the entries in it are loaded from the library collection of books
*	b) StudentBook -> Book is sorted by id   and the entries in it are the books issued by the students
*	StudentBook is often derrived to sb by taking the first letter of each word when used in functions
*	The class Book has constructor which is used to set a default value 
*	The default value of title is used in the program as to check whether the entry is "empty" 
*/


#include "Namespace&Includes.h"
using namespace start;

class Book {
public:
	Book(string over = "0",string t = "---", int p = 0, string i = "No",
		 string is = "/", string DOF = "//.//.////", string DOR = "//.//.////", string res = "No", string dor="")
	{
		Title = t;
		Pages = p;
		Is_checked = i;
		Isbn = is;
		DateOfIssuing = DOF;
		DateToReturnBy = DOR;
		DaysOverdue = over;
		Reserved = res;
		DayOfReservation = dor;
	}

	//Getters
	string Get_Title() const
	{
		return Title;
	}
	string Get_Pages() const
	{
		return Pages;
	}
	string Get_Is_checked() const
	{
		return Is_checked;
	}
	string Get_Isbn() const
	{
		return Isbn;
	}
	string Get_DateOfIssuing() const
	{
		return DateOfIssuing;
	}
	string Get_DateToReturnBy() const
	{
		return DateToReturnBy;
	}
	string Get_DaysOverdue() const
	{
		return DaysOverdue;
	}
	string Get_Reserved() const
	{
		return Reserved;
	}
	string Get_DayOfReservation() const {
		return DayOfReservation;
	}

	//Setters
	void Set_Title(string t)
	{
		Title = t;
	}
	void Set_Pages(string p)
	{
		Pages = p;
	}
	void Set_Is_checked(string is)
	{
		Is_checked = is;
	}
	void Set_Isbn(string i)
	{
		Isbn = i;
	}
	void Set_DateOfIssuing(string doi)
	{
		DateOfIssuing = doi;
	}
	void Set_DateToReturnBy(string dtrb)
	{
		DateToReturnBy = dtrb;
	}
	void Set_DaysOverdue(string dov)
	{
		DaysOverdue = dov;
	}
	void Set_Reserved(string r)
	{
		Reserved = r;
	}
	void Set_DayOfReservation(string dor) {
		DayOfReservation = dor;
	}
private:
	string Title;
	string Pages;
	string Is_checked;
	string Isbn;
	string DateOfIssuing;
	string DateToReturnBy;
	string DaysOverdue;
	string Reserved;
	string DayOfReservation;
};
#endif