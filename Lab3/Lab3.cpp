// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Book.h"
#include "GetNewFromConsole.h"
#include "WriteAll.h"
#include "GetAll.h"
#include <functional>

using namespace std;


void InsertSort(Book* arr, int n, function<bool(Book, Book)> predicate) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && predicate(arr[j - 1], arr[j]); j--) {
			Book tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
}

int compare(const void* a, const void* b)
{
	
	return (*(Book * *)a)->Author > (*(Book * *)b)->Author;
}

int main()
{

	while (true) {
		string command;

		cout << endl << "command (Insert - 1, Show - 2, Sort - 3, Year -4 ):" << endl;
		cin >> command;
		cout << endl;

		if (command == "1") {
			int booksCount = 0;

			Book* newBook = GetNewFromConsole();
			Book* allBooks = GetAll(booksCount);

			Book* newBooks = new Book[booksCount + 1];

			for (int i = 0; i < booksCount + 1; i++) {
				if (i != booksCount) {
					newBooks[i] = allBooks[i];
				}
				else {
					newBooks[i] = *newBook;
				}
			}

			WriteAll(newBooks, booksCount + 1);
		}

		if (command == "2") {
			int booksCount = 0;

			Book* allBooks = GetAll(booksCount);

			for (int i = 0; i < booksCount; i++) {
				allBooks[i].Print();
					cout << endl;
			}
		}

		if (command == "3") {
			string field;
			cout << endl << "Enter field name - Author, Book Name, Year:" << endl;
			cin >> field;

			int booksCount = 0;

			Book* allBooks = GetAll(booksCount);

			if (field == "Book Name") {
				InsertSort(allBooks, booksCount, [](Book first, Book second) { return first.BookName > second.BookName;  });
			}

			if (field == "Year") {
				InsertSort(allBooks, booksCount, [](Book first, Book second) { return first.Year > second.Year;  });
			}

			if (field == "Author") {
				InsertSort(allBooks, booksCount, [](Book first, Book second) { return first.Author > second.Author;  });
			}



			for (int i = 0; i < booksCount; i++) {
				allBooks[i].Print();
				cout << endl;
			}
		}

		if (command == "4") {

			int enteredYear;
			int booksCount = 0;

			

			while (true) {
				try {
					cout << "Year:" << endl;
					cin >> enteredYear;

					Book* allBooks = GetAll(booksCount);
					InsertSort(allBooks, booksCount, [](Book first, Book second) { return first.Author > second.Author;  });


					for (int i = 0; i < booksCount; i++) {
						if (allBooks[i].Year >= enteredYear) {
							allBooks[i].Print();
						}
					}

					break;
				}
				catch (...) {

				}

			}
		}
	}
}
