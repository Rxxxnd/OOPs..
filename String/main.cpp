#include <iostream>

class String
{
	int size;  // size of string in bytes;
	char* str; // adress of string in dynamic memory

public:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << " + Default Constructor: " << this << std::endl;
	}
	~String()
	{
		delete[] str;
		std::cout << " - Destructor: " << this << std::endl;
	}

	// ============= methods ==============

	void print()const
	{
		std::cout << "Size: \t" << size << std::endl;
		std::cout << "Str: \t" << str << std::endl;
	}

};

void main()
{
	String str;
	str.print();
}