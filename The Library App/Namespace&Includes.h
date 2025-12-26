#ifndef NamespaceH
#define NamespaceH

/*
*	Basic definition as to not use all the time std:: e.g. std::cout, std::map, std::endl
*	And all of the includes are here except .h and .cpp files
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>


namespace start
{
	using std::string, std::vector, std::map, std::fstream, std::cout, std::endl;
	using std::ostream, std::istream, std::cin, std::wstring;
	using timer = std::chrono::system_clock;
};

#endif