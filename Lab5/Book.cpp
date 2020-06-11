#include "Book.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <conio.h>

Book::Book() {

}
void Book::Sort(Book* lst,int size) {
	Book* p = lst;
	Book* t = lst->Next;
	for (int i = 0; i < size-1; ++i) {
		for (int j = i + 1; j < size-1; ++j) {
			if (p->N_Book > t->N_Book) { swap(p, t); }

			t = t->Next;
		}
		p = p->Next;
	}
}

void Book::Print() {
	cout << "N Book : " << this->N_Book << endl;
	cout << "Author : " << this->Author << endl;
	cout << "Book Name : " << this->BookName << endl;
	cout << "Year: " << this->Year << endl;
	cout << "Editor: " << this->Editor << endl;
	cout << "Count of Pages: " << this->CountPages << endl;
}

void Book::FillWithConsole() {
	Book& book = *this;
	cout << endl;
	cout << "Write BOOK info" << endl;
	
	cout << "Book Number: ";

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

	cout << "Book Author: ";

	cin >> book.Author;

	cout << "Book Name: ";

	cin >> book.BookName;

	cout << "Year of Creation: ";

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

	cout << "Book Editor: ";

	cin >> book.Editor;

	cout << "Count of pages: ";

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