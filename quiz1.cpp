#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

int remove_odd(int arr[], int size)
{
    int i, j = 0;

    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr[j++] = arr[i];
        }
    }
    return j;
}

int main()
{
    int array[] = {1, 5, 6, 10, 4, 19};
    int size = sizeof(array) / sizeof(int);

    int new_size = remove_odd(array, size);

    print(array, new_size);

    return 0;
}