//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank record data
typedef struct BankRecord
{
    char name[50];
    int accountNo;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new bank record at the end
void insertAtEnd(BankRecord** head, char* name, int accountNo, double balance)
{
    BankRecord* newNode = (BankRecord*)malloc(sizeof(BankRecord));

    strcpy(newNode->name, name);
    newNode->accountNo = accountNo;
    newNode->balance = balance;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

// Function to search for a bank record by account number
BankRecord* searchByAccountNo(BankRecord* head, int accountNo)
{
    BankRecord* current = head;

    while (current)
    {
        if (current->accountNo == accountNo)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to update the balance of a bank record
void updateBalance(BankRecord* record, double newBalance)
{
    record->balance = newBalance;
}

// Main function
int main()
{
    BankRecord* head = NULL;

    // Insert some bank records
    insertAtEnd(&head, "John Doe", 123456, 1000.0);
    insertAtEnd(&head, "Jane Doe", 654923, 2000.0);
    insertAtEnd(&head, "Peter Pan", 984123, 3000.0);

    // Search for a bank record by account number
    BankRecord* record = searchByAccountNo(head, 123456);

    // If the record is found, update its balance
    if (record)
    {
        updateBalance(record, 1500.0);
    }

    // Print the updated bank record
    record = searchByAccountNo(head, 123456);
    printf("Name: %s\n", record->name);
    printf("Account No: %d\n", record->accountNo);
    printf("Balance: %.2lf\n", record->balance);

    return 0;
}