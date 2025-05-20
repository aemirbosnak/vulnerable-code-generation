//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record
{
    char name[50];
    int account_no;
    double balance;
    struct Record* next;
} Record;

void insert_record(Record** head)
{
    Record* new_record = (Record*)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);
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

void search_record(Record* head, int account_no)
{
    while (head)
    {
        if (head->account_no == account_no)
        {
            printf("Name: %s\n", head->name);
            printf("Account number: %d\n", head->account_no);
            printf("Balance: %.2lf\n", head->balance);
            return;
        }
        head = head->next;
    }
    printf("Record not found.\n");
}

int main()
{
    Record* head = NULL;
    int choice;
    int account_no;

    printf("Welcome to the Banking Record System.\n");
    printf("1. Insert Record\n");
    printf("2. Search Record\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            insert_record(&head);
            break;
        case 2:
            printf("Enter account number: ");
            scanf("%d", &account_no);
            search_record(head, account_no);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}