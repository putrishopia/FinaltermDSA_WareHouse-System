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
void warehousing::createItem( string nameItem, int codeItem ){
    head = new dataItem();
    head->nameItem = nameItem;
    head->codeItem = codeItem;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

int countItem(){
    if( head == NULL ){
        return 0;
    }else{
        int nominal = 0; // initialization
        cur = head;

        while( cur != NULL ){
            cur = cur->next;
            nominal++;
        }
        return nominal;
    }
}

bool isFullItem(){
    if( countItem() == maximumItem ){
        return true;
    }else{
        return false;
    }
}

bool isEmptyItem(){
    if( countItem() == 0 ){
        return true;
    }else{
        return false;
    }
}

void warehousing :: pushItem(){
	cout<<" Enter Item name\t: ";
    cin>>nameItem;
    cout<<" Enter item code\t: ";
    cin>>codeItem;

    if( isFullItem() ){
	    cout<<"\n=================================================";
        cout << "\nSorry, unable to input new item" << endl;
        cout << "The Warehouse is Full" << endl;
        getch();
    }else{
        if( isEmptyItem() || tail == NULL ){
            createItem(nameItem, codeItem);
        }else{
            newNode = new dataItem();
            newNode->nameItem = nameItem;
            newNode->codeItem = codeItem;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
    }
}

void warehousing :: popItem(){
    if( isEmptyItem() || tail == NULL )
		{cout<<" Warehouse is empty\n";
		getch();}

	else
	{
		cur=tail;
		tail=tail->prev;
		cout<<" Item code "<<cur->codeItem<<" is removed\n";
		delete(cur);
		getch();
	}
}


void warehousing :: display(){
    if( isEmptyItem() || tail == NULL ){
        cout << "Warehouse is empty\t" << endl;
        getch();
    }else{
        cout << "Warehouse items (item name, item code) : " << endl;
        cur = tail;

        while( cur != NULL ){
            cout << cur->nameItem << " - " << cur->codeItem << endl;
            cur = cur->prev;
        }
        getch();
    }
}

void warehousing :: peekItem(){
    int find1;
    int found = 0;
    cur = head;

    if(cur != NULL)
    {
        cout<<"\n Enter item code\t: ";
        cin>>find1;

        while(cur!=NULL)
        {
            cur->codeItem;
            if(find1==cur->codeItem)
            {
                cout<<"\n\n>>>   Item founded   <<<"<<endl;
                cout<<" Item name\t: "<<cur->nameItem<<endl;
                cout<<" ------------------------------"<<endl;
                cout<<"\n\n";
              found=1;
            }
            cur = cur->next;
        }
        if(found==0)
        {
            cout<<" Item is not found";
        }
    }
    else cout<<" Warehouse is empty";
    getch();
}

void warehousing :: changeItem(){
    int find1;
    int found = 0;
    cur = head;

    if(cur != NULL)
    {
        cout<<"\n Enter item code to be changed\t: ";
        cin>>find1;
        cout<<"\n Input item name to be stored\t: ";
        cin>>nameItem;

        while(cur!=NULL)
        {
            cur->codeItem;
            if(find1==cur->codeItem)
            {
                cout<<"\n Item code " << cur->codeItem << " had been changed to "<< nameItem <<endl;
                cout<<" Please check warehouse display to see the updated items";
                cur->nameItem = nameItem;
              found=1;
            }
            cur = cur->next;

        }
        if(found==0)
        {
            cout<<" Item is not found";
        }
    }
    else cout<<" Warehouse is empty";
    getch();
}

void warehousing :: destroyItem(){
    cur = head;
    while( cur != NULL ){
        del = cur;
        head = head->next;
        delete del;
        cur = cur->next;
    }
}
