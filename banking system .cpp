#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(const string& accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposit of $" << amount << " successful.\n";
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful.\n";
        } else {
            cout << "Insufficient balance.\n";
        }
    }

    virtual void displayBalance() const {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: $" << balance << "\n";
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const string& accNumber, double initialBalance, double interestRate)
        : Account(accNumber, initialBalance), interestRate(interestRate) {}

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest of $" << interest << " added.\n";
    }

    void displayBalance() const override {
        Account::displayBalance();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

int main() {
    // Create a SavingsAccount object
    SavingsAccount savings("12345", 1000, 5);

    // Perform operations
    savings.deposit(500);
    savings.withdraw(200);
    savings.addInterest();

    // Display final balance
    savings.displayBalance();

    return 0;
}
