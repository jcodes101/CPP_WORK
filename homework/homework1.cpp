#include <iostream>
using namespace std;

#include <string>
#include <map>

// FUNCTION 1
string binary_to_hex(string b)
{
    string final_hex_result = "";

    /*
    this is how to initialize a map with a list of keys|pairs

    - all of the keys ("0000") are represented by a certain number ("3")
    or a letter ("A")
    */

    map<string, string> binary_to_hex_map = {
        {"0000", "0"}, {"0001", "1"}, {"0010", "2"}, {"0011", "3"}, {"0100", "4"}, {"0101", "5"}, {"0110", "6"}, {"0111", "7"}, {"1000", "8"}, {"1001", "9"}, {"1010", "A"}, {"1011", "B"}, {"1100", "C"}, {"1101", "D"}, {"1110", "E"}, {"1111", "F"}};

    /*
        because all hex values are represented by exactly 4,
        in some cases all 4 slots may not be filled so a 0 needs to
        be pre appended to the front.

        the number that is being checked is how many spaces are filled already,
        and then the amount of zeros to make sure it is filled completely.
    */

    if (b.length() % 4 == 1)
    {
        b.insert(0, "000");
    }
    else if (b.length() % 4 == 2)
    {
        b.insert(0, "00");
    }
    else if (b.length() % 4 == 3)
    {
        b.insert(0, "0");
    }

    /*
        this for loop starts at the beginning of the string
        and iterates through the entire *length* of the string (b)

        and instead of doing ++ which will keep on going even to
        the next 4 even without checking, we need to do +=4 to get 4
        at a time and check if it is equal to anything back in the map
    */
    for (int i = 0; i < b.length(); i += 4)
    {
        string hex_group = b.substr(i, 4);

        // here is a check for any pre appende zeros so that it will not
        // unnecessarily show in the final result
        if (final_hex_result.empty() && hex_group == "0000")
            continue;

        final_hex_result += binary_to_hex_map[hex_group];
    }

    // last case if the entire input is zero to just return "0".
    if (final_hex_result.empty())
    {
        return "0";
    }

    return final_hex_result;
}

// ====================================================================================================================

// FUNCTION 2
int max_two_product(int *a, int n)
{
    // set the max product to the the first pair (first two indexes of the array)
    int max_product = a[0] * a[1];

    // this outer loop picks the first number in the pair
    for (int i = 0; i < n - 1; i++)
    {
        // this inner loop picks the second number, but has to start one index after i
        // so it does not grab the same number
        for (int j = i + 1; j < n; j++)
        {
            int current_product = a[i] * a[j];

            if (current_product > max_product)
            {
                max_product = current_product;
            }
        }
    }
    return max_product;
}

// int main()
// {
//     cout << binary_to_hex("10010011111") << endl;
//     cout << binary_to_hex("000010") << endl;

//     int a[] = {2, -1, 3};
//     int n = 3;
//     cout << max_two_product(a, n);
//     return 0;
// }