#include "VaccQueue.h"
#include "User.h"
#include "HashTable.h"

#include <iostream>
using namespace std;

VaccQueue User::waiting_list;
HashTable table;
int inputID;
string inputPass;

void main()
{
    User U;
    int x;
    bool attemp = true;
    while (attemp)
    {
        x = U.MainMenu();
        if (x == 1)
            U.Login(inputID, inputPass);
        else if (x == 2)
        {
            U.GetData();
            table.insert(U.ID, U);
            U.Login(inputID, inputPass);
        }
        if (inputID == 9999 && inputPass == "Admin")
        {
            attemp = false;
            int ad = U.AdminMenu();
            if (ad == 0) {}
            else if (ad == 1) {
                table.hashdisplayall();
            }
            else if (ad == 3) {
                int t;
                cout << "enter the id of the user you want to remove" << endl;
                cin >> t;
                User* display = table.search(t);
                cout << "User Number: " << x << endl;
                cout << "Name: " << display->name << endl;
                cout << "ID: " << display->ID << endl;
                cout << "Age: " << display->age << endl;
                cout << "Gender: " << display->gender << endl;
                cout << "Governorate: " << display->governorate << endl;
                cout << "Pass: " << display->pass << endl;
                if (display->Vaccine)
                {
                    cout << "Doses: " << display->dose << endl;
                }
                else {

                    cout << "User is not Vaccinated" << endl;
                }
            }
            else if (ad == 2) {
                int w;
                cout << "enter the id of the user you want to display" << endl;
                cin >> w;
                table.remove(w, w);

            }
            else  if (ad == 4)
                U.waiting_list.vacdisplayall();

            /*else  if (ad == 5)
                U.DisplayStatistics();*/

            else if (ad == 6)
                U.MainMenu();

            else {


                system("cls");

            }
        }
        else
        {
            User* HashUser = table.search(inputID);
            int res = inputPass.compare(HashUser->pass);

            if (res == 0)
            {
                attemp = false;
                x = HashUser->UserMenu();
                if (x == 1)
                {
                    table.remove(HashUser->ID, HashUser->ID);
                    U.GetData();
                    table.insert(U.ID, U);
                    cout << "Account Has been updated" << endl;

                }
                else if (x == 2)
                {
                    table.remove(HashUser->ID, HashUser->ID);
                    cout << "Account Has been Deleted" << endl;
                    system("pause");
                    system("cls");
                    U.MainMenu();
                }
            }
        }
        
       if(attemp==true) {
            cout << "\n\nIncorrect Username or Password.";
            cout << "\nPlease, Retry the Login.\n";
            system("pause");
            system("cls");
            U.MainMenu();
        }
    }
}