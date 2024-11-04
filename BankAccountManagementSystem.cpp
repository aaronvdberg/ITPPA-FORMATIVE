#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <unistd.h>
using namespace std;

// Account structure to hold account details
struct Account {
    string name;
    int accountNumber;
    double balance;
    double initialdeposit;
};
 

// Function prototypes
void createAccount(Account &account);
void depositMoney(Account &account, double amount);
void withdrawMoney(Account &account, double amount);
void checkBalance(const Account &account);
void displayAccountDetails(const Account &account);

int main() {
    Account account;
    int choice;
    bool isAccountCreated = false; // To check if the account is created
   sleep(1);
    do {
        // Display the menu
        cout << "\n--- Bank Account Management System ---\n" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Display Account Details" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu selection
        switch (choice) {
            case 1:
                createAccount(account);
                isAccountCreated = true;
                break;
            case 2:
                if (isAccountCreated) {
                    double depositAmount;
                    cout << "Enter amount to deposit: ";
                    cin >> depositAmount;
                    depositMoney(account, depositAmount);
                } else {
                    cout << "Please create an account first." << endl;
                }
                break;
            case 3:
                if (isAccountCreated) {
                    double withdrawAmount;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawAmount;
                    withdrawMoney(account, withdrawAmount);
                } else {
                    cout << "Please create an account first." << endl;
                }
                break;
            case 4:
                if (isAccountCreated) {
                    checkBalance(account);
                } else {
                    cout << "Please create an account first." << endl;
                }
                break;
            case 5:
                if (isAccountCreated) {
                    displayAccountDetails(account);
                } else {
                    cout << "Please create an account first." << endl;
                }
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid selection. Please choose a number from 1 to 6.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

// Function to create an account
void createAccount(Account &account) {
    cout << "Enter your name: ";
    cin >> account.name;
    cout << "Enter account number: ";
    cin >> account.accountNumber;
    cout << "Enter your initial deposit: ";
    cin >> account.initialdeposit;

    if (account.initialdeposit > 0) {
        account.balance = account.initialdeposit;
        cout << "Account created successfully!" << endl;
    } else {
        cout << "Please enter a number greater than 0 for the initial deposit." << endl;
    }
     sleep(1);
}

// Function to deposit money
void depositMoney(Account &account, double amount) {
    if (amount > 0) {
        account.balance += amount;
        cout << "Successfully deposited R" << amount << ". New balance: R" << account.balance << endl;
    } else {
        cout << "Invalid amount. Please enter a positive number." << endl;
    }
     sleep(1);
}

// Function to withdraw money
void withdrawMoney(Account &account, double amount) {
    if (amount > 0 && amount <= account.balance) {
        account.balance -= amount;
        cout << "Successfully withdrew R" << amount << ". Remaining balance: R" << account.balance << endl;
    } else if (amount > account.balance) {
        cout << "Insufficient balance. You only have R" << account.balance << " available." << endl;
    } else {
        cout << "Invalid amount. Please enter a positive number." << endl;
    }
     sleep(1);
}

// Function to check balance
void checkBalance(const Account &account) {
    cout << "Current balance: R" << account.balance << endl;
     sleep(1);
}

// Function to display account details
void displayAccountDetails(const Account &account) {
    cout << "\n--- Account Details ---" << endl;
    cout << "Name: " << account.name << endl;
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Balance: R" << account.balance << endl;
     sleep(1);
}
