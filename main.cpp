#include<iostream>
#include<conio.h>
using namespace std;

class warehousing{
private:
    string nameItem;
    int codeItem;
public:
    void createItem(string nameItem, int codeItem);
    void pushItem();
    void popItem();
    void display();
    void peekItem();
    void changeItem();
    void destroyItem();
};

// create linked list node
struct dataItem{
    string nameItem;
    int codeItem;

    //pointer
    dataItem *prev;
    dataItem *next;
};

//global variable
dataItem *head, *tail, *cur, *newNode, *del;
int maximumItem = 5;
