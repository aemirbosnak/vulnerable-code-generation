//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record
{
    char name[50];
    int account_no;
    double balance;
    struct Record* next;
} Record;

Record* insert_record(Record* head)
{
    Record* new_record = (Record*)malloc(sizeof(Record));
    printf("Enter name:");
    scanf("%s", new_record->name);
    printf("Enter account number:");
    scanf("%d", &new_record->account_no);
    printf("Enter balance:");
    scanf("%lf", &new_record->balance);

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

void display_records(Record* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Account Number: %d\n", head->account_no);
        printf("Balance: %.2lf\n", head->balance);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Record* head = NULL;

    char choice;

    while (1)
    {
        printf("Enter 'a' to add a record, 'd' to display records, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'a':
                head = insert_record(head);
                break;
            case 'd':
                display_records(head);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}