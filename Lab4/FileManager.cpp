#include "FileManager.h"
#include<iostream>
#include<fstream>



std::ifstream::pos_type filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

void FileManager::Add(Book* book) {
	int length = filesize("data.txt");

	fstream file("data.txt", ios::binary | ios::in | ios::out);

	file.seekp(length);

	file.write((char*)book, sizeof(Book));

	file.close();
}

void FileManager::OrderDown(function<bool(Book, Book)> predicate) {
	this->Order(false, predicate);
}

void FileManager::OrderUp(function<bool(Book, Book)> predicate) {
	this->Order(true, predicate);
}

void FileManager::Order(bool up, function<bool(Book, Book)> predicate) {
	int fileLength = filesize("data.txt");
	int n = fileLength / sizeof(Book);

	fstream file("data.txt", ios::binary | ios::in | ios::out);

	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			Book left;
			file.seekg((j - 1) * sizeof(Book));
			file.read((char*)&left, sizeof(Book));

			Book right;
			file.seekg((j) * sizeof(Book));
			file.read((char*)&right, sizeof(Book));

			if (up == false && !predicate(left,right)) {
				break;
			}

			if (up == true && predicate(left, right)) {
				break;
			}

			file.seekp((j) * sizeof(Book));
			file.write((char*)&left, sizeof(Book));

			file.seekp((j - 1) * sizeof(Book));
			file.write((char*)&right, sizeof(Book));
		}
	}
}

void FileManager::Print() {
	int fileLength = filesize("data.txt");
	int length = fileLength / sizeof(Book);

	fstream file("data.txt", ios::binary | ios::in);

	file.seekp(0);

	for (int i = 0; i < length; i++) {
		Book book;

		file.read((char*) &book, sizeof(Book));

		book.Print();
	}
}