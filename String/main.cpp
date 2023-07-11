#include <iostream>

#define delimiter "\n----------------------------------------------------------------------------\n"

class String
{
	int size;
	char* str;

public:
	int get_size()const
	{
		return size;
	}
	const char* get_str() const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << " + Default constructor: " << this << std::endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1; // +1 bc of adding 0;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++) this->str[i] = str[i];
		std::cout << " + Constructor:\t" << this << std::endl;
	}
	String(const String& other)
	{
		//Deep copy
		this->size = other.size;
		this->str = new char[size] {};

		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		std::cout << " + Copy constructor:\t" << this << std::endl;
	}
	String& operator = (const String& other)
	{
		if (this == &other)return *this;
		
		delete[] this->str; //clearing the memory;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		std::cout << " + Copy assignment:\t" << this << std::endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;

		other.size = 0;
		other.str = nullptr;
		std::cout << " + MoveAssignment:\t" << this << std::endl;
		return *this;
	}

	String(String&& other) //&& - r-value reference;
	{
		//Shallow copy;
		this->size = other.size;
		this->str = other.str;
		std::cout << " + MoveConstructor:\t" << this << std::endl;
		other.size = 0;
		other.str = 0;
	}

	~String()
	{
		delete[] str;
		std::cout << " - Destructor:\t\t" << this << std::endl;
	}
	// ========== Operators ==========

	char& operator[](int i)const
	{
		return str[i];
	}
	// ========== Metords ==========
	
	void print() const
	{
		std::cout << " Size: \t" << size << std::endl;
		std::cout << "  Str: \t" << str << std::endl;
	}
	
};
	String operator+(const String& left, const String& right)
	{
		String cat (left.get_size() + right.get_size() - 1);
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

void main()
{
	String str (5);
	str.print();

	String str1 = "Hello";
	str1 = str1;
	std::cout << str1 << std::endl;

	std::cout << delimiter << std::endl;

	String str2 = "World";
	std::cout << str2 << std::endl;

	std::cout << delimiter << std::endl;

	String str3 = str1 + str2;
	std::cout << str3 << std::endl;

	std::cout << delimiter << std::endl;
	String str4;
	str4 = str1 + str2;
	std::cout << str4 << std::endl;

}

