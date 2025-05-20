//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100

struct Record
{
    char name[MAX_NUM];
    double amount;
    struct Record* next;
};

void insert(struct Record** head, char* name, double amount)
{
    struct Record* new_record = malloc(sizeof(struct Record));
    strcpy(new_record->name, name);
    new_record->amount = amount;
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

void print_records(struct Record* head)
{
    while (head)
    {
        printf("%s: %.2lf\n", head->name, head->amount);
        head = head->next;
    }
}

int main()
{
    struct Record* head = NULL;

    insert(&head, "John Doe", 100.0);
    insert(&head, "Jane Doe", 200.0);
    insert(&head, "Jack Doe", 300.0);

    print_records(head);

    return 0;
}