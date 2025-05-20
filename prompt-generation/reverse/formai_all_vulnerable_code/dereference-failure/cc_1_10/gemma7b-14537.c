//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX 100

struct bank_record
{
    char name[50];
    int account_no;
    double balance;
    char type;
    struct bank_record* next;
};

void insert_record(struct bank_record** head, char* name, int account_no, double balance, char type)
{
    struct bank_record* new_record = (struct bank_record*)malloc(sizeof(struct bank_record));
    strcpy(new_record->name, name);
    new_record->account_no = account_no;
    new_record->balance = balance;
    new_record->type = type;
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

void display_records(struct bank_record* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Account No: %d\n", head->account_no);
        printf("Balance: %.2lf\n", head->balance);
        printf("Type: %c\n", head->type);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    struct bank_record* head = NULL;

    insert_record(&head, "John Doe", 123456, 1000.0, 'S');
    insert_record(&head, "Jane Doe", 654321, 2000.0, 'C');
    insert_record(&head, "Peter Pan", 321468, 3000.0, 'A');

    display_records(head);

    return 0;
}