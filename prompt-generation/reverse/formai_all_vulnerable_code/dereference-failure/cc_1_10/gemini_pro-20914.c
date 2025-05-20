//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the maximum number of accounts
#define MAX_ACCOUNTS 100

//Define the account structure
typedef struct account {
    char name[50];
    int balance;
} account;

//Define the bank structure
typedef struct bank {
    account accounts[MAX_ACCOUNTS];
    int num_accounts;
} bank;

//Function to create a new bank
bank* create_bank() {
    bank* b = malloc(sizeof(bank));
    b->num_accounts = 0;
    return b;
}

//Function to add an account to a bank
void add_account(bank* b, account* a) {
    b->accounts[b->num_accounts] = *a;
    b->num_accounts++;
}

//Function to get an account from a bank
account* get_account(bank* b, char* name) {
    for (int i = 0; i < b->num_accounts; i++) {
        if (strcmp(b->accounts[i].name, name) == 0) {
            return &b->accounts[i];
        }
    }
    return NULL;
}

//Function to deposit money into an account
void deposit_money(account* a, int amount) {
    a->balance += amount;
}

//Function to withdraw money from an account
void withdraw_money(account* a, int amount) {
    if (amount <= a->balance) {
        a->balance -= amount;
    }
}

//Function to print the account details
void print_account(account* a) {
    printf("Name: %s\n", a->name);
    printf("Balance: %d\n", a->balance);
}

//Function to print the bank details
void print_bank(bank* b) {
    for (int i = 0; i < b->num_accounts; i++) {
        print_account(&b->accounts[i]);
    }
}

int main() {
    //Create a new bank
    bank* b = create_bank();

    //Add some accounts to the bank
    account a1 = {"John Doe", 1000};
    account a2 = {"Jane Doe", 2000};
    account a3 = {"John Smith", 3000};
    add_account(b, &a1);
    add_account(b, &a2);
    add_account(b, &a3);

    //Print the account details
    print_bank(b);

    //Deposit money into an account
    account* a = get_account(b, "John Doe");
    deposit_money(a, 500);

    //Withdraw money from an account
    withdraw_money(a, 200);

    //Print the account details again
    print_account(a);

    return 0;
}