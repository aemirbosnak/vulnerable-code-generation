//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define an array to store expense details
struct Expense
{
    char name[50];
    int amount;
    char category[50];
    struct Expense* next;
};

// Function to insert a new expense into the linked list
void insertExpense(struct Expense** head, char* name, int amount, char* category)
{
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    strcpy(newExpense->category, category);
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

// Function to print all expenses
void printExpenses(struct Expense* head)
{
    struct Expense* current = head;
    while (current)
    {
        printf("%s: %d, Category: %s\n", current->name, current->amount, current->category);
        current = current->next;
    }
}

int main()
{
    // Create a linked list to store expenses
    struct Expense* head = NULL;

    // Insert some expenses
    insertExpense(&head, "Groceries", 50, "Food");
    insertExpense(&head, "Electronics", 200, "Electronics");
    insertExpense(&head, "Clothing", 75, "Clothing");
    insertExpense(&head, "Entertainment", 25, "Entertainment");

    // Print all expenses
    printExpenses(head);

    return 0;
}