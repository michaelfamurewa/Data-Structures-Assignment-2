#include <iostream>
#include <string>

using namespace std;

struct node{
    string data ;
    unsigned int index;
    node* next;
};


class linkedList {
private:
    node* headPtr;
    node* tailPtr;
public:
    linkedList();
    void push_front(string);
    void push_back(string);
    void pop_front();
    void pop_back();
    void print();
    int size();
    string front();
    string back();
    bool empty();
    void insert(unsigned int, string);
    bool remove(unsigned int);
    unsigned int find(string);
};

