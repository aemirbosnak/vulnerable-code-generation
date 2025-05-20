//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 10

// Define the expense structure
typedef struct Expense {
    char name[50];
    int amount;
    struct Expense* next;
} Expense;

// Create a linked list of expenses
Expense* createExpenseList() {
    return NULL;
}

// Add an expense to the linked list
void addExpense(Expense* list, char* name, int amount) {
    // Allocate memory for the new expense
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));

    // Copy the expense name and amount
    strcpy(newExpense->name, name);
    newExpense->amount = amount;

    // Insert the new expense into the list
    if (list == NULL) {
        list = newExpense;
    } else {
        newExpense->next = list;
        list = newExpense;
    }
}

// Print the expenses
void printExpenses(Expense* list) {
    // Traverse the list of expenses
    while (list) {
        // Print the expense name and amount
        printf("%s: %d\n", list->name, list->amount);
        list = list->next;
    }
}

int main() {
    // Create a linked list of expenses
    Expense* expenseList = createExpenseList();

    // Add some expenses
    addExpense(expenseList, "Groceries", 50);
    addExpense(expenseList, "Eating out", 25);
    addExpense(expenseList, "Clothes", 75);

    // Print the expenses
    printExpenses(expenseList);

    return 0;
}