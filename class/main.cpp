#include <iostream>

using namespace std;

int findmax(int nums[], int size)
{
    int max = nums[0];

    for (int i = 1; i < size; i++)
    {
        if (max < nums[i])
            max = nums[i];
    }

    return max;
}

int main()
{
    int nums[4] = {10, 2, 30, 4};

    int mx = findmax(nums, sizeof(nums) / sizeof(4));

    cout << "Max: " << mx;
    return 0;
}