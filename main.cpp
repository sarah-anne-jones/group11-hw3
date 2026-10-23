#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using namespace std;

int main()
{
    Store store1;

    ifstream people_file("people.txt");
    ifstream cards_file("credit_card.txt");
    ifstream products_file("products.txt");

    if (!people_file || !cards_file || !products_file)
    {
        cerr << "Error: Could not open one or more input files."
             << endl;
        return 1;
    }

    // Read credit card records.
    struct CardRecord
    {
        string name;
        credit_card card;
    };

    CardRecord cards[100];
    int card_count = 0;
    int number_of_cards = 0;

    cards_file >> number_of_cards;
    cards_file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < number_of_cards && i < 100; ++i)
    {
        string card_name;
        int card_number;
        double limit;
        double balance;

        if (!getline(cards_file, card_name))
            break;

        if (!(cards_file >> card_number >> limit >> balance))
        {
            cerr << "Error reading credit card data." << endl;
            return 1;
        }

        cards_file.ignore(numeric_limits<streamsize>::max(), '\n');

        cards[card_count].name = card_name;
        cards[card_count].card.cc_number = card_number;
        cards[card_count].card.limit = limit;
        cards[card_count].card.current_balance = balance;
        ++card_count;
    }

    // Read customer records.
    string name;
    string phone;

    while (store1.num_customers() < 100 && getline(people_file, name))
    {
        if (name.empty())
            continue;

        if (!getline(people_file, phone))
            break;

        address home;

        if (!getline(people_file, home.address_line1))
            break;
        if (!getline(people_file, home.address_line2))
            break;
        if (!getline(people_file, home.city))
            break;
        if (!getline(people_file, home.state))
            break;
        if (!getline(people_file, home.zip))
            break;

        credit_card customer_card;
        bool card_found = false;

        for (int i = 0; i < card_count; ++i)
        {
            if (cards[i].name == name)
            {
                customer_card = cards[i].card;
                card_found = true;
                break;
            }
        }

        if (!card_found)
        {
            cerr << "Warning: No credit card found for "
                 << name << endl;
        }

        Person customer(name, phone, home, customer_card);
        store1.add_customer(customer);
    }

    // Read product records.
    int number_of_products = 0;

    products_file >> number_of_products;
    products_file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < number_of_products && i < 100; ++i)
    {
        product item;

        if (!getline(products_file, item.name))
            break;
        if (!getline(products_file, item.description))
            break;
        if (!(products_file >> item.price))
            break;

        products_file.ignore(numeric_limits<streamsize>::max(), '\n');
        store1.add_product(item);
    }

    // Display the initial store information.
    cout << "Store info before transactions:" << endl << endl;
    cout << store1.store_info() << endl;

    // Generate between 11 and 99 purchase attempts.
    srand(static_cast<unsigned int>(time(nullptr)));
    int attempts = 11 + rand() % 89;

    cout << "\nAttempting " << attempts << " transactions.\n";

    for (int i = 0; i < attempts; ++i)
    {
        if (store1.num_customers() == 0 ||
            store1.num_products() == 0 ||
            store1.num_transactions() >= 100)
        {
            break;
        }

        int customer_index = rand() % store1.num_customers();
        int product_index = rand() % store1.num_products();
        int quantity = 1 + rand() % 3;

        Person customer = store1.get_customer(customer_index);
        product item = store1.get_product(product_index);

        bool success = store1.make_purchase(customer, item, quantity);

        if (success)
        {
            cout << "Transaction " << i + 1 << " successful: "
                 << customer.name() << " purchased "
                 << quantity << " of " << item.name << "."
                 << endl;
        }
        else
        {
            cout << "Transaction " << i + 1 << " unsuccessful for "
                 << customer.name() << " purchasing "
                 << item.name << "." << endl;
        }
    }

    // Display final store information.
    cout << "\nStore info after transactions:" << endl << endl;
    cout << store1.store_info() << endl;

    return 0;
}
