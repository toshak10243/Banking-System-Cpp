#include <iostream.h>  // Use iostream.h for Turbo C++
#include <conio.h>     // For clrscr() and getch()
#include <string.h>    // For string handling (char arrays)

class BankAccount {
    char accountHolderName[50]; // Character array for name
    int accountNumber;
    float balance;

public:
    // Constructor to initialize account
    BankAccount(const char name[], int accNum, float initialBalance) {
        strcpy(accountHolderName, name);
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Function to deposit money
    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nAmount deposited successfully. New Balance: " << balance;
        } else {
            cout << "\nInvalid deposit amount!";
        }
    }

    // Function to withdraw money
    void withdraw(float amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "\nAmount withdrawn successfully. Remaining Balance: " << balance;
            } else {
                cout << "\nInsufficient balance!";
            }
        } else {
            cout << "\nInvalid withdrawal amount!";
        }
    }

    // Function to display account details
    void displayDetails() {
        cout << "\nAccount Holder Name: " << accountHolderName;
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nCurrent Balance: " << balance;
    }
};

int main() {
    clrscr(); // Clear the screen for Turbo C++

    char name[50];
    int accNum;
    float initialBalance;

    // Get user details
    cout << "Enter Account Holder Name: ";
    cin >> name;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    // Create an account object
    BankAccount account(name, accNum, initialBalance);

    int choice;
    do {
        cout << "\n\n----- Banking System Menu -----\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                float amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            }
            case 2: {
                float amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            }
            case 3:
                account.displayDetails();
                break;
            case 4:
                cout << "\nThank you for using the banking system!";
                break;
            default:
                cout << "\nInvalid choice. Please try again.";
        }
    } while (choice != 4);

    getch(); // Wait for user input before exiting
    return 0;
}
