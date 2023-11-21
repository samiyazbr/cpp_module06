#include "ScalarConverter.hpp"

int main() {
    std::string input;

    std::cout << "Enter a value to convert: " ;
    std::getline(std::cin, input);

    ScalarConverter::convert(input);
    return 0;
}
