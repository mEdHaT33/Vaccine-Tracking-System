#pragma once
#include "VaccQueue.h"

#include <iostream>
using namespace std;

class User
{
public:
	static VaccQueue waiting_list;
	string name;
	int ID;
	int age;
	string pass;
	string gender;
	string governorate;
	bool Vaccine;
	int dose;
	int wait_num = 0;
	int* arr;

	User();
	User(string name, int ID, int age, string pass, string gender, string governorate, bool Vaccine, int dose);
	User(User& p);
	
	int MainMenu();
	void Login(int& inputID, string& inputPass);
	int UserMenu();
	int AdminMenu();
	void GetData();
	void DisplayData();
	void checkVaccine();
	void DisplayStatistics(int* arr, int n);
	~User();
};

