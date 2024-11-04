#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>  // Include this to use std::ofstream

// Declaring Q1 Variables
const double COFFEE_PRICE = 15.00;
const double SANDWICH_PRICE = 30.00;
const double SALAD_PRICE = 25.00;
const double JUICE_PRICE = 10.00;
const double MUFFIN_PRICE = 20.00;
const double PIZZA_PRICE = 35.00;
const double SOUP_PRICE = 18.00;
const double BURGER_PRICE = 40.00;
const double DISCOUNT_RATE = 0.10;
const double DISCOUNT_THRESHOLD = 100.00;

// Declare Name And Surname
std::string displayName;
std::string displayLName;

void displayNames() {
    std::cout << "Please enter your name : " << "\n" << std::endl;
    getline(std::cin, displayName);
    std::cout << "Please enter your last name : " << "\n" << std::endl;
    getline(std::cin, displayLName);

    std::cout << "Welcome, " << displayName << " " << displayLName << std::endl;
}

void displayMenu() {
    sleep(1);
    std::cout << "Cafeteria Menu:\n";
    std::cout << "1. Coffee - R15.00\n";
    std::cout << "2. Sandwich - R30.00\n";
    std::cout << "3. Salad - R25.00\n";
    std::cout << "4. Juice - R10.00\n";
    std::cout << "5. Muffin - R20.00\n";
    std::cout << "6. Pizza Slice - R35.00\n";
    std::cout << "7. Soup - R18.00\n";
    std::cout << "8. Burger - R40.00\n";
}

double inputMenuItems() {
    int numberOfItems, itemSelection;
    double totalBill = 0.0;

    std::cout << "How many items would you like to order (up to 8)? ";
    std::cin >> numberOfItems;

    if (numberOfItems < 1 || numberOfItems > 8) {
        std::cout << "Please select between 1 and 8 items.\n";
        return 0.0;
    }

    for (int i = 0; i < numberOfItems; ++i) {
        std::cout << "Enter the menu item number for item " << (i + 1) << ": ";
        std::cin >> itemSelection;

        switch (itemSelection) {
            case 1: totalBill += COFFEE_PRICE; break;
            case 2: totalBill += SANDWICH_PRICE; break;
            case 3: totalBill += SALAD_PRICE; break;
            case 4: totalBill += JUICE_PRICE; break;
            case 5: totalBill += MUFFIN_PRICE; break;
            case 6: totalBill += PIZZA_PRICE; break;
            case 7: totalBill += SOUP_PRICE; break;
            case 8: totalBill += BURGER_PRICE; break;
            default:
                std::cout << "Invalid selection. Please choose a number from 1 to 8.\n";
                --i;
                break;
        }
    }

    return totalBill;
}

double applyDiscount(double totalBill) {
    return (totalBill > DISCOUNT_THRESHOLD) ? totalBill * (1 - DISCOUNT_RATE) : totalBill;
}

void writeBillToFile(double finalBill) {
    std::ofstream billFile("CafeteriaBill.txt");
    if (billFile.is_open()) {
        billFile << "Customer Name: " << displayName << " " << displayLName << "\n";
        billFile << "Total Bill: R" << finalBill << "\n";
        billFile.close();
        std::cout << "The bill has been written to CafeteriaBill.txt\n";
    } else {
        std::cerr << "Error: Could not open file to write the bill.\n";
    }
}

int main() {
    displayNames();
    displayMenu();
    double totalBill = inputMenuItems();

    if (totalBill == 0.0) return 1;

    double finalBill = applyDiscount(totalBill);

    std::cout << "Total before discount: R" << totalBill << "\n";
    if (finalBill < totalBill) {
        std::cout << "Discount applied: 10%\n";
    }
    std::cout << "Final total after discount (if applicable): R" << finalBill << "\n";

    writeBillToFile(finalBill);
    return 0;
}
