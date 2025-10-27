#include <iostream>
using namespace std;

// node is like a box that holds a number and a link to another box
class node
{
public:
    // current number inside the box
    int data;
    // a pointer (p or pointer) to the next box
    node *next;

    /*
        this is a default node constructor (ex. node a;)
        data = 0
        next = NULL
    */
    node()
    {
        data = 0;
        next = NULL; // NULL = (void *) 0;
    }

    /*
        this is for giving a node a value right away
        (ex. new node(5) makes a box with...
            - data = 5
            - next = NULL
        )

        The this-> just means “this node’s variable”,
        so the computer knows you mean the class variable, not a local one.
    */
    node(int data, node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

/*
    A linked list is just a bunch of nodes connected together like a chain:
    🧱🧱🧱 each box points to the next.
*/
class LinkedList
{
private:
    // n - how many nodes is in the list
    int n;

    // head - points to the first node (start of list)
    // tail - points to the last node (end of the list)
    node *head, *tail;

public:
    LinkedList()
    {
        n = 0;
        head = tail = NULL;
    }

    // remove the last item in linked list and return the value of the deleted item
    // time complexity O(n)
    int pop_back()
    {
        if (tail == NULL)
            throw "Empty Linked List";

        /*
            Save the number from the last node in r (so we can return it later).
            Reduce the count n because one node is about to be deleted.
        */
        int r = tail->data;
        n--;

        /*
            This loop walks through the list from the head until it reaches the last node:
            p keeps moving forward (p = p->next)
            prev stays one step behind.
            At the end:
            p = last node
            prev = second-to-last node
        */
        node *p = head;
        node *prev = NULL;
        while (p->next != NULL)
        {
            prev = p;
            p = p->next;
        }

        // deletes the last node from mem
        delete tail;
        // makes the new tail be the node right before the deleted one
        tail = prev;

        /*
            If there’s still a tail left, make sure it doesn’t point to anything (since it’s now the last).
            If there’s no tail left, the list is empty — so set head to NULL.
        */
        if (tail)
            tail->next = NULL;
        else
            head = NULL;

        // return the number that was in the deleted node
        return r;
    }

    // add a new node at the end
    // time complexity: O(1): space complexity: O(1)
    void push_back(int k)
    {
        /*
            new node(k) makes a new box with the number (k)
            tail->next = new node(k) attaches it to the last node
            then, tail = tail->next moves the tail pointer to the new node
            then n++ increases the count

        */
        tail->next = new node(k);
        tail = tail->next;
        n++;
        /*
            if(head == NULL) {
              push_front(k);
              return;
            }
            node* p = head;
            while (p->next != NULL) p = p->next;
            // p is the last node in the linked list
            p->next = new node(k);
        */
    }

    // add to the front
    // O(1)
    void push_front(int k)
    {
        /*
            Make a new node that points to the old head (new node(k, head)).
            Then make the new node the new head.
            If the list was empty (no tail), make tail = head (since there’s now one node).
        */
        n++;
        head = new node(k, head);
        if (!tail)
            tail = head;
    }

    // removes head from Linked List and return the value of the head
    // O(1)
    int pop_front()
    {
        if (head == NULL)
            throw "Empty Linked List";

        // store the number from the had in temp_data and decrease the size
        int temp_data = head->data;
        n--;

        // save old head in temp_node (to delete it)
        // move foroward to the next node
        node *temp_node = head;
        head = head->next;

        if (!head)
            tail = NULL;
        delete temp_node; // removes the old head from memory
        return temp_data;
    }

    void print()
    {
        node *p = head;
        while (p != NULL)
        {
            cout << p->data << "->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
    int size()
    {
        return n;
    }
};

int main()
{
    LinkedList L;
    L.push_front(5);
    L.push_back(15);
    L.push_front(2);
    L.pop_front();
    L.push_front(9);
    L.push_back(11);
    L.print();

    /*
      while (L.size() > 0) {
        cout << L.pop_front() << endl;
      }
    */
    return 0;
}