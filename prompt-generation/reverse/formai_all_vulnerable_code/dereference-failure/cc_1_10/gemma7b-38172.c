//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 10

// Define the structure of an expense
typedef struct Expense {
    char name[20];
    int amount;
    struct Expense* next;
} Expense;

// Function to add an expense to the list
void addExpense(Expense** head) {
    // Allocate memory for the new expense
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));

    // Get the name, amount, and next expense of the new expense
    printf("Enter the name of the expense: ");
    scanf("%s", newExpense->name);

    printf("Enter the amount of the expense: ");
    scanf("%d", &newExpense->amount);

    newExpense->next = NULL;

    // If the list is empty, make the new expense the first expense
    if (*head == NULL) {
        *head = newExpense;
    } else {
        // Traverse the list to the last expense and add the new expense after the last expense
        Expense* lastExpense = *head;
        while (lastExpense->next != NULL) {
            lastExpense = lastExpense->next;
        }
        lastExpense->next = newExpense;
    }
}

// Function to print the expenses
void printExpenses(Expense* head) {
    // Traverse the list of expenses
    while (head) {
        printf("%s: %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    // Create an empty list of expenses
    Expense* head = NULL;

    // Add some expenses to the list
    addExpense(&head);
    addExpense(&head);
    addExpense(&head);

    // Print the expenses
    printExpenses(head);

    return 0;
}