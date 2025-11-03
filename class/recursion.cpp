#include <iostream>
using namespace std;

int findMin(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    return min(findMin(arr, n - 1), arr[n - 1]);
}

int getSum(int arr[], int n)
{
    if (n == 0)
        return 0;

    return getSum(arr, n - 1) + arr[n - 1];
}

bool findNum(int arr[], int n, int t)
{

    if (n == 0)
        return false;
    if (findNum(arr, n - 1, t))
        return true;
    return t == arr[n - 1];

    // return findNum(arr, n - 1, t) || t == arr[n - 1];
}

int main()
{
    int array[] = {1, 6, 3, 4, 5, 0, 9, 10};
    //
    int i, n = sizeof(array) / sizeof(int);
    cout << findMin(array, n) << endl;

    cout << getSum(array, n) << endl;

    cout << findNum(array, n, 10);

    return 0;
}
