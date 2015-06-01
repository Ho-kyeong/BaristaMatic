#ifndef BARISTAMENU_H
#define BARISTAMENU_H
#include "BaristaInventory.h"
#include "BaristaDrink.h"
#include<map>
using namespace std;

#define BOOL_STR(b) ((b)?"true":"false")

/* MENU Class which handles serving and intialization of all Drink Classes */
class BaristaMenu {
	BaristaInventory *theInventory; // Reference to the BaristaInventory

	/* Map conataining the collection of existing drinks.
	Map is used with Drink name as Key, this ensures extra logic is not required when Drinks are to
	be displayed in sorted order */
	map<string,BaristaDrink*> drinks;	
	
public:
	BaristaMenu(BaristaInventory *inventory){
		theInventory = inventory;
	}

	~BaristaMenu();

	/*Checks whether the ingredients are available for serving paritcular Drink and 
	if available the Drink will be served consuming the ingredients from inventory*/
	string CheckAndPrepareDrink(int selection); 

	/*Restcoking - Set Inventory ingredients to default value and Set Avaialbility of all Drinks to true */
	void reStock();

	void printMenu();

	/* Returns total no of drink types in the menu  */
	int getDrinksCount();

	/* Drink Object is initialized in this function 
	New Drink Object can be added using this function and no other code change is required*/
	void intializeDrinkList();

	//List of functions initializing the specific Drink object
	map<string,int> coffeeIngredients();
	map<string,int> decafCoffeeIngredients();
	map<string,int> caffeLatteIngredients();
	map<string,int> caffeAmericanoIngredients();
	map<string,int> caffeMochaIngredients();
	map<string,int> cappucinoIngredients();

};

#endif