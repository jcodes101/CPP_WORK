#include <iostream>
using namespace std;

int main()
{

    int nums[5];

    cout << "Enter 5 numbers: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> nums[i];
    }

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += nums[i];
    }

    double avg = sum / 5;
    cout << "Avg: " << avg << endl;

    return 0;
}