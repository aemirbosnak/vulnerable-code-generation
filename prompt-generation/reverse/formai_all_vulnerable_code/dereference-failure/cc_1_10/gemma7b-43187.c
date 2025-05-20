//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <string.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the record structure
typedef struct Record
{
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

// Create a linked list of records
Record* head = NULL;

// Function to insert a new record at the end
void insert_record(char* name, int account_number, double balance)
{
    // Allocate memory for the new record
    Record* new_record = (Record*)malloc(sizeof(Record));

    // Copy the name, account number, and balance into the new record
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;

    // If the head of the list is NULL, make the new record the head
    if (head == NULL)
    {
        head = new_record;
    }
    // Otherwise, traverse the list to the end and insert the new record there
    else
    {
        Record* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_record;
    }
}

// Function to search for a record by account number
Record* search_record(int account_number)
{
    // Traverse the list of records
    Record* current = head;
    while (current)
    {
        // If the account number of the current record matches the account number of the search, return the current record
        if (current->account_number == account_number)
        {
            return current;
        }
        // Otherwise, move to the next record
        current = current->next;
    }

    // If no record is found, return NULL
    return NULL;
}

// Function to update the balance of a record
void update_balance(int account_number, double new_balance)
{
    // Search for the record by account number
    Record* record = search_record(account_number);

    // If the record is found, update its balance
    if (record)
    {
        record->balance = new_balance;
    }
}

// Function to delete a record
void delete_record(int account_number)
{
    // Search for the record by account number
    Record* record = search_record(account_number);

    // If the record is found, delete it from the list
    if (record)
    {
        // If the record is the head of the list, update the head of the list
        if (record == head)
        {
            head = record->next;
        }
        // Otherwise, traverse the list to the record before the record to be deleted and delete the record
        else
        {
            Record* previous = NULL;
            Record* current = head;
            while (current && current->account_number != account_number)
            {
                previous = current;
                current = current->next;
            }
            if (previous)
            {
                previous->next = record->next;
            }
            else
            {
                head = record->next;
            }
        }
        // Free the memory of the record
        free(record);
    }
}

int main()
{
    // Insert some records
    insert_record("John Doe", 123456, 1000);
    insert_record("Jane Doe", 654912, 2000);
    insert_record("Bill Smith", 321548, 3000);

    // Search for a record by account number
    Record* record = search_record(123456);

    // If the record is found, print its name, account number, and balance
    if (record)
    {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2f\n", record->balance);
    }

    // Update the balance of a record
    update_balance(654912, 2500);

    // Search for the record by account number and print its updated balance
    record = search_record(654912);
    if (record)
    {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2f\n", record->balance);
    }

    // Delete a record
    delete_record(321548);

    // Search for the record by account number and print its balance after deletion
    record = search_record(321548);
    if (record)
    {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2f\n", record->balance);
    }

    return 0;
}