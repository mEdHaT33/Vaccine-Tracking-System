#pragma once
#include <iostream>
using namespace std;
class sets
{
public:
	int* id_array;
	int id_entry;
	int index;
	int size;
	sets();

	bool insert(int entry);
	bool check_13(int entry);
	bool uniquecheck(int entry);
	void expand();
	~sets();

};