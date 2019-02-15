#pragma once
#include <iostream>
#include "BadType.h"
enum class Types {
	UNDEFINED = -1,
	BOOL = 0,
	SIGNED_CHAR = 1,
	UNSIGNED_CHAR = 2,
	WCHAR_T = 3,
	SHORT_INT = 4,
	UNSIGNED_SHORT_INT = 5,
	INT = 6,
	UNSIGNED_INT = 7,
	LONG_INT = 8,
	UNSIGNED_LONG_INT = 9,
	LONG_LONG_INT = 10,
	UNSIGNED_LONG_LONG_INT = 11,
	FLOAT = 12,
	DOUBLE = 13,
	LONG_DOUBLE = 14,
};

class BadType;

class AnyType
{
public:
	AnyType();
	AnyType(const AnyType& Obj);
	AnyType(AnyType&& rhs);
	AnyType(bool bool_type);
	AnyType(signed char signed_char_type);
	AnyType(unsigned char unsigned_char_type);
	AnyType(wchar_t wchar_t_type);
	AnyType(short int short_int_type);
	AnyType(unsigned short int	unsigned_short_int_type);
	AnyType(int int_type);
	AnyType(unsigned int unsigned_int_type);
	AnyType(long int long_int_type);
	AnyType(unsigned long int unsigned_long_int_type);
	AnyType(long long int long_long_int_type);
	AnyType(unsigned long long int	unsigned_long_long_int_type);
	AnyType(float float_type);
	AnyType(double double_type);
	AnyType(long double long_double_type);


	AnyType& operator=(const AnyType& rhs);
	AnyType& operator=(AnyType&& rhs);
	friend std::ostream& operator<<(std::ostream& out, const AnyType& obj);

	void Swap(AnyType& lhs, AnyType& rhs);

	const char* get_TypeName() const;
	bool ToBool() const;
	signed char ToSignedChar() const;
	unsigned char ToUnsignedChar() const;
	wchar_t To_Wchar_t() const;
	short int ToShortInt() const;
	unsigned short int ToUnsignedShortInt() const;
	int ToInt() const;
	unsigned int ToUnsignedInt() const;
	long int ToLongInt() const;
	unsigned long int ToUnsignedLongInt() const;
	long long int ToLongLongInt() const;
	unsigned long long int ToUnsignedLongLongInt() const;
	float ToFloat() const;
	double ToDouble() const;
	long double ToLongDouble() const;


private:
	Types m_type;
	Types get_Type() const { return m_type; }


	union Data
	{
		bool bool_type;

		signed char signed_char_type;
		unsigned char unsigned_char_type;
		wchar_t	wchar_t_type;

		short int short_int_type;
		unsigned short int unsigned_short_int_type;
		int int_type;
		unsigned int unsigned_int_type;
		long int long_int_type;
		unsigned long int unsigned_long_int_type;
		long long int long_long_int_type;
		unsigned long long int unsigned_long_long_int_type;

		float float_type;
		double double_type;
		long double long_double_type;
	} m_data;
};