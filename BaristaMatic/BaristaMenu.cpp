#include "BaristaMenu.h"
#include <iostream>
#include <string>


BaristaMenu::~BaristaMenu(){
	std::map<string, BaristaDrink*>::iterator it = drinks.begin();
	while(it != drinks.end()){
		delete it->second;
	}
}

string BaristaMenu::CheckAndPrepareDrink(int selection){
	std::map<string, BaristaDrink*>::iterator it = drinks.begin();
	int count = 1;

	if(selection > drinks.size()){
		string res = "Invalid Selection: " + selection;
		return res;
	}

	while(count != selection && it != drinks.end()) {
			++it;
			++count;
		}

	/* Check if drink is in stock*/
	if(it->second->isAvailable == false){
		string res = "Out of Stock: " + it->first; 
		return res;
	}
	/* Check if ingredients for the drink are available in inventory and serve the drink */
	else if( theInventory != NULL && theInventory->isDrinkIngAvailable(it->second->getIngredients()) ) {
		theInventory->consumeResources(it->second->getIngredients());
		string res = "Dispensing: " + it->first;
		return res;
	}
	/*Return 'out of stock' if ingredients are not available */
	it->second->isAvailable = false;
	string res = "Out of Stock: " + it->first; 
	return res; 
}

void BaristaMenu::reStock(){
	std::map<string, BaristaDrink*>::iterator it = drinks.begin();
	
	while(it != drinks.end()){
		it->second->isAvailable = true;
		++it;
	}
	if(theInventory != NULL){
		theInventory->reStockInventory();
	}
	else {
		// We can have exception handling in this case
		cout << "ERROR: Inventory is NULL in BaristMenu " << endl;
	}
}

void BaristaMenu::printMenu(){
	cout << "Menu:" << endl;
	int count = 1;
	std::map<string,BaristaDrink*>::iterator it = drinks.begin();
	//for(it = drinks.begin(); it != drinks.end(); ++it){
	while(it != drinks.end()){
		if (theInventory != NULL){
			it->second->isAvailable = theInventory->isDrinkIngAvailable(it->second->getIngredients());
		}
		cout << count++ <<  "," << it->second->getName() << "," << '$' << it->second->getCost() << "," << 
		BOOL_STR(it->second->isAvailable) << endl;
		++it;
	}
}

int BaristaMenu::getDrinksCount(){
	return drinks.size();
}

void BaristaMenu::intializeDrinkList() {

	if(theInventory == NULL){		
		cout << "ERROR: intializeDrinkList() -> Inventory is NULL in BaristaMenu " << endl;
		return;
	}
	
	BaristaDrink *coffeeDrink = new BaristaDrink("Coffee",coffeeIngredients(),theInventory);		
	drinks.insert(std::pair<string, BaristaDrink*>("Coffee", coffeeDrink));	

	BaristaDrink *decafCoffeeDrink = new BaristaDrink("Decaf Coffee",decafCoffeeIngredients(),theInventory);
	drinks.insert(std::pair<string, BaristaDrink*>("Decaf Coffee", decafCoffeeDrink));

	BaristaDrink *caffeLatteDrink = new BaristaDrink("Caffe Latte",caffeLatteIngredients(),theInventory);
	drinks.insert(std::pair<string, BaristaDrink*>("Caffe Latte", caffeLatteDrink));

	BaristaDrink *caffeAmericanoDrink = new BaristaDrink("Caffe Americano",caffeAmericanoIngredients(),theInventory);
	drinks.insert(std::pair<string, BaristaDrink*>("Caffe Americano", caffeAmericanoDrink));

	BaristaDrink *caffeMochaDrink = new BaristaDrink("Caffe Mocha",caffeMochaIngredients(),theInventory);
	drinks.insert(std::pair<string, BaristaDrink*>("Caffe Mocha", caffeMochaDrink));

	BaristaDrink *cappucinoDrink = new BaristaDrink("Cappuccino",cappucinoIngredients(),theInventory);
	drinks.insert(std::pair<string, BaristaDrink*>("Cappuccino", cappucinoDrink));		
}

map<string,int> BaristaMenu::coffeeIngredients(){
	map<string,int> ingredients;
	ingredients.insert(std::pair<string,int>("Coffee",3));
	ingredients.insert(std::pair<string,int>("Sugar",1));
	ingredients.insert(std::pair<string,int>("Cream",1));

	return ingredients;
}

map<string,int> BaristaMenu::decafCoffeeIngredients(){
	map<string,int> ingredients;
	ingredients.insert(std::pair<string,int>("Decaf Coffee",3));
	ingredients.insert(std::pair<string,int>("Sugar",1));
	ingredients.insert(std::pair<string,int>("Cream",1));

	return ingredients;
}

map<string,int> BaristaMenu::caffeLatteIngredients(){
	map<string,int> ingredients;
	ingredients.insert(std::pair<string,int>("Espresso",2));
	ingredients.insert(std::pair<string,int>("Steamed Milk",1));		

	return ingredients;
}

map<string,int> BaristaMenu::caffeAmericanoIngredients(){
	map<string,int> ingredients;
	ingredients.insert(std::pair<string,int>("Espresso",3));

	return ingredients;
}

map<string,int> BaristaMenu::caffeMochaIngredients(){
	map<string,int> ingredients;
	ingredients.insert(std::pair<string,int>("Espresso",1));
	ingredients.insert(std::pair<string,int>("Cocoa",1));		
	ingredients.insert(std::pair<string,int>("Steamed Milk",1));
	ingredients.insert(std::pair<string,int>("Whipped Cream",1));

	return ingredients;
}

map<string,int> BaristaMenu::cappucinoIngredients(){
	map<string,int> ingredients;
	ingredients.insert(std::pair<string,int>("Espresso",2));			
	ingredients.insert(std::pair<string,int>("Steamed Milk",1));
	ingredients.insert(std::pair<string,int>("Foamed Milk",1));

	return ingredients;
}