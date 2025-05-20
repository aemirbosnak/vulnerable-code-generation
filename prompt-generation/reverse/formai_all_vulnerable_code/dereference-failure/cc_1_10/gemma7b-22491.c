//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Account {
    char name[MAX];
    double balance;
    struct Account* next;
} Account;

Account* insertAccount(Account* head) {
    Account* newAccount = (Account*)malloc(sizeof(Account));
    printf("Enter account name: ");
    scanf("%s", newAccount->name);
    printf("Enter account balance: ");
    scanf("%lf", &newAccount->balance);

    newAccount->next = head;
    head = newAccount;

    return head;
}

void printAccounts(Account* head) {
    Account* currentAccount = head;
    while (currentAccount) {
        printf("Account name: %s\n", currentAccount->name);
        printf("Account balance: %.2lf\n", currentAccount->balance);
        printf("\n");
        currentAccount = currentAccount->next;
    }
}

int main() {
    Account* head = NULL;

    while (1) {
        int choice;
        printf("1. Insert Account\n");
        printf("2. Print Accounts\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertAccount(head);
                break;
            case 2:
                printAccounts(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}