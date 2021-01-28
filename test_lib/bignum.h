//.h (Прототипы функции)
#pragma once
#include <string>
#include <iostream>
#include <algorithm>

//bignum by NNC. Version: 0.1.4
//ExitCode (1001-1012) = BigNumLib: The object is not a number!

class bignum {
private:
	std::string _value;
	unsigned long long int _size;
	bool _isNum;
	bool _isNegative;
	
	void swap(std::string* str1, std::string* str2);
	void swap(unsigned long long int* num1, unsigned long long int* num2);
	void swap(bool* boo1, bool* boo2);
	bool setIsNum();
	bool comparison(std::string str1, std::string str2);
	bool comparison(const bignum& other);
	void refact_value();
	void const my_exeption(unsigned int exp);
	void const my_exeption(unsigned int exp, const bignum& other);
	std::string sum(std::string str1, std::string str2);
	std::string minus(const bignum& other);
	void sumOne();
	void minusOne();
public:
	bignum();
	bignum(const char* other_value);
	bignum(std::string other_value);
	bignum(long long int other_value);
	bool isNum();
	std::string getValue();
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