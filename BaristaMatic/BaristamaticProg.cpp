#include<iostream>
#include<string>
#include "BaristaMenu.h"
#include "BaristaInventory.h"
using namespace std;

#define RESTOCK 'R'
#define QUIT 'Q'
#define ONE 1


int main()
{	
	BaristaInventory *theInventory = new BaristaInventory();
	if(theInventory == NULL){
		/* Exception Handling can be added here - 
		To make program simple it is not included assuming this case will not arise  */
		cout << "ERROR: theInventory is NULL " << endl;
		return 0;
	}
	theInventory->initializeIngredients();
	BaristaMenu theMenu(theInventory);
	theMenu.intializeDrinkList();
	
	theInventory->printInventory();
	theMenu.printMenu();

	int totalDrinks = theMenu.getDrinksCount();

	//Clear the input buffer
	cin.clear();
	fflush(stdin);
	
	//Loop to get the input from console till 'q' is entered to quit
	while(true){
		string str;		
		std::getline(cin,str);	//getline function is used in order to avoid  multiple selection using whitespaces/tabs
		const char* command = str.c_str();
		
		//Check if the input command has more than one character
		if(strlen(command) > 1){			
			bool isBlankLine = true;
			for(int i=0; i<strlen(command); i++){
				if(command[i] != ' ' && command[i] != '\t'){
					isBlankLine = false;
					break;
				}
			}
			if(isBlankLine){
				continue; // Ignore Blank Line
			}
			cout << "Invalid Selection: " << str << endl;			
		}
		else if(strlen(command) == 0 || command[0] == ' ' || command[0] == '\t'){
			continue; //Ignore blank lines lines with only white spaces
		}
		else if(toupper(command[0]) == RESTOCK){
			cout << "Restocking" << endl;
			theMenu.reStock();			
		}
		else if(toupper(command[0]) == QUIT){
			delete theInventory;	// Clean up function can be used but in our case only inventory has to be deleted
			cout << "Quit" << endl;
			exit(0);
		}
		else{
			int value = command[0] - '0';
			
			//Check to see if it is invalid number or invalid command
			if(value < ONE || value > totalDrinks){
				cout << "Invalid Selection: " << str << endl;
			}
			else{
				string cstr = theMenu.CheckAndPrepareDrink(value);
				cout << cstr << endl;
			}			
		}

		theInventory->printInventory();
		theMenu.printMenu();
	}
		
	cin.get();
	return 0;
}
