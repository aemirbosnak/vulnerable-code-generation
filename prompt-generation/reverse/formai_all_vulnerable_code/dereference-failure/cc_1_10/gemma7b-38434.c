//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

struct Expense {
    char name[256];
    int amount;
    struct Expense* next;
};

void add_expense(struct Expense** head, char* name, int amount)
{
    struct Expense* new_expense = malloc(sizeof(struct Expense));

    strcpy(new_expense->name, name);
    new_expense->amount = amount;

    if (*head == NULL)
    {
        *head = new_expense;
    }
    else
    {
        (*head)->next = new_expense;
        *head = new_expense;
    }
}

void print_expenses(struct Expense* head)
{
    while (head)
    {
        printf("%s: %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main()
{
    struct Expense* head = NULL;

    add_expense(&head, "Groceries", 50);
    add_expense(&head, "Rent", 100);
    add_expense(&head, "Dining", 25);

    print_expenses(head);

    return 0;
}