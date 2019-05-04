#include <iostream>
#include <string>
#include <map>
#include "maped.h"

using namespace std;



int main() {

    std::cout << "Welcome" << std::endl << std::endl; //When you open the app "Welcome" fades in & out
    												   //boom boom pow rave music starts


    defaultMap[1] = make_pair(10, "Bananas");
    defaultMap[2] = make_pair(6, "Apples");
    defaultMap[3] = make_pair(7, "Apricot");
    defaultMap[4] = make_pair(8, "Oranges");
    defaultMap[5] = make_pair(3, "Plums");
    defaultMap[6] = make_pair(1, "Lemons");

    int choice;
    bool doneFlag = true;
    while (doneFlag) {
        cout << "1 - Insert Entry Into Default Dictionary" << endl;
        cout << "2 - Print Default Dictionary" << endl;
        cout << "3 - Insert Entry Into Inventory" << endl;
        cout << "4 - Print Inventory" << endl;
        cout << "5 - Inventory Selection Sort" << endl;
        cout << "6 - Amend Data" << endl;
        cout << "7 - Done" << endl;
        cout << "Enter Your Choice & Press Enter: ";

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
                inventorySelectionSort();
                break;
            case 6:
            	amendDefaultMap();
            	break;
            case 7:
                cout << "End of Program.\n";
                doneFlag = false;
                break;
            default:
                cout << "********************************" << endl;
                cout << "**Invalid Choice. Choose Again**" << endl;
                cout << "********************************" << endl << std::endl;
                break;
        }
    }
    return 0;
}
