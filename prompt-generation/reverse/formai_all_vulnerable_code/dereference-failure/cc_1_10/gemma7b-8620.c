//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Banking Record Structure
typedef struct BankingRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankingRecord* next;
} BankingRecord;

// Create a Banking Record Node
BankingRecord* create_banking_record(char* name, int account_number, double balance)
{
    BankingRecord* new_record = (BankingRecord*)malloc(sizeof(BankingRecord));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;
    return new_record;
}

// Insert a Banking Record Node at the End
void insert_at_end(BankingRecord** head, BankingRecord* new_record)
{
    if (*head == NULL)
    {
        *head = new_record;
    }
    else
    {
        (*head)->next = new_record;
        *head = new_record;
    }
}

// Print All Banking Records
void print_records(BankingRecord* head)
{
    BankingRecord* current = head;
    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Account Number: %d\n", current->account_number);
        printf("Balance: %.2lf\n", current->balance);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    BankingRecord* head = NULL;

    // Create some sample banking records
    BankingRecord* new_record1 = create_banking_record("John Doe", 123456, 1000.0);
    BankingRecord* new_record2 = create_banking_record("Jane Doe", 654321, 2000.0);
    BankingRecord* new_record3 = create_banking_record("Peter Pan", 321468, 3000.0);

    // Insert the records into the linked list
    insert_at_end(&head, new_record1);
    insert_at_end(&head, new_record2);
    insert_at_end(&head, new_record3);

    // Print all the banking records
    print_records(head);

    return 0;
}