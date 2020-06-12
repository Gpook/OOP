#include "Book.h"
#include <iostream>
#include <fstream>
#include <iostream>

Book::Book() {

}

void Book::Print() {
    cout << "Book Name: " << this->BookName << endl;

    cout << "Count of Pages: " << this->CountPages << endl;
    cout << "Year: " << this->Year << endl;
    cout << "N Book: " << this->N_Book << endl << endl;
}

void Book::FillWithConsole() {
	Book& book = *this;


	cout << "Write BOOK info" << endl;


	cout << "Book Number" << endl;

	while (true)
	{
		try {
			string val;
			cin >> val;
			int intVal = stoi(val);

			book.N_Book = intVal;

			break;
		}
		catch (...) {
			cout << "Invalid input, try again" << endl;
		}
	}

	cout << "Book Author" << endl;

	cin >> book.Author;

	cout << "Book Name" << endl;

	cin >> book.BookName;

	cout << "Year of Creation" << endl;

	while (true)
	{
		try {
			string val;
			cin >> val;
			int intVal = stoi(val);

			book.Year = intVal;

			break;
		}
		catch (...) {
			cout << "Invalid input, try again" << endl;
		}
	}

	cout << "Book Editor" << endl;

	cin >> book.Editor;

	cout << "Count of pages" << endl;

	while (true)
	{
		try {
			string val;
			cin >> val;
			int intVal = stoi(val);

			book.CountPages = intVal;

			break;
		}
		catch (...) {
			cout << "Invalid input, try again" << endl;
		}
	}
}