#pragma once
#include <iterator>
#include "Book.h"

using namespace std;

class ReverseIterator
{
	friend class RingContainer;
public:
	Book* current;

	ReverseIterator(Book* first);

	Book& operator ++ (int);
	Book& operator ++ ();

	bool operator != (const ReverseIterator& it);
	bool operator == (const ReverseIterator& it);

	Book& operator* ();
};