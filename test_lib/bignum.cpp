#include "bignum.h"


bignum::bignum()
{
	_value = "0";
	_size = 1;
	_isNegative = false;
}


bignum::bignum(long long other_value)
{
	_isNegative = other_value < 0 ? true : false;
	_value = _isNegative ? std::to_string(other_value).erase(0, 1) : std::to_string(other_value);
	_size = _value.size();
}


bignum::bignum(const char* other_value)
{
	_value = other_value;
	parsStringToBigNumParams();
}


bignum::bignum(std::string other_value)
{
	_value = other_value;
	parsStringToBigNumParams();
}


std::string bignum::getValue()
{
	std::string _value = this->_value;
	if (this->_isNegative)
		_value.insert(0, "-");
	return _value;
}


long long bignum::getValueInt()
{
	if ((*this > LLONG_MAX) || (*this < LLONG_MIN))
		my_exeption(1013);
	long long int answer{};
	for (size_t i = 0; i < this->_size; i++)
	{
		answer += this->_value[i] - '0';
		if (i != this->_size - 1)
			answer *= 10;
	}
	if (this->_isNegative)
		answer *= -1;
	return answer;
}


void bignum::parsStringToBigNumParams()
{
	if (_value[0] == '-') {
		_value = _value.erase(0, 1);
		_isNegative = true;
	}
	else
		_isNegative = false;
	if (_value.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error(_value + " it's not a number!");
	_size = _value.size();
}


void bignum::swap(std::string* str1, std::string* str2)
{
	std::string temp{};
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}


void bignum::swap(size_t* num1, size_t* num2)
{
	size_t temp{};
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


void bignum::swap(bool* boo1, bool* boo2)
{
	bool temp;
	temp = *boo1;
	*boo1 = *boo2;
	*boo2 = temp;
}


bool bignum::comparison(std::string str1, std::string str2)
{
	if (str1.size() != str2.size())
	{
		if (str1.size() > str2.size())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	for (size_t i = 0; i < this->_size; i++)
	{
		if (!(str1[i] == str2[i]))
		{
			int num1 = (str1[i] - '0');
			int num2 = (str2[i] - '0');
			if (num1 == num2)
				continue;
			if (num1 < num2)
				return true;
			return false;
		}
	}
	return false;
}


bool bignum::comparison(const bignum& other)
{
	int negative_1 = 1;
	int negative_2 = 1;
	bool negative_on = false;
	if (this->_isNegative == true)
	{
		negative_1 = -1;
		negative_on = true;
	}
	if (other._isNegative == true)
	{
		negative_2 = -1;
		negative_on = true;
	}
	for (size_t i = 0; i < this->_size; i++)
	{
		if (!(this->_value[i] == other._value[i]) || (negative_on))
		{
			int num1 = (this->_value[i] - '0') * negative_1;
			int num2 = (other._value[i] - '0') * negative_2;
			if (num1 == num2)
				continue;
			if (num1 < num2)
				return true;
			return false;
		}
	}
	return false;
}


std::string bignum::sum(std::string str1, std::string str2)
{
	size_t lenght1 = str1.length();
	size_t lenght2 = str2.length();
	int temp = 0;
	std::string answer{};
	if (lenght1 > lenght2)
	{
		swap(&str1, &str2);
		swap(&lenght1, &lenght2);
	}

	std::reverse(str1.begin(), str1.end());
	std::reverse(str2.begin(), str2.end());

	short int residue = 0;
	for (size_t i = 0; i < lenght1; i++)
	{
		short int sum = ((str1[i] - '0') + (str2[i] - '0') + residue);
		answer.push_back(sum % 10 + '0');
		residue = sum / 10;
	}
	for (size_t i = lenght1; i < lenght2; i++)
	{
		short int sum = ((str2[i] - '0') + residue);
		answer.push_back(sum % 10 + '0');
		residue = sum / 10;
	}
	if (residue)
	{
		answer.push_back(residue + '0');
	}
	reverse(answer.begin(), answer.end());
	return answer;
}


std::string bignum::minus(const bignum& other)
{
	size_t lenght1 = this->_size;
	size_t lenght2 = other._size;
	std::string str1 = this->_value;
	std::string str2 = other._value;
	bool Neg1 = this->_isNegative;
	bool Neg2 = other._isNegative;
	int temp = 0;
	bool isNegative = false;
	std::string answer{};
	if (comparison(str1, str2))
	{
		swap(&str1, &str2);
		swap(&lenght1, &lenght2);
		swap(&Neg1, &Neg2);
	}

	std::reverse(str1.begin(), str1.end());
	std::reverse(str2.begin(), str2.end());

	short int residue = 0;
	int temp1 = 0;
	int temp2 = 0;

	for (size_t i = 0; i < lenght2; i++)
	{
		temp1 = str1[i] - '0';
		temp2 = str2[i] - '0';
		if (temp1 < temp2)
		{
			size_t l = i + 1;
			while (str1[l] == 0)
			{
				str1[l] = '9';
				l++;
			}
			str1[l] = str1[l] - 1;
			temp1 += 10;
		}
		short int sum = temp1 - temp2;
		answer.push_back(sum + '0');
	}
	for (size_t i = lenght2; i < lenght1; i++)
	{
		short int sum = str1[i] - '0';
		answer.push_back(sum + '0');
	}
	reverse(answer.begin(), answer.end());
	return answer;
}


void bignum::sumOne()
{
	std::reverse(this->_value.begin(), this->_value.end());
	short int residue = 0;
	short int sum = 0;
	for (size_t i = 0; i < this->_size; i++)
	{
		if (i == 0)
		{
			sum = ((this->_value[i] - '0') + ('1' - '0') + residue);
		}
		else
		{
			sum = ((this->_value[i] - '0') + residue);
		}
		this->_value[i] = (sum % 10 + '0');
		residue = sum / 10;
	}
	if (residue)
	{
		this->_value.push_back(residue + '0');
	}
	if (this->_value == "0")
		this->_isNegative = false;
	else
		std::reverse(this->_value.begin(), this->_value.end());
}


void bignum::minusOne()
{
	std::reverse(this->_value.begin(), this->_value.end());
	short int residue = 0;
	short int sum = 0;
	for (size_t i = 0; i < this->_size; i++)
	{
		if (i == 0)
		{
			sum = ((this->_value[i] - '0') - ('1' - '0') + residue);
		}
		else
		{
			sum = ((this->_value[i] - '0') + residue);
		}
		this->_value[i] = (sum % 10 + '0');
		residue = sum / 10;
	}
	if (residue)
	{
		this->_value.push_back(residue + '0');
	}
	if (this->_value == "0")
		this->_isNegative = false;
	else
		std::reverse(this->_value.begin(), this->_value.end());
}


bignum& bignum::operator =(const bignum& other)
{
	this->_value = other._value;
	this->_size = other._size;
	this->_isNegative = other._isNegative;
	return *this;
}

//TODO: ÔÓ‚ÂËÚ¸ ÙÛÌÍˆË˛
bignum bignum::operator +(const bignum& other)
{
	bignum num3;
	bool Negative = false;
	if ((this->_isNegative) && !(other._isNegative))
	{
		num3 = minus(other);
		if (comparison(this->_value, other._value))
			Negative = false;
		else
			Negative = true;
	}
	else if (!(this->_isNegative) && (other._isNegative))
	{
		num3 = minus(other);
		if (comparison(this->_value, other._value))
			Negative = true;
		else
			Negative = false;
	}
	else
		num3 = sum(this->_value, other._value);
	if ((this->_isNegative) && (other._isNegative))
		Negative = true;
	if (Negative == true)
		num3._isNegative = true;
	//num3.setIsNum(); ¬Œ«ÃŒ∆Õ€ Œÿ»¡ » »«-«¿ ”ƒ¿À≈Õ»ﬂ setIsNum() ÔÓ‚ÂÍ‡ Ì‡ ˜ËÒÎÓ
	return num3;
}

//TODO: ÔÓ‚ÂËÚ¸ ÙÛÌÍˆË˛
bignum bignum::operator -(const bignum& other)
{
	bignum num3;
	bool Negative = false;
	if (!(this->_isNegative) && (other._isNegative))
	{
		num3 = sum(this->_value, other._value);
		Negative = false;
	}
	else if ((this->_isNegative) && !(other._isNegative))
	{
		num3 = sum(this->_value, other._value);
		Negative = true;
	}
	else if ((this->_isNegative) && (other._isNegative))
	{
		num3 = minus(other);
		if (comparison(this->_value, other._value))
			Negative = false;
		else
			Negative = true;
	}
	else if ((!(this->_isNegative) && !(other._isNegative)))
	{
		num3 = minus(other);
		if (comparison(this->_value, other._value))
			Negative = true;
		else
			Negative = false;
	}
	if (Negative == true)
		num3._isNegative = true;
	//num3.setIsNum(); ¬Œ«ÃŒ∆Õ€ Œÿ»¡ » »«-«¿ ”ƒ¿À≈Õ»ﬂ setIsNum() ÔÓ‚ÂÍ‡ Ì‡ ˜ËÒÎÓ
	return num3;
}



bignum& bignum::operator++()
{
	if (this->_isNegative)
		minusOne();
	else
		sumOne();
	this->_size = this->_value.size();
	return *this;
}


bignum& bignum::operator--()
{
	if (this->_isNegative)
		sumOne();
	else
		minusOne();
	this->_size = this->_value.size();
	return *this;
}


bignum& bignum::operator++(int pref)
{
	if (this->_isNegative)
		minusOne();
	else
		sumOne();
	this->_size = this->_value.size();
	return *this;
}


bignum& bignum::operator--(int pref)
{
	if (this->_isNegative)
		sumOne();
	else
		minusOne();
	this->_size = this->_value.size();
	return *this;
}


bool const bignum::operator ==(const bignum& other)
{
	if ((this->_isNegative != other._isNegative)
		|| (this->_size != other._size) || (this->_value != other._value))
	{
		return false;
	}
	return true;
}


bool const bignum::operator !=(const bignum& other)
{
	if ((this->_size != other._size) || (this->_isNegative != other._isNegative))
		return true;
	if ((this->_value == other._value))
	{
		return false;
	}
	return true;
}


bool const bignum::operator <(const bignum& other)
{
	if (this->_isNegative && !(other._isNegative))
		return true;
	else if (!(this->_isNegative) && other._isNegative)
		return false;
	else if ((this->_size > other._size) && !(this->_isNegative) && !(other._isNegative))
		return false;
	else if ((this->_size < other._size) && !(this->_isNegative) && !(other._isNegative))
		return true;
	else if ((this->_size > other._size) && this->_isNegative && other._isNegative)
		return true;
	else if ((this->_size < other._size) && this->_isNegative && other._isNegative)
		return false;
	else if ((this->_value == other._value) && (this->_isNegative == other._isNegative))
		return false;
	return comparison(other);
}


bool const bignum::operator >(const bignum& other)
{
	if (this->_isNegative && !(other._isNegative))
		return false;
	else if (!(this->_isNegative) && other._isNegative)
		return true;
	else if ((this->_size > other._size) && !(this->_isNegative) && !(other._isNegative))
		return true;
	else if ((this->_size < other._size) && !(this->_isNegative) && !(other._isNegative))
		return false;
	else if ((this->_size > other._size) && this->_isNegative && other._isNegative)
		return false;
	else if ((this->_size < other._size) && this->_isNegative && other._isNegative)
		return true;
	else if ((this->_value == other._value) && (this->_isNegative == other._isNegative))
		return false;
	return !comparison(other);
}


bool const bignum::operator <=(const bignum& other)
{
	if (this->_isNegative && !(other._isNegative))
		return true;
	else if (!(this->_isNegative) && other._isNegative)
		return false;
	else if ((this->_size > other._size) && !(this->_isNegative) && !(other._isNegative))
		return false;
	else if ((this->_size < other._size) && !(this->_isNegative) && !(other._isNegative))
		return true;
	else if ((this->_size > other._size) && this->_isNegative && other._isNegative)
		return true;
	else if ((this->_size < other._size) && this->_isNegative && other._isNegative)
		return false;
	else if ((this->_value == other._value) && (this->_isNegative == other._isNegative))
		return true;
	return comparison(other);
}


bool const bignum::operator >=(const bignum& other)
{
	if (this->_isNegative && !(other._isNegative))
		return false;
	else if (!(this->_isNegative) && other._isNegative)
		return true;
	else if ((this->_size > other._size) && !(this->_isNegative) && !(other._isNegative))
		return true;
	else if ((this->_size < other._size) && !(this->_isNegative) && !(other._isNegative))
		return false;
	else if ((this->_size > other._size) && this->_isNegative && other._isNegative)
		return false;
	else if ((this->_size < other._size) && this->_isNegative && other._isNegative)
		return true;
	else if ((this->_value == other._value) && (this->_isNegative == other._isNegative))
		return true;
	return !comparison(other);
}


bignum& bignum::operator+=(const bignum& other)
{
	*this = *this + other;
	return *this;
}

bignum& bignum::operator-=(const bignum& other)
{
	*this = *this - other;
	return *this;
}


std::ostream& operator <<(std::ostream& os, const bignum& obj)
{
	std::string _value = obj._value;
	if (obj._isNegative)
		_value.insert(0, "-");
	os << _value;
	return os;
}

//TODO: ÔÓ‚ÂËÚ¸ ˝ÚÛ ÙÛÍÌˆË˛.
std::istream& operator >>(std::istream& is, bignum& obj)
{
	is >> obj._value;
	obj._size = obj._value.size();
	obj._isNegative = false;
	//obj._isNum = obj.setIsNum(); ¬Œ«ÃŒ∆Õ€ Œÿ»¡ » »«-«¿ ”ƒ¿À≈Õ»ﬂ ‘”Õ ÷»» setIsNum (ÔÓ‚ÂÍ‡ Ì‡ ˜ËÒÎÓ)
	return is;
}


void const bignum::my_exeption(unsigned exp)
{
	std::string _operator{};
	std::string _error{};
	switch (exp)
	{
	case(1001):
		_operator = "<";
		break;
	case(1003):
		_operator = ">";
		break;
	case(1005):
		_operator = "<=";
		break;
	case(1007):
		_operator = ">=";
		break;
	case(1009):
		_operator = "++";
		break;
	case(1010):
		_operator = "--";
		break;
	case(1013):
		_error = "The number has exceeded the limit long long int. No conversion possible!\n";
		break;
	default:
		break;
	}
	if (_error == "")
		_error = "BigNumLib: The object is not a number! The operator gave the error '" + _operator + "'\n";
	if (this->_isNegative)
		_error += "\nVariable properties:\nValue: -" + this->_value;
	else
		_error += "\nVariable properties:\nValue: " + this->_value;
	_error += "\nSize: " + std::to_string(this->_size);
	throw std::runtime_error(_error);
}


void const bignum::my_exeption(unsigned exp, const bignum& other)
{
	std::string _operator = {};
	bool TwoVariables = false;
	switch (exp)
	{
	case(1002):
		_operator = "<";
		break;
	case(1004):
		_operator = ">";
		break;
	case(1006):
		_operator = "<=";
		break;
	case(1008):
		_operator = ">=";
		break;
	case(1011):
		_operator = "+";
		TwoVariables = true;
		break;
	case(1012):
		_operator = "-";
		TwoVariables = true;
		break;
	default:
		break;
	}
	auto _error = "BigNumLib: The object is not a number! The operator gave the error '" + _operator + "'\n";

	if (TwoVariables)
	{
		if (this->_isNegative)
			_error += "\nVariable properties:\nValue: -" + this->_value;
		else
			_error += "\nVariable properties:\nValue: " + this->_value;
		_error += "\nSize: " + std::to_string(this->_size);
		_error += "\n";
	}
	if (other._isNegative)
		_error += "\nVariable properties:\nValue: -" + other._value;
	else
		_error += "\nVariable properties:\nValue: " + other._value;
	_error += "\nSize: " + std::to_string(other._size);
	throw std::runtime_error(_error);
}
