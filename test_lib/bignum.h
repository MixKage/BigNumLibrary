#pragma once
#include <string>
#include <iostream>
#include <algorithm>

//bignum by NNC. Version: 0.1.6
//ExitCode (1001-1012) = BigNumLib: The object is not a number!
//ExitCode (1013) = BigNumLib: The number has exceeded the limit long long int. No conversion possible!

//By default, it is initialized to 0. It can accept either a string or long long int.
class bignum {
private:
	std::string _value;
	size_t _size;
	bool _isNum;
	bool _isNegative;

	void swap(std::string* str1, std::string* str2);
	void swap(size_t* num1, size_t* num2);
	void swap(bool* boo1, bool* boo2);
	//Checks if a number @return bool
	bool setIsNum();
	bool comparison(std::string str1, std::string str2);
	bool comparison(const bignum& other);
	//Delete "-"
	void refact_value();
	void const my_exeption(unsigned int exp);
	void const my_exeption(unsigned int exp, const bignum& other);
	std::string sum(std::string str1, std::string str2);
	std::string minus(const bignum& other);
	void sumOne();
	void minusOne();
	void ñonvertToInt(long long int* num);
public:
	bignum();
	bignum(const char* other_value);
	bignum(std::string other_value);
	bignum(long long int other_value);
	//Checks if a number @return bool
	bool isNum();
	//@return string
	std::string getValue();
	//@return long long int
	long long getValueInt();

	bignum& operator = (const bignum& other);
	bignum operator + (const bignum& other);
	bignum operator - (const bignum& other);
	bool const operator == (const bignum& other);
	bool const operator != (const bignum& other);
	bool const operator < (const bignum& other);
	bool const operator > (const bignum& other);
	bool const operator <= (const bignum& other);
	bool const operator >=(const bignum& other);
	bignum& operator += (const bignum& other);
	bignum& operator -= (const bignum& other);
	bignum& operator ++();
	bignum& operator --();
	bignum& operator ++(int pref);
	bignum& operator --(int pref);
	friend std::ostream& operator <<(std::ostream& os, const bignum& obj);
	friend std::istream& operator >>(std::istream& is, bignum& obj);
};