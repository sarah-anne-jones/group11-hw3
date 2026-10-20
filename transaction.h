#include <string>
#include "person.h"
#include "product.h"

#ifndef TRANSACTION_H
#define TRANSACTION_H

//a struct that can be used to capture
//transactions in a store
struct transaction
{
	//data members
	int transaction_number;
	Person customer;
	product purchased_item;
	int quantity;

	//prints information about one transaction
	std::string transaction_info();
};
#endif

