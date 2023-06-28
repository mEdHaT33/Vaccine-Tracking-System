#include "User.h"
#include "HashTable.h"
#include "Sets.h"
#include <iostream>
using namespace std;

VaccQueue Q;
sets  idsets;

User::User(string name, int ID, int age, string pass, string gender, string governorate, bool Vaccine, int dose)
{
    this->name = name;
    this->ID = ID;
    this->age = age;
    this->gender = gender;
    this->governorate = governorate;
    this->Vaccine = Vaccine;
    this->dose = dose;
    if (!Vaccine)
        waiting_list.enqueue(ID);

}

User::User(User& p)
{
    this->age = p.age;
    this->name = p.name;
    this->ID = p.ID;
    this->pass = p.pass;
    this->governorate = p.governorate;
    this->gender = p.gender;
    this->Vaccine = p.Vaccine;
    this->dose = p.dose;
}

User::User()
{

}

int User::MainMenu()
{
    int close = 1;
    int choice;
    while (close < 4)
    {
        cout << "**** Vaccine Tracking System ****\n" << endl;
        if (close > 1)
            cout << "Attempt " << close << ".\n\n";
        if (close == 3)
        {
            cout << "If You Entered This Attemp Wrong the Program Will Close.\n \n";
        }
        cout << "Please choose 1 or 2." << endl;
        cout << "1. Login" << endl;
        cout << "2. New User" << endl;
        cout << "Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            return 1;
            break;
        case 2:
            system("cls");
            return 2;
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nInvalid Input!\n";
            if (close < 3)
            {
                cout << "Please type 1 or 2 ONLY.\n";
                system("pause");
                system("cls");
            }
            close++;
            break;
        }
    }
    system("pause");
    system("cls");
    cout << "Thank You For Using Our Program.\n";
}

void User::Login(int& inputID, string& inputPass)
{
    cout << "** Login **\n\n";
    cout << "Please Enter Your Username and Password.\n \n";
    cout << "ID: ";
    cin >> inputID;
    cout << "Password: ";
    cin >> inputPass;
}

int User::UserMenu()
{
    int choice;
    cout << "User Data\n" << endl;
    DisplayData();
    cout << "Please choose a number from 1 to 4.\n" << endl;
    cout << "1. Edit Data\n" << "2. Delete this User\n" << "3. I took the Vaccine\n" << "4. Log Out" << endl;
    cout << "Choice: ";
    cin >> choice;
    bool x = true;
    while (x = true)
    {
        switch (choice)
        {
        case 1:
            system("cls");
            return 1;
            x = false;
            break;
        case 2:
            system("cls");
            return 2;
            x = false;
            break;
        case 3:
            checkVaccine();
        case 4:
            cout << "\nYou have logged out from your account.\n";
            system("pause");
            system("cls");
            MainMenu();
            x = false;
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nIncorrect Number.\n";
            cout << "Please type 1, 2, 3 ONLY.\n";
            x = true;
        }
    }
}

int User::AdminMenu()
{
    int inputID;
    int choice;
    system("cls");
    cout << "Hi Admin.\n\n";
    cout << "Please choose a number from 1 to 5.\n" << endl;
    cout << "1. Display All Users" << endl << "2. Delete a User" << endl;
    cout << "3. Display a User Info" << endl << "4. Display Vaccine Queue" << endl;
    cout << "5. Display All Statistics\n" << endl << "6. Return to Main Menu\n" << endl;
    cout << "Your Choice: ";
    cin >> choice;
    bool x = true;
    while (true)
    {
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "Display all Users Data.\n\n";
            return 1;
            x = false;
            break;
        case 2:
            system("cls");
            cout << "Preview User.\n\n";
            return 2;
            x = false;

            break;
        case 3:
            system("cls");
            cout << "Enter User ID: ";
            return 3;
            break;
        case 4:
            system("cls");
            return 4;
            x = false;
            break;
        case 5:
            system("cls");
            return 5;

            x = false;
            break;
        case 6:
            system("cls");
            return 6;
            x = false;
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nIncorrect Number\n";
            cout << "Please type 1, 2, 3, 4, 5, 6 ONLY.\n\n";
            x = true;
        }
    }
}


void User::GetData()
{
    cout << "Please Enter User Data\n" << endl;
    cout << "Enter ID: ";
    int temp;
    cin >> temp;

    if (idsets.insert(temp))
    {
        ID = temp;
    }
    else
    {
        cout << endl << "wrong correct ID , you will return to main menu";
        MainMenu();
    }

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Gender: ";
    cin >> gender;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Governorate: ";
    cin >> governorate;
    cout << "Are you " << endl << "1. Applying " << endl << "2. Vaccinated" << endl << "Choose 1 or 2" << endl;
    int y;
    cin >> y;
    Vaccine = y - 1;
    if (!Vaccine) {
        cout << "You will be added to the Waitting List" << endl;
        waiting_list.enqueue(ID);
        wait_num = waiting_list.Qnum();
        dose = 0;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "How many doses you have taken?" << endl;
        cin >> dose;
        system("pause");
        system("cls");
    }
}

void User::DisplayData()
{
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Pass: " << pass << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age << endl;
    cout << "Governorate: " << governorate << endl;
    if (Vaccine)
        cout << "You have taken " << dose << " doses.\n" << endl;
    else
        cout << "Your Number in Waiting list is: " << wait_num << endl;
}

void User::checkVaccine()
{
    if (wait_num == Q.Rfront())
        Q.dequeue();
    else
        cout << "You can't edit, it's still not your turn!!" << endl;
}

//void User::DisplayStatistics(int* arr, int n)
//{
//    
//        int f = 0, m = 0, fd = 0, bd = 0, cairo = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (arr[i].gender == 'm' || "male") {
//                m++;
//            }
//            else if (arr[i].gender == 'f' || "female")
//            {
//                f++;
//            }
//            if (arr[i].dose == 1)
//            {
//                fd++;
//            }
//            else if (arr[i].dose == 2)
//            {
//                bd++;
//            }
//
//        }
//        double avgfd = (fd / n) * 100;
//        cout << "average of people vaccined 1st dose" << avgfd << endl;
//        double avgbd = (bd / n) * 100;
//        cout << "average of people vaccined both doses" << avgbd << endl;
//        double avgm = (m / n) * 100;
//        cout << "average of male" << avgm << endl;
//        double avgf = (f / n) * 100;
//        cout << "average of female=" << avgf << endl;
//}

User::~User()
{

}