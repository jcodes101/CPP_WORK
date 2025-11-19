#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

/*
    ***** Given an array of doubles of size n. 
    Return the most frequent number in the list. 
    If there is a tie, return the larger one of the 2.
*/

// FUNCTION 1
double mostfrequent(double a[], int n){
    double  most_frequent_number = a[0];
    int highest_frequency = 0;

    for (int i = 0; i < n; i++){
        int frequency = 0;

        for (int j = 0; j < n; j++){
            if (a[j] == a[i]){
                frequency += 1;
            }
        }

        if (frequency > highest_frequency){
            highest_frequency = frequency;
            most_frequent_number = a[i];
        }
        else if (frequency == highest_frequency && a[i] > most_frequent_number){
            most_frequent_number = a[i];
        }

    }

    return most_frequent_number;
}

// =================================================================================

/*
    ***** Given an array of integers of size n, 
    return the the top k numbers in the array that are closest to the target. 
    Put these k numbers into a vector in the order of closeness.
*/

// FUNCTION 2
vector<int> topkclosestto(int a[], int n, int k, int target){
    vector<int> result;

    // create the distance array
    vector<int> distance(n);
    for (int i = 0; i < n; i++){
        distance[i] = abs(a[i] - target);
    }

    // pick k closest values
    for (int i = 0; i < k; i++){
        int best_index = -1;
        int best_distance = INT_MAX;

        // find the smallest distance
        for (int j = 0; j < n; j++){
            if (best_index == -1 || 
                distance[j] < best_distance || 
                (distance[j] == best_distance && a[j] > a[best_index])){
                best_distance = distance[j];
                best_index = j;
            }
        }

        // add the closest num to the result
        result.push_back(a[best_index]);

        // mark as used so it won't be chosen again
        distance[best_index] = INT_MAX;
    }

    
    
    return result;
}

int main(){

    // Test 1 -- mostfrequent
    double test1[] = {1.5, 2.5, 3.2, 4.8, 3.2, 5.9};
    int n1 = 6;
    cout << "Test 1 Results: " << mostfrequent(test1, n1) << endl;

    // Test 2 -- topkclosestto
    int a1[] = {1, 5, 2, 10, 6};
    int n_1 = 5;
    int k1 = 3;
    int target1 = 5;

    vector<int> result1 = topkclosestto(a1, n_1, k1, target1);
    cout << "Test 1: ";
    for (int x : result1) cout << x << " " << endl;

    return 0;
}