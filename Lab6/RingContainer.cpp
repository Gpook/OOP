#include "RingContainer.h"
#include "Book.h"
#include "InputIterator.h"

RingContainer::RingContainer(Book* first, Book* second) {
	book = first;
	book->Next = second;
	book->Next->Next = book;
}

InputIterator RingContainer::inputBegin() { return book; }

void RingContainer::Add(Book* item) {
	Book* currentPoiner = book;

	for (; currentPoiner->Next != book; currentPoiner = currentPoiner->Next)
	{
	}

	currentPoiner->Next = item;
	item->Next = this->book;

	return;
}

void RingContainer::Remove(Book* item) {
	Book* currentPoiner = item;

	for (; currentPoiner->Next != item; currentPoiner = currentPoiner->Next)
	{
	}

	currentPoiner->Next = item->Next;
}

void RingContainer::MoveUp(Book* item) {
	Book* prevPointer = item;

	Book* nextPointer = item->Next;

	for (; prevPointer->Next != item; prevPointer = prevPointer->Next)
	{
	}

	item->Next = nextPointer->Next;
	nextPointer->Next = item;
	prevPointer->Next = nextPointer;
}