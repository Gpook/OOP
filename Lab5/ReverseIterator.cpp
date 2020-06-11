#include "ReverseIterator.h"
#include "Book.h"

ReverseIterator::ReverseIterator(Book* first) :current(first) {
}

Book& ReverseIterator::operator ++ (int) { 
	Book* currentPoiner = current;

	for (; currentPoiner->Next != this->current; currentPoiner = currentPoiner->Next) {
	}

	current = currentPoiner;

	return *current;
}

Book& ReverseIterator::operator ++ () {
	Book* currentPoiner = current;

	for (; currentPoiner->Next != this->current; currentPoiner = currentPoiner->Next) {
	}

	current = currentPoiner;

	return *current;
}

bool ReverseIterator::operator != (const ReverseIterator& it) {
	return current != it.current;
}
bool ReverseIterator::operator == (const ReverseIterator& it) {
	return current == it.current;
}

Book& ReverseIterator::operator* () {
	return *current;
}