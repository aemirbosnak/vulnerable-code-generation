//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definition of a bank account structure
typedef struct {
    int account_number; // Unique account number
    char name[20]; // Customer name
    double balance; // Current balance
    double interest_rate; // Interest rate per year
} bank_account;

// Function to create a new bank account
bank_account *create_account(int account_number, char name[20], double balance, double interest_rate) {
    bank_account *new_account = (bank_account *) malloc(sizeof(bank_account));
    new_account->account_number = account_number;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    new_account->interest_rate = interest_rate;
    return new_account;
}

// Function to deposit money into a bank account
void deposit_money(bank_account *account, double amount) {
    account->balance += amount;
    printf("Deposited %f into account %d\n", amount, account->account_number);
}

// Function to withdraw money from a bank account
void withdraw_money(bank_account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawn %f from account %d\n", amount, account->account_number);
    } else {
        printf("Insufficient funds in account %d\n", account->account_number);
    }
}

// Function to calculate interest on a bank account
void calculate_interest(bank_account *account) {
    double interest = account->balance * account->interest_rate * 0.01;
    account->balance += interest;
    printf("Interest added %f to account %d\n", interest, account->account_number);
}

// Function to print the balance of a bank account
void print_balance(bank_account *account) {
    printf("Account %d has a balance of %f\n", account->account_number, account->balance);
}

int main() {
    // Create a new bank account
    bank_account *account = create_account(123, "John Doe", 1000.0, 0.05);

    // Deposit money into the account
    deposit_money(account, 500.0);

    // Withdraw money from the account
    withdraw_money(account, 200.0);

    // Calculate interest on the account
    calculate_interest(account);

    // Print the balance of the account
    print_balance(account);

    return 0;
}