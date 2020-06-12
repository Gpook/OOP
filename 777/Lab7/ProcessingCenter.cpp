#include "Book.h"
#include <iostream>
#include "Book.h"
#include <functional>
#include <vector>

using namespace std;

class ProcessingCenter
{
public:
	void OrderPC(vector<Book>* container, function<bool(Book, Book)> predicate);
	int CountPC(vector<Book>* container, vector<Book>* sequence, function<bool(Book, Book)> predicate);
	void DistinctPC(vector<Book>* container, function<bool(Book, Book)> predicate);
	void MovePC(vector<Book>* container, function<bool(Book)> comporator);
	
};




void ProcessingCenter::OrderPC(vector<Book>* container, function<bool(Book, Book)> predicate) {
	auto first = container->begin();
	auto last = container->end();

	for (auto d = (last - first) / 2; d != 0; d /= 2) {
		for (auto i = first + d; i != last; ++i) {
			for (auto j = i; j - first >= d && predicate(*j, *(j - d)); j -= d) {
				std::swap(*j, *(j - d));
			}
		}
				}
}


int ProcessingCenter::CountPC(vector<Book>* container, vector<Book>* sequence, function<bool(Book, Book)> predicate) {
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


void ProcessingCenter::DistinctPC(vector<Book>* container, function<bool(Book, Book)> predicate) {
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




void ProcessingCenter::MovePC(vector<Book>* container, function<bool(Book)> comporator)
{
	vector <Book>v;
	
	auto it = container->begin();
	while (it != container->end()) {
		auto tempIt = it++;
		if (comporator(*tempIt))
		{
			v.push_back(*it);
			container->erase(it);

		}
	}
	/*
	if (v.size() > indexxx) {

	it = v.end();
}
	else {
		it = container->begin() + indexxx;

	}

	for (int i = 0; i < v.size(); i++) {
		container->insert(it++, v[i]);
	}
	*/
}