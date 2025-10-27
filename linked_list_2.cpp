#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL; // NULL = (void *)0
    }

    // node(int data)
    // {
    //     this->data = data;
    // }

    node(int data, node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

class LinkedList
{
private:
    int size;
    node *head, *tail;
    // node *reverse(node *head)
    // {
    //     if (!head || !head->next)
    //         return head;
    //     node *p = reverse(head->next); // revserse th elist after the first node and returns head
    //     head->next->next = head;       // second node next to head
    //     head->next = NULL;
    //     return p;
    // }

    node *reverse(node *head)
    {
        if (!head || !head->next)
            return head;
        node *p, *q, *r;
        p = head;
        q = p->next;
        r = q->next;
        while (q)
        {
            cout << q->data << endl;
            q->next = p;
            p = q;
            r = q->next;
            q = r;
        }
        head->next = NULL;
        return p;
    }

public:
    LinkedList()
    {
        size = 0;
        head = tail = NULL;
    }

    // O(1)
    void push_front(int insert)
    {
        size++;
        head = new node(insert, head);
    }

    // remove last item in linked list and return the value of the deleted item
    // Time Complexity: O(n)
    int pop_back()
    {
        if (tail == NULL)
            throw "Empty Linked List";

        int r = tail->data;
        size--;
        node *p = head;
        node *prev = NULL;

        while (p->next != NULL)
        {
            prev = p;
            p = p->next;
        }
        delete tail;
        tail = prev;

        if (tail)
            tail->next = NULL;
        else
            head = NULL;
        return r;
    }

    // time complexity: O(n) -- space complexity: O(1)
    void push_back(int k)
    {
        if (head == NULL)
            push_front(k);
        node *p = head;
        size++;
        head = new node(k, head);
        while (p->next != NULL)
            p = p->next;
        p->next = new node(k);
    }

    // removes the head from the LinkedList and returns the value of the head
    int pop_front()
    {
        if (head == NULL)
            throw "Empty Linked List";
        int temp_data = head->data;
        size--;
        node *temp_node = head;
        head = head->next;
        delete temp_node; // removes the old head from memory
        return temp_data;
    }

    void print()
    {
        node *pointer = head;
        while (pointer != NULL)
        {
            cout << pointer->data << "->";
            pointer = pointer->next;
        }
        cout << "NULL" << endl;
    }

    int size()
    {
        return size;
    }
};

void print(node *pointer)
{
    while (pointer != NULL)
    {
        cout << pointer->data << "->";
        pointer = pointer->next;
    }
    cout << "NULL" << endl;
}

// insert the "insert" to the beginning of the linked list and return the new head of the linked list
node *push_front(node *head, int insert)
{
    return new node(insert, head);
}

int main()
{

    LinkedList L;
    L.push_front(5);
    L.push_back(15);
    L.push_front(2);
    L.pop_front();
    L.push_front(9);
    L.print();

    // a new node is created  in heap memory, data = 0, next = NULL;
    // int *head = (int*) new node() <- don't do
    // node *head = new node(19);

    // give data a specific integer
    // head->data = 19;

    // node *temp = new node(5);
    // temp->next = head;
    // cout << head->data << ", " << head->next << endl;

    node *head = new node(19, new node(5, new node(11)));
    print(head);

    head = push_front(head, -100);
    print(head);

    return 0;
}