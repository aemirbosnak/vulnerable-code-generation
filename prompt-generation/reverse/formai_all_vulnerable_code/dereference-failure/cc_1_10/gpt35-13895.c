//FormAI DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold banking record information
typedef struct{
    int account_number;
    char name[50];
    float balance;
}BankingRecord;

// Function to add a new banking record
void addBankingRecord(BankingRecord** banking_records, int* num_records){
    int account_number;
    char name[50];
    float balance;

    // Ask user for information about new record
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter balance: ");
    scanf("%f", &balance);

    // Create new banking record
    BankingRecord* new_record = malloc(sizeof(BankingRecord));
    new_record->account_number = account_number;
    strcpy(new_record->name, name);
    new_record->balance = balance;

    // Add new record to records array
    (*num_records)++;
    *banking_records = realloc(*banking_records, (*num_records) * sizeof(BankingRecord));
    (*banking_records)[*num_records-1] = *new_record;

    printf("\nNew banking record added successfully!\n\n");
}

// Function to search for a banking record by account number
void searchBankingRecordByAccountNumber(BankingRecord* banking_records, int num_records){
    int search_account_number;

    // Ask user for account number to search
    printf("Enter account number to search: ");
    scanf("%d", &search_account_number);

    // Search for record with specified account number
    int record_found = 0;
    for(int i=0; i<num_records; i++){
        if(banking_records[i].account_number == search_account_number){
            printf("\nFound record for account number %d:\n", search_account_number);
            printf("Name: %s\n", banking_records[i].name);
            printf("Balance: $%.2f\n\n", banking_records[i].balance);
            record_found = 1;
            break;
        }
    }

    // If record not found, print error message
    if(!record_found){
        printf("\nRecord not found for account number %d.\n\n", search_account_number);
    }
}

// Function to display all existing banking records
void displayAllBankingRecords(BankingRecord* banking_records, int num_records){
    printf("\nExisting banking records:\n");
    for(int i=0; i<num_records; i++){
        printf("Account Number: %d, Name: %s, Balance: $%.2f\n", banking_records[i].account_number, banking_records[i].name, banking_records[i].balance);
    }
    printf("\n");
}

int main(){
    // Initialize empty banking records array
    int num_records = 0;
    BankingRecord* banking_records = NULL;

    int choice;
    while(1){
        // Display menu
        printf("1. Add a new banking record\n");
        printf("2. Search for a banking record by account number\n");
        printf("3. Display all existing banking records\n");
        printf("4. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addBankingRecord(&banking_records, &num_records);
                break;
            case 2:
                searchBankingRecordByAccountNumber(banking_records, num_records);
                break;
            case 3:
                displayAllBankingRecords(banking_records, num_records);
                break;
            case 4:
                printf("\nExiting program...bye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}