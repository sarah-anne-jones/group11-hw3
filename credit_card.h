#include <string>

#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

//a struct that is able to store
//credit card information for one customer
struct credit_card
{
	int cc_number;  	//credit card number
	double limit;
	double current_balance;

	//method to make a purchase against the 
	//credit card limit. returns true if 
	//successfull and false otherwise. 
	bool make_purchase(double purchase_amount);

	//method to make a payment towards the credit
	//card balance. returns true if
	//successfull and false otherwise.
	bool make_payment(double payment_amount);

	//method to print credit card details
	std::string credit_card_info();
};


#endif
