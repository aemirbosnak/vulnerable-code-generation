//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Declare an expense
typedef struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
} Expense;

// Declare a linked list of expenses
Expense *head = NULL;

// Function to add an expense to the linked list
void addExpense(char *description, float amount) {
    Expense *newExpense = malloc(sizeof(Expense));
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        Expense *currentExpense = head;
        while (currentExpense->next != NULL) {
            currentExpense = currentExpense->next;
        }
        currentExpense->next = newExpense;
    }
}

// Function to print the linked list of expenses
void printExpenses() {
    Expense *currentExpense = head;
    while (currentExpense != NULL) {
        printf("%s: $%.2f\n", currentExpense->description, currentExpense->amount);
        currentExpense = currentExpense->next;
    }
}

// Function to clear the linked list of expenses
void clearExpenses() {
    Expense *currentExpense = head;
    while (currentExpense != NULL) {
        Expense *nextExpense = currentExpense->next;
        free(currentExpense);
        currentExpense = nextExpense;
    }
    head = NULL;
}

// Main function
int main() {
    // Add some expenses to the linked list
    addExpense("Coffee", 3.50);
    addExpense("Lunch", 10.00);
    addExpense("Dinner", 15.00);
    addExpense("Movie", 12.00);

    // Print the linked list of expenses
    printf("Your expenses:\n");
    printExpenses();

    // Clear the linked list of expenses
    clearExpenses();

    return 0;
}