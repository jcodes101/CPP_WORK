#include <iostream>
using namespace std;

int g = 18393;
int n = 1000000000;
int my_count = 0;
int guess(int ins)
{
    cout << ins << endl;
    my_count++;
    return g - ins;
}

int strg(int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    int r = guess(mid);
    if (r == 0)
    {
        return mid;
    }
    else if (r < 0)
    {
        return strg(low, mid - 1);
    }
    else
    {
        return strg(mid + 1, high);
    }
}

int main()
{
    cout << strg(1, n) << endl;

    cout << "Number of guesses: " << my_count << endl;

    return 0;
}