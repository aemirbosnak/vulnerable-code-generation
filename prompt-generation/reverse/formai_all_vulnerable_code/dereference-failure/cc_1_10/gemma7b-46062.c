//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a bank record
typedef struct bank_record
{
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
} bank_record;

// Function to insert a new bank record at the end
void insert_record(bank_record* head)
{
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        head->next = new_record;
    }
    head = new_record;
}

// Function to search for a bank record
void search_record(bank_record* head)
{
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    bank_record* current_record = head;
    while (current_record)
    {
        if (current_record->account_number == account_number)
        {
            printf("Name: %s\n", current_record->name);
            printf("Account number: %d\n", current_record->account_number);
            printf("Balance: %.2lf\n", current_record->balance);
            break;
        }
        current_record = current_record->next;
    }

    if (current_record == NULL)
    {
        printf("Record not found.\n");
    }
}

// Function to update a bank record
void update_record(bank_record* head)
{
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    bank_record* current_record = head;
    while (current_record)
    {
        if (current_record->account_number == account_number)
        {
            printf("Enter new balance: ");
            scanf("%lf", &current_record->balance);
            break;
        }
        current_record = current_record->next;
    }

    if (current_record == NULL)
    {
        printf("Record not found.\n");
    }
}

// Function to delete a bank record
void delete_record(bank_record* head)
{
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    bank_record* current_record = head;
    bank_record* previous_record = NULL;

    while (current_record)
    {
        if (current_record->account_number == account_number)
        {
            if (previous_record)
            {
                previous_record->next = current_record->next;
            }
            else
            {
                head = current_record->next;
            }
            free(current_record);
            break;
        }
        previous_record = current_record;
        current_record = current_record->next;
    }

    if (current_record == NULL)
    {
        printf("Record not found.\n");
    }
}

int main()
{
    bank_record* head = NULL;

    // Insert a few bank records
    insert_record(head);
    insert_record(head);
    insert_record(head);

    // Search for a bank record
    search_record(head);

    // Update a bank record
    update_record(head);

    // Delete a bank record
    delete_record(head);

    return 0;
}