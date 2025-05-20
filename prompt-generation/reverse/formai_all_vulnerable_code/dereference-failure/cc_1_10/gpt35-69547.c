//FormAI DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a bank account record
typedef struct bankRecord {
    int accountNumber;
    char firstName[20];
    char lastName[20];
    float balance;
} BankRecord;

// Function to display a single bank record
void displayRecord(BankRecord* record) {
    printf("\nAccount Number: %d", record->accountNumber);
    printf("\nName: %s %s", record->firstName, record->lastName);
    printf("\nBalance: $%.2f\n", record->balance);
}

// Function to add a new bank record
void addRecord(BankRecord* recordArray, int* recordCount) {
    // Increase the record count and get the current record index
    int currentIndex = (*recordCount)++;
    
    // Get input values from the user
    printf("Enter account number: ");
    scanf("%d", &recordArray[currentIndex].accountNumber);
    printf("Enter first name: ");
    scanf("%s", recordArray[currentIndex].firstName);
    printf("Enter last name: ");
    scanf("%s", recordArray[currentIndex].lastName);
    printf("Enter balance: ");
    scanf("%f", &recordArray[currentIndex].balance);
    
    // Display the added record
    printf("\n--- Record added ---\n");
    displayRecord(&recordArray[currentIndex]);
}

// Function to find a bank record by account number
int findRecord(BankRecord* recordArray, int recordCount, int accountNumber) {
    for (int i = 0; i < recordCount; i++) {
        if (recordArray[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

// Function to make a deposit to a bank record
void deposit(BankRecord* recordArray, int recordCount) {
    int accountNumber;
    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    
    int index = findRecord(recordArray, recordCount, accountNumber);
    if (index >= 0) {
        float amount;
        printf("Enter deposit amount: ");
        scanf("%f", &amount);
        
        recordArray[index].balance += amount;
        printf("\n--- Deposit successful ---\n");
        displayRecord(&recordArray[index]);
    }
    else {
        printf("\n--- Record not found ---\n");
    }
}

// Function to make a withdrawal from a bank record
void withdrawal(BankRecord* recordArray, int recordCount) {
    int accountNumber;
    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    
    int index = findRecord(recordArray, recordCount, accountNumber);
    if (index >= 0) {
        float amount;
        printf("Enter withdrawal amount: ");
        scanf("%f", &amount);
        
        if (amount > recordArray[index].balance) {
            printf("\n--- Insufficient funds ---\n");
        }
        else {
            recordArray[index].balance -= amount;
            printf("\n--- Withdrawal successful ---\n");
            displayRecord(&recordArray[index]);
        }
    }
    else {
        printf("\n--- Record not found ---\n");
    }
}

// Main function
int main() {
    // Allocate memory for an array of bank records
    BankRecord* recordArray = (BankRecord*) malloc(sizeof(BankRecord) * 10);
    int recordCount = 0;
    
    // Display menu options and process user input
    while (1) {
        printf("\nBank Record System\n");
        printf("=========================\n");
        printf("1. Add new record\n");
        printf("2. Deposit\n");
        printf("3. Withdrawal\n");
        printf("4. Exit\n");
        printf("=========================\n");
        printf("\nEnter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: addRecord(recordArray, &recordCount); break;
            case 2: deposit(recordArray, recordCount); break;
            case 3: withdrawal(recordArray, recordCount); break;
            case 4: exit(0);
            default: printf("\nInvalid choice\n");
        }
    }
    
    return 0;
}