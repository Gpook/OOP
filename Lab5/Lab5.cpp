
#include <iostream>
#include <vector>
#include <iterator>
#include "RingContainer.h"

using namespace std;

int main()
{
	Book* first = new Book();
	first->FillWithConsole();

	Book *second = new Book();
	second->FillWithConsole();

	RingContainer container(first, second);

	cout << "How many items to add?" << endl;

	int count = 0;

	cin >> count;

	for (int i = 0; i < count; i++) {
		Book* item = new Book();
		item->FillWithConsole();

		container.Add(item);
	}

	cout << endl;
	cout << "|          Output Iterator          |" << endl;
	cout << endl;
	auto OutputIterator = container.inputBegin();

	for (int i = 0; i < count+2; i++) {
		OutputIterator++;
		OutputIterator.current->Print();
				cout << endl;
	}
	
	cout << endl;
	cout << "|         Reverse Iterator          |" << endl;
	cout << endl;
	auto reverseIterator = container.reverseBegin();

	for (int i = 0; i < count + 2; i++) {
		reverseIterator.current->Print();
		reverseIterator++;
		cout << endl;
	}

	
	cout << endl;
	cout << "|           Bubble Sort             |" << endl;
	cout << endl;
	for (int i = 0; i < count + 2; i++) {
		OutputIterator.current->Sort(OutputIterator.current, count + 2);
		OutputIterator++;
		OutputIterator.current->Print();

		cout << endl;
	}
	system("pause");
}
