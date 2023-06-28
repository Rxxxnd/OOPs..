#include <iostream>

class Fraction
{
	int integer; 
	int numerator; 
	int denominator; 

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numenator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//		 constructors:

	Fraction() // default constructor 
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "Default Construct: " << this << std::endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "Single-arg constructor: "<< this << std::endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		std::cout << "Constructor:\t" << this << std::endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		std::cout << "Constructor:\t" << this << std::endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "Copy constructor: "<< this << std::endl;
	}
	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//	       operators:
	Fraction&operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}

	//          methods:

	void print()const
	{
		if (integer)std::cout << integer;  
		if (numerator)
		{
			if (integer)std::cout << "(";
			std::cout << numerator << "/" << denominator;
			if (integer)std::cout << ")";
		}
		else if (integer == 0) std::cout << 0;
		std::cout << std::endl;
	}
	//===============================================================================
	// не решение, просто мысли
	Fraction& proper_fraction()                        
	{
		this->integer = this->numerator % this->denominator;
		this->numerator = this->numerator - this->integer * this->denominator;
		return *this;
	}  
	//тоже не решение, только мысли
	Fraction& improp_fraction()                        
	{
		this->numerator = this->integer * this->denominator + this->numerator;
		return *this;
	}
	//================================================================================
};

#define CONSTRUCTORS_CHECK

void main()
{
#ifdef CONSTRUCTORS_CHECK
	setlocale(LC_ALL, "");

	Fraction A; //default constructor
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction  E = C; //copy constructor
	E.print();

	Fraction F; //assingment operator
	F = D;
	F.print();
	#endif// Constructors check



}
