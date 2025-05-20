//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

typedef struct Expense
{
    char name[50];
    int amount;
    struct Expense* next;
} Expense;

void addExpense(Expense** head)
{
    Expense* newExpense = malloc(sizeof(Expense));

    printf("Enter expense name: ");
    scanf("%s", newExpense->name);

    printf("Enter expense amount: ");
    scanf("%d", &newExpense->amount);

    newExpense->next = NULL;

    if (*head == NULL)
    {
        *head = newExpense;
    }
    else
    {
        (*head)->next = newExpense;
    }
}

void printExpenses(Expense* head)
{
    while (head)
    {
        printf("%s - %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main()
{
    Expense* head = NULL;

    printf("Enter 'add' to add an expense or 'print' to print expenses: ");
    char command;
    scanf("%c", &command);

    while (command == 'a' || command == 'A')
    {
        addExpense(&head);
        printf("Enter 'add' to add an expense or 'print' to print expenses: ");
        scanf("%c", &command);
    }

    while (command == 'p' || command == 'P')
    {
        printExpenses(head);
        printf("Enter 'add' to add an expense or 'print' to print expenses: ");
        scanf("%c", &command);
    }

    return 0;
}