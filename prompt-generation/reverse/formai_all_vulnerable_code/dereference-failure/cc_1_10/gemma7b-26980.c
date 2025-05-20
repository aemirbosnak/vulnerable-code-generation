//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store banking records
typedef struct BankRecord
{
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new record into the linked list
void insertRecord(BankRecord** head, char* name, int account_no, double balance)
{
    BankRecord* newRecord = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(newRecord->name, name);
    newRecord->account_no = account_no;
    newRecord->balance = balance;
    newRecord->next = NULL;

    if (*head == NULL)
    {
        *head = newRecord;
    }
    else
    {
        (*head)->next = newRecord;
    }
}

// Function to search for a record by account number
BankRecord* searchRecord(BankRecord* head, int account_no)
{
    while (head)
    {
        if (head->account_no == account_no)
        {
            return head;
        }
        else
        {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update the balance of a record
void updateBalance(BankRecord* head, int account_no, double new_balance)
{
    BankRecord* record = searchRecord(head, account_no);

    if (record)
    {
        record->balance = new_balance;
    }
}

// Main function
int main()
{
    BankRecord* head = NULL;

    // Insert some records
    insertRecord(&head, "John Doe", 123456, 1000.0);
    insertRecord(&head, "Jane Doe", 654912, 2000.0);
    insertRecord(&head, "Peter Pan", 321468, 3000.0);

    // Search for a record by account number
    BankRecord* record = searchRecord(head, 123456);

    // Update the balance of a record
    if (record)
    {
        updateBalance(head, 123456, 1500.0);
    }

    // Print the updated balance
    record = searchRecord(head, 123456);
    printf("Balance: %.2lf", record->balance);

    return 0;
}