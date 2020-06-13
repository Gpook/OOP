#include "InputIterator.h"

InputIterator::InputIterator(Book* first) :current(first) {
}

Book& InputIterator::operator ++ (int) {
	current = this->current->Next;

	return *current;
}


Book& InputIterator::operator ++ () {
	current = this->current->Next;

	return *current;
}

bool InputIterator::operator != (const InputIterator& it) {
	return current != it.current;
}
bool InputIterator::operator == (const InputIterator& it) {
	return current == it.current;
}

Book& InputIterator::operator* () {
	return *current;
}