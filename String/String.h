#pragma once
#include <iostream>
#define delimiter "\n--------------------------\n"

////////////////////////////////////         CLASS DECLARATION                ////////////////////////////////////////////////
class String
{
	int size;
	char* str;

public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	// ========== constructors ==========
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String& operator = (const String& other);
	String(String&& other);
	~String();
	// ========== operators ==========
	String& operator =(String&& other);
	char& operator[](int i) const;
	// ========== methods ==========
	void print() const;
};
std::ostream& operator << (std::ostream& os, const String& obj);
String operator + (const String& left, const String& right);

//////////////////////////////////             CLASS DECLARATION               ////////////////////////////////////////////

