#include "product.h"
#include "transaction.h"
#include "person.h"

#ifndef STORE_H
#define STORE_H

class Store 
{
	private:
	int num_customers_; //how many products are in the customers_[]
	Person customers_[100];
	int num_products_; //how many products are in the products_[]
	product products_[100];
	int num_transactions_; //how many transactions are stored in the 
						  //transactions_[]
	transaction transactions_[100];

	public:

	//default constructor to initialize
	//all values to empty
	Store();

	//getters/setters for num_customers_
	void num_customers(int customer_count);
	int num_customers();

	//getters/setters for num_products_
	void num_products(int product_count);
	int num_products();

	//getters/setters for num_transactions
	void num_transactions(int transaction_count);
	int num_transactions();


	//add a Person to the customers_[]
	//@Person
	bool add_customer(Person customer);

	//replace a customer in the customers_[] with
	//an updated version of same customer. Must provide
	//index and customer to replace. Customer in parameter
	//should match customer in that position.
	//@int, @Person 
	bool update_customer(int index, Person customer);

	Person get_customer(int index);
	/* Adds a single product to the products_[]
 	 * at the next available position.
 	 * If products_[] is full returns false. Otherwise,
 	 * returns true.
 	 */
	bool add_product(product item);

	//returns product at specified index in products_[]
	//@index int 
	product get_product(int); 

	/* Adds a single transaction to the transactions_[]
 	 * at the next available position.
 	 * If transactions_[] is full returns false. Otherwise,
 	 * returns true.
 	 */
	bool add_transaction(transaction ntransaction);

	//returns transaction at specified index in products_[]
	//@index int 
	transaction get_transaction(int); 

	//attempts to make a purchase using a person's credit
	//card. If successfull returns true. Otherwise, returns false.
	//@Person, @product, @int
	bool make_purchase(Person, product, int);

	//returns a string listing all products associated 
	//with this store.
	string product_info();

	//returns a string listing all transactions associated
	//with this store
	string transaction_info();

	string customer_info();

	//returns a string listing all information about this
	//store (transactions and products)
	string store_info();

	//searches through the transactions_[] and returns a
	//string representing all transactions that belong to 
	//a specific customer.
	string purchase_history(Person);

	//given a customer, returns the index in the customer_[]
	//where that customer is located
	int find_customer(Person cust);
};

#endif
