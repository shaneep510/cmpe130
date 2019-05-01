#include <iostream>
#include <map>

using namespace std;

typedef map<int,pair<int,string>> Structure;
Structure defaultMap;

void UserInputDefault() {
    int newInsert = defaultMap.size() + 1;
    int temp1;
    string temp2;
    cout << "Enter The Fruit You Want To Add To The Dictionary: " << endl;
    cin >> temp2;
    cout << "How Many Days Does It Take For " << temp2 <<  " To Go Bad? Enter Numeric Value" << endl;
    cin >> temp1;
    defaultMap[newInsert] = make_pair(temp1,temp2);
};

void PrintDefaultMap() {
    int size = defaultMap.size();

    for (int i = 1; i <= size; i++) {
        pair<int, string> printItem = defaultMap[i];
        cout << "Fruit: " << printItem.second << "\t" << "Days Till Rotten: " << printItem.first << endl;
    }
}
int main() {

    defaultMap[1] = make_pair(10, "Bananas");
    defaultMap[2] = make_pair(6, "Apples");
    defaultMap[3] = make_pair(7, "Apricot");
    defaultMap[4] = make_pair(8, "Oranges");
    defaultMap[5] = make_pair(3, "Plums");
    defaultMap[6] = make_pair(1, "Deez");

    int choice;
    bool doneFlag = true;
    while (doneFlag != false) {
        cout << "*******************************\n";
        cout << " 1 - Insert Entry Into Default Dictionary" << endl;
        cout << " 2 - Print" << endl;
        cout << " 3 - Done" << endl;
        cout << " Enter Your Choice & Press Enter: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                UserInputDefault();
                break;
            case 2:
                PrintDefaultMap();
                break;
            case 3:
                cout << "End of Program.\n";
                doneFlag = false;
                break;
            default:
                cout << "Invalid Choice. Choose Again." << endl;
                cin >> choice;
                break;
        }
    }
    return 0;
}