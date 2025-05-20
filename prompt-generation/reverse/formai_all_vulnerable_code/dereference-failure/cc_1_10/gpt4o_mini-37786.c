//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[100];
    double balance;
} Account;

Account *accounts = NULL;
int accountCount = 0;

void createAccount() {
    accounts = realloc(accounts, (accountCount + 1) * sizeof(Account));
    if (accounts == NULL) {
        printf("Memory allocation failed!");
        return;
    }

    Account *newAccount = &accounts[accountCount];
    printf("Enter Account Number: ");
    scanf("%d", &newAccount->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", newAccount->name);
    newAccount->balance = 0.0;

    accountCount++;
    printf("Account created successfully!\n");
}

void depositMoney() {
    int accountNumber;
    double amount;
    printf("Enter Account Number to Deposit: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("Deposited %.2lf to %s's account. New Balance: %.2lf\n", amount, accounts[i].name, accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdrawMoney() {
    int accountNumber;
    double amount;
    printf("Enter Account Number to Withdraw: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrew %.2lf from %s's account. New Balance: %.2lf\n", amount, accounts[i].name, accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAccountInfo() {
    int accountNumber;
    printf("Enter Account Number to Display Info: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder Name: %s\n", accounts[i].name);
            printf("Account Balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void freeResources() {
    free(accounts);
    accounts = NULL;
    accountCount = 0;
}

int main() {
    int choice;
    do {
        printf("\nBanking Record System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Info\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccountInfo(); break;
            case 5: 
                printf("Exiting...\n");
                freeResources();
                break;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}