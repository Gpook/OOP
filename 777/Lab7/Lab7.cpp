// Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional> 
#include <algorithm>
#include <vector>
#include "Book.h"
#include "ProcessingCenter.cpp"

using namespace std;

vector<Book>* Initialize() {
	cout << "Count of added Books is :";

	int itemsCount;

	cin >> itemsCount;

	cout << endl;

	vector<Book>& container = *new vector<Book>();

	for (auto i = 0; i < itemsCount; i++) {
		Book* toy = new Book();
		toy->FillWithConsole();
		container.push_back(*toy);
	}

	cout << endl;


	return &container;
}


vector<Book>* GetSequence() {
	cout << endl << "Hello, how many items will be in sequence?" << endl;

	int itemsCount;

	cin >> itemsCount;

	cout << endl;

	vector<Book>& container = *new vector<Book>();

	for (auto i = 0; i < itemsCount; i++) {
		Book* toy = new Book();
		toy->FillWithConsole();
		container.push_back(*toy);
	}

	cout << endl;


	return &container;
}



void Count(vector<Book>* container) {

	cout << endl << "Count:" << endl;

	ProcessingCenter& processingCenter = *new ProcessingCenter();

	auto sequence = GetSequence();

	auto position = processingCenter.CountPC(container, sequence, [](Book first, Book second) {
		return (first).BookName == (second).BookName;
		});

	cout << "Count result:" << position << endl;
}

void Order(vector<Book>* container) {

	cout << endl << "Bubble sort by: Book Name - 1, Year - 2, N Book - 3, Pages Count - 4" << endl;

	ProcessingCenter& processingCenter = *new ProcessingCenter();


	function<bool(Book, Book)> predicate;

	string field;

	cin >> field;
	
	if (field == "1") {
		predicate = [](Book first, Book second) { return first.BookName.compare(second.BookName) < 0; };
	}

	if (field == "2") {
		predicate = [](Book first, Book second) { return first.Year < second.Year;  };
	}

	if (field == "3") {
		predicate = [](Book first, Book second) { return first.N_Book < second.N_Book;  };
	}

	if (field == "4") {
		predicate = [](Book first, Book second) { return first.CountPages < second.CountPages;  };
	}

	processingCenter.OrderPC(container, predicate);

	auto iterator = container->begin();

	while (iterator != container->end()) {
		(*(iterator++)).Print();
	}
}





void Distinct(vector<Book>* container) {

	cout << endl << "Distinct:" << endl;

	ProcessingCenter& processingCenter = *new ProcessingCenter();

	processingCenter.DistinctPC(container, [](Book first, Book second) {
		return (first).BookName == (second).BookName;
		});

	auto iterator = container->begin();

	while (iterator != container->end()) {
		(*(iterator++)).Print();
	}
}

void Move(vector<Book>* container) {

	cout << endl << "Before Move : " << endl;

	auto iterator = container->begin();

	while (iterator != container->end()) {
		(*(iterator++)).Print();
	}

	cout << endl << "After Move if copy: " << endl;

	ProcessingCenter& processingCenter = *new ProcessingCenter();
	
	processingCenter.MovePC(container, Book::CompareByYear()); 
	
	

}

int main()
{
	auto container = Initialize();
	//auto container2 = Initialize();

	while (true) {

		string command;

		cout << endl << "command (Count of elements - 1, Move To - 2,  Distinct - 3, Sort - 4):" << endl;
		cin >> command;
		cout << endl;

		if (command == "1") {
			Count(container);
		}

		if (command == "2") {
			Move(container);
		}
		if (command == "3") {
			Distinct(container);
		}

		if (command == "4") {
			Order(container);
		}

		cout << endl << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
