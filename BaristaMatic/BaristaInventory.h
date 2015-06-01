#ifndef BARISTAINVENTORY_H
#define BARISTAINVENTORY_H
#include<map>
using namespace std;

class BaristaInventory {
	map<string, pair<int,double>> ingredients; // Map containing ingredient and pair of available units and cost per unit 
	static const int DEF_UNIT = 10; // Default value of each ingredient

public:
	BaristaInventory(){		
	}

	/* Return the cost of the drink for the given ingredients */
	double getDrinkCost(map<string, int> theIngredients);

	/* Check if ingredients are available for a specific drink with given ingredients */
	bool isDrinkIngAvailable(map<string, int> theIngredients);

	/* Consume resources to serve the drink with given ingredients */
	void consumeResources(map<string, int> theIngredients);

	void printInventory();

	/*Intializes the inventory
	1. Intialize the total units for each ingredient
	2. Intialize cost per unit of each ingredient
	New ingredient can be added without any other code change*/
	void initializeIngredients();

	/* Set the total units of each ingredient to default value */
	void reStockInventory();

};

#endif