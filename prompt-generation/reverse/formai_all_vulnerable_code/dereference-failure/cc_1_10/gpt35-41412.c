//FormAI DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[64];
    double balance;
} Account;

typedef struct {
    int id;
    char name[64];
    double amount;
    char type[16];
} Transaction;

int main() {
    Account accounts[10];
    Transaction transactions[100];
    int numAccounts = 0;
    int numTransactions = 0;

    while(1) {
        printf("\nEnter 1 to add account, 2 to add transaction, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);
        if(choice == 1) { // Add account
            Account newAccount;
            printf("\nEnter account name: ");
            scanf("%s", newAccount.name);
            printf("Enter starting balance: ");
            scanf("%lf", &newAccount.balance);
            newAccount.id = numAccounts;
            accounts[numAccounts++] = newAccount;
            printf("\nAccount added successfully with ID %d\n", newAccount.id);
        }
        else if(choice == 2) { // Add transaction
            Transaction newTransaction;
            printf("\nEnter account ID: ");
            scanf("%d", &newTransaction.id);
            if(newTransaction.id >= numAccounts) {
                printf("Invalid account ID\n");
                continue;
            }
            printf("Enter transaction type (DEPOSIT or WITHDRAWAL): ");
            scanf("%s", newTransaction.type);
            printf("Enter transaction amount: ");
            scanf("%lf", &newTransaction.amount);
            strcpy(newTransaction.name, accounts[newTransaction.id].name);
            transactions[numTransactions++] = newTransaction;

            if(strcmp(newTransaction.type, "DEPOSIT") == 0) {
                accounts[newTransaction.id].balance += newTransaction.amount;
            }
            else if(strcmp(newTransaction.type, "WITHDRAWAL") == 0) {
                accounts[newTransaction.id].balance -= newTransaction.amount;
            }
            printf("\nTransaction added successfully\n");
        }
        else if(choice == 3) { // Exit
            printf("\nGoodbye!\n");
            break;
        }
        else { // Invalid input
            printf("\nInvalid choice, please try again\n");
        }
    }
    return 0;
}