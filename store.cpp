#include "store.h"
#include <sstream>
#include <iomanip>

Store::Store()
{
    num_customers_ = 0;
    num_products_ = 0;
    num_transactions_ = 0;
}

void Store::num_customers(int customer_count)
{
    if (customer_count >= 0 && customer_count <= 100)
        num_customers_ = customer_count;
}

int Store::num_customers()
{
    return num_customers_;
}

void Store::num_products(int product_count)
{
    if (product_count >= 0 && product_count <= 100)
        num_products_ = product_count;
}

int Store::num_products()
{
    return num_products_;
}

void Store::num_transactions(int transaction_count)
{
    if (transaction_count >= 0 && transaction_count <= 100)
        num_transactions_ = transaction_count;
}

int Store::num_transactions()
{
    return num_transactions_;
}

bool Store::add_customer(Person customer)
{
    if (num_customers_ >= 100)
        return false;

    customers_[num_customers_] = customer;
    ++num_customers_;
    return true;
}

bool Store::update_customer(int index, Person customer)
{
    if (index < 0 || index >= num_customers_)
        return false;

    customers_[index] = customer;
    return true;
}

Person Store::get_customer(int index)
{
    if (index < 0 || index >= num_customers_)
        return Person();

    return customers_[index];
}

bool Store::add_product(product item)
{
    if (num_products_ >= 100)
        return false;

    products_[num_products_] = item;
    ++num_products_;
    return true;
}

product Store::get_product(int index)
{
    if (index < 0 || index >= num_products_)
        return product();

    return products_[index];
}

bool Store::add_transaction(transaction ntransaction)
{
    if (num_transactions_ >= 100)
        return false;

    transactions_[num_transactions_] = ntransaction;
    ++num_transactions_;
    return true;
}

transaction Store::get_transaction(int index)
{
    if (index < 0 || index >= num_transactions_)
        return transaction();

    return transactions_[index];
}

int Store::find_customer(Person cust)
{
    for (int i = 0; i < num_customers_; ++i)
    {
        if (customers_[i].name() == cust.name())
            return i;
    }

    return -1;
}

bool Store::make_purchase(Person customer, product item, int quantity)
{
    if (quantity <= 0)
        return false;

    int customer_index = find_customer(customer);

    if (customer_index == -1 || num_transactions_ >= 100)
        return false;

    double total = item.price * quantity;

    Person updated_customer = customers_[customer_index];
    credit_card card = updated_customer.person_credit_card();

    if (!card.make_purchase(total))
        return false;

    updated_customer.person_credit_card(card);

    transaction new_transaction;
    new_transaction.transaction_number = num_transactions_ + 1;
    new_transaction.customer = updated_customer;
    new_transaction.purchased_item = item;
    new_transaction.quantity = quantity;

    customers_[customer_index] = updated_customer;
    add_transaction(new_transaction);

    return true;
}

string Store::product_info()
{
    std::ostringstream output;

    for (int i = 0; i < num_products_; ++i)
        output << products_[i].product_info() << '\n';

    return output.str();
}

string Store::transaction_info()
{
    std::ostringstream output;

    for (int i = 0; i < num_transactions_; ++i)
        output << transactions_[i].transaction_info() << '\n';

    return output.str();
}

string Store::customer_info()
{
    std::ostringstream output;

    for (int i = 0; i < num_customers_; ++i)
        output << customers_[i].person_info() << '\n';

    return output.str();
}

string Store::store_info()
{
    std::ostringstream output;

    output << "Customers:\n";
    output << customer_info() << '\n';

    output << "Products:\n";
    output << product_info() << '\n';

    output << "Transactions:\n";
    output << transaction_info();

    return output.str();
}

string Store::purchase_history(Person customer)
{
    std::ostringstream output;

    for (int i = 0; i < num_transactions_; ++i)
    {
        if (transactions_[i].customer.name() == customer.name())
            output << transactions_[i].transaction_info() << '\n';
    }

    return output.str();
}
