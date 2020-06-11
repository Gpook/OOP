#pragma once
#include <iterator>
#include "Book.h"

using namespace std;

class OutputIterator
{
	friend class RingContainer;
public:
	Book* current;
	OutputIterator(Book* first);

	Book& operator ++ (int);
	Book& operator ++ ();

	bool operator != (const OutputIterator& it);
	bool operator == (const OutputIterator& it);

	};