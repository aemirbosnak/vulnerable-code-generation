//FormAI DATASET v1.0 Category: Banking Record System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct to hold the banking record information
struct BankRecord {
    int accountNumber;
    char accountType[20];
    float accountBalance;
};

//Function to add new accounts
void addAccount(struct BankRecord *ptr, int size) {
    int count = 0;
    while (count < size) {
        printf("Enter Account Number: ");
        scanf("%d", &ptr->accountNumber);
        printf("Enter Account Type: ");
        scanf(" %[^\n]s", &ptr->accountType);
        printf("Enter Account Balance: ");
        scanf("%f", &ptr->accountBalance);
        ptr++;
        count++;
    }
}

//Function to display all accounts
void displayAllAccounts(struct BankRecord *ptr, int size) {
    printf("\nDisplaying All Accounts:\n");
    int count = 0;
    while (count < size) {
        printf("Account Number: %d\n", ptr->accountNumber);
        printf("Account Type: %s\n", ptr->accountType);
        printf("Account Balance: %.2f\n\n", ptr->accountBalance);
        ptr++;
        count++;
    }
}

//Function to search an account by account number
void searchAccount(struct BankRecord *ptr, int size) {
    int accountNumber, count = 0;
    printf("Enter Account Number to Search: ");
    scanf("%d", &accountNumber);
    while (count < size) {
        if(ptr->accountNumber == accountNumber) {
            printf("\nAccount Found:\n");
            printf("Account Number: %d\n", ptr->accountNumber);
            printf("Account Type: %s\n", ptr->accountType);
            printf("Account Balance: %.2f\n", ptr->accountBalance);
            return;
        }
        ptr++;
        count++;
    }
    printf("\nAccount Number %d not found in the records.\n", accountNumber);
}

//Function to delete an account by account number
void deleteAccount(struct BankRecord *ptr, int size) {
    int accountNumber, count = 0;
    printf("Enter Account Number to Delete: ");
    scanf("%d", &accountNumber);
    while (count < size) {
        if(ptr->accountNumber == accountNumber) {
            ptr->accountNumber = 0;
            strcpy(ptr->accountType, "");
            ptr->accountBalance = 0;
            printf("\nAccount Number %d has been successfully deleted.\n", accountNumber);
            return;
        }
        ptr++;
        count++;
    }
    printf("\nAccount Number %d not found in the records.\n", accountNumber);
}

int main() {
    int numAccounts;
    printf("Enter the number of accounts: ");
    scanf("%d", &numAccounts);
    struct BankRecord *bankRecord = (struct BankRecord*)malloc(numAccounts * sizeof(struct BankRecord));
    int choice;
    do {
        printf("\nBanking Record System\n");
        printf("1. Add Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Delete Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAccount(bankRecord, numAccounts);
                break;
            case 2:
                displayAllAccounts(bankRecord, numAccounts);
                break;
            case 3:
                searchAccount(bankRecord, numAccounts);
                break;
            case 4:
                deleteAccount(bankRecord, numAccounts);
                break;
            case 5:
                printf("\nExiting Banking Record System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    free(bankRecord);
    return 0;
}