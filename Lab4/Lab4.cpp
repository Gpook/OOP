#pragma warning (disable:4996)
#include <iostream>
#include <fstream> 
#include <stdio.h>

#include "Book.h"
#include "FileManager.h"

using namespace std;


string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

int main()
{	
	FileManager manager;

	
	while (true) {
		string command;

		cout << endl << "command (Insert - 1, Show - 2, Sort UP - 3, Sort DOWN - 4 ):" << endl;
		cin >> command;
		cout << endl;

		if (command == "1") {
			Book* book = new Book();

			book->FillWithConsole();

			manager.Add(book);
		}

		if (command == "2") {
			manager.Print();
		}

		if (command == "3" || command == "4") {
			string field;
			cout << endl << "Enter field name - Author, Book Name, Year:" << endl;
			cin >> field;

			function<bool(Book, Book)> predicate;

			if (field == "Book Name") {
				predicate = [](Book first, Book second) {
					int first_size = sizeof(first.BookName) / sizeof(char);
					int second_size = sizeof(second.BookName) / sizeof(char);

					string firstString = first.BookName;
					string secondString = second.BookName;

					return firstString < secondString;
				};
			}

			if (field == "Year") {
				predicate = [](Book first, Book second) { return first.Year > second.Year;  };
			}

			if (field == "Author") {
				predicate = [](Book first, Book second) { return first.Author > second.Author;  };
			}


			if (command == "up") {
				manager.OrderUp(predicate);
			}

			if (command == "down") {
				manager.OrderDown(predicate);
			}
		}


	}
}

