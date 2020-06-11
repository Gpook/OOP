#pragma once
#include "Book.h"
#include <string>
#include <functional>

using namespace std;

class FileManager
{
public:
	void Add(Book * toy);
	void OrderUp(function<bool(Book, Book)> predicate);
	void OrderDown(function<bool(Book, Book)> predicate);
	void Print();
	void Order(bool up, function<bool(Book, Book)> predicate);
};

