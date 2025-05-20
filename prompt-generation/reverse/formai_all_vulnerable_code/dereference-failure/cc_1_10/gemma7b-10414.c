//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <string.h>

// Define a structure to store bank records
typedef struct bank_record {
    char name[50];
    int account_no;
    double balance;
    char address[100];
} bank_record;

// Function to insert a new bank record
void insert_record(bank_record *records, int *num_records) {
    records = (bank_record *)realloc(records, (*num_records + 1) * sizeof(bank_record));
    (*num_records)++;

    printf("Enter name: ");
    scanf("%s", records[*num_records - 1].name);

    printf("Enter account number: ");
    scanf("%d", &records[*num_records - 1].account_no);

    printf("Enter balance: ");
    scanf("%lf", &records[*num_records - 1].balance);

    printf("Enter address: ");
    scanf("%s", records[*num_records - 1].address);
}

// Function to search for a bank record
void search_record(bank_record *records, int num_records) {
    int account_no;

    printf("Enter account number: ");
    scanf("%d", &account_no);

    for (int i = 0; i < num_records; i++) {
        if (records[i].account_no == account_no) {
            printf("Name: %s\n", records[i].name);
            printf("Account number: %d\n", records[i].account_no);
            printf("Balance: %.2lf\n", records[i].balance);
            printf("Address: %s\n", records[i].address);
            return;
        }
    }

    printf("Record not found.\n");
}

// Main function
int main() {
    // Allocate memory for the bank records
    bank_record *records = NULL;
    int num_records = 0;

    // Insert a new bank record
    insert_record(records, &num_records);

    // Search for a bank record
    search_record(records, num_records);

    return 0;
}