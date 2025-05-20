//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

struct account {
    char account_number[11];
    char account_holder_name[20];
    int account_balance;
};

struct account* create_account(char account_number[], char account_holder_name[], int account_balance) {
    struct account* new_account = (struct account*) malloc(sizeof(struct account));
    strcpy(new_account->account_number, account_number);
    strcpy(new_account->account_holder_name, account_holder_name);
    new_account->account_balance = account_balance;
    return new_account;
}

void deposit(struct account* account, int amount) {
    account->account_balance += amount;
}

int withdraw(struct account* account, int amount) {
    if (account->account_balance >= amount) {
        account->account_balance -= amount;
        return 1;
    }
    return 0;
}

int get_balance(struct account* account) {
    return account->account_balance;
}

void print_account(struct account* account) {
    printf("Account Number: %s\n", account->account_number);
    printf("Account Holder Name: %s\n", account->account_holder_name);
    printf("Account Balance: %d\n", account->account_balance);
}

int main() {
    char account_number[] = "1234567890";
    char account_holder_name[] = "John Doe";
    int initial_balance = 1000;

    struct account* account = create_account(account_number, account_holder_name, initial_balance);

    printf("Initial Balance: %d\n", get_balance(account));

    deposit(account, 500);
    printf("Deposited 500. New Balance: %d\n", get_balance(account));

    withdraw(account, 200);
    printf("Withdrawn 200. New Balance: %d\n", get_balance(account));

    print_account(account);

    free(account);

    return 0;
}