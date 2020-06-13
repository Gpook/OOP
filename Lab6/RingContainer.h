#pragma once
#include "Book.h"
#include "InputIterator.h"

class RingContainer
{
	Book* book;
public:
	RingContainer(Book* first, Book* second);
	InputIterator inputBegin();

	void Add(Book* item);
	void Remove(Book* item);
	void MoveUp(Book* item);
};

