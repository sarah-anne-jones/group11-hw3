
#include "credit_card.h"
#include <iomanip>
#include <sstream>

bool credit_card::make_purchase(double purchase_amount)
{
    if (purchase_amount <= 0 ||
        current_balance + purchase_amount > limit)
    {
        return false;
    }

    current_balance += purchase_amount;
    return true;
}

bool credit_card::make_payment(double payment_amount)
{
    if (payment_amount <= 0 ||
        payment_amount > current_balance)
    {
        return false;
    }

    current_balance -= payment_amount;
    return true;
}

std::string credit_card::credit_card_info()
{
    std::ostringstream output;

    output << "Credit card number: " << cc_number << '\n';
    output << std::fixed << std::setprecision(2);
    output << "Credit Card Limit: $" << limit << '\n';
    output << "Current Balance: $" << current_balance;

    return output.str();
}
//implementation code for credit_card struct here
