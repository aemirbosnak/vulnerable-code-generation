//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an expense
struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
};

// Function to create a new expense
struct Expense *createExpense(char *description, float amount) {
    struct Expense *newExpense = (struct Expense *)malloc(sizeof(struct Expense));
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = NULL;
    return newExpense;
}

// Function to add an expense to the list
void addExpense(struct Expense **head, struct Expense *newExpense) {
    if (*head == NULL) {
        *head = newExpense;
    } else {
        struct Expense *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newExpense;
    }
}

// Function to print the list of expenses
void printExpenses(struct Expense *head) {
    struct Expense *current = head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// Function to free the memory allocated for the list of expenses
void freeExpenses(struct Expense *head) {
    struct Expense *current = head;
    while (current != NULL) {
        struct Expense *next = current->next;
        free(current);
        current = next;
    }
}

// Function to get the total amount of expenses
float getTotalAmount(struct Expense *head) {
    float totalAmount = 0;
    struct Expense *current = head;
    while (current != NULL) {
        totalAmount += current->amount;
        current = current->next;
    }
    return totalAmount;
}

// Function to get the average amount of expenses
float getAverageAmount(struct Expense *head) {
    float totalAmount = getTotalAmount(head);
    int count = 0;
    struct Expense *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return totalAmount / count;
}

// Function to get the maximum amount of expenses
float getMaxAmount(struct Expense *head) {
    float maxAmount = 0;
    struct Expense *current = head;
    while (current != NULL) {
        if (current->amount > maxAmount) {
            maxAmount = current->amount;
        }
        current = current->next;
    }
    return maxAmount;
}

// Function to get the minimum amount of expenses
float getMinAmount(struct Expense *head) {
    float minAmount = 0;
    struct Expense *current = head;
    while (current != NULL) {
        if (current->amount < minAmount) {
            minAmount = current->amount;
        }
        current = current->next;
    }
    return minAmount;
}

// Main function
int main() {
    // Create a linked list of expenses
    struct Expense *head = NULL;
    addExpense(&head, createExpense("Dinner", 20.00));
    addExpense(&head, createExpense("Movies", 15.00));
    addExpense(&head, createExpense("Groceries", 30.00));
    addExpense(&head, createExpense("Rent", 1000.00));

    // Print the list of expenses
    printf("Expenses:\n");
    printExpenses(head);

    // Get the total amount of expenses
    float totalAmount = getTotalAmount(head);
    printf("Total amount: $%.2f\n", totalAmount);

    // Get the average amount of expenses
    float averageAmount = getAverageAmount(head);
    printf("Average amount: $%.2f\n", averageAmount);

    // Get the maximum amount of expenses
    float maxAmount = getMaxAmount(head);
    printf("Maximum amount: $%.2f\n", maxAmount);

    // Get the minimum amount of expenses
    float minAmount = getMinAmount(head);
    printf("Minimum amount: $%.2f\n", minAmount);

    // Free the memory allocated for the list of expenses
    freeExpenses(head);

    return 0;
}