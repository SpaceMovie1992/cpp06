/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:39:20 by ahusic            #+#    #+#             */
/*   Updated: 2025/03/25 16:23:50 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

enum Type {
		INT,
		CHAR,
		FLOAT,
		DOUBLE,
		INVALID
};

class ScalarConverter
{
public:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &other) = delete;
	ScalarConverter &operator=(const ScalarConverter &other) = delete;
	~ScalarConverter() = delete;

	static void charConvert(const std::string& input);
	static void intConvert(const std::string& input);
	static void floatConvert(const std::string& input);
	static void doubleConvert(const std::string& input);
	static void convert(const std::string& input);

	static Type detectInputType(const std::string& input);
};
bool isChar(const std::string& input);
bool isInt(const std::string& input);
bool isFloat(const std::string& input);
bool isDouble(const std::string& input);
void setDecimalPrecision();
