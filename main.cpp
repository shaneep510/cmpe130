#include <iostream>
#include <map>

using namespace std;

typedef map<int,pair<int,string>> Structure;
Structure defaultMap;

void UserInput(int,int,string) {
    int newInsert = defaultMap.size() + 1;
};

int main() {

    defaultMap[1] = make_pair(10, "Bananas");
    defaultMap[2] = make_pair(6, "Apples");
    defaultMap[3] = make_pair(7, "Apricot");
    defaultMap[4] = make_pair(8, "Oranges");
    defaultMap[5] = make_pair(3, "Plums");
    defaultMap[6] = make_pair(1, "Deez");

    int size = defaultMap.size();

    for (int i = 1; i <= size; i++) {
        pair<int, string> printItem = defaultMap[i];
        cout << "Fruit: " << printItem.second << "\t" << "Days Till Rotten: " << printItem.first << endl;
    }

    return 0;
}