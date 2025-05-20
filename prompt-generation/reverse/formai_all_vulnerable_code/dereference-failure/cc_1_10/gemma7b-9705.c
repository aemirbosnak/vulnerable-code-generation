//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include "stdio.h"
#include "stdlib.h"

#define MAX 100

typedef struct PersonalFinance
{
    char name[MAX];
    int income;
    int expenses;
    struct PersonalFinance* next;
} PersonalFinance;

PersonalFinance* insertAtTail(PersonalFinance* head, int income, int expenses, char name[])
{
    PersonalFinance* newPersonalFinance = malloc(sizeof(PersonalFinance));
    newPersonalFinance->income = income;
    newPersonalFinance->expenses = expenses;
    strcpy(newPersonalFinance->name, name);
    newPersonalFinance->next = NULL;

    if (head == NULL)
    {
        return newPersonalFinance;
    }

    head->next = newPersonalFinance;
    return head;
}

void printPersonalFinance(PersonalFinance* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Income: %d\n", head->income);
        printf("Expenses: %d\n", head->expenses);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    PersonalFinance* head = NULL;

    insertAtTail(head, 5000, 2000, "John Doe");
    insertAtTail(head, 6000, 3000, "Jane Doe");
    insertAtTail(head, 7000, 4000, "Peter Pan");

    printPersonalFinance(head);

    return 0;
}