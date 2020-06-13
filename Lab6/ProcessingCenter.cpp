#include "Book.h"
#include <iostream>
#include "Book.h"
#include <functional>
#include <vector>
#include "RingContainer.h"

using namespace std;

class ProcessingCenter
{
public:
	void OrderPC(RingContainer* container, function<bool(Book, Book)> predicate) {
		InputIterator i = container->inputBegin();
		InputIterator startIterator = container->inputBegin();


		for (; (*i).Next != &(*startIterator); i++) {
			InputIterator j = container->inputBegin();

			for (; (*j).Next != &(*startIterator); j++) {
				if (predicate(*j, *(*j).Next)) {
					container->MoveUp(&*j);
				}
			}
		}
	}


	int CountPC(RingContainer* container, vector<Book>* sequence, function<bool(Book, Book)> predicate) {
		auto iterator = container->inputBegin();
		auto startIterator = container->inputBegin();

		int elementsCount = 0;

		do {
			auto local = iterator;

			bool flag = true;

			for (int i = 0; i < sequence->size(); i++) {
				if (!predicate((*sequence)[i], (*local))) {
					flag = false;
				}

				local++;
			}

			if (flag == true) {
				return elementsCount + 1;
			}

			elementsCount++;
			iterator++;
		} while (startIterator != iterator);

		return -1;
	}


	void DistinctPC(RingContainer * container, function<bool(Book, Book)> predicate) {
		auto iterator = container->inputBegin();
		auto startIterator = container->inputBegin();

		do {
			auto local = iterator;

			bool flag = true;

			do {
				if (iterator != local && predicate(*iterator, *local)) {
					container->Remove(&*local);
				}

				local++;
			} while (local != startIterator);

			iterator++;
		} while (startIterator != iterator);
	}

	void MovePC(RingContainer* container, int m, int n)
	{
		auto iterator = container->inputBegin();
		auto startIterator = container->inputBegin();

		do {
			auto local = iterator;

			bool flag = true;

			do {
				
					container->MoveUp(&*local);
				

				local++;
			} while (local != startIterator);

			iterator++;
		} while (startIterator != iterator);
	}


};