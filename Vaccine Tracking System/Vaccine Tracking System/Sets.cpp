#include "sets.h"
#pragma once
#include <iostream>
using namespace std;
sets::sets() {
	size = 10;
	index = 0;
	id_array = new int[size];
	id_entry = 0;

}
bool sets::check_13(int entry) {
	int temp = entry;
	for (int i = 0; i < 13; i++) {
		temp /= 10;
	}
	if (temp < 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool sets::uniquecheck(int entry)
{
	for (int i = 0; i < size; i++) {
		if (id_array[i] == entry) {
			return false;

		}
	}
	return true;
}
void sets::expand() {

	int* arr2 = new int[size * 2];
	for (int i = 0; i < size; i++)
	{
		arr2[i] = id_array[i];
	}
	size *= 2;
	delete[] id_array;
	id_array = arr2;
}
bool  sets::insert(int entry) {
	if (!check_13(entry))
		cout << "wrong id" << endl;
	else if (!uniquecheck(entry))
		cout << "the id is not 13 digit" << endl;
	else
	{
		id_array[index] = entry;
		index++;
		return true;
	}
}
sets::~sets() {
	delete[] id_array;
}