//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 10

// Define the structure of an expense
typedef struct Expense {
    char name[20];
    float amount;
    struct Expense* next;
} Expense;

// Function to insert an expense
void insertExpense(Expense* head, char* name, float amount) {
    // Allocate memory for the new expense
    Expense* newExpense = malloc(sizeof(Expense));

    // Copy the name and amount of the new expense
    strcpy(newExpense->name, name);
    newExpense->amount = amount;

    // If the head of the list is NULL, make it the new head
    if (head == NULL) {
        head = newExpense;
    } else {
        // Traverse the list until the last expense is reached
        Expense* currentExpense = head;
        while (currentExpense->next != NULL) {
            currentExpense = currentExpense->next;
        }

        // Insert the new expense at the end of the list
        currentExpense->next = newExpense;
    }
}

// Function to print the expenses
void printExpenses(Expense* head) {
    // Traverse the list of expenses
    Expense* currentExpense = head;
    while (currentExpense) {
        // Print the name and amount of the expense
        printf("%s: %.2f\n", currentExpense->name, currentExpense->amount);
        currentExpense = currentExpense->next;
    }
}

int main() {
    // Create a linked list of expenses
    Expense* head = NULL;

    // Insert some expenses
    insertExpense(head, "Groceries", 50.0);
    insertExpense(head, "Eating out", 25.0);
    insertExpense(head, "Clothing", 10.0);
    insertExpense(head, "Entertainment", 20.0);

    // Print the expenses
    printExpenses(head);

    return 0;
}