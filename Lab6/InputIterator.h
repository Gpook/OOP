#pragma once
#include <iterator>
#include "Book.h"

using namespace std;

class InputIterator
{
public:
	InputIterator(Book* first);

	Book& operator ++ (int);
	Book& operator ++ ();

	bool operator != (const InputIterator& it);
	bool operator == (const InputIterator& it);

	Book& operator* ();
private:
	Book* current;
};