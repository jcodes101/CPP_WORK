#include <iostream>
using namespace std;

int out_of_order_pairs(int *a, int n)
{
    int num_pairs = 0;

    // first for loop to iterate over once for i
    for (int i = 0; i < n; i++)
    {
        // second for loop to iterate a second time comparing j to i
        for (int j = i + 1; j < n; j++)
        {
            // check for i being greater than j and increasing the count
            if (a[i] > a[j])
            {
                num_pairs += 1;
                // cout << a[i] << "," << a[j] << endl;
                // num_pairs[0] = a[i];
                // num_pairs[1] = a[j];
            }
        }
    }
    return num_pairs;
}

int main()
{
    // input for size
    int n;
    cin >> n;

    // input for array
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << out_of_order_pairs(a, n) << endl;

    return 0;
}