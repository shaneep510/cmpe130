#include <iostream>
#include <map>

using namespace std;

typedef map<int,pair<int,string>> defaultMap;

int main() {

    defaultMap M;
    M[1] = make_pair(10, "Bananas");
    M[2] = make_pair(6, "Apples");
    M[3] = make_pair(7, "Apricot");
    M[4] = make_pair(8, "Oranges");
    M[5] = make_pair(3, "Plums");
    M[6] = make_pair(1, "Deez");
    int size = M.size();


    for (int i = 1; i <= size; i++) {
        pair<int, string> printItem = M[i];
        cout << "Fruit: " << printItem.second << "\t" << "Days Till Rotten: " << printItem.first << endl;
    }

    return 0;
}