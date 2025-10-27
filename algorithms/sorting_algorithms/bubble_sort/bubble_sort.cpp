#include <iostream>
using namespace std;

int *bubbleSort(int arr[], int size)
{
    // for loop for iteration over index for comparispn
    for (int i = 0; i < size; i++)
    {
        // nested for loop to iterate and grab index for comparison
        for (int j = 0; j < size - i - 1; j++)
        {
            // check if current index *j* is on > the next j over (*j + 1*)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];   // store *j* in temporary
                arr[j] = arr[j + 1]; // set the current j to the next one over (*j + 1*)
                arr[j + 1] = temp;   // temp is assigned to the next j over (*j + 1*)
            }
        }
    }
    return arr;
}

int main()
{
    int array[5] = {3, 15, 45, 9, 10};
    int arr_size = 5;

    for (int i = 0; i < arr_size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    bubbleSort(array, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}