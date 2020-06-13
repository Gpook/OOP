#include "Book.h"
#include <iostream>
#include <fstream>
#include <iostream>

Book::Book() {

}

void Book::Print() {
	cout << "Name: " << this->BookName << endl;
	cout << "Year: " << this->Year << endl;
	cout << "Pages: " << this->Page_Count << endl;
	cout << "Price: " << this->Price << endl << endl;
}

void Book::FillWithConsole() {
    Book& toy = *this;

    cout << "Write Inf. about books" << endl;
    cout << "Book Name" << endl;

    cin >> toy.BookName;


    cout << "Year" << endl;

    while (true)
    {
        try {
            string val;
            cin >> val;
            int intVal = stoi(val);

            toy.Year = intVal;

            break;
        }
        catch (...) {
            cout << "Invalid input, try again" << endl;
        }
    }

    cout << "Pages" << endl;

    while (true)
    {
        try {
            string val;
            cin >> val;
            float floatVal = stof(val);

            toy.Page_Count = floatVal;

            break;
        }
        catch (...) {
            cout << "Invalid input, try again" << endl;
        }
    }

    cout << "Price" << endl;

    while (true)
    {
        try {
            string val;
            cin >> val;
            float floatVal = stof(val);

            toy.Price = floatVal;

            break;
        }
        catch (...) {
            cout << "Invalid input, try again" << endl;
        }
    }
}