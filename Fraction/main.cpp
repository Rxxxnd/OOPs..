#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define delimiter "\n--------------------------------\n"

class Fraction;
Fraction operator * (Fraction left, Fraction right);
Fraction operator / (const Fraction& left, const Fraction& right);
Fraction operator + (const Fraction& left, const Fraction& right);
Fraction operator - (const Fraction& left, const Fraction& right);
bool operator > (Fraction left, Fraction right);
bool operator < (Fraction left, Fraction right);
bool operator == (Fraction left, Fraction right);
bool operator != (const Fraction left, const Fraction right);
bool operator >= (const Fraction& left, const Fraction& right);
bool operator <= (const Fraction& left, const Fraction& right);

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
	explicit Fraction(int integer) // explicit - forbidding the implicit conversion
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << " + Single-arg constructor: "<< this << std::endl;
	}
	Fraction(double decimal)
	{
		decimal += 1e-10;  // 1*10^-10 
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9; // 1 * 10^9
		numerator = decimal * denominator; 
		reduce();
		std::cout << " + Single-arg constructor: " << this << std::endl;
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

//========= type-cast operators =======
	explicit operator int()
	{
		return integer;
	}

	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
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
		to_proper(); // more efficient method;
		int less = numerator;
		int more = denominator;
		int rest;
		if (less == 0) return *this;
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
	).to_proper().reduce();
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

std::ostream& operator << (std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if(obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if(obj.get_integer())os << ")";
	}
	else if(obj.get_integer() == 0)os << 0;
		return os;
}
std::istream& operator >> (std::istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);	
	obj.set_denominator(denominator);*/	
	const int SIZE = 256;
	char buffer[SIZE] = {};
	is >> buffer;
	//is.getline(buffer, SIZE);
	int number[3] = {};
	int n = 0; // input numbers counter;
	char delimiters[] = "()/ ";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = std::atoi(pch); //atoi - ascii string to 'int'.  string -> integer number from
	//for (int i = 0; i < n; i++) std::cout << number[i] << "\t"; std::cout << std::endl;
	switch (n)
	{
	case 1: obj = Fraction(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]); break;
		/*obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);*/		
	case 3: obj = Fraction(number[0], number[1], number[2]);
		/*obj.set_integer(number[0]);
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]);*/
	}
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define REDUCING_CHECK
//#define INPUT_CHECK
//#define INPUT_CHECK_2
//#define CONVERSION_CHECK
//#define COVERSIONS_FROM_OTHER_2_CLASS_CHECK
//#define COVERSIONS_FROM_CLASS_2_OTHER_CHECK


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
#endif

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 16, 20);
	B.print();

	//Fraction C = A * B;
	//C.print();

	//Fraction D = A / B;
	//D.print();
	A *= B;
	A.print();

#endif 

#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(1, 2);
	Fraction B(5, 10);
	std::cout << (A <= B) << std::endl;
#endif 

#ifdef REDUCING_CHECK
	Fraction A(5, 10);
	A.print();
	A.reduce();
	A.print();
#endif

#ifdef INPUT_CHECK
	Fraction A(5,10);
	std::cout << "Enter your fraction: " << std::endl; std::cin >> A;
	std::cout << A << std::endl;
	A.reduce();
	std::cout << "Reduced: " << A << std::endl;
#endif 

#ifdef INPUT_CHECK_2
	Fraction A, B, C;
	std::cout << "Enter your fraction: "; std::cin >> A >> B >> C;
	std::cout << A << "\t" << B << "\t" << C << std::endl;
#endif 

#ifdef CONVERSION_CHECK

	int a = 2;         // No conversions;
	double b = 3;      // Conversion  less => more;
	int c = b;         // Conversion  more => less w/out data loss;
	int d = 5.7;       // Conversion  more => less w/ data loss;
	//int e = "Hello"; // Types are not compatible; 

	std::cout << 7. / 2 << std::endl; // Implicit conversion less => more. 
    //In this case '2' - was covertly converted from 'int' to a 'double', bc of '7' with '. ', means that '7' starts to be 'double' after adding the ".";

#endif 

#ifdef COVERSIONS_FROM_OTHER_2_CLASS_CHECK
	Fraction A = (Fraction)5;  // Conversion from 'int' to 'Fraction'.  
					 // Conversion from other to class;
					 // Single-arg coonstructor;
	std::cout << A << std::endl;
	std::cout << delimiter << std::endl;
	Fraction B;      //Default constructor;
	std::cout << delimiter << std::endl;
	B = Fraction(8);
	std::cout << delimiter << std::endl;
	std::cout << B << std::endl;

	// Fraction C = 12; //explicit constructor cannot be called by assignment operator.
	//Fraction C(12);     // proper explicit constructor calling.
	//Fraction C{ 12 };   // or like 
	//std::cout << C << std::endl;

#endif

#ifdef COVERSIONS_FROM_CLASS_2_OTHER_CHECK
	Fraction A(2, 1, 2);
	std::cout << A << std::endl;
	int a = (int)A;
	std::cout << a << std::endl;

	Fraction B(2, 3, 4);
	std::cout << B << std::endl;
	double b = (double)B;
	std::cout << b << std::endl;
#endif

	Fraction A = -2.77;
	std::cout << A << std::endl;

	Fraction B = -3.333;
	std::cout << B << std::endl;

}

// The "," operator allows to write several expressions in the place where one expression is expected;
// All expressions will be sequentially executed from left to right, and the operator "," will return only the value of the [!]last expression;