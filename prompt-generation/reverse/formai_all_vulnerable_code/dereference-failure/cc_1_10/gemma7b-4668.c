//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_RECORDS 100
#define MAX_RECORD_LENGTH 255

typedef struct Record
{
    char *name;
    char *account_number;
    int balance;
    struct Record *next;
} Record;

Record *create_record(char *name, char *account_number, int balance)
{
    Record *new_record = malloc(sizeof(Record));
    new_record->name = strdup(name);
    new_record->account_number = strdup(account_number);
    new_record->balance = balance;
    new_record->next = NULL;

    return new_record;
}

void add_record(Record *head, char *name, char *account_number, int balance)
{
    Record *new_record = create_record(name, account_number, balance);

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        head->next = new_record;
    }
}

void print_records(Record *head)
{
    Record *current = head;

    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Account Number: %s\n", current->account_number);
        printf("Balance: %d\n", current->balance);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    Record *head = NULL;

    add_record(head, "John Doe", "123456", 1000);
    add_record(head, "Jane Doe", "456789", 2000);
    add_record(head, "Peter Pan", "698234", 3000);

    print_records(head);

    return 0;
}