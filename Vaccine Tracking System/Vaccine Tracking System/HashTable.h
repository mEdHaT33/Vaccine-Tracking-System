#pragma once
#include "User.h"
class node {
public:
    User valu;
    node* next;

    node();
    node(User value);
};

class HashTable
{
    node* table[10];
    int loadfactor;
    int counter;
public:
    HashTable(int key, User value);
    HashTable();
    int hash(int key);
    void insert(int key, User value);
    void remove(int key, int value);
    bool search(int key, int value);
    User* search(int national_id);
    bool isempty();
    void hashdisplayall();
    ~HashTable();
};