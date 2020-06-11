#include "Book.h"
#include <iostream>
#include <fstream>
#include <iostream>

Book::Book() {

}


Book::Book(string* values) {
	try {
		this->N_Book = stoi(values[0]);
		this->Year = stoi(values[3]);
		this->CountPages = stoi(values[5]);
	}
	catch (...) {
		cout << "Invalid input, try again" << endl;
	}
	this->Author = values[1];
	this->BookName = values[2];
	
	this->Editor = values[4];
	
	
	
}

void Book::Print() {
	cout << "N Book : " << this->N_Book << endl;
	cout << "Author : " << this->Author << endl;
	cout << "Book Name : " << this->BookName << endl;
	cout << "Year: " << this->Year << endl;
	cout << "Editor: " << this->Editor << endl;
	cout << "Count of Pages: " << this->CountPages << endl;
	
}