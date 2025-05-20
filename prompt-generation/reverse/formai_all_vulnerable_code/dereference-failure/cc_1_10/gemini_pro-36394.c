//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    long long int account_number;
    long long int balance;
} account;

account *accounts[100];
int num_accounts = 0;

void create_account(char *name, long long int account_number, long long int balance) {
    accounts[num_accounts] = malloc(sizeof(account));
    accounts[num_accounts]->name = strdup(name);
    accounts[num_accounts]->account_number = account_number;
    accounts[num_accounts]->balance = balance;
    num_accounts++;
}

void deposit(long long int account_number, long long int amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i]->account_number == account_number) {
            accounts[i]->balance += amount;
            printf("Deposit successful. New balance: %lld\n", accounts[i]->balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(long long int account_number, long long int amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i]->account_number == account_number) {
            if (accounts[i]->balance >= amount) {
                accounts[i]->balance -= amount;
                printf("Withdrawal successful. New balance: %lld\n", accounts[i]->balance);
                return;
            } else {
                printf("Insufficient funds.\n");
                return;
            }
        }
    }
    printf("Account not found.\n");
}

void transfer(long long int from_account_number, long long int to_account_number, long long int amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i]->account_number == from_account_number) {
            if (accounts[i]->balance >= amount) {
                accounts[i]->balance -= amount;
                for (int j = 0; j < num_accounts; j++) {
                    if (accounts[j]->account_number == to_account_number) {
                        accounts[j]->balance += amount;
                        printf("Transfer successful. New balance for account %lld: %lld\n", from_account_number, accounts[i]->balance);
                        printf("New balance for account %lld: %lld\n", to_account_number, accounts[j]->balance);
                        return;
                    }
                }
                printf("To account not found.\n");
                return;
            } else {
                printf("Insufficient funds.\n");
                return;
            }
        }
    }
    printf("From account not found.\n");
}

void print_all_accounts() {
    printf("** All Accounts **\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Name: %s\n", accounts[i]->name);
        printf("Account Number: %lld\n", accounts[i]->account_number);
        printf("Balance: %lld\n\n", accounts[i]->balance);
    }
}

int main() {
    create_account("John Doe", 123456789, 1000);
    create_account("Jane Doe", 987654321, 2000);

    deposit(123456789, 500);
    withdraw(987654321, 300);
    transfer(123456789, 987654321, 200);

    print_all_accounts();

    return 0;
}