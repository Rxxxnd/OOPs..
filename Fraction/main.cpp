#include <iostream>

class Fraction;
Fraction operator * (Fraction left, Fraction right);
Fraction operator / (const Fraction& left, const Fraction& right);
Fraction operator + (const Fraction& left, const Fraction& right);
Fraction operator - (const Fraction& left, const Fraction& right);
bool operator == (Fraction left, Fraction right);
bool operator != (const Fraction left, const Fraction right);
bool operator > (Fraction left, Fraction right);
bool operator < (Fraction left, Fraction right);

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
		std::cout << " + Default Constructor: " << this << std::endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << " + Single-arg constructor: "<< this << std::endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		std::cout << " + Constructor:\t  " << this << std::endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		std::cout << " + Constructor:\t  " << this << std::endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << " + Copy constructor: "<< this << std::endl;
	}
	~Fraction()
	{
		std::cout << " ~ Destructor:\t  " << this << std::endl;
	}

//========= operators ===========
	Fraction& operator = (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}
	Fraction& operator *= (Fraction& other)
	{
		return *this = *this * other;

	}
	Fraction& operator /= (const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator += (const Fraction& other)
	{
		this->integer += other.integer;
		this->numerator += other.numerator;
		this->denominator += other.denominator;
		return *this;
	}
	Fraction& operator -= (const Fraction& other)
	{
		this->integer -= other.integer;
		this->numerator -= other.numerator;
		this->denominator -= other.denominator;
		return *this;
	}
	Fraction& operator ++ () //pref++;
	{
		integer++;
		numerator++;
		denominator++;
		return*this;
	}
	Fraction operator ++ (int) //post--;
	{
		Fraction old = *this;
		integer++;
		numerator++;
		denominator++;
		return old;
	}
	Fraction& operator -- () // pref--;
	{
		--integer;
		--numerator;
		--denominator;
		return *this;
	}
	Fraction operator -- (int) // post++;
	{
		Fraction old = *this;
		integer--;
		numerator--;
		denominator--;
		return old;
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
	Fraction& reduce()
	{/*
		int more, less, rest;
		if (numerator > denominator) more = numerator, less = denominator;
		else less = numerator, more = denominator;*/
		to_proper();
		int less = numerator;
		int more = denominator;
		int rest;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		}
		while(rest);

		int GCD = more; //GCD - Greatest Common Divisor;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
};

Fraction operator * (Fraction left, Fraction right)
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
Fraction operator / (const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
Fraction operator + (const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() + right.get_numerator(),
		left.get_denominator() + right.get_denominator()
	);
}
Fraction operator - (const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator() - right.get_numerator(),
		left.get_denominator() - right.get_denominator()
	);
}
bool operator == (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator != (const Fraction left, const Fraction right)
{
	return !(left == right);
}
bool operator > (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * right.get_denominator();
}
bool operator < (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() <  right.get_numerator() * right.get_denominator();
}
bool operator >= (const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right); //better performance, 'cause operator "==" is not involved;
}
bool operator <= (const Fraction& left, const Fraction& right)
{
	return !(left > right); 
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define REDUCING_CHECK

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
	#endif// Constructors check;
#ifdef ARITHMETICAL_OPERATORS_CHECK
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

#endif //Arithmetical operators check;
#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(1, 2);
	Fraction B(5, 10);
	std::cout << (A <= B) << std::endl;
#endif //Comparison operations check;
#ifdef REDUCING_CHECK
	Fraction A(5, 10);
	A.print();
	A.reduce();
	A.print();
#endif //reducing check;


}

// The "," operator allows to write several expressions in the place where one expression is expected;
// All expressions will be sequentially executed from left to right, and the operator "," will return only the value of the [!]last expression;