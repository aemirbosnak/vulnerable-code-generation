//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
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
Record* create_record_list()
{
    return NULL;
}

// Add a record to the linked list
void add_record(Record* head, char* name, int account_number, double balance)
{
    Record* new_record = (Record*)malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        head->next = new_record;
    }
}

// Print all records
void print_records(Record* head)
{
    Record* current_record = head;
    while (current_record)
    {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", current_record->name, current_record->account_number, current_record->balance);
        current_record = current_record->next;
    }
}

int main()
{
    // Create a linked list of records
    Record* head = create_record_list();

    // Add some records to the list
    add_record(head, "John Doe", 123456, 1000.0);
    add_record(head, "Jane Doe", 654321, 2000.0);
    add_record(head, "Peter Pan", 982146, 3000.0);

    // Print all records
    print_records(head);

    return 0;
}