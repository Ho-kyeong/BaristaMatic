#include "BaristaInventory.h"
#include <iostream>
#include <string>
using namespace std;


double BaristaInventory::getDrinkCost(map<string, int> theIngredients){
	double drinkCost = 0.0;
	double unitCost = 0.0;
	int ingCount = 0;

	std::map<string, int>::iterator it = theIngredients.begin();
	while(it != theIngredients.end()){
		unitCost = (ingredients[it->first]).second;
		ingCount = it->second;
		drinkCost += ingCount * unitCost;
		//drinkCost += (it->second) * ((ingredients.find(it->first))->second.second);
		++it;
	}

	return drinkCost;
}

bool BaristaInventory::isDrinkIngAvailable(map<string, int> theIngredients){
	int avalUnits = 0;
	int ingCount = 0;

	std::map<string, int>::iterator it = theIngredients.begin();
	while(it != theIngredients.end()){
		avalUnits = (ingredients.find(it->first))->second.first;
		ingCount = it->second;
		
		if(avalUnits < ingCount){
			return false;
		}

		++it;
	}
	return true;
}

void BaristaInventory::consumeResources(map<string, int> theIngredients){
	std::map<string, int>::iterator it = theIngredients.begin();

	while(it != theIngredients.end()){
		// AVAILABLE UNITS -= UNITS CONSUMED
		(ingredients.find(it->first))->second.first -= it->second;
		++it;
	}
}

void BaristaInventory::printInventory(){
	cout << "Inventory:" << endl;
	std::map<string,pair<int, double>>::iterator it = ingredients.begin();
	for(ingredients.begin() ; it != ingredients.end(); ++it){
		// cout << DRINK NAME << "," << AVAILABLE UNITS << endl
		cout << (it->first).c_str() << "," << (it->second).first << endl;
	}
}

void BaristaInventory::initializeIngredients(){

	ingredients.insert(std::pair<string, pair<int,double>>("Coffee", std::pair<int,double>(DEF_UNIT, 0.75)));
	ingredients.insert(std::pair<string, pair<int,double>>("Decaf Coffee", std::pair<int,double>(DEF_UNIT, 0.75)));
	ingredients.insert(std::pair<string, pair<int,double>>("Sugar", std::pair<int,double>(DEF_UNIT, 0.25)));
	ingredients.insert(std::pair<string, pair<int,double>>("Cream", std::pair<int,double>(DEF_UNIT, 0.25)));
	ingredients.insert(std::pair<string, pair<int,double>>("Steamed Milk", std::pair<int,double>(DEF_UNIT, 0.35)));
	ingredients.insert(std::pair<string, pair<int,double>>("Foamed Milk", std::pair<int,double>(DEF_UNIT, 0.35)));
	ingredients.insert(std::pair<string, pair<int,double>>("Espresso", std::pair<int,double>(DEF_UNIT, 1.10)));
	ingredients.insert(std::pair<string, pair<int,double>>("Cocoa", std::pair<int,double>(DEF_UNIT, 0.90)));
	ingredients.insert(std::pair<string, pair<int,double>>("Whipped Cream", std::pair<int,double>(DEF_UNIT, 1.00)));		
}

void BaristaInventory::reStockInventory(){
	std::map<string,pair<int, double>>::iterator it = ingredients.begin();
	for(it; it != ingredients.end(); ++it){
		it->second.first = DEF_UNIT;
	}
}