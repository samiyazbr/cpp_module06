#include "ScalarConverter.hpp"

/* static_cast is a compile-time cast and provides a way to 
 convert between types in a way that is checked at compile time for correctness. */
 /*
    "nan" - represents a NaN (not a number) value
    "nanf" - represents a NaN (not a number) value with a float suffix
    "+inf" - represents positive infinity
    "inf" - represents positive or negative infinity
    "-inf" - represents negative infinity
    "+inff" - represents positive infinity with a float suffix
    "inff" - represents positive or negative infinity with a float suffix
    "-inff" - represents negative infinity with a float suffix
*/
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::is_pseudo_literal(std::string & s) {
    return s == "nan" || s == "nanf" || s == "+inf" || s == "inf" || s == "-inf"
            || s == "+inff" || s == "inff" || s == "-inff";
}

void ScalarConverter::cast_to_char(std::string &s) {
    if (is_pseudo_literal(s)) {
        std::cout << "Unable to cast" << std::endl;
        return ;
    }
    char c = static_cast<char>(atoi(s.c_str()));
    if (!std::isprint(c)) {
        std::cout << "Non displayable" << std::endl;
        return ;
    }
    std::cout << c  << std::endl;
}

void ScalarConverter::cast_to_int(std::string &s) {
    if (is_pseudo_literal(s)) {
        std::cout << "Unable to cast" << std::endl;
        return ;
    }
    long long value = std::atoll(s.c_str());
    if (value > INT_MAX || value < INT_MIN) {
        std::cout << "Unable to cast" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::cast_to_float(std::string &s) {
    char* end;
    float nbr = std::strtof(s.c_str(), &end);

    //  check if the float value has no decimal part.
    if (*end == '\0' && nbr - static_cast<int>(nbr) == 0) {
        std::cout << nbr << ".0f" << std::endl;
        return ;
    }
    std::cout << nbr << "f" << std::endl;
}

void ScalarConverter::cast_to_double(std::string &s) {
    char * end;
    double nbr = std::strtod(s.c_str(), &end);

    //  check if the double value has no decimal part.
    if (*end == '\0' && nbr - static_cast<int>(nbr) == 0) {
        std::cout << nbr << ".0" << std::endl;
        return ;
    }
    std::cout << nbr << std::endl;
}

void ScalarConverter::convert(std::string &s) {
    std::cout << "char: ", cast_to_char(s);
    std::cout << "int: ", cast_to_int(s);
    std::cout << "float: ", cast_to_float(s);
    std::cout << "double: ", cast_to_double(s);
}   
