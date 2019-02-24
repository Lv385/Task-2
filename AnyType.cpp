#include "stdafx.h"
#include "AnyType.h"
#include "BadType.h"

AnyType::AnyType()
{

}
AnyType::AnyType(const AnyType & rhs)
{
	m_type = rhs.m_type;
	m_data = rhs.m_data;
}

AnyType::AnyType(AnyType&& rhs)
{
	this->m_data = std::move(rhs.m_data);
	this->m_type = std::move(rhs.m_type);
	rhs.m_type = Types::UNDEFINED;
}


AnyType::AnyType(bool bool_type): m_type(Types::BOOL)
{
	m_data.bool_type = bool_type;
}

AnyType::AnyType(signed char signed_char_type): m_type(Types::SIGNED_CHAR)
{
	m_data.signed_char_type = signed_char_type;
}

AnyType::AnyType(unsigned char unsigned_char_type): m_type(Types::UNSIGNED_CHAR)
{
	m_data.unsigned_char_type = unsigned_char_type;
}

AnyType::AnyType(wchar_t wchar_t_type): m_type(Types::WCHAR_T)
{
	m_data.wchar_t_type = wchar_t_type;
}

AnyType::AnyType(short int short_int_type): m_type(Types::SHORT_INT)
{
	m_data.short_int_type = short_int_type;
}

AnyType::AnyType(unsigned short int unsigned_short_int_type): m_type(Types::UNSIGNED_SHORT_INT)
{
	m_data.unsigned_short_int_type = unsigned_short_int_type;
}

AnyType::AnyType(int int_type): m_type(Types::INT)
{
	m_data.int_type = int_type;
}

AnyType::AnyType(unsigned int unsigned_int_type): m_type(Types::UNSIGNED_INT)
{
	m_data.unsigned_int_type = unsigned_int_type;
}

AnyType::AnyType(long int long_int_type): m_type(Types::LONG_INT)
{
	m_data.long_int_type = long_int_type;
}

AnyType::AnyType(unsigned long int unsigned_long_int_type): m_type(Types::UNSIGNED_LONG_INT)
{
	m_data.unsigned_long_int_type = unsigned_long_int_type;
}

AnyType::AnyType(long long int long_long_int_type): m_type(Types::LONG_LONG_INT)
{
	m_data.long_long_int_type = long_long_int_type;
}

AnyType::AnyType(unsigned long long int unsigned_long_long_int_type): m_type(Types::UNSIGNED_LONG_LONG_INT)
{
	m_data.unsigned_long_long_int_type = unsigned_long_long_int_type;
}

AnyType::AnyType(float float_type): m_type(Types::FLOAT)
{
	m_data.float_type = float_type;
}

AnyType::AnyType(double double_type): m_type(Types::DOUBLE)
{
	m_data.double_type = double_type;
}

AnyType::AnyType(long double long_double_type): m_type(Types::LONG_DOUBLE)
{
	m_data.long_double_type = long_double_type;
}

AnyType& AnyType::operator=(const AnyType & rhs)
{
	if (this != &rhs)
	{
		AnyType copy(rhs);
		Swap(copy, *this);
	}
	return *this;
}

AnyType& AnyType::operator=(AnyType && rhs)
{
	if (this != &rhs)
	{
		this->m_data = std::move(rhs.m_data);
		this->m_type = std::move(rhs.m_type);

		rhs.m_type = Types::UNDEFINED;
	}
	return *this;
}

void AnyType::Swap(AnyType & lhs, AnyType & rhs)
{
	std::swap(lhs.m_data, rhs.m_data);
	std::swap(lhs.m_type, rhs.m_type);
}

const char * AnyType::get_TypeName() const
{
	switch (m_type)
	{
	case Types::BOOL:
		return "bool";
	case Types::SIGNED_CHAR:
		return "signed char";
	case Types::UNSIGNED_CHAR:
		return "unsigned char";
	case Types::WCHAR_T:
		return "wchar_t";
	case Types::SHORT_INT:
		return "short int";
	case Types::UNSIGNED_SHORT_INT:
		return "unsigned short int";
	case Types::INT:
		return "int";
	case Types::UNSIGNED_INT:
		return "unsigned int";
	case Types::LONG_INT:
		return "long int";
	case Types::UNSIGNED_LONG_INT:
		return "unsigned long int";
	case Types::LONG_LONG_INT:
		return "long long int";
	case Types::UNSIGNED_LONG_LONG_INT:
		return "unsigned long long int";
	case Types::FLOAT:
		return "float";
	case Types::DOUBLE:
		return "double";
	case Types::LONG_DOUBLE:
		return "long double";
	default:
		return "type undefined";
	}
}

bool AnyType::ToBool() const
{
	if (m_type != Types::BOOL)
		throw BadType();
	else
		return m_data.bool_type;
}

signed char AnyType::ToSignedChar() const
{
	if (m_type != Types::SIGNED_CHAR)
		throw BadType();
	else
		return m_data.signed_char_type;
}

unsigned char AnyType::ToUnsignedChar() const
{
	if (m_type != Types::UNSIGNED_CHAR)
		throw BadType();
	else
		return m_data.unsigned_char_type;
}

wchar_t AnyType::To_Wchar_t() const
{
	if (m_type != Types::WCHAR_T)
		throw BadType();
	else
		return m_data.wchar_t_type;
}

short int AnyType::ToShortInt() const
{
	if (m_type != Types::SHORT_INT)
		throw BadType();
	else
		return m_data.short_int_type;
}

unsigned short int AnyType::ToUnsignedShortInt() const
{
	if (m_type != Types::UNSIGNED_SHORT_INT)
		throw BadType();
	else
		return m_data.unsigned_short_int_type;
}

int AnyType::ToInt() const
{
	if (m_type != Types::INT)
		throw BadType();
	else
		return m_data.int_type;
}

unsigned int AnyType::ToUnsignedInt() const
{
	if (m_type != Types::UNSIGNED_INT)
		throw BadType();
	else
		return m_data.unsigned_int_type;
}

long int AnyType::ToLongInt() const
{
	if (m_type != Types::LONG_INT)
		throw BadType();
	else
		return m_data.long_int_type;
}

unsigned long int AnyType::ToUnsignedLongInt() const
{
	if (m_type != Types::UNSIGNED_LONG_INT)
		throw BadType();
	else
		return m_data.unsigned_long_int_type;
}

long long int AnyType::ToLongLongInt() const
{
	if (m_type != Types::LONG_LONG_INT)
		throw BadType();
	else
		return m_data.long_long_int_type;
}

unsigned long long int AnyType::ToUnsignedLongLongInt() const
{
	if (m_type != Types::UNSIGNED_LONG_LONG_INT)
		throw BadType();
	else
		return m_data.unsigned_long_long_int_type;
}

float AnyType::ToFloat() const
{
	if (m_type != Types::FLOAT)
		throw BadType();
	else
		return m_data.float_type;
}

double AnyType::ToDouble() const
{
	if (m_type != Types::DOUBLE)
		throw BadType();
	else
		return m_data.double_type;
}

long double AnyType::ToLongDouble() const
{
	if (m_type != Types::LONG_DOUBLE)
		throw BadType();
	else
		return m_data.long_double_type;
}

std::ostream & operator<<(std::ostream & out, const AnyType & obj)
{
	out << obj.get_TypeName() << ": ";

	switch (obj.get_Type())
	{
	case Types::BOOL:
		return out << obj.m_data.bool_type;
	case Types::SIGNED_CHAR:
		return out << obj.m_data.signed_char_type;
	case Types::UNSIGNED_CHAR:
		return out << obj.m_data.unsigned_char_type;
	case Types::WCHAR_T:
		return out << obj.m_data.wchar_t_type;
	case Types::SHORT_INT:
		return out << obj.m_data.short_int_type;
	case Types::UNSIGNED_SHORT_INT:
		return out << obj.m_data.unsigned_short_int_type;
	case Types::INT:
		return out << obj.m_data.int_type;
	case Types::UNSIGNED_INT:
		return out << obj.m_data.unsigned_int_type;
	case Types::LONG_INT:
		return out << obj.m_data.long_int_type;
	case Types::UNSIGNED_LONG_INT:
		return out << obj.m_data.unsigned_long_int_type;
	case Types::LONG_LONG_INT:
		return out << obj.m_data.long_long_int_type;
	case Types::UNSIGNED_LONG_LONG_INT:
		return out << obj.m_data.unsigned_long_long_int_type;
	case Types::FLOAT:
		return out << obj.m_data.float_type;
	case Types::DOUBLE:
		return out << obj.m_data.double_type;
	case Types::LONG_DOUBLE:
		return out << obj.m_data.long_double_type;
		// Types::UNDEFINED or other
	default:
		return out << "can't represent data";
	}
}

