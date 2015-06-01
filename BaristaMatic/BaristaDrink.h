#ifndef BARISTADRINK_H
#define BARISTADRINK_H
#include "BaristaInventory.h"
#include <iostream>
#include<string>
#include<map>
using namespace std;

/* DRINK CLASS */
class BaristaDrink {
	string name; // Name of the drink
	map<string,int> ingredients; // Map containing the ingredients of the drink
	double cost; // Cost of the drink
	BaristaInventory *theInventory; // Reference to the inventory class

public:
	bool isAvailable; // Boolean variable to check if the drink is in stock

	BaristaDrink(string theName, map<string,int> theIngredients,BaristaInventory *inventory){	
		this->name = theName;
		ingredients = theIngredients;
		theInventory = inventory;		
		isAvailable = true;
		if(theInventory != NULL) {
			cost = theInventory->getDrinkCost(ingredients); // Call this function on object creation to set the cost of the drink
		}
	}

	string getName() {
		return name;
	}
	
	double getCost() {
		return cost;
	}

	void setCost() { 
		if(theInventory != NULL){
			cost = theInventory->getDrinkCost(ingredients);
		}
		else{
			cout << "ERROR: Inventory is NULL in BaristaDrink for " << name << " Object" <<endl;			
		}
	}

	map<string, int> getIngredients(){
		return ingredients;
	}

};

#endif