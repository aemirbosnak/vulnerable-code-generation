//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the struct to hold an expense
typedef struct Expense {
    char *description;
    float amount;
    struct Expense *next;
} Expense;

// Declare the head of the linked list of expenses
Expense *head = NULL;

// Function to create a new expense
Expense *createExpense(char *description, float amount) {
    // Allocate memory for the new expense
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));

    // Check if memory was allocated successfully
    if (newExpense == NULL) {
        printf("Error allocating memory for new expense!\n");
        exit(1);
    }

    // Initialize the new expense
    newExpense->description = strdup(description);
    newExpense->amount = amount;
    newExpense->next = NULL;

    // Return the new expense
    return newExpense;
}

// Function to add an expense to the linked list
void addExpense(Expense *newExpense) {
    // If the linked list is empty, set the head to the new expense
    if (head == NULL) {
        head = newExpense;
        return;
    }

    // Otherwise, traverse the linked list until we find the last expense
    Expense *currentExpense = head;
    while (currentExpense->next != NULL) {
        currentExpense = currentExpense->next;
    }

    // Set the next pointer of the last expense to the new expense
    currentExpense->next = newExpense;
}

// Function to print the expenses in the linked list
void printExpenses() {
    // Traverse the linked list and print each expense
    Expense *currentExpense = head;
    while (currentExpense != NULL) {
        printf("%s: $%.2f\n", currentExpense->description, currentExpense->amount);
        currentExpense = currentExpense->next;
    }
}

// Function to free the memory allocated for the expenses in the linked list
void freeExpenses() {
    // Traverse the linked list and free the memory for each expense
    Expense *currentExpense = head;
    while (currentExpense != NULL) {
        Expense *nextExpense = currentExpense->next;
        free(currentExpense->description);
        free(currentExpense);
        currentExpense = nextExpense;
    }
}

// Main function
int main() {
    // Create some expenses
    Expense *expense1 = createExpense("Rent", 1200.00);
    Expense *expense2 = createExpense("Utilities", 200.00);
    Expense *expense3 = createExpense("Groceries", 300.00);

    // Add the expenses to the linked list
    addExpense(expense1);
    addExpense(expense2);
    addExpense(expense3);

    // Print the expenses
    printf("Your expenses:\n");
    printExpenses();

    // Free the memory allocated for the expenses
    freeExpenses();

    return 0;
}