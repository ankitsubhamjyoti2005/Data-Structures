#include <iostream>
using namespace std;
// node class is created
class node
{
public:
    int data;
    node *next;

    node(int data)   
    {
        this->data = data;
        this->next = NULL;
    }

    //descructer
    ~node(){
        int value = this->data;
        //memory free
        if(this != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free with data "<<value<<endl;
    }
};
// insert ele in the head
void insertHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
// print the element of linklisr
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << endl;
};
// insert element in the tail
void inserTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}
// insert ele int the k-th position
void insert(node *&head, node *&tail, int d, int k)
{
    if (k == 1)
    {
        insertHead(head, d);
        return;
    }
    // else
    // {
    node *temp = head;
    int cnt = 1;
    while (cnt < k - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // insert at the tail
    if (temp->next == NULL)
    {
        inserTail(tail, d);
        return;
    }
    // creating node for inserting ele or d
    node *nodeToInsert = new node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    // }
}

//delete of node
void delNode(int k,node* &head){
     if(k == 1){
        //del the head node
        node* temp = head;
        head = head->next;
        //memory free
        temp->next = NULL;
        delete temp;
     }else{
        //delete the value of middle and last node 
        node* curr = head;
        node* prev = NULL;

        int count = 1;
        while(count<k){
            prev = curr;
            curr=curr->next;
            count++;
        }
        prev->next = curr->next;
        curr -> next = NULL;
        delete curr;
     }
}
int main()
{
    node *n1 = new node(10);
    // cout<<n1->data<<endl;
    // cout<<n1->next<<endl;
    // print(n1);
    print(n1);
    node *tail = n1;
    insertHead(n1, 5);
    inserTail(tail, 15);
    //print(n1);

    insert(n1,tail,20,4);
    insert(n1,tail,18,4);
    print(n1);

    delNode(5,n1);
    print(n1);
}