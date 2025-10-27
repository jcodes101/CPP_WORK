#include <iostream>
using namespace std;

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " << endl;
    }
}

void insert(int a[], int n, int k)
{
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        if (k < a[i])
            a[i + 1] = a[i];
        else
            break;
    }

    a[i + 1] = k;
}

int main()
{
    int a[1024] = {1, 3, 5, 10};

    int n = 4;

    print(a, n);
    cout << " " << endl;

    insert(a, n++, 9);

    print(a, n);

    return 0;
}