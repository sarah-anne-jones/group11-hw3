#include "product.h"
#include <sstream>
#include <iomanip>

std::string product::product_info()
{
    std::ostringstream output;

    output << "Product Name: " << name << '\n';
    output << "Description: " << description << '\n';
    output << std::fixed << std::setprecision(2);
    output << "Price: $" << price;

    return output.str();
}
//code for product struct here
