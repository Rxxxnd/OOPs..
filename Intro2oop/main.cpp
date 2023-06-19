#include <iostream>

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
	//------------- homework starts here ----------------
	double distance(Point A, Point B)
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
 // ------------- function -----------------------
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();

	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

//define STRUCT_POINT
//#define DISTANCE_CHECK

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

#endif

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
	std::cout << " --------------------------------------- " << std::endl;
	std::cout << "Distance between points 'A' and 'B' is: \t " << distance(A, B) << std::endl;
	std::cout << "Distance between points 'B' and 'A' is: \t " << distance(B, A) << std::endl;
#endif // DISTANCE_CHECK
	Point A;
	A.print();
}
// at this point cout:   X = -9.25596e+61        Y = -9.25596e+61

