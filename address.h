#include <string>

using std::string;

#ifndef ADDRESS_H
#define ADDRESS_H

//definition of a struct that is able of storing 
//address information for an individual
struct address 
{
	//data members
	string address_line1;
	string address_line2;
	string city;
	string state;
	string zip;

	//prints address information
	string address_info();		
};

#endif

