//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Define the Banking Record System structure
typedef struct BankingRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankingRecord* next;
} BankingRecord;

// Function to insert a new record into the Banking Record System
void insert_record(BankingRecord** head, char* name, int account_number, double balance)
{
    BankingRecord* new_record = malloc(sizeof(BankingRecord));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (*head == NULL)
    {
        *head = new_record;
    }
    else
    {
        (*head)->next = new_record;
    }
}

// Function to search for a record in the Banking Record System
BankingRecord* search_record(BankingRecord* head, int account_number)
{
    BankingRecord* current_record = head;

    while (current_record)
    {
        if (current_record->account_number == account_number)
        {
            return current_record;
        }
        current_record = current_record->next;
    }

    return NULL;
}

// Function to update the balance of a record in the Banking Record System
void update_balance(BankingRecord* record, double new_balance)
{
    record->balance = new_balance;
}

// Function to print all records in the Banking Record System
void print_records(BankingRecord* head)
{
    BankingRecord* current_record = head;

    while (current_record)
    {
        printf("Name: %s\n", current_record->name);
        printf("Account Number: %d\n", current_record->account_number);
        printf("Balance: %.2lf\n", current_record->balance);
        printf("\n");
        current_record = current_record->next;
    }
}

int main()
{
    BankingRecord* head = NULL;

    insert_record(&head, "Romeo", 1234, 1000.0);
    insert_record(&head, "Juliet", 5678, 2000.0);
    insert_record(&head, "Benvolio", 9842, 3000.0);

    BankingRecord* record = search_record(head, 1234);
    if (record)
    {
        update_balance(record, 2000.0);
    }

    print_records(head);

    return 0;
}