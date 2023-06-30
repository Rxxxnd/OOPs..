#include <iostream>

class Fraction;
Fraction operator*(Fraction left, Fraction right);

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

//======== constructors =========

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

//========= operators ===========
	Fraction&operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}

	Fraction& operator *= (Fraction& other)
	{
		return *this = *this *other;
	}
//========== methods ============

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
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();						
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
//Fraction operator/(Fraction left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//	return Fraction
//	(
//		left.get_numerator() * right.get_denominator(),
//		left.get_denominator() * right.get_numerator()
//	).to_proper();
//}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}


//#define CONSTRUCTORS_CHECK

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

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	//Fraction C = A * B;
	//C.print();

	//Fraction D = A / B;
	//D.print();
	A *= B;
	A.print();

}
