#include  "HashTable.h"
#include  <iostream>
#include "User.h"
using namespace std;
node::node() {
    valu;
    next = NULL;
}

node::node(User value) {
    valu = value;
    next = NULL;
}

HashTable::HashTable(int key, User value) {
    for (int i = 0; i < 10; i++) {
        table[i] = NULL;
    }
    node* n = new node(value);
    table[hash(key)] = n;
}

HashTable::HashTable() {
    for (int i = 0; i < 10; i++) {
        table[i] = NULL;
    }
}

int HashTable::hash(int key) {
    return key % 10;
}

void HashTable::insert(int key, User value) {
    node* n = new node(value);
    if (table[hash(key)] == NULL)
        table[hash(key)] = n;
    else
    {
        node* temp = table[hash(key)];
        while (temp->next != NULL)
        {
            temp = temp->next;

        }
        temp->next = n;
        temp = NULL;
        delete temp;
    }
    counter++;
}

void HashTable::remove(int key, int value) {
    if (search(key, value)) {
        node* del = table[hash(key)];
        node* temp = del;

        if (del->valu.ID == value)
        {
            table[hash(key)] = del->next;
        }
        else
        {
            bool found = false;
            while (del->valu.ID != value)
            {

                temp = del;
                del = del->next;
            }
            temp->next = del->next;

        }
        counter--;
        delete del;
    }
    else
        cout << "Value Not Found" << endl;
}

bool HashTable::search(int key, int value) {
    node* temp = table[hash(key)];
    while (temp != NULL)
    {
        if (temp->valu.ID == value)
            return true;
        if (temp->next == NULL)
            return false;
        temp = temp->next;
    }
    temp = NULL;
    delete temp;
}

User* HashTable::search(int national_id) {
    node* temp;

    temp = table[hash(national_id)];
    while (temp != NULL)
    {
        if (temp->valu.ID == national_id)
        {
            return &temp->valu;
        }

        temp = temp->next;

    }
    User* wrong = new User();
    wrong->ID = 0;
    wrong->pass = "wrong";
    return wrong;
}

bool HashTable::isempty() {
    if (counter > 0)
        return false;
    else
        return true;
}


void HashTable::hashdisplayall() {
    node* temp;
    int x = 0;
    for (int i = 0; i < 10; i++)
    {
        temp = table[i];
        while (temp != NULL)
        {
            x++;
            cout << "User Number: " << x << endl;
            cout << "Name: " << temp->valu.name << endl;
            cout << "ID: " << temp->valu.ID << endl;
            cout << "Age: " << temp->valu.age << endl;
            cout << "Gender: " << temp->valu.gender << endl;
            cout << "Governorate: " << temp->valu.governorate << endl;
            cout << "Pass: " << temp->valu.pass << endl;
            if (temp->valu.Vaccine)
            {
                cout << "Doses: " << temp->valu.dose << endl;
            }
            else {

                cout << "User is not Vaccinated" << endl;
            }            temp = temp->next;
        }
    }
    temp = NULL;
    delete temp;
}

HashTable::~HashTable() {
    node* temp;
    node* del;
    for (int i = 0; i < 10; i++)
    {
        temp = table[i];
        while (temp != NULL)
        {
            del = temp;
            temp = temp->next;
            delete del;
        }
    }
    temp = NULL;
    delete temp;
}