//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 10

// Define the structure of an expense
typedef struct Expense
{
    char name[20];
    int amount;
    struct Expense* next;
} Expense;

// Create a new expense
Expense* newExpense(char* name, int amount)
{
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;
    return newExpense;
}

// Insert an expense into the list
void insertExpense(Expense* head, Expense* newExpense)
{
    if (head == NULL)
    {
        head = newExpense;
    }
    else
    {
        head->next = newExpense;
        head = newExpense;
    }
}

// Print all expenses
void printExpenses(Expense* head)
{
    while (head)
    {
        printf("%s: %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main()
{
    // Create a new expense list
    Expense* head = NULL;

    // Insert some expenses
    insertExpense(head, newExpense("Groceries", 50));
    insertExpense(head, newExpense("Eating out", 25));
    insertExpense(head, newExpense("Clothing", 10));

    // Print all expenses
    printExpenses(head);

    return 0;
}