//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct BankRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

void insert_record(BankRecord** head, char* name, int account_number, double balance)
{
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
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

void search_record(BankRecord* head, int account_number)
{
    while (head)
    {
        if (head->account_number == account_number)
        {
            printf("Name: %s\n", head->name);
            printf("Account Number: %d\n", head->account_number);
            printf("Balance: %.2lf\n", head->balance);
            return;
        }
        head = head->next;
    }

    printf("Record not found.\n");
}

int main()
{
    BankRecord* head = NULL;
    insert_record(&head, "John Doe", 123456, 1000.0);
    insert_record(&head, "Jane Doe", 654321, 2000.0);
    insert_record(&head, "Peter Pan", 789412, 3000.0);

    search_record(head, 123456);
    search_record(head, 654321);

    return 0;
}