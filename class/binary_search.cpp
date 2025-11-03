#include <iostream>
using namespace std;

// BEST CASE: O(1) | WORST CASE: O(log n) | AVG CASE: O(log n)
int binarySearch(int array[], int insert, int low, int high)
{
    /*
        this is a check for that if an entered (insert) is not
        inside of the array, whether it is a number lower higher than
        anything inside of the array -- and also even if it is in between any
        numbers but still not included.
    */
    if (low > high)
    {
        return -1;
    }

    // we determine the middle by adding the low and high and splitting it in 2
    int mid = (low + high) / 2;

    // if the middle of the array is equal to the desired search then return the element at the middle index
    if (array[mid] == insert)
    {
        return mid;
    }
    // if the number that is inserted is greater than the middle element in the array...
    else if (array[mid] < insert)
    {
        // return/search the greater/higher side of the array
        return binarySearch(array, insert, mid + 1, high);
    }
    else
    {
        // otherwise return/search at the lesser side.
        return binarySearch(array, insert, low, mid - 1);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 7, 10, 12, 15, 20, 23, 50, 51};
    /*
        sizeof(arr) = gets the total amount of elements/bytes in the array
        sizeof(int) = the number of bytes per integer (4 bytes)

        so (amount of ints * 4 bytes = amount of bytes)...
        and (amount of bytes / 4 bytes = amount of elements.
    */
    int n = sizeof(arr) / sizeof(int);
    cout << binarySearch(arr, 12, 0, n - 1);

    return 0;
}