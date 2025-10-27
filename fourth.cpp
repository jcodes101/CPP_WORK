#include <iostream>
using namespace std;

int main()
{

    int my_matrix[3][3];

    cout << "Enter 9 numbers: " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> my_matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += my_matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << sum << endl;
    }

    return 0;
}
