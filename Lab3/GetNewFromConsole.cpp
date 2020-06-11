#include <iostream>
#include <fstream>
#include <iostream>

#include "Book.h"

Book* GetNewFromConsole() {
    Book* bookObject = new Book();

    Book& book = *bookObject;

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

   

    

    return &book;
}
