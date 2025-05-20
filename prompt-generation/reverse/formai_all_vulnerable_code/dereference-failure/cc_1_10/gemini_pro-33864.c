//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// account struct
typedef struct account {
    char *name;
    double balance;
} account;

// function to create a new account
account *create_account(char *name, double balance) {
    account *new_account = malloc(sizeof(account));
    new_account->name = malloc(strlen(name) + 1);
    strcpy(new_account->name, name);
    new_account->balance = balance;
    return new_account;
}

// function to deposit money into an account
void deposit(account *account, double amount) {
    account->balance += amount;
}

// function to withdraw money from an account
void withdraw(account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    }
}

// function to print the account balance
void print_balance(account *account) {
    printf("%s: %.2f\n", account->name, account->balance);
}

int main() {
    // create two accounts
    account *john = create_account("John", 1000.0);
    account *jane = create_account("Jane", 500.0);

    // deposit money into John's account
    deposit(john, 500.0);

    // withdraw money from Jane's account
    withdraw(jane, 200.0);

    // print the account balances
    print_balance(john);
    print_balance(jane);

    // free the memory allocated for the accounts
    free(john->name);
    free(john);
    free(jane->name);
    free(jane);

    return 0;
}