#include <iostream>
#include <map>

using namespace std;

map<string,int> defaultMap;

int main() {
    cout << "Hello, World!" << endl;
    defaultMap["Banana"]=15;
    defaultMap["Apples"]=7;

    return 0;
}