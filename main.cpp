#include <iostream>
#include <map>

using namespace std;

typedef map<int,pair<int,string>> Structure;
Structure defaultMap;
Structure inventory;

void UserInputDefault() {
    int newInsert = defaultMap.size() + 1;
    int temp1;
    string temp2;
    cout << "Enter The Fruit You Want To Add To The Dictionary: " << endl;
    cin >> temp2;
    cout << "How Many Days Does It Take For " << temp2 <<  " To Go Bad? Enter Numeric Value" << endl;
    cin >> temp1;
    defaultMap[newInsert] = make_pair(temp1,temp2);
}

void UserInputInventory() {
    int size = defaultMap.size();
    for (int i = 1; i <= size; i++) {
        pair<int, string> printItem = defaultMap[i];
        cout << "Item: " << i << "\t"  << "Fruit: " << printItem.second << "\t" << "Days Till Rotten: " << printItem.first << endl;
    }
    int newInsert = inventory.size() + 1;
    int temp1;
    cout << "Enter The Item Number Of The Fruit You Bought: " << endl;
    cin >> temp1;
    inventory[newInsert] = defaultMap[temp1];
}

void PrintDefaultMap() {
    int size = defaultMap.size();

    for (int i = 1; i <= size; i++) {
        pair<int, string> printItem = defaultMap[i];
        cout << "Fruit: " << printItem.second << "\t" << "Days Till Rotten: " << printItem.first << endl;
    }
}

void PrintInventory() {
    int size = inventory.size();

    for (int i = 1; i <= size; i++) {
        pair<int, string> printItem = inventory[i];
        cout << "Fruit: " << printItem.second << "\t" << "Days Till Rotten: " << printItem.first << endl;
    }
}

void swap(pair<int, string> SpotOne, pair<int, string> SpotTwo)
{
    pair<int, string> temp = SpotOne;
    SpotOne = SpotTwo;
    SpotTwo = temp;
}

void inventorySort()
{
    int size = inventory.size();
    for(int i = 1; i <= size; i++)
    {
        for(int j = i+1; j <= size; j++)
        {
            pair<int, string> sortItem1 = inventory[i];
            pair<int, string> sortItem2 = inventory[j];
            if(sortItem2.first < sortItem1.first)
            {
                pair<int, string> temp = inventory[j];
                inventory[j] = inventory[i];
                inventory[i] = temp;
            }
        }
    }
}
int main() {

    defaultMap[1] = make_pair(10, "Bananas");
    defaultMap[2] = make_pair(6, "Apples");
    defaultMap[3] = make_pair(7, "Apricot");
    defaultMap[4] = make_pair(8, "Oranges");
    defaultMap[5] = make_pair(3, "Plums");
    defaultMap[6] = make_pair(1, "Lemons");

    int choice;
    bool doneFlag = true;
    while (doneFlag) {
        cout << "*******************************" << endl;
        cout << " 1 - Insert Entry Into Default Dictionary" << endl;
        cout << " 2 - Print Default Dictionary" << endl;
        cout << " 3 - Insert Entry Into Inventory" << endl;
        cout << " 4 - Print Inventory" << endl;
        cout << " 5 - Sort" << endl;
        cout << " 6 - Done" << endl;
        cout << " Enter Your Choice & Press Enter: " << endl;

        cin >> choice;
        cout << endl << endl;

        switch (choice)
        {
            case 1:
                UserInputDefault();
                break;
            case 2:
                PrintDefaultMap();
                break;
            case 3:
                UserInputInventory();
                break;
            case 4:
                PrintInventory();
                break;
            case 5:
                inventorySort();
                break;
            case 6:
                cout << "End of Program.\n";
                doneFlag = false;
                break;
            default:
                cout << "********************************" << endl;
                cout << "**Invalid Choice. Choose Again**" << endl;
                cout << "********************************" << endl;
                break;
        }
    }
    return 0;
}
