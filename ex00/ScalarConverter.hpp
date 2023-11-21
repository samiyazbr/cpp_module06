#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <climits>

class ScalarConverter
{
	private :

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const & copy);
		ScalarConverter &operator=(ScalarConverter const &rhs);	
		static void cast_to_char(std::string& str);
        static void cast_to_int(std::string& str);
        static void cast_to_float(std::string& str);
        static void cast_to_double(std::string& str);
		static bool is_pseudo_literal(std::string& s);


	public:

		static void convert(std::string &str);
};

#endif
/* when you make the constructor private user won't be able to make an instance of the class, 
we should use the functions like Class_name::function_name() */