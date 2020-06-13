// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Book.h"
#include "RingContainer.h"
#include "ProcessingCenter.cpp"

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


void Position(RingContainer& container) {
	ProcessingCenter* processingCenter = new ProcessingCenter();

	cout << endl << "Count: " << endl;

	int itemsCount = 0;

	cin >> itemsCount;

	vector<Book>* sequence = new vector<Book>();

	for (int i = 0; i < itemsCount; i++) {
		Book* item = new Book();
		item->FillWithConsole();
		sequence->push_back(*item);
	}

	auto result = processingCenter->CountPC(&container, sequence, [](Book first, Book second) {
		return (first.BookName == second.BookName);
		});

	cout << endl;

	for (int i = 0; i < sequence->size(); i++) {
		cout << (*sequence)[i].BookName << endl;
	}

	cout << endl << "Result: " << result << endl;

}

void Distinct(RingContainer& container) {
	ProcessingCenter* processingCenter = new ProcessingCenter();

	cout << endl << "Distinct: " << endl;

	processingCenter->DistinctPC(&container, [](Book first, Book second) {
		return (first.BookName == second.BookName);
		});


	auto distinctInterator = container.inputBegin();
	auto startInterator = container.inputBegin();

	do {
		(*distinctInterator).Print();
		distinctInterator++;
	} while (distinctInterator != startInterator);
}

void Move(RingContainer& container) {
	ProcessingCenter* processingCenter = new ProcessingCenter();
	cout << "Enter Year:" << endl;
	int y;
	cin >> y;
	cout << "Enter M position to move:" << endl;
	int m;
	cin >> m;
	cout << endl << "Move: " << endl;

	processingCenter->MovePC(&container,y,m); 


	auto distinctInterator = container.inputBegin();
	auto startInterator = container.inputBegin();

	do {
		(*distinctInterator).Print();
		distinctInterator++;
	} while (distinctInterator != startInterator);
}

void Order(RingContainer& container) {
	ProcessingCenter* processingCenter = new ProcessingCenter();
	cout << endl << "Bubble sort by: Book Name - 1, Year - 2, Pages Count - 3, Pages Count - 4" << endl;

	string field;

	cin >> field;

	function<bool(Book, Book)> predicate;

	if (field == "1") {
		predicate = [](Book first, Book second) { return first.BookName.compare(second.BookName) > 0; };
	}

	if (field == "3") {
		predicate = [](Book first, Book second) { return first.Page_Count > second.Page_Count;  };
	}

	if (field == "4") {
		predicate = [](Book first, Book second) { return first.Price > second.Price;  };
	}

	if (field == "2") {
		predicate = [](Book first, Book second) { return first.Year > second.Year;  };
	}
	
	processingCenter->OrderPC(&container, predicate);

	auto orderIterator = container.inputBegin();
	auto startInterator = container.inputBegin();

	do {
		(*orderIterator).Print();
		orderIterator++;
	} while (orderIterator != startInterator);
}

RingContainer* Initialize() {
	Book* first = new Book();
	Book* second = new Book();

	first->FillWithConsole();
	second->FillWithConsole();

	RingContainer* container = new RingContainer(first, second);

	int itemsCount;
	cout << endl << "How many items to add?" << endl;
	cin >> itemsCount;

	for (int i = 0; i < itemsCount; i++) {
		Book* item = new Book();
		item->FillWithConsole();
		container->Add(item);
	}

	cout << endl << "All: " << endl;


	auto iterator = container->inputBegin();
	auto startInterator = container->inputBegin();

	do {
		(*iterator).Print();
		iterator++;
	} while (iterator != startInterator);

	return container;
}
int main()
{
	RingContainer container = *Initialize();

	while (true) {

		string command;

		cout << endl << "command (Count of elements - 1, Move To - 2,  Sort - 3):" << endl;
		cin >> command;
		cout << endl;

		if (command == "1") {
			Position(container);
		}

		if (command == "3") {
			Distinct(container);
		}

		if (command == "3") {
			Order(container);
		}
		if (command == "2") {
			Move(container);
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
