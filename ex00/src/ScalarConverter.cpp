/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:23:16 by ahusic            #+#    #+#             */
/*   Updated: 2025/03/25 16:34:56 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::charConvert(const std::string& input)
{
	char c = input[0];
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " <<static_cast<double>(c) << std::endl;
}

void ScalarConverter::intConvert(const std::string& input)
{
	try
	{
		int i = std::stoi(input);

		if (i > 127 || i < 0)
			std::cout << "char: impossible" << std::endl;
		else if (i < 32 || i == 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(i) << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error with input: " << input << ", " << e.what() << std::endl;
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	}
}

void ScalarConverter::floatConvert(const std::string& input)
{
	try
	{
		float f = std::stof(input);

		if (input == "+inff" || input == "-inff" || input == "nanf")
			std::cout << "char: impossible\nint: impossible" << std::endl;
		else
		{
			if (std::truncf(f) != f || f > 127 || f < 0)
				std::cout << "char: impossible" << std::endl;
			else if (f < 32 || f == 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(f) << std::endl;
			if (std::truncf(f) != f)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(f) << std::endl;
		}
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error with input: " << input << ", " << e.what() << std::endl;
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	}
}

void ScalarConverter::doubleConvert(const std::string& input)
{
	try
	{
		double d = std::stod(input);
		if (input == "+inf" || input == "-inf" || input == "nan")
			std::cout << "char: impossible\nint: impossible" << std::endl;
		else
		{
			if (std::truncf(d) != d || d > 127 || d < 0)
				std::cout << "char: impossible" << std::endl;
			else if (d < 32 || d == 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(d) << std::endl;
			if (std::truncf(d) != d)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(d) << std::endl;
		}
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error with input: " << input << ", " << e.what() << std::endl;
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& input)
{
	if (input.empty())
	{
		std::cerr << "Invalid input" << std::endl;
		return;
	}
	setDecimalPrecision();
	switch (detectInputType(input))
	{
	case CHAR:
		charConvert(input);
		break;
	case INT:
		intConvert(input);
		break;
	case FLOAT:
		floatConvert(input);
		break;
	case DOUBLE:
		doubleConvert(input);
		break;
	case INVALID:
		std::cerr << "Invalid input" << std::endl;
		break;
	}
}
