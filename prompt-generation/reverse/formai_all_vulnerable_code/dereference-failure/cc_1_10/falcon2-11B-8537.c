//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int account_number;
    char name[100];
    double balance;
};

struct account* get_account(int account_number) {
    struct account* accounts = NULL;
    int i;
    for (i = 0; i < 10; i++) {
        if (accounts[i].account_number == account_number) {
            break;
        }
    }
    if (i < 10) {
        return &accounts[i];
    } else {
        accounts = (struct account*)malloc(10 * sizeof(struct account));
        if (accounts == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        for (i = 0; i < 10; i++) {
            accounts[i].account_number = account_number;
            accounts[i].name[0] = '\0';
            accounts[i].balance = 0.0;
        }
        return &accounts[i];
    }
}

int main() {
    struct account accounts[10];
    int i, account_number;
    char name[100];
    double balance;
    int choice = 0;
    while (choice!= -1) {
        printf("1. Create account\n2. Deposit money\n3. Withdraw money\n4. Print account details\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                get_account(account_number);
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                strncpy(accounts[account_number].name, name, sizeof(name));
                printf("Enter initial balance: ");
                scanf("%lf", &balance);
                accounts[account_number].balance = balance;
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                get_account(account_number);
                printf("Enter amount to deposit: ");
                scanf("%lf", &balance);
                accounts[account_number].balance += balance;
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                get_account(account_number);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &balance);
                if (balance > accounts[account_number].balance) {
                    printf("Insufficient balance\n");
                } else {
                    accounts[account_number].balance -= balance;
                }
                break;
            case 4:
                printf("Account details:\n");
                printf("Account number: %d\n", accounts[account_number].account_number);
                printf("Name: %s\n", accounts[account_number].name);
                printf("Balance: %lf\n", accounts[account_number].balance);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}