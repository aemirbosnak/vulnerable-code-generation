//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

struct BankRecord
{
    char name[20];
    int account_no;
    double balance;
    struct BankRecord* next;
};

void insert_record(struct BankRecord** head)
{
    struct BankRecord* new_record = (struct BankRecord*)malloc(sizeof(struct BankRecord));
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

void display_records(struct BankRecord* head)
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
    struct BankRecord* head = NULL;
    int choice;

    while (1)
    {
        printf("1. Insert Record\n");
        printf("2. Display Records\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_record(&head);
                break;
            case 2:
                display_records(head);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N')
        {
            break;
        }
    }

    return 0;
}