/*
 * maped.h
 *
 *  Created on: May 2, 2019
 *      Author: Lucy
 */

#ifndef MAPED_H_
#define MAPED_H_

#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<int,pair<int,string> > Structure;
Structure defaultMap;
Structure inventory;

/**
 *check to see if item exists in default map
 * @return boolean true if true
 */
bool isInDefaultMap(string item)
{
    int size = defaultMap.size();

    for (int i = 1; i <= size; i++)
    {
        pair<int, string> findItem = defaultMap[i];
        if(item == findItem.second)
        {
        	return true;
        }
    }
	return false;
}

/**
 * Alters data of item name/expiration date
 */
void amendDefaultMap()
{
	string exit;
	string item;
	std::cout << "Which item data do you wish to alter: ";

	while(1)
	{
		std::cin >> item;
		if(isInDefaultMap(item))
		{
			break;
		}
		else
		{
			if(exit == "1")
			{
				return;
			}
			std::cout << "Item doesn't exist. To exit enter 1 for item name" << std::endl;
		}
		std::cout << "Re-enter correct item name: ";
	}

    int size = defaultMap.size();
    int at;
    for (int i = 1; i <= size; i++)				//alter name of item first, you guys got a better idea do this part?
    {
        pair<int, string> alterItemData = defaultMap[i];
        if(item == alterItemData.second)
        {

        	at = i;
        	int date;
        	string name;
        	std::cout << "What name do you wish to change it too: "; std::cin>> name;
        	std::cout << "When does this item expire: "; std::cin>> date;
        	defaultMap[i] = make_pair(date, name);
        	break;
        }
    }

    size = inventory.size();
    for (int i = 1; i <= size; i++)						//fixing the data in inventory
    {
        pair<int, string> fixInvData = inventory[i];

        if(item == fixInvData.second)
        {
            pair<int, string> alterItemData = defaultMap[at];


            inventory[i] = make_pair(alterItemData.first, alterItemData.second);
        	break;
        }
    }

    std::cout << "fin" << std::endl << std::endl;
}

void UserInputDefault() {

	int count;
	cout << "How many items to you wish add" << endl;
	cin >> count; cout << endl;
	cout << "Enter The Item name: "; //adds item(fruits) to the dictionary
	while(count)
	{
		int newInsert = defaultMap.size() + 1;
		int temp1;
		string temp2;

		cin >> temp2;
		if(isInDefaultMap(temp2))
		{
			std::cout << "This item already exist." << std::endl;
		}
		else
		{
			cout << "How many days does " << temp2 <<  " take to expire? Enter Numeric Value: ";
			cin >> temp1; cout<< endl;
			defaultMap[newInsert] = make_pair(temp1,temp2);
		}
    	count--;
    	if(count==0)
    	{
    		std::cout << "fin" << std::endl << std::endl;
    		break;
    	}
		std::cout << "Please enter the next item." << endl;
	}
}

void UserInputInventory() {
    int size = defaultMap.size();
    for (int i = 1; i <= size; i++) {
        pair<int, string> printItem = defaultMap[i];
        cout << "Item " << i << ":\t"  << "Fruit: " << printItem.second << "\t\t" << "Days Till Rotten: " << printItem.first << endl;
    }
    int newInsert = inventory.size() + 1;
    int temp1;

    while(1)
    {
        cout << "Enter The Item Number Of The Fruit You Bought: ";
    	cin >> temp1;
    	std::cout << std::endl;
    	if(size < temp1 || temp1 <=0)
    	{
    		std::cout<< "Item # does not exists" << std::endl;
    	}
    	else
    	{
    		break;
    	}
    }
    inventory[newInsert] = defaultMap[temp1];
}

void PrintDefaultMap() {

	std::cout << "Current Inventory:" << std::endl;
    int size = defaultMap.size();

    for (int i = 1; i <= size; i++) {
        pair<int, string> printItem = defaultMap[i];
        cout << "Fruit: " << printItem.second << "\t" << "Days Till Rotten: " << printItem.first << endl;
    }
    std::cout << std::endl;
}

void PrintInventory() {
    int size = inventory.size();
    std::cout << "Current Inventory:" << std::endl;
    for (int i = 1; i <= size; i++) {
        pair<int, string> printItem = inventory[i];
        cout << "Fruit: " << printItem.second << "\t" << "Days Till Rotten: " << printItem.first << endl;
    }
    std::cout << std::endl;
}

void inventorySelectionSort()
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


#endif /* MAPED_H_ */
