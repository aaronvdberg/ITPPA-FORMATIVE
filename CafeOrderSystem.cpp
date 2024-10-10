// my first program in C++
#include <iostream>
#include <string>

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
int main()
{

	displayNames();

}
