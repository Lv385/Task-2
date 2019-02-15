#pragma once
#include <iostream>

const enum Types {
	UNDEFINED = -1,
	BOOL,
	SIGNED_CHAR,
	UNSIGNED_CHAR,
	WCHAR_T,
	SHORT_INT,
	UNSIGNED_SHORT_INT,
	INT = 6,
	UNSIGNED_INT,
	LONG_INT,
	UNSIGNED_LONG_INT,
	LONG_LONG_INT,
	UNSIGNED_LONG_LONG_INT,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE = 14,
};


union DataType
{
	bool bool_t;

	signed char signed_char_t;
	unsigned char unsigned_char_t;
	wchar_t	wchar_t_t;

	short int short_int_t;
	unsigned short int unsigned_short_int_t;
	int int_t;
	unsigned int unsigned_int_t;
	long int long_int_t;
	unsigned long int unsigned_long_int_t;
	long long int long_long_int_t;
	unsigned long long int unsigned_long_long_int_t;

	float float_t;
	double double_t;
	long double long_double_t;
};


class AnyType
{
public:
	AnyType();
	AnyType(const AnyType& holder) = default;
	AnyType(AnyType&& holder);

	AnyType(bool);
	AnyType(signed char);
	AnyType(unsigned char);
	AnyType(wchar_t);
	AnyType(short int);
	AnyType(unsigned short int);
	AnyType(int);
	AnyType(unsigned int);
	AnyType(long int);
	AnyType(unsigned long int);
	AnyType(long long int);
	AnyType(unsigned long long int);
	AnyType(float);
	AnyType(double);
	AnyType(long double);
	~AnyType() = default;

	AnyType& operator=(const AnyType& rhs) = default;
	AnyType& operator=(AnyType&& rhs);
	friend std::ostream& operator<<(std::ostream& out, const AnyType& obj);

	static void Swap(AnyType& lhs, AnyType& rhs);

	const char* get_TypeName() const;

	bool get_Bool() const;
	signed char get_SignedChar() const;
	unsigned char get_UnsignedChar() const;
	wchar_t	get_Wchar_t() const;
	short int get_ShortInt() const;
	unsigned short int get_UnsignedShortInt() const;
	int get_Int() const;
	unsigned int get_UnsignedInt() const;
	long int get_LongInt() const;
	unsigned long int get_UnsignedLongInt() const;
	long long int get_LongLongInt() const;
	unsigned long long int get_UnsignedLongLongInt() const;
	float get_Float() const;
	double get_Double() const;
	long double get_LongDouble() const;
	
private:
	Types get_Type() const { return m_type; }

	Types m_type;
	DataType m_data;
};

