//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <string.h>

// Define the maximum number of records
#define MAX_RECORDS 10

// Define the record structure
typedef struct Record
{
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

// Function to insert a new record into the linked list
void insert_record(Record* head, Record* new_record)
{
    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        new_record->next = head;
        head = new_record;
    }
}

// Function to search for a record
Record* search_record(Record* head, int account_number)
{
    while (head)
    {
        if (head->account_number == account_number)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the balance of a record
void update_balance(Record* head, int account_number, double new_balance)
{
    Record* record = search_record(head, account_number);

    if (record)
    {
        record->balance = new_balance;
    }
}

// Function to print the records
void print_records(Record* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Account Number: %d\n", head->account_number);
        printf("Balance: %.2lf\n", head->balance);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    // Create a linked list of records
    Record* head = NULL;

    // Insert some records
    insert_record(head, malloc(sizeof(Record)));
    insert_record(head, malloc(sizeof(Record)));
    insert_record(head, malloc(sizeof(Record)));

    // Print the records
    print_records(head);

    // Update the balance of a record
    update_balance(head, 12345, 1000.0);

    // Print the records after updating the balance
    print_records(head);

    return 0;
}