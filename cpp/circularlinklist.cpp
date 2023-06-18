#include<iostream>
using namespace std;

class node{
    public:
    node* next;
    // node* prev;
    int data;

    node(int d)  
    {
        this->data = d;
        this->next = NULL;
        //this->prev = NULL;
    }

    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free from node with data : "<<value<<endl;
    }
};

//insert data
void insertnode(node* &tail,int element,int d){
    //empty list
    if(tail == NULL){
        node* newNode = new node(d);
        tail = newNode;
        newNode -> next = newNode;
    }else{
        node* curr = tail;
        while (curr->data != element)     
        {
            curr = curr->next;
        }
        node* temp = new node(d);
        temp -> next = curr ->next;
        curr -> next = temp;
    }
}
void print(node* tail) {

    node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << "->";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 


void deleteNode(node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        node* prev = tail;
        node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

int main(){
    node* tail = NULL;

    insertnode(tail,5,4);
    print(tail);
    insertnode(tail,4,4);
    insertnode(tail,4,411);
    print(tail);
    deleteNode(tail,4);
    print(tail);
}
