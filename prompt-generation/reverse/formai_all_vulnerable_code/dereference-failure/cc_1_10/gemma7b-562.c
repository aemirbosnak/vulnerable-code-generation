//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a bank record
typedef struct BankRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new bank record into the linked list
void insert_record(BankRecord* head, BankRecord* new_record)
{
    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }
}

// Function to search for a bank record
BankRecord* search_record(BankRecord* head, int account_number)
{
    BankRecord* current = head;
    while (current) {
        if (current->account_number == account_number) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main()
{
    // Create a linked list of bank records
    BankRecord* head = NULL;

    // Insert some sample bank records
    insert_record(head, malloc(sizeof(BankRecord)));
    insert_record(head, malloc(sizeof(BankRecord)));
    insert_record(head, malloc(sizeof(BankRecord)));

    // Search for a bank record
    BankRecord* record = search_record(head, 1234);

    // Print the bank record details
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %f\n", record->balance);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}