//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    char *name;
    char *account_number;
    double balance;
} account_t;

account_t *accounts[100];
int num_accounts = 0;

void create_account(char *name, char *account_number, double balance) {
    account_t *account = malloc(sizeof(account_t));
    account->name = strdup(name);
    account->account_number = strdup(account_number);
    account->balance = balance;
    accounts[num_accounts++] = account;
}

account_t *find_account(char *account_number) {
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i]->account_number, account_number) == 0) {
            return accounts[i];
        }
    }
    return NULL;
}

void deposit(char *account_number, double amount) {
    account_t *account = find_account(account_number);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }
    account->balance += amount;
}

void withdraw(char *account_number, double amount) {
    account_t *account = find_account(account_number);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }
    if (account->balance < amount) {
        printf("Insufficient funds.\n");
        return;
    }
    account->balance -= amount;
}

void transfer(char *from_account_number, char *to_account_number, double amount) {
    account_t *from_account = find_account(from_account_number);
    if (from_account == NULL) {
        printf("From account not found.\n");
        return;
    }
    if (from_account->balance < amount) {
        printf("Insufficient funds.\n");
        return;
    }
    account_t *to_account = find_account(to_account_number);
    if (to_account == NULL) {
        printf("To account not found.\n");
        return;
    }
    from_account->balance -= amount;
    to_account->balance += amount;
}

void print_accounts() {
    int i;
    for (i = 0; i < num_accounts; i++) {
        printf("%s %s %.2f\n", accounts[i]->name, accounts[i]->account_number, accounts[i]->balance);
    }
}

int main() {
    create_account("John Doe", "1234567890", 1000.00);
    create_account("Jane Doe", "0987654321", 2000.00);

    deposit("1234567890", 100.00);
    withdraw("0987654321", 200.00);

    transfer("1234567890", "0987654321", 300.00);

    print_accounts();

    return 0;
}