//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <string.h>

// Define the Banking Record Structure
typedef struct BankRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Create a Linked List of Banking Records
BankRecord* create_bank_record(char* name, int account_number, double balance)
{
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    return new_record;
}

// Insert a Banking Record into the Linked List
void insert_bank_record(BankRecord* head, BankRecord* new_record)
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

// Print the Banking Records
void print_bank_records(BankRecord* head)
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
    // Create a Linked List of Banking Records
    BankRecord* head = NULL;

    // Insert some Banking Records
    insert_bank_record(head, create_bank_record("John Doe", 12345, 1000.0));
    insert_bank_record(head, create_bank_record("Jane Doe", 65482, 500.0));
    insert_bank_record(head, create_bank_record("Bill Smith", 32148, 200.0));

    // Print the Banking Records
    print_bank_records(head);

    return 0;
}