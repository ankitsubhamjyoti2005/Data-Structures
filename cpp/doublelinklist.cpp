#include <iostream>
using namespace std;

// node creation
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

c// print the link-list
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << endl;
}

// find length of the link-list
int len(node *&head)
{
    node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

// insert element in the double linklist
void insertHed(node *&tail,node *&head, int d)
{
    // empty list
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// insert in the tail
void insertTail(node *&head,node *&tail, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// insert at any point
void insertAtPosition(node *&tail, node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertHed(tail,head, d);
        return;
    }

    node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertTail(head,tail, d);
        return;
    }

    // creating a node for d
    node *nodeToInsert = new node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// delet a node
void deleteNode(int position, node* & head) { 

    //deleting first or start node
    if(position == 1) {
        node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}

int main()
{
    //node *n1 = new node(15);
    node *head = NULL;
    node *tail = NULL;

    insertHed(tail,head, 10);
    insertTail(head,tail, 20);
    cout << "the length of the linklist is:-" << len(head) << endl;
    print(head);
    insertAtPosition(tail, head, 2, 5);
    print(head);
}