#ifndef STORE_H
#define STORE_H

#include <string>
#include "product.h"
#include "transaction.h"
#include "person.h"

using std::string;

class Store
{
private:
    int num_customers_;
    Person customers_[100];

    int num_products_;
    product products_[100];

    int num_transactions_;
    transaction transactions_[100];

public:
    // Default constructor
    Store();

    // Getters and setters for customer count
    void num_customers(int customer_count);
    int num_customers();

    // Getters and setters for product count
    void num_products(int product_count);
    int num_products();

    // Getters and setters for transaction count
    void num_transactions(int transaction_count);
    int num_transactions();

    // Add, update, and retrieve customers
    bool add_customer(Person customer);
    bool update_customer(int index, Person customer);
    Person get_customer(int index);

    // Add and retrieve products
    bool add_product(product item);
    product get_product(int index);

    // Add and retrieve transactions
    bool add_transaction(transaction ntransaction);
    transaction get_transaction(int index);

    // Process a purchase
    bool make_purchase(Person customer, product item, int quantity);

    // Information methods
    string product_info();
    string transaction_info();
    string customer_info();
    string store_info();

    // Purchase history for a customer
    string purchase_history(Person customer);

    // Find a customer by name
    int find_customer(Person cust);
};

#endif
