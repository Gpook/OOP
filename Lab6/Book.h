#pragma once

#include <string>

using namespace std;

class Book
{
public:
	string BookName;
	int Year;
	float Page_Count;
	float Price;
	Book* Next;

	Book();
	static auto CompareByYear()
	{
		return [](const Book & b) -> bool { return b.Year > 2009; };
	}
	void Print();
	void FillWithConsole();
};
