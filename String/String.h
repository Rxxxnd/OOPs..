#pragma once
#include<iostream>
#define delimiter "\n-------------------------------------------\n"


/////////////////////////////////////////////////////////////////////////////////////
///////////////					Class declaration				   	/////////////////

class String
{
	int size;	// string size in bytes;
	char* str;	// string adress in dynamic memory;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//						Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	char operator[](int i)const;
	char& operator[](int i);

	//						Methods:
	void print()const;
};

String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

///////////////					Class declaration					/////////////////
/////////////////////////////////////////////////////////////////////////////////////