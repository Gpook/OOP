#pragma once
#include "Book.h"
#include "OutputIterator.h"
#include "ReverseIterator.h"

class RingContainer
{
	Book* book;
public:
	RingContainer(Book* first, Book *second);
	OutputIterator inputBegin();
	ReverseIterator reverseBegin();

	void Add(Book* item);
	void Sort(Book* item);
};

