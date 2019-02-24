#include "AnyType.h"
#include "WrongType.h"

const char* types_array[] = { "bool", "signed char", "unsigned char", "wchar_t", "short int", "unsigned short int", "int", "unsigned int",
							 "long int", "unsigned long int", "long long int", "unsigned long long int", "float", "double", "long double" };

AnyType::AnyType() : m_type(Types::UNDEFINED) {}

AnyType::AnyType(AnyType&& obj)
{
	m_type = std::move(obj.m_type);
	m_data = std::move(obj.m_data);

	obj.m_type = Types::UNDEFINED;
}

AnyType::AnyType(bool obj) : m_type(Types::BOOL)
{
	m_data.bool_t = obj;
}

AnyType::AnyType(signed char obj) : m_type(Types::SIGNED_CHAR)
{
	m_data.signed_char_t = obj;
}

AnyType::AnyType(unsigned char obj) : m_type(Types::UNSIGNED_CHAR)
{
	m_data.unsigned_char_t = obj;
}

AnyType::AnyType(wchar_t obj) : m_type(Types::WCHAR_T)
{
	m_data.wchar_t_t = obj;
}

AnyType::AnyType(short int obj) : m_type(Types::SHORT_INT)
{
	m_data.short_int_t = obj;
}

AnyType::AnyType(unsigned short int obj) : m_type(Types::UNSIGNED_SHORT_INT)
{
	m_data.unsigned_short_int_t = obj;
}

AnyType::AnyType(int obj) : m_type(Types::INT)
{
	m_data.int_t = obj;
}

AnyType::AnyType(unsigned int obj) : m_type(Types::UNSIGNED_INT)
{
	m_data.unsigned_int_t = obj;
}

AnyType::AnyType(long int obj) : m_type(Types::LONG_INT)
{
	m_data.long_int_t = obj;
}

AnyType::AnyType(unsigned long int obj) : m_type(Types::UNSIGNED_LONG_INT)
{
	m_data.unsigned_long_int_t = obj;
}

AnyType::AnyType(long long int obj) : m_type(Types::LONG_LONG_INT)
{
	m_data.long_long_int_t = obj;
}

AnyType::AnyType(unsigned long long int obj) : m_type(Types::UNSIGNED_LONG_LONG_INT)
{
	m_data.unsigned_long_long_int_t = obj;
}

AnyType::AnyType(float obj) : m_type(Types::FLOAT)
{
	m_data.float_t = obj;
}

AnyType::AnyType(double obj) : m_type(Types::DOUBLE)
{
	m_data.double_t = obj;
}

AnyType::AnyType(long double obj) : m_type(Types::LONG_DOUBLE)
{
	m_data.long_double_t = obj;
}


std::ostream & operator<<(std::ostream & out, const AnyType & obj)
{
	out << obj.get_TypeName() << ": ";

	switch (obj.get_Type())
	{
	case Types::BOOL:
		return out << obj.m_data.bool_t;
	case Types::SIGNED_CHAR:
		return out << obj.m_data.signed_char_t;
	case Types::UNSIGNED_CHAR:
		return out << obj.m_data.unsigned_char_t;
	case Types::WCHAR_T:
		return out << obj.m_data.wchar_t_t;
	case Types::SHORT_INT:
		return out << obj.m_data.short_int_t;
	case Types::UNSIGNED_SHORT_INT:
		return out << obj.m_data.unsigned_short_int_t;
	case Types::INT:
		return out << obj.m_data.int_t;
	case Types::UNSIGNED_INT:
		return out << obj.m_data.unsigned_int_t;
	case Types::LONG_INT:
		return out << obj.m_data.long_int_t;
	case Types::UNSIGNED_LONG_INT:
		return out << obj.m_data.unsigned_long_int_t;
	case Types::LONG_LONG_INT:
		return out << obj.m_data.long_long_int_t;
	case Types::UNSIGNED_LONG_LONG_INT:
		return out << obj.m_data.unsigned_long_long_int_t;
	case Types::FLOAT:
		return out << obj.m_data.float_t;
	case Types::DOUBLE:
		return out << obj.m_data.double_t;
	case Types::LONG_DOUBLE:
		return out << obj.m_data.long_double_t;

	default:
		return out << "can't represent data";
	}
}


AnyType & AnyType::operator=(AnyType && rhs)
{
	m_data = std::move(rhs.m_data);
	m_type = std::move(rhs.m_type);

	rhs.m_type = Types::UNDEFINED;
	return *this;
}

void AnyType::Swap(AnyType & lhs, AnyType & rhs)
{
	std::swap(lhs.m_type, rhs.m_type);
	std::swap(lhs.m_data, rhs.m_data);
}

const char* AnyType::get_TypeName() const
{
	if (m_type == Types::UNDEFINED)
		return "type undefined";
	else
		return types_array[m_type];
}


bool AnyType::get_Bool() const
{
	if (m_type != Types::BOOL)
		throw WrongType();
	else
		return m_data.bool_t;
}

signed char AnyType::get_SignedChar() const
{
	if (m_type != Types::SIGNED_CHAR)
		throw WrongType();
	else
		return m_data.signed_char_t;
}

unsigned char AnyType::get_UnsignedChar() const
{
	if (m_type != Types::UNSIGNED_CHAR)
		throw WrongType();
	else
		return m_data.unsigned_char_t;
}

wchar_t AnyType::get_Wchar_t() const
{
	if (m_type != Types::WCHAR_T)
		throw WrongType();
	else
		return m_data.wchar_t_t;
}

short int AnyType::get_ShortInt() const
{
	if (m_type != Types::SHORT_INT)
		throw WrongType();
	else
		return m_data.short_int_t;
}

unsigned short int AnyType::get_UnsignedShortInt() const
{
	if (m_type != Types::UNSIGNED_SHORT_INT)
		throw WrongType();
	else
		return m_data.unsigned_short_int_t;
}

int AnyType::get_Int() const
{
	if (m_type != Types::INT)
		throw WrongType();
	else
		return m_data.int_t;
}

unsigned int AnyType::get_UnsignedInt() const
{
	if (m_type != Types::UNSIGNED_INT)
		throw WrongType();
	else
		return m_data.unsigned_int_t;
}

long int AnyType::get_LongInt() const
{
	if (m_type != Types::LONG_INT)
		throw WrongType();
	else
		return m_data.long_int_t;
}

unsigned long int AnyType::get_UnsignedLongInt() const
{
	if (m_type != Types::UNSIGNED_LONG_INT)
		throw WrongType();
	else
		return m_data.unsigned_long_int_t;
}

long long int AnyType::get_LongLongInt() const
{
	if (m_type != Types::LONG_LONG_INT)
		throw WrongType();
	else
		return m_data.long_long_int_t;
}

unsigned long long int AnyType::get_UnsignedLongLongInt() const
{
	if (m_type != Types::UNSIGNED_LONG_LONG_INT)
		throw WrongType();
	else
		return m_data.unsigned_long_long_int_t;
}

float AnyType::get_Float() const
{
	if (m_type != Types::FLOAT)
		throw WrongType();
	else
		return m_data.float_t;
}

double AnyType::get_Double() const
{
	if (m_type != Types::DOUBLE)
		throw WrongType();
	else
		return m_data.double_t;
}

long double AnyType::get_LongDouble() const
{
	if (m_type != Types::LONG_DOUBLE)
		throw WrongType();
	else
		return m_data.long_double_t;
}