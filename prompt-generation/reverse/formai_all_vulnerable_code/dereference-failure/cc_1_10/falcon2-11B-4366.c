//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int account_number;
    char name[50];
    int balance;
} Account;

void initializeAccount(Account* account) {
    strcpy(account->name, "John Doe");
    account->balance = 0;
}

void deposit(Account* account, int amount) {
    account->balance += amount;
}

void withdraw(Account* account, int amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void printAccount(Account* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %d\n", account->balance);
}

int main() {
    srand(time(0));
    Account* account = (Account*)malloc(sizeof(Account));
    initializeAccount(account);

    printf("Welcome to the C Banking Record System!\n");
    int choice;
    while (1) {
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Print Account\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the amount to deposit: ");
                int depositAmount;
                scanf("%d", &depositAmount);
                deposit(account, depositAmount);
                printf("Deposit successful!\n");
                break;
            case 2:
                printf("Enter the amount to withdraw: ");
                int withdrawAmount;
                scanf("%d", &withdrawAmount);
                withdraw(account, withdrawAmount);
                printf("Withdrawal successful!\n");
                break;
            case 3:
                printAccount(account);
                break;
            case 4:
                free(account);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}