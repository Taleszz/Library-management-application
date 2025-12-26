#include "SaveToDatabase.h"
#include "LoadFromDatabase.h"
#include "SaveToReserve.h"
#include "LoadFromReserve.h"
#include "Timer.h"

using namespace start;

/*
*	Function used to create a log 
*	log is stored in Log.txt and you cannot open it from inside the program and you can only append it
*	It's purpose is to be used as a history of an program 
*	example entries:
*		user | with id: 12345| Issued a book   : 'The_Fountainhead'| and isbn : 9780553283686| On Fri Jun  7  17:16:38 2024
*		user | with id: 12345| Returned a book : 'The_Fountainhead'| and isbn : 9780553283686| On Fri Jun  17 12:32:15 2024
*	The function could be rewritten and improved. Now it's quite clunky and the "if"s are bugging me 
*	c  - collection
*   sb - StudentBook
*	d  - date
*/
void Log(string id, string title, string isbn, Collection c, Date d, string IssuedOrReturned)
{
	if (IssuedOrReturned == "Issued")
	{
		string user = "user";
		fstream dataSave("Log.txt", std::ios::app);
		try
		{
			if (!(dataSave.is_open()))
				throw "not open";
		}
		catch (...) {
			cout << "ERROR - The file hasn't been opened properly!" << endl;
		}
		dataSave << "" << user << " | with id: " << id << "| Issued a book : '" << title;
		dataSave << "'| and isbn : " << isbn << "| On " << d.All(0);
		dataSave.close();
	}
	else if (IssuedOrReturned == "Returned")
	{
		string user;
		if (true)
			user = "user";
		else
			user = "admin";
		fstream dataSave("Log.txt", std::ios::app);
		try
		{
			if (!(dataSave.is_open()))
				throw "not open";
		}
		catch (...) {
			cout << "ERROR - The file hasn't been opened properly!" << endl;
		}
		dataSave << "" << user << " | with id: " << id << "| Returned a book : '" << title;
		dataSave << "'| and isbn : " << isbn << "| On " << d.All(0);
		dataSave.close();
	}
	else if (IssuedOrReturned == "Modified")
	{
		string user;
		if (true)
			user = "user";
		else
			user = "admin";
		fstream dataSave("Log.txt", std::ios::app);
		try
		{
			if (!(dataSave.is_open()))
				throw "not open";
		}
		catch (...) {
			cout << "ERROR - The file hasn't been opened properly!" << endl;
		}
		dataSave << "" << user << " | with id: " << id << "| Modified a book : '" << title;
		dataSave << "'| and isbn : " << isbn << "| On " << d.All(0);
		dataSave.close();
	}
	else if (IssuedOrReturned == "Modified ")
	{
		string user;
		if (true)
			user = "user";
		else
			user = "admin";
		fstream dataSave("Log.txt", std::ios::app);
		try
		{
			if (!(dataSave.is_open()))
				throw "not open";
		}
		catch (...) {
			cout << "ERROR - The file hasn't been opened properly!" << endl;
		}
		dataSave << "" << user << " | with id: " << id << "| Modyfied an entry on a book : '" << title;
		dataSave << "'| and isbn : " << isbn << "| On " << d.All(0);
		dataSave.close();
	}
}


/*
*	This function is quite self explanatory - print the whole collection so inside of collection is printed
*	c  - collection
*   sb - StudentBook 
*/
void PrintCollection(Collection c, map<string, Book> sb) {
	cout << "---------------------------------------------------------------------" << endl;
	for (auto item : c.GetCollection())
	{
			cout << "---------------------------------------------------------------------" << endl;
			cout << "ISBN: " << item.first << endl << "Title: " << item.second.Get_Title() << endl;
			cout << "Pages: " << item.second.Get_Pages() << endl << "Is it checked?: " << item.second.Get_Is_checked() << endl;
			cout << "Reserved: " << item.second.Get_Reserved() << endl;
			cout << "---------------------------------------------------------------------" << endl;
	}
	cout << "---------------------------------------------------------------------" << endl;
}

/*
*	Function used to issue books. Information about it is stored in StudentBook and collection
*	d  - date
*	c  - collection
*   sb - StudentBook 
*/
map<string,Book> Issue(map<string, Book>& sb, Date& d, Collection collection, string isbn, string id)
{	
	{
		auto pom = collection.GetCollection()[isbn];
		sb[id].Set_Title(pom.Get_Title());
		sb[id].Set_Pages(pom.Get_Pages());
		sb[id].Set_Isbn(isbn);
		sb[id].Set_Is_checked("Yes");
		sb[id].Set_DateOfIssuing(d.DoW(0) + "_" + d.Hours(0) + "_" + d.Days(0) + "_" + d.Months(0) + "_" + d.Years(0) + "\n");
		sb[id].Set_DateToReturnBy(d.DoW(15) + "_" + d.Hours(15) + "_" + d.Days(15) + "_" + d.Months(15) + "_" + d.Years(15) + "\n");
		sb[id].Set_DaysOverdue( "0");
		Log(id, pom.Get_Title(), isbn, collection, d, "Issued");
		return sb;
	}
}

/*
*	Shows all books that were issued -> Shows contents of StudentBook
*	sb - StudentBook
*/
void ShowAllIssued(const map<string,Book>& sb)
{
	for (auto& item : sb)
	{
		cout << "---------------------------------------------------------------------" << endl;
		cout << "ID:    " << item.first << endl;
		cout << "Title: " << item.second.Get_Title() << endl;
		cout << "ISBN:  " << item.second.Get_Isbn() << endl;
		cout << "Pages: " << item.second.Get_Pages() << endl;
		cout << "Is it checked? -   " << item.second.Get_Is_checked() << endl;
		cout << "Date of issuing:   " << item.second.Get_DateOfIssuing();
		cout << "Return by      :   " << item.second.Get_DateToReturnBy();
		cout << "Days overdue: " << item.second.Get_DaysOverdue() << endl;
		cout << "---------------------------------------------------------------------" << endl;
	}
}

/*
*	Shows only the book that was issued by id which is inputed
*	sb - StudentBook
*/
void ShowIDIssued(map<string,Book> sb, string id, Collection c)
{
	auto it = sb.find(id);
	if (it == sb.end()) 
	{
		cout << " ERROR NO BOOK ISSUED WITH THIS ID" << endl;
	}
	else {
		cout << "---------------------------------------------------------------------" << endl;
		cout << "---------------------------------------------------------------------" << endl;
			cout << endl;
			cout << "The book issued by :    " << id << endl;
			cout << "---------------------------------------------------------------------" << endl;
			cout << "Title: " << sb[id].Get_Title() << endl;
			cout << "ISBN:  " << sb[id].Get_Isbn() << endl;
			cout << "Pages: " << sb[id].Get_Pages() << endl;
			cout << "Is it checked? -   " << sb[id].Get_Is_checked() << endl;
			cout << "Is it reserved? - " << c.GetCollection()[sb[id].Get_Isbn()].Get_Reserved() << endl;
			cout << "Date of issuing:   " << sb[id].Get_DateOfIssuing();
			cout << "Return by      :   " << sb[id].Get_DateToReturnBy();
			cout << "Days overdue: " << sb[id].Get_DaysOverdue() << endl;
			cout << "---------------------------------------------------------------------" << endl;
			cout << "---------------------------------------------------------------------" << endl;
		}
	
}

/*
*	Update is a function used update the days overdue of an entry in StudnetBook
*	sb - StudentBook
*	d - date
*/
map<string,Book> Update(map<string,Book> sb, Date d)
{
	string doi;
	for (auto item : sb)
	{
		auto id = item.first;

		string pom = sb[id].Get_DateOfIssuing();
		pom.pop_back();

		//dov <==> DaysOVerdue -> DOV -> dov
		string dov = d.DaysOverdue(pom, d);

		if (item.second.Get_Title() != "" && item.second.Get_Title() != "---")
			sb[id].Set_DaysOverdue(d.DaysOverdue(pom, d));
	}
	return sb;
}

/*
*	Raport is function which prints information about overdue books and their fees
*	Information about overdue books is stored in StudentBook
*	Fee is calculated as follows:
*		Fee = (1+0.1*Days_Overdue)^2
*/
void Raport(map<string,Book> sb)
{
	for (auto item : sb) 
	{
		if (stoi(item.second.Get_DaysOverdue()) > 0)
		{
			cout << "---------------------------------------------------------------------" << endl;
			cout << "ID:    " << item.first << endl;
			cout << "Title: " << item.second.Get_Title() << endl;
			cout << "ISBN:  " << item.second.Get_Isbn() << endl;
			cout << "Pages: " << item.second.Get_Pages() << endl;
			cout << "Is it checked? -   " << item.second.Get_Is_checked() << endl;
			cout << "Date of issuing:   " << item.second.Get_DateOfIssuing();
			cout << "Return by      :   " << item.second.Get_DateToReturnBy();
			cout << "Days overdue: " << item.second.Get_DaysOverdue() << endl;
			cout << "For which a fee of " << (stoi(item.second.Get_DaysOverdue()) * 0.1 + 1) * (stoi(item.second.Get_DaysOverdue()) * 0.1 + 1) << " PLN is charged" << endl;
			cout << "---------------------------------------------------------------------" << endl;
		}
	}
}

/*
*	Function used to reserve books. Information about it is stored in collection
*	d  - date
*	c  - collection
*/
Collection Reserve(Collection c, string id, Date d)
{
	cout << "---------------------------------------------------------------------" << endl;
	for (auto item : c.GetCollection())
	{
		if (item.second.Get_Is_checked() == "Yes")
		{
			cout << "---------------------------------------------------------------------" << endl;
			cout << "ISBN: " << item.first << endl << "Title: " << item.second.Get_Title() << endl;
			cout << "Pages: " << item.second.Get_Pages() << endl << "Is it checked?: " << item.second.Get_Is_checked() << endl;
			cout << "Reserved: " << item.second.Get_Reserved() << endl;
			cout << "---------------------------------------------------------------------" << endl;
		}
	}
	cout << "---------------------------------------------------------------------" << endl;

	string isbn;

	cout << "Type the isbn of the book you want to reserve.\n";
	cin >> isbn;
	if (isbn == "back" || isbn == "Back") { return c; }
	//Condition used to check if isbn is viable i.e is in the library collection
	if (c.GetCollection()[isbn].Get_Title() == "---")
	{
		cout << "Incorrect input - no book with this isbn\n";
		Reserve(c, id, d);
	}
	else
	{
		string pom;
		pom = "Yes, by: " + id;
		bool test = (c.GetCollection()[isbn].Get_Reserved() == "No");
		//cout << test << endl;
		if (test)
		{
			c.SetReserved(isbn, pom);
			pom = (d.DoW(0) + "_" + d.Hours(0) + "_" + d.Days(0) + "_" + d.Months(0) + "_" + d.Years(0) + "\n");
			c.SetDayReserved(isbn, pom);
			cout << "Done!\nYou just reserved a book: " << c.GetCollection()[isbn].Get_Title() << endl << endl;
			Log(id, c.GetCollection()[isbn].Get_Title(), isbn, c, d, "Reserved");
			return c;
		}
		else
		{
			cout << "This book is already reserved! \nChoose another one.\n";
			return c;
		}	
	}
}

/*
*	Simmilar function to Update but is used for removing reservations after 15 days
*	c - collection
*	d - date
*/
Collection UpdateReserve(Collection c, Date d) {
	for (auto item : c.GetCollection())
	{
		string dor = item.second.Get_DayOfReservation();
		//cout << "dor: " << dor << endl;
		if (!dor.empty()) 
		{
			if ((stoi(d.DaysOverdue(dor, d)) > 0))
			{
				c.SetReserved(item.first, "No");
				c.SetDayReserved(item.first, "");
				//cout << c.GetCollection()[item.first].Get_Reserved() << endl;
			}
		}
	}
	SaveToReserve(c, d);
	return c;
}

int main()
{

		Date date;
		map<string, Book> StudentBook;
		Collection coll(StudentBook);
		StudentBook = LoadFromFile(StudentBook, "DataSave.txt", coll);
		Collection collection(StudentBook);
		StudentBook = Update(StudentBook, date);
		collection = LoadReserve(collection);
		collection = UpdateReserve(collection, date);
	while (true)
	{

		if(StudentBook.find("") != StudentBook.end())
			StudentBook.erase(StudentBook.find(""));

		string sChoice = "0";
		int choice = 0;

		//Text displayed in the main menu
		cout << "---------------------------------------------------------------------" << endl;
		cout << "If you type 'back' at any time you will be brought back to main menu\n";
		cout << "What do you want to do?\n";
		cout << "Type 1 to issue a book\nType 2 to Show all books that's been issued\n";
		cout << "Type 3 to Show book issued by an student (using id)\nType 4 to Create a report of overdue books\n";
		cout << "Type 5 to check in a book (unless it is overdue in which case you need to contact the administrator and pay the fee)\n";
		cout << "Type 6 to show all books that are reserved\nType 7 to modify an entry\n";
		cout << "Type 0 to exit the app\n";

		try {
			cin >> sChoice;
			choice = stoi(sChoice);
		}
		catch (...) {
			if (sChoice == "back" || sChoice == "Back")
			{
				continue;
			}
			cout << "ERROR - incorrect input! \nTry again.\n";
			continue;
		}


		if (choice == 1)
		{
			string id, isbn;
		try
		{
			int iId;
			cout << "Input your id: " << endl;
			cin >> id;
			iId = stoi(id);
			if (iId < 0) {
				throw("id must be an number over 0 -> error");
			}
		}
		catch (...)
		{
			if (id == "back" || id == "Back")
			{
				continue;
			}
			cout << "ERROR - incorrect input! \nTry again.\n";
			continue;
		}
			auto it = StudentBook.find(id);

			PrintCollection(collection, StudentBook);

			cout << "Do you want to checkout a book which hasn't been checked out yet? (type 'C') \nOr do you wish to put a book on reserve";
			cout << "in order to issue the book with priority when the book is returned? (type 'R')  \n";
				
			string pom = "- ";
			cin >> pom;
			if (pom == "back" || pom == "Back") 
			{
				continue;
			}
				if ((pom[0] == 'R' && pom == string("R")) || (pom[0] == 'r' && pom == string("r")))
				{
					collection = Reserve(collection, id, date);
					
					SaveToReserve(collection, date);
				}
				else if((pom[0] == 'C' && pom == string("C")) || (pom[0] == 'c' && pom == string("c")))
				{
					if (it != StudentBook.end())
					{
						cout << "ERROR - ANOTHER BOOK ALREADY ISSUED" << endl;
					}
					else
					{
						string pm = "Yes, by: " + id;
						cout << "Type the isbn of a book you want to issue \n";
						cin >> isbn;
						if (isbn == "back" || isbn == "Back") { continue; }
							if (collection.GetCollection()[isbn].Get_Title() == "---")
							{
								cout << "ERROR - Incorrect input\n";
								continue;
							}
						if ((collection.GetCollection()[isbn].Get_Reserved() == pm))
						{
							if (collection.GetCollection()[isbn].Get_Is_checked() == "No")
							{
								collection.SetChecked(isbn, "Yes");
								StudentBook = Issue(StudentBook, date, collection, isbn, id);
								collection.SetReserved(isbn, "No");
								SaveToDatabase(StudentBook);
							}
							else
							{
								cout << "Error - Is this book checked? - " << collection.GetCollection()[isbn].Get_Is_checked() << endl;
							}
						}
						else if (collection.GetCollection()[isbn].Get_Reserved() == "No")
						{
							if (collection.GetCollection()[isbn].Get_Is_checked() == "No")
							{
							collection.SetChecked(isbn, "Yes");
							StudentBook = Issue(StudentBook, date, collection, isbn, id);
							collection.SetReserved(isbn, "No");
							SaveToDatabase(StudentBook);
							cout << "Done!\nYou just issued a book: " << StudentBook[id].Get_Title() << endl << endl;
							}
							else
							{
								cout << "Error - Is this book checked? - " << collection.GetCollection()[isbn].Get_Is_checked() << endl;
							}
						}
						else
						{
							cout << "Sorry but this book is already reserved. \n" << "Reserved? \n" << collection.GetCollection()[isbn].Get_Reserved() << endl;
						}
					}
				}
				else
				{
					cout << "ERROR - Incorrect input.\nTry Again.\n";
				}
		}
		else if (choice == 2)
			ShowAllIssued(StudentBook);
		else if (choice == 3)
		{
			string id;
			try
			{
				int iId;
				cout << "Type the id you want to search by\n";
				cin >> id;
				if (id == "back" || id == "Back") { continue; }
				iId = stoi(id);
			}
			catch (...)
			{
				cout << "ERROR - incorrect input! \nTry again.\n";
				continue;
			}
			ShowIDIssued(StudentBook, id, collection);
		}
		else if (choice == 4)
			Raport(StudentBook);
		else if (choice == 5)
		{
			string id, isbn;
			try
			{
				int iId;
				cout << "Type your id to return the book" << endl;
				cin >> id;
				if (id == "back" || id == "Back") { continue; }
				iId = stoi(id);
			}
			catch (...)
			{
				cout << "ERROR - incorrect input! \nTry again.\n";
				continue;
			}
			isbn = StudentBook[id].Get_Isbn();
			if (stoi(StudentBook[id].Get_DaysOverdue()) > 0)
			{
				cout << "Your fee is equal to: " << (stoi(StudentBook[id].Get_DaysOverdue()) * 0.1 + 1) * (stoi(StudentBook[id].Get_DaysOverdue()) * 0.1 + 1) << " PLN" << endl;
				cout << "You need to contact admin and pay off the fee" << endl;
			}
			else
			{
				if (StudentBook[id].Get_Title() == "---")
					cout << "There no book to return.\n";
				else
				{
					collection.SetChecked(isbn, "No");
					Log(id, collection.GetCollection()[isbn].Get_Title(), isbn, collection, date, "Returned");
					cout << "Done!\nYou just returned a book: " << StudentBook[id].Get_Title() << endl << endl;
					StudentBook.erase(id);
					SaveToDatabase(StudentBook);
				}
			}
		}
		else if (choice == 6)
		{
			for(auto item : collection.GetCollection())
				if (item.second.Get_Reserved() != "No" && item.second.Get_Reserved() != "" && item.second.Get_Title() != "---" && item.first != "")
				{
					cout << "---------------------------------------------------------------------" << endl;
					cout << "Title: " << item.second.Get_Title() << endl;
					cout << "ISBN:  " << item.first << endl;
					cout << "Pages: " << item.second.Get_Pages() << endl;
					cout << "Is it checked? -   " << item.second.Get_Is_checked() << endl;
					cout << "Is it reserved? - " << item.second.Get_Reserved() << endl;
					cout << "---------------------------------------------------------------------" << endl;
				}
		}
		else if (choice == 7)
		{
			//Add logs everywhere
			string Schoice;
			int Ichoice;
			try {
				cout << "Type 1 to Change DateOfIssuing.\nType 2 to change whether is it checked.\n";
				cout << "Type 3 to change whether it is reserved.\n";
				cin >> Schoice;
				if (Schoice == "back" || Schoice == "Back") { continue; }
				Ichoice = stoi(Schoice);
			}
			catch(...){
				cout << "ERROR - Incorrect Input.\nTry again.";
				continue;
			}
			string id;

			

			if (Ichoice == 1) { //Modify the date of issuing
				ShowAllIssued(StudentBook);
				cout << "Input id.\n";
				try {
					cin >> id;
					if (id == "back" || id == "Back") { continue; }
					if (stoi(id) < 0)
						throw("Id cannot be negative");
				}
				catch (...)
				{
					cout << "ERROR - Incorrect id\n";
					continue;
				}
				Log(id, StudentBook[id].Get_Title(), StudentBook[id].Get_Isbn(), collection, date, "Modified");
				int days = 0;
				cout << "To change the date of issuing input a number of days from today to that date e.g.\n";
				cout << "Today -> Today ==> 0 days (Input 0); Same week, Monday -> Friday ==> 4 days (input 4) etc.\n";
				cout << "If the date of issuing will be before today same rule applies but with a minus e.g.\n";
				cout << "Same week, Friday -> Monday == > -4 days (input -4).\n";
				int Days;
				try {
					string SD;
					cin >> SD;
					if (SD == "back" || SD == "Back") { continue; }
					 Days = stoi(SD);
				}
				catch (...) {
					cout << "Error - Incorrect input.\nTry again.";
					continue;
				}
				days = Days;
				string NewDayOfIssuing = date.DoW(days) + "_" + date.Hours(days) + "_" + date.Days(days) + "_" + date.Months(days) + "_" + date.Years(days)  +  "\n";
				days = Days + 15;
				string NewDayOfReturn = date.DoW(days) + "_" + date.Hours(days) + "_" + date.Days(days) + "_" + date.Months(days) + "_" + date.Years(days)   + "\n";
				StudentBook[id].Set_DateOfIssuing(NewDayOfIssuing);
				StudentBook[id].Set_DateToReturnBy(NewDayOfReturn);
				days = Days + 15;
				
				if (days < 0)
				{
					StudentBook[id].Set_DaysOverdue(std::to_string(-days));
				}
				else
				{
					StudentBook[id].Set_DaysOverdue("0");
				}
				SaveToDatabase(StudentBook);
				

			}
			else if(Ichoice == 2) { //Modify whether it is checked
				string SYes;
				int IYes;
				cout << "Modify to 'Yes' - type 1\nModify to 'No' - type 0\n";
				try {
					cin >> SYes;
					if (SYes == "back" || SYes == "Back") { continue; }
					IYes = stoi(SYes);
				}
				catch (...)
				{
					cout << "ERROR - Incorrect Input.\n";
					continue;
				}
				string isbn = StudentBook[id].Get_Isbn();
				if (IYes == 1)
				{ //If yes then issue but without checking reservations
					PrintCollection(collection, StudentBook);
					try {
						cout << "input isbn: \n";
						cin >> isbn;
						if (isbn == "back" || isbn == "Back") { continue; }
						if (collection.GetCollection()[isbn].Get_Title() == "---")
						{
							cout << "ERROR - Incorrect input\n";
							continue;
						}
					}
					catch (...) {
						cout << "ERROR - Incorrect input.\n";
						continue;
					}
					if (collection.GetCollection()[isbn].Get_Is_checked() == "No") {
						try {
							cout << "Input id issuing the book:\n";
							cin >> id;
							if (id == "back" || id == "Back") { continue; }
							if (stoi(id) < 0)
								throw("Error - Incorrect id");
						}
						catch (...) {
							cout << "Error - Incorrect id\n";
						}
						collection.SetChecked(isbn, "Yes");
						StudentBook = Issue(StudentBook, date, collection, isbn, id);
						Log(id, collection.GetCollection()[isbn].Get_Title(), isbn, collection, date, "Modified");
						SaveToDatabase(StudentBook);
					}
					else
					{
						cout << "This book is already checked.\n";
					}

				}
				else if (IYes == 0) { // Modify to "No" -> something like return a book 
					try
					{
						int iid;
						cout << "Type your id to return the book" << endl;
						cin >> id;
						if (id == "back" || id == "Back") { continue; }
						iid = stoi(id);
					}
					catch (...)
					{
						cout << "ERROR - incorrect input! \n Try again.\n";
						continue;
					}
					isbn = StudentBook[id].Get_Isbn();
						if (StudentBook[id].Get_Title() == "---")
							cout << "There no book to return.\n";
						else
						{
							StudentBook.erase(id);
							collection.SetChecked(isbn, "No");
							SaveToDatabase(StudentBook);
							Log(id, collection.GetCollection()[isbn].Get_Title(), isbn, collection, date, "Modified");
						}
				}
				else {
					cout << "ERROR Incorrect input.\n";
				}
			}
			else if (Ichoice == 3) {
				string SYes;
				int IYes;
				cout << "Yes - type 1\nNo - type 0\n";
				try {
					cin >> SYes;
					if (SYes == "back" || SYes == "Back") { continue; }
					IYes = stoi(SYes);
				}
				catch (...)
				{

				}
				string isbn = StudentBook[id].Get_Isbn();
				if (IYes == 1)
				{
					string isbn, id;
					PrintCollection(collection, StudentBook);
					try {
						cout << "Input isbn of a book you want to reserve.\n";
						cin >> isbn;
						if (isbn == "back" || isbn == "Back") { continue; }
						if (collection.GetCollection()[isbn].Get_Title() == "---")
						{
							throw("Error");
						}
						cout << "Input id which will be reserving.\n";
						cin >> id;
						if (id == "back" || id == "Back") { continue; }
						if (stoi(id) < 0 )
						{
							throw("Error");
						}
						
					}
					catch (...) {
						cout << "ERROR - Incorrect input.\n";
						continue;
					}
					string pom = "Yes, by" + id;
					if (collection.GetCollection()[isbn].Get_Reserved() == "No") {
						collection.SetDayReserved(isbn, (date.DoW(0) + "_" + date.Hours(0) + "_" + date.Days(0) + "_" + date.Months(0) + "_" + date.Years(0) + "\n"));
						collection.SetReserved(isbn, pom);
					}
					else
					{
						cout << "ERROR - This book is already reserved.\n";
					}
				}
				else if (IYes == 0)
				{
					string isbn;
					PrintCollection(collection, StudentBook);
					try {
						cout << "Input isbn of a book you want to cancel reservation.\n";
						cin >> isbn;
						if (isbn == "back" || isbn == "Back") { continue; }
						if (collection.GetCollection()[isbn].Get_Title() == "---")
						{
							throw("Error");
						}
					}
					catch (...) {
						cout << "ERROR - Incorrect input\n";
						continue;
					}
					if (collection.GetCollection()[isbn].Get_Reserved() != "No") {
						collection.SetReserved(isbn, "No");
						SaveToReserve(collection, date);
						Log(id, StudentBook[id].Get_Title(), StudentBook[id].Get_Isbn(), collection, date, "Modified");
					}
					else
					{
						cout << "ERROR - This book is not reserved.\n";
					}
				}
				else { cout << "ERROR - Incorrect input.\n"; }
			}
			else { cout << "ERROR - Incorrect input.\n"; }
		}
		else if (choice == 0)
			exit(0);
		else
		{
			cout << "Error - Incorrect input. Try again. \n";
		}
	}
	return 0;
}
