#include <string>
#include "address.h"
#include "credit_card.h"

using std::string;

#ifndef PERSON_H
#define PERSON_H

//class definition for a person  
class Person 
{
	private:
	//data members
	string name_;
	string phone_;
	address person_address_;
	credit_card person_credit_card_;

	public:
	//constructor for a Person. 
	//parameters:
	//@name string, @phone string, 
	//@address person_address, @credit_card person_credit_card
	Person(string, string, address, credit_card);

	//default constructor for a person.
	//initialized all data members to 
	//basic defaults
	Person();

	//setters/getters for name_
	void name(string);
	string name();

	//setters/getters for phone_
	void phone(string);
	string phone();

	//setters/getters for customer_address_
	void person_address(address);
	address person_address();

	//setters/getters for customer_credit_card_
	void person_credit_card(credit_card);
	credit_card person_credit_card();

	//returns string representation of a person
	string person_info();
};
#endif
