//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORD_NUM 100

typedef struct Record
{
    int account_number;
    char name[50];
    double balance;
    struct Record* next;
} Record;

Record* insert_record(Record* head, int account_number, char* name, double balance)
{
    Record* new_record = (Record*)malloc(sizeof(Record));
    new_record->account_number = account_number;
    strcpy(new_record->name, name);
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

    return head;
}

void search_record(Record* head, int account_number)
{
    Record* current_record = head;

    while (current_record)
    {
        if (current_record->account_number == account_number)
        {
            printf("Account Number: %d\n", current_record->account_number);
            printf("Name: %s\n", current_record->name);
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

int main()
{
    Record* head = NULL;

    insert_record(head, 101, "John Doe", 1000.0);
    insert_record(head, 102, "Jane Doe", 2000.0);
    insert_record(head, 103, "Peter Pan", 3000.0);

    search_record(head, 102);

    return 0;
}