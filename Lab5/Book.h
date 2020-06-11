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
	Book* Next;

	Book();
	void Sort(Book* lst, int size);
	void Print();
	void FillWithConsole();

};
