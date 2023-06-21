#include <iostream>

#define delimiter "\n---------------------------------------\n"
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

class Point
{              //members of class
	double x;
	double y;

public:
	//   GET/SET methods (functions for members of class)

	double get_x()const // MUST BE cosntant [!]
	{
		return x;
	}
	void set_x(double x) // must be 'void' 
	{
		this->x = x;
	}
	double get_y()const
	{
		return y;
	}
	void set_y(double y)
	{
		this->y = y;
	}
// ======================== Constructors =================================
	/*
	Point()
	{
		x = y = double(); // type() - default value for the given type;
						  // "calling" the default constructor
		std::cout << "Default Constructor:\t" << this << std::endl;
	}
	//========================================================================
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		std::cout << "Single-Argument Constructor:\t " << this << std::endl;
	}
	*/
//========================================================================
	Point(double x = 0, double y = 0) // 'universal' constructor
	{
		this->x = x;
		this->y = y;
		std::cout << "Constructor:\t" << this << std::endl;
	}
//========================================================================
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "Copy constructor:" << this << std::endl;
	}

	~Point()
	{
		std::cout << "Destructor:  \t" << this << std::endl;
	}
	
	//---------------- Operators ----------------- 
    Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "Copy Assignment:\t" << this << std::endl;
		return *this;
	}

//-------------------- Methods ----------------------

	double distance(Point& A, Point& B)const
	{
		// pow(base, exponent); 
		// base - base number;
		// exponent - power of number;

		return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2)); // <- obviously not mine.

		/*
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
		*/
	}

	void print()
	{
		std::cout << "X = " << x << "\tY = " << y << std::endl;
	}
};
 //---------------- function ------------------------
double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();

	return sqrt(x_distance * x_distance + y_distance * y_distance);
}


void main()
{

#ifdef STRUCK_POINT
	int a;
	Pont A;
	A.x = 2;
	A.y = 3;
	std::cout << A.x << "\t" << A.y << std::endl;

	Point* pA = &A;
	std::pA->x << "\t" << pA->y << std::endl;

#endif //STRUC_POINT
#ifdef DISTANCE_CHECK
	Point A;      // 'Point' - user's type,  'A' - object;  
	A.set_x(2);   // init of A.x   
	A.set_y(3);   // init of A.y
	std::cout << "A:\t" << A.get_x() << "\t" << A.get_y() << std::endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	std::cout << "B:\t" << B.get_x() << "\t" << B.get_y() << std::endl;
	//std::cout << "Distance between points 'A' and 'B' is: \t " << A.distance(B) << std::endl;
	//std::cout << "Distance between points 'B' and 'A' is: \t " << B.distance(A) << std::endl;
	std::cout << delimiter << std::endl;
	std::cout << "Distance between points 'A' and 'B' is: \t " << distance(A, B) << std::endl;
	std::cout << delimiter << std::endl;
	std::cout << "Distance between points 'B' and 'A' is: \t " << distance(B, A) << std::endl;
#endif // DISTANCE_CHECK
#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.print();

	Point B = 5;  // Single-argumenr constructor;
	B.print();

	Point C(2, 3);
	
	C.print();

	Point D = C; //Copy constructor
	D.print();

	Point E;
	E = D;       //Copy assignment
	E.print();

#endif//CONSTRUCTIONS_CHECK

	int a, b, c;
	a = b = c = 0;
	std::cout << a << "\t" << b << "\t" << c << "\t" << std::endl;
	std::cout << delimiter;

	Point A, B, C;

	A = B = C = Point(2, 3);

	A.print();
	B.print();
	C.print();

}



