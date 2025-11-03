#include <iostream>
using namespace std;

// FUNCTION 1 -- int sumdigits(int n,int b);
/*
    the purpose of this function is to return the sum of digits
    in base (b)
*/
int sumdigits(int n, int b)
{
    /*
        this is the base case of the function that checks
        when n becomes 0, and without this the recursion would go on forever
    */
    if (n == 0)
        return 0;

    /*
        this takes away the least needed digit in the base (b)
        example_1: 123 % 10 = 3
        example_2: 7 % 2 = 1

    */
    int current_digit = n % b;

    // this line removes the last
    // example_1: 123 / 10 = 12
    // example_2: 7 / 2 = 3

    int next = n / b;

    // returns the current digit added to the sum of digits of the smaller number (next)
    return current_digit + sumdigits(next, b);
}

// FUNCTION 2 -- node* merge_sorted(node* head1,node* head2);

// this is the (class node) definition
class node
{
public:
    // the value is (data)
    int data;
    // the pointer is the (next) node
    node *next;

    node(int data, node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

// print function for testing
void print(node *pointer)
{
    while (pointer != nullptr)
    {
        cout << pointer->data << "->";
        pointer = pointer->next;
    }
    cout << "NULL" << endl;
}

/*
    this function merges two decreasing linked lists with head1 and head2
    into a single decreasing linked list and returns the head of merged linked list.
*/
node *merge_sorted(node *head1, node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    if (head1->data >= head2->data)
    {
        head1->next = merge_sorted(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = merge_sorted(head1, head2->next);
        return head2;
    }
}

// FUNCTION 3 -- bool cycle(node* head);

bool cycle(node *head)
{
    node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        // move slow by 1
        slow = slow->next;

        // move fast by 2
        fast = fast->next->next;

        // there is a cycle
        if (slow == fast)
            return true;
    }
    // there is no cycle
    return false;
}

int main()
{
    // FUNCTION 1 TESTS
    cout << sumdigits(7, 2) << endl;
    cout << sumdigits(123, 10) << endl;

    // FUNCTION 2 TESTS
    node *list1 = new node(5, new node(3));
    node *list2 = new node(4, new node(3, new node(1)));

    cout << "List 1: ";
    print(list1);

    cout << "List 2: ";
    print(list2);

    node *merge_l1_l2 = merge_sorted(list1, list2);
    cout << "Merged List: ";
    print(merge_l1_l2);

    // FUNCTION 3 TESTS
    node *list3 = new node(1, new node(2, new node(3, new node(4))));
    cout << cycle(list3) << endl;

    node *p1 = new node(1);
    node *p2 = new node(2);
    p1->next = p2;
    p2->next = p1;

    cout << cycle(p1) << endl;

    return 0;
}