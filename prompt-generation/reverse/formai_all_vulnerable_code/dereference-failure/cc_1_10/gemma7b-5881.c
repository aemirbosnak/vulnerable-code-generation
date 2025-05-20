//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Bank Record Structure
typedef struct BankRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Create a new bank record
BankRecord* create_bank_record(char* name, int account_number, double balance)
{
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    return new_record;
}

// Insert a new bank record at the end
void insert_bank_record(BankRecord* head, BankRecord* new_record)
{
    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        head->next = new_record;
        head = new_record;
    }
}

// Print all bank records
void print_bank_records(BankRecord* head)
{
    BankRecord* current_record = head;
    while (current_record)
    {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", current_record->name, current_record->account_number, current_record->balance);
        current_record = current_record->next;
    }
}

int main()
{
    // Create a new bank record
    BankRecord* new_record = create_bank_record("John Doe", 123456, 1000.0);

    // Insert the new bank record into the linked list
    insert_bank_record(NULL, new_record);

    // Print all bank records
    print_bank_records(new_record);

    return 0;
}