#include <iostream>
#define delimiter "\n--------------------------\n"

class String
{
	int size;
	char* str;

public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	// ========== constructors ==========
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String& operator = (const String& other);
	String(String&& other);
	~String();
// ========== operators ==========
	String& operator =(String&& other);
	char& operator[](int i) const;
// ========== methods ==========
	void print() const;
};

//==================================================================================

// :: - scope operator 
// Scope::name
// namespace::name

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
// ========== constructors ==========

String::String(int size) :size(size), str(new char[size] {}) // 'explicit' can use only in class;
{
	std::cout << " + Default constructor: " << this << std::endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; str[i]; i++) this->str[i] = str[i];
	std::cout << " + Constructor: \t" << this << std::endl;
}
String::String(const String& other) :String(other.str)
{
	//deep copy;
	std::cout << " + Copy constructor:\t" << this << std::endl;
}
String& String::operator = (const String& other)
{
	if (this == &other)return *this;
	delete[] this->str; //cleaning the memory;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	std::cout << " + Copy assignment:\t" << this << std::endl;
	return *this;
}
String::String(String&& other) :size(other.size), str(other.str) //&& - r value reference;
{
	//Shallow copy;
	//this->size = other.size; // == : size(other.size);
	//this->str = other.str;   // == str(other.str);
	std::cout << " + Move constructor:\t" << this << std::endl;
	other.size = 0;
	other.str = 0;
}
String::~String()
{
	delete[] str;
	std::cout << " ~ Destructor:\t\t" << this << std::endl;
}
// ========== operators ==========

String& String::operator =(String&& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	std::cout << " + Move assingment:\t" << this << std::endl;
	return *this;
}
char& String::operator[](int i) const
{
	return str[i];
}
// ========== methods ==========
void String::print() const
{
	std::cout << " Size: \t" << this << std::endl;
	std::cout << " Str: \t" << str << std::endl;
}
	String operator + (const String& left, const String& right)
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

	std::ostream& operator << (std::ostream& os, const String& obj)
	{
		return os << obj.get_str();
	}
//#define BASE_CHECK
//#define CALLING_CONSTRUCTORS

	void main()
	{
#ifdef BASE_CHECK
		String str(5);
		str.print();
		String str1 = "Hello";
		str1 = str1;
		std::cout << str1 << std::endl;

		std::cout << delimiter << std::endl;

		String str2 = " World!";
		std::cout << str2 << std::endl;
		
		std::cout << delimiter << std::endl;

		String str3 = str1 + str2;
		std::cout << str3 << std::endl;

		std::cout << delimiter << std::endl;

		String str4;
		str4 = str1 + str2;
		std::cout << str4 << std::endl;
		std::cout << delimiter << std::endl;
#endif
#ifdef CALLING_CONSTRUCTOR
		String str1;  // Default coanstructor;
		str1.print();

		String str2(5); // explicit constructor;
		str2.print();

		String str3 = "Hello"; // single-argument constructor;
		str3.print();

		String str4(); //it's function "str4()" - no parameters and returns "String";
		// For explicit default constructor:

		String str5{};  // explicit default constructor;
		str5.print();

		std::cout << String() << std::endl;
		String().print();
#endif
	}