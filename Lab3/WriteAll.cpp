#include "WriteAll.h"


#include <iostream>
#include <fstream>
#include <iostream>

#include "Book.h"

using namespace std;

void WriteAll(Book* books, int count) {

	string values = "";


	for (int i = 0; i < count; i++) {
		Book book = books[i];

		values += to_string(book.N_Book) + "&";
		values += book.Author + "&";
		values += book.BookName + "&";
		values += to_string(book.Year) + "&";
		values += book.Editor + "&";
		values += to_string(book.CountPages) + "&";
		
		

		values += "||";

	};

	ofstream file;

	file.open("data.txt");
	file << values;
	file.close();
}