#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

#include "RingContainer.h"

using namespace std;

template<class T> class ProcessingCenter
{
public:
	void Order(RingContainer * container, function<bool(T, T)> predicate);
	int Count(RingContainer * container, vector<T> * sequence, function<bool(T, T)> predicate);
	void Distinct(RingContainer * container, function<bool(T, T)> predicate);
	void MovePC(vector<Book>* container, function<bool(Book)> comporator);

};



