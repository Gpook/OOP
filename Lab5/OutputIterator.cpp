#include "OutputIterator.h"

OutputIterator::OutputIterator(Book* first) :current(first) {
}

Book& OutputIterator::operator ++ (int) { 
	current = this->current->Next;

	return *current;
}

/*
Book& OutputIterator::operator ++ () {
	current = this->current->Next;

	return *current;
}
*/
bool OutputIterator::operator != (const OutputIterator& it) {
	return current != it.current;
}
bool OutputIterator::operator == (const OutputIterator& it) {
	return current == it.current;
}
