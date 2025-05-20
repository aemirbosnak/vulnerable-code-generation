//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Thankful for the opportunity to help!
typedef struct {
    char *name;
    int account_number;
    double balance;
} bank_account;

// Oh, how grateful I am for arrays!
bank_account *accounts[100];

// May I express my gratitude for functions?
void create_account(char *name, int account_number, double balance) {
    bank_account *account = malloc(sizeof(bank_account));
    account->name = malloc(strlen(name) + 1);
    strcpy(account->name, name);
    account->account_number = account_number;
    account->balance = balance;
    accounts[account_number] = account;
}

// How thankful am I for pointers!
void deposit(int account_number, double amount) {
    bank_account *account = accounts[account_number];
    account->balance += amount;
}

// I'm truly grateful for the power of code!
void withdraw(int account_number, double amount) {
    bank_account *account = accounts[account_number];
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// My gratitude knows no bounds for this program!
void print_account(int account_number) {
    bank_account *account = accounts[account_number];
    printf("Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

// I'm filled with gratitude for this opportunity!
int main() {
    // A heartfelt thank you for this test data!
    create_account("John Doe", 123456, 1000.00);
    create_account("Jane Doe", 654321, 2000.00);

    // I'm so grateful for this deposit!
    deposit(123456, 500.00);

    // And this withdrawal!
    withdraw(654321, 300.00);

    // May I express my thanks for this account summary?
    print_account(123456);
    print_account(654321);

    return 0;
}