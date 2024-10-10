// my first program in C++
#include <iostream>
#include <string>
#include <unistd.h>

const double COFFEE_PRICE = 15.00;
const double SANDWICH_PRICE = 30.00;
const double SALAD_PRICE = 25.00;
const double JUICE_PRICE = 10.00;
const double MUFFIN_PRICE = 20.00;
const double PIZZA_PRICE = 35.00;
const double SOUP_PRICE = 18.00;
const double BURGER_PRICE = 40.00;

std::string displayName;
std::string displayLName;


void displayNames()
{

std::cout << "Please enter your name : " << "\n" << std::endl;
getline (std::cin, displayName);
std::cout << "Please enter your last name : " << "\n" << std::endl;
getline (std::cin, displayLName);

std::cout << "Welcome, " << displayName << " " << displayLName << std::endl;

return;
}

void displayMenu ()
{
	sleep(1);
	std::cout << "Cafeteria Menu:" << "\n" << std::endl;
        std::cout << "1. " << "Coffee" << " - " << "R15.00" << "\n" << std::endl;
        std::cout << "2. " << "Sandwich" << " - " << "R30.00" << "\n" << std::endl;
	std::cout << "3. " << "Salad" << " - " << "R25.00" << "\n" << std::endl;
	std::cout << "4. " << "Juice" << " - " << "R10.00" << "\n" << std::endl;
	std::cout << "5. " << "Muffin" << " - " << "R20.00" << "\n" << std::endl;
	std::cout << "6. " << "Pizza Slice" << " - " << "R35.00" << "\n" << std::endl;
	std::cout << "7. " << "Soup" << " - " << "R18.00" << "\n" << std::endl;
	std::cout << "8. " << "Burger" << " - " << "R40.00" << "\n" << std::endl;
}

int main()
{

	displayNames();
	displayMenu();
}
