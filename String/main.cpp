#include <iostream>

class String
{
	int size;
	char* str;
public:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << " + Default constructor: " << this << std::endl;
	}
	~String()
	{
		delete[] str;
		std::cout << " - Destructor: " << this << std::endl;
	}
	// ========== metords ==========

	void print() const
	{
		std::cout << " Size: \t" << size << std::endl;
		std::cout << "  Str: \t" << str << std::endl;
	}
};

void main()
{
	String str;
	str.print();
}