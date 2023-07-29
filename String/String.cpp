#include"String.h"

/////////////////////////////////////////////////////////////////////////////////////
///////////////				    Class definition					/////////////////

//:: - Scope operator
//scope::name
//namespace::name 
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

// ---------- Constructors -----------
// 'explicit' can use only in the class.
String::String(int size /*= 80*/) :size(size), str(new char[size] {})
// the dafault parameters are use only in the declaration;
{
	std::cout << " + Default constructor:\t" << this << std::endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	std::cout << " + Constructor:\t\t" << this << std::endl;
}
String::String(const String& other) : String(other.str)
{
	//Deep copy
	std::cout << " + Copy constructor:\t" << this << std::endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{
	//Shallow copy:
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = 0;
	std::cout << " + Move constructor: \t" << this << std::endl;
}
String::~String()
{
	delete[] str;
	std::cout << " ~ Destructor:\t\t" << this << std::endl;
}

// ---------- Operators ----------
//type  name  (parameters)
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	int a = 2;
	int b = 3;
	a = b;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	std::cout << " + CopyAssignment:\t" << this << std::endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;

	other.size = 0;
	other.str = nullptr;
	std::cout << " + MoveAssignment:\t" << this << std::endl;
	return *this;
}
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

// ---------- Methods ----------
void String::print()const
{
	std::cout << "Size:\t" << size << std::endl;
	std::cout << "Str:\t" << str << std::endl;
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

///////////////				  Class definition						/////////////////
/////////////////////////////////////////////////////////////////////////////////////