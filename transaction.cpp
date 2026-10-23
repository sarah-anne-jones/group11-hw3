#include "transaction.h"
#include <sstream>
#include <iomanip>

std::string transaction::transaction_info()
{
    std::ostringstream output;

    output << "Transaction Number: " << transaction_number << '\n';
    output << "Customer:\n";
    output << customer.person_info() << '\n';
    output << "Purchased Item:\n";
    output << purchased_item.product_info() << '\n';
    output << "Quantity: " << quantity << '\n';

    output << std::fixed << std::setprecision(2);
    output << "Total: $" << purchased_item.price * quantity;

    return output.str();
}

