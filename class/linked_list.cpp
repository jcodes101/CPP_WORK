#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
        : data(0), next(nullptr)
    {
    }

    // node(int data)
    // {
    //     this->data = data;
    // }

    node(int data, node *next = nullptr)
        : data(data), next(next)
    {
    }
};

class LinkedList
{
private:
    int sz;
    node *head, *tail;

public:
    LinkedList()
        : sz(0), head(nullptr), tail(nullptr)
    {
    }

    ~LinkedList()
    {
        // clean up all nodes
        while (head != nullptr)
        {
            node *tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
        sz = 0;
    }

    // O(1)
    void push_front(int insert)
    {
        node *n = new node(insert, head);
        head = n;
        if (tail == nullptr)
            tail = head;
        ++sz;
    }

    // remove last item in linked list
    int pop_back()
    {
        // remove last item in linked list and return its value
        if (tail == nullptr)
            throw "Empty Linked List";

        int r = tail->data;
        --sz;

        node *p = head;
        node *prev = nullptr;

        while (p != nullptr && p->next != nullptr)
        {
            prev = p;
            p = p->next;
        }

        // delete the old tail
        delete tail;
        tail = prev;

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;

        return r;
    }

    // time complexity: O(n) -- space complexity: O(1)
    void push_back(int k)
    {
        node *n = new node(k, nullptr);
        if (head == nullptr)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        ++sz;
    }

    // removes the head from the LinkedList and returns the value of the head
    int pop_front()
    {
        if (head == nullptr)
            throw "Empty Linked List";
        int temp_data = head->data;
        node *temp_node = head;
        head = head->next;
        delete temp_node; // removes the old head from memory
        if (head == nullptr)
            tail = nullptr;
        --sz;
        return temp_data;
    }

    void print()
    {
        node *pointer = head;
        while (pointer != nullptr)
        {
            cout << pointer->data << "->";
            pointer = pointer->next;
        }
        cout << "NULL" << endl;
    }

    int size()
    {
        return sz;
    }
};

void print(node *pointer)
{
    while (pointer != nullptr)
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

    // clean up manual chain created above
    while (head != nullptr)
    {
        node *tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}