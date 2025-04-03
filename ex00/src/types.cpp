/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:41:24 by ahusic            #+#    #+#             */
/*   Updated: 2025/04/03 22:48:26 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isChar(const std::string& input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return true;
	return false;
}

bool isInt(const std::string& input)
{
	size_t start = 0;
	if (input[0] == '-' || input[0] == '+')
		start = 1;
	for (size_t i = start; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	return !input.empty();
}

bool isFloat(const std::string& input)
{
	if (input == "+inff" || input == "-inff" || input == "nanf")
		return true;
	if (input.back() != 'f' || input.find('.') == std::string::npos)
		return false;

	std::string temp = input.substr(0, input.length() - 1);
	size_t start = 0;
	if (temp[0] == '-' || temp[0] == '+')
		start = 1;

	bool dotFound = false;
	for (size_t i = start; i < temp.size(); i++)
	{
		if (temp[i] == '.')
		{
			if (dotFound)
				return false;
			dotFound = true;
		}
		else if (!isdigit(temp[i]))
			return false;
	}
	return true;
}

bool isDouble(const std::string& input)
{
	if (input == "+inf" || input == "-inf" || input == "nan")
		return true;
	if (input.find('.') == std::string::npos)
		return false;

	std::string temp = input;
	size_t dotPos = temp.find('.');
	temp.erase(dotPos, 1);

	size_t start = 0;
	if (temp[0] == '-' || temp[0] == '+')
		start = 1;

	for (size_t i = start; i < temp.size(); i++)
	{
		if (!isdigit(temp[i]))
			return false;
	}
	return true;
}

void setDecimalPrecision(){
	std::cout << std::fixed;
	std::cout.precision(1);
}

Type ScalarConverter::detectInputType(const std::string& input)
{
	if (isChar(input))
		return CHAR;
	else if (isInt(input))
		return INT;
	else if (isFloat(input))
		return FLOAT;
	else if (isDouble(input))
		return DOUBLE;
	else
		return INVALID;
}
