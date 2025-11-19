#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class hashtable {
    list<int> *arr;
    int table_size;
    int num_elements;

    int hash(int k){
        return k % table_size;
    }

    public:
    // hashtable(){
    //     tsize = 1024;
    //     a = new list<int> [tsize];
    //     n = 0;
    // }

    hashtable(int table_size=1024){
        this->table_size = table_size;
        arr = new list<int> [table_size];
        num_elements = 0;
    }

    void insert(int k){
        int p = hash(k);

        // store k in the arr[p]
        bool found = false;
        for (int &val : arr[p]){
            if (val == k){
                found = true;
                break;
            }
        }
        if (!found){
            arr[p].push_back(k);
            num_elements++;
        }
    }

    bool search(int k){
        int p = hash(k);
        return find(arr[p].begin(), arr[p].end(), k) != arr[p].end();
    }

    void remove(int k){
        int p = hash(k);
        if (find(arr[p].begin(), arr[p].end(), k) != arr[p].end()){
            arr[p].remove(k);
            num_elements--;
        }
    }

    void print(){
        int i;

        for (i = 0; i < table_size; i++){
            cout << i << ": ";
            for (int &k : arr[i]){
                cout << k << "->";
            }
            cout << "NULL" << endl;
        }
    }

    int size(){
        return num_elements;
    }
};


int main() {

    hashtable h(10);

    
    h.insert(123);
    h.insert(123);
    h.insert(55);
    h.insert(133);
    h.print();

    cout << "size=" << h.size() << endl;

    h.remove(123);

    if (h.search(123)) cout << "found!" << endl;
    
    else cout << "not found!\n";

    return 0;
}
