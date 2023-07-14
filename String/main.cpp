#include"String.h"

#define BASE_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	std::cout << sizeof("Hello") << std::endl;
	String str(5);
	str.print();

	String str1 = "Hello";
	str1 = str1;
	std::cout << str1 << std::endl;

	String str2 = "World";
	std::cout << str2 << std::endl;

	std::cout << delimiter << std::endl;
	String str3 = str1 + str2;
	std::cout << str3 << std::endl;
	std::cout << delimiter << std::endl;

	String str4;
	str4 = str1 + str2;
	std::cout << str4 << std::endl;

	String str5 = str4;
	std::cout << str5 << std::endl;
#endif // BASE_CHECK

#ifdef CALLING_CONSTRUCTORS
	String str1;	//Default constructor
	str1.print();

	String str2(5);
	str2.print();

	String str3 = "Hello";	//Single-argumrnt constructor
	str3.print();

	String str4();	
	String str5{};
	str5.print();

	std::cout << String() << std::endl;
	String().print();
#endif // CALLING_CONSTRUCTORS

}