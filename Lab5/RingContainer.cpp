#include "RingContainer.h"
#include "OutputIterator.h"
#include "ReverseIterator.h"
#include "Book.h"

RingContainer::RingContainer(Book* first, Book* second) {
	book = first;
	book->Next = second;
	book->Next->Next = book;
}

OutputIterator RingContainer::inputBegin() { return book; }

ReverseIterator RingContainer::reverseBegin() { return book; }

void RingContainer::Add(Book* item) {
	Book* currentPoiner = book;

	for (; currentPoiner->Next != book; currentPoiner = currentPoiner->Next) {
	}

	currentPoiner->Next = item;
	item->Next = this->book;

	return;
}
