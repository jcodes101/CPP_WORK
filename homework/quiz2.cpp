#include <iostream>
using namespace std;

int multiply(int x, int n)
{
    if (n < 0)
        -multiply(x, -n);
    if (n == 0)
        return 0;
    return x + multiply(x, n - 1);
}

// time complexity: O(n)
int multiply(int x, int n)
{
    if (n < 0)
    {
        return x - multiply(x, -n);
    }
    if (n == 0)
        return 0;
    multiply(x, n / 2);
}

int multiply(int x, int n)
{
    if (n < 0)
    {
        return x - multiply(x, -n);
    }
    if (n == 0)
        return 0;
    int r = multiply(x, n >> 1);
    r = r + r;
}

int main()
{
    int a = 5;
    int b = a << 1;
    cout << b << endl;
    // cout << multiply(-10, -9) << endl;
    return 0;
}