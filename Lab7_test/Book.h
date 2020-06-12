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

	void Print();
	void FillWithConsole();
};
