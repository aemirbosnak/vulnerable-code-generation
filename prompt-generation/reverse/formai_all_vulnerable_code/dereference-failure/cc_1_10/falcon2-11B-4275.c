//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct account {
    char accountNumber[11];
    double balance;
} Account;

void deposit(Account* account, double amount) {
    account->balance += amount;
    printf("Deposited %f\n", amount);
}

void withdraw(Account* account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient funds\n");
        return;
    }
    account->balance -= amount;
    printf("Withdrew %f\n", amount);
}

int main() {
    Account* account1 = (Account*)malloc(sizeof(Account));
    account1->accountNumber[0] = 'A';
    account1->accountNumber[1] = 'C';
    account1->accountNumber[2] = 'C';
    account1->accountNumber[3] = '2';
    account1->accountNumber[4] = '5';
    account1->accountNumber[5] = '1';
    account1->accountNumber[6] = '0';
    account1->accountNumber[7] = '0';
    account1->accountNumber[8] = '0';
    account1->accountNumber[9] = '0';
    account1->accountNumber[10] = '0';
    account1->balance = 0.0;

    Account* account2 = (Account*)malloc(sizeof(Account));
    account2->accountNumber[0] = 'A';
    account2->accountNumber[1] = 'C';
    account2->accountNumber[2] = 'C';
    account2->accountNumber[3] = '2';
    account2->accountNumber[4] = '5';
    account2->accountNumber[5] = '1';
    account2->accountNumber[6] = '0';
    account2->accountNumber[7] = '0';
    account2->accountNumber[8] = '0';
    account2->accountNumber[9] = '0';
    account2->accountNumber[10] = '0';
    account2->balance = 0.0;

    deposit(account1, 1000.0);
    withdraw(account1, 500.0);
    printf("%s\n", account1->accountNumber);
    printf("%f\n", account1->balance);

    deposit(account2, 1000.0);
    withdraw(account2, 500.0);
    printf("%s\n", account2->accountNumber);
    printf("%f\n", account2->balance);

    return 0;
}