#include "Book.h"
#include <iostream>
#include "Book.h"
#include <functional>
#include <vector>

using namespace std;

template<class T> class ProcessingCenter
{
public:
	void Order(vector<T>* container, function<bool(T, T)> predicate);
	int Count(vector<T>* container, vector<T>* sequence, function<bool(T, T)> predicate);
	void Distinct(vector<T>* container, function<bool(T, T)> predicate);
};

template<class T>
void ProcessingCenter<T>::Order(vector<T>* container, function<bool(T, T)> predicate) {
	auto first = container->begin();
	auto last = container->end();

	for (auto d = (last - first) / 2; d != 0; d /= 2) {
		for (auto i = first + d; i != last; ++i) {
			for (auto j = i; j - first >= d && predicate(*j, *(j - d)); j -= d) {
				std::swap(*j, *(j - d));
			}
		}
	
		/*
	bool swapp = true;
	while (swapp) {
		swapp = false;
		for (auto i = 0; i < last - 1; i++) {
			if (container[i] > container[i + 1]) {
				container[i] += container[i + 1];
				container[i + 1] = container[i] - container[i + 1];
				container[i] -= container[i + 1];
				swapp = true;
			}
		}
	}*/
	}
}

template<class T>
int ProcessingCenter<T>::Count(vector<T>* container, vector<T>* sequence, function<bool(T, T)> predicate) {
	int position = 0;

	

	for (auto i = container->begin(); i != container->end(); i++) {
		if (container->end() - i < sequence->size()) {
			break;
		}

		bool flag = true;

		auto local = i;
		auto j = sequence->begin();

		while (j != sequence->end() && local != container->end()) {
			if (!predicate(*j, *local)) {
				flag = false;
				break;
			}

			j++;
			local++;
		}

		if (flag == true) {
			return position+1;
		}

		position++;
	}

	return -1;
}

template<class T>
void ProcessingCenter<T>::Distinct(vector<T>* container, function<bool(T, T)> predicate) {
	for (auto i = 0; i < container->size(); i++) {
		for (auto j = container->begin() + i + 1; j != container->end(); ) {
			if (predicate(*j, container->at(i))) {
				j = container->erase(j);
			}
			else {
				j++;
			}
		}
	}
}
