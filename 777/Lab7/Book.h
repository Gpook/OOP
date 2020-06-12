#pragma once

#include <string>

using namespace std;

class Book
{
public:
	int N_Book;
	string Author;
	string BookName;
	int Year;
	string Editor;
	int CountPages;

	Book();
	static auto CompareByYear() 
	{ 
		return [](const Book & b) -> bool { return b.Year > 2009;}; 
	}
	void Print();
	void FillWithConsole();
};
