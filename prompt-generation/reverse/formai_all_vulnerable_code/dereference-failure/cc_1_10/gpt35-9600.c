//FormAI DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a single bank account record
struct BankAccountRecord {
    int accountNumber;
    char accountHolderName[50];
    double balance;
};

// Define a function to add a new bank account record to the system
void addNewRecord(struct BankAccountRecord *bankAccounts, int *numAccounts) {
    // Allocate memory for the new record
    bankAccounts = realloc(bankAccounts, (*numAccounts + 1) * sizeof(struct BankAccountRecord));

    // Get input for the new record
    printf("\nEnter account number: ");
    scanf("%d", &(bankAccounts[*numAccounts].accountNumber));

    printf("Enter account holder name: ");
    scanf("%s", bankAccounts[*numAccounts].accountHolderName);

    printf("Enter account balance: ");
    scanf("%lf", &(bankAccounts[*numAccounts].balance));

    // Increment the number of accounts counter
    (*numAccounts)++;

    printf("\nNew account added successfully!\n");
}

// Define a function to print all existing bank account records in the system
void listAllRecords(struct BankAccountRecord *bankAccounts, int numAccounts) {
    printf("\nAll bank account records in the system:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("\nAccount number: %d\n", bankAccounts[i].accountNumber);
        printf("Account holder name: %s\n", bankAccounts[i].accountHolderName);
        printf("Account balance: %.2f\n", bankAccounts[i].balance);
    }

    // If there are no records, inform the user
    if (numAccounts == 0) {
        printf("\nNo records found.\n");
    }
}

// Define a function to search for a bank account record by account number
void searchByAccountNumber(struct BankAccountRecord *bankAccounts, int numAccounts) {
    int accountNumber;
    printf("\nEnter the account number to search: ");
    scanf("%d", &accountNumber);

    // Check each record for the matching account number
    int found = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (bankAccounts[i].accountNumber == accountNumber) {
            printf("\nRecord found:\n\n");
            printf("Account number: %d\n", bankAccounts[i].accountNumber);
            printf("Account holder name: %s\n", bankAccounts[i].accountHolderName);
            printf("Account balance: %.2f\n", bankAccounts[i].balance);
            found = 1;
            break;
        }
    }

    // If the account number wasn't found, inform the user
    if (!found) {
        printf("\nNo record found with that account number.\n");
    }
}

int main() {
    // Initialize an array for bank account records with a single dummy record
    struct BankAccountRecord *bankAccounts = malloc(sizeof(struct BankAccountRecord));
    bankAccounts[0].accountNumber = 0;
    strcpy(bankAccounts[0].accountHolderName, "Dummy Record");
    bankAccounts[0].balance = 0.0;
    int numAccounts = 0;

    // Display the menu and get user input
    int choice;

    do {
        printf("\nBanking Record System\n");
        printf("----------------------\n");
        printf("1. Add new record\n");
        printf("2. List all records\n");
        printf("3. Search by account number\n");
        printf("4. Exit\n");
        printf("----------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewRecord(bankAccounts, &numAccounts);
                break;

            case 2:
                listAllRecords(bankAccounts, numAccounts);
                break;

            case 3:
                searchByAccountNumber(bankAccounts, numAccounts);
                break;

            case 4:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    // Free the allocated memory before exiting
    free(bankAccounts);

    return 0;
}