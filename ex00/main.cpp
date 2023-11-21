#include "ScalarConverter.hpp"

int main() {
    std::string input;

    std::cout << "Enter a value to convert: " ;
    std::getline(std::cin, input);

	    if (is_valid(input)) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    ScalarConverter::convert(input);
    return 0;
}
