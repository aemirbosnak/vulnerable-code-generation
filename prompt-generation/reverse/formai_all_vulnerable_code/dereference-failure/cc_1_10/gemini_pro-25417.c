//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an expense
typedef struct Expense {
    char *category;
    char *description;
    double amount;
    struct Expense *next;
} Expense;

// Function to create a new expense
Expense *createExpense(char *category, char *description, double amount) {
    Expense *expense = malloc(sizeof(Expense));
    expense->category = strdup(category);
    expense->description = strdup(description);
    expense->amount = amount;
    expense->next = NULL;
    return expense;
}

// Function to add an expense to the list
void addExpense(Expense **head, Expense *expense) {
    if (*head == NULL) {
        *head = expense;
    } else {
        Expense *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = expense;
    }
}

// Function to print the list of expenses
void printExpenses(Expense *head) {
    Expense *current = head;
    while (current != NULL) {
        printf("%s - %s - %.2f\n", current->category, current->description, current->amount);
        current = current->next;
    }
}

// Function to free the list of expenses
void freeExpenses(Expense *head) {
    Expense *current = head;
    while (current != NULL) {
        Expense *next = current->next;
        free(current->category);
        free(current->description);
        free(current);
        current = next;
    }
}

// Function to get the total amount of expenses
double getTotalAmount(Expense *head) {
    double total = 0.0;
    Expense *current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

// Function to get the average amount of expenses
double getAverageAmount(Expense *head) {
    double total = getTotalAmount(head);
    int count = 0;
    Expense *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return total / count;
}

// Function to get the maximum amount of expenses
double getMaxAmount(Expense *head) {
    double max = 0.0;
    Expense *current = head;
    while (current != NULL) {
        if (current->amount > max) {
            max = current->amount;
        }
        current = current->next;
    }
    return max;
}

// Function to get the minimum amount of expenses
double getMinAmount(Expense *head) {
    double min = 0.0;
    Expense *current = head;
    while (current != NULL) {
        if (current->amount < min) {
            min = current->amount;
        }
        current = current->next;
    }
    return min;
}

// Function to get the most expensive category
char *getMostExpensiveCategory(Expense *head) {
    char *category = NULL;
    double max = 0.0;
    Expense *current = head;
    while (current != NULL) {
        if (current->amount > max) {
            max = current->amount;
            category = current->category;
        }
        current = current->next;
    }
    return category;
}

// Function to get the least expensive category
char *getLeastExpensiveCategory(Expense *head) {
    char *category = NULL;
    double min = 0.0;
    Expense *current = head;
    while (current != NULL) {
        if (current->amount < min) {
            min = current->amount;
            category = current->category;
        }
        current = current->next;
    }
    return category;
}

// Main function
int main() {
    // Create a list of expenses
    Expense *head = NULL;
    addExpense(&head, createExpense("Food", "Groceries", 100.00));
    addExpense(&head, createExpense("Entertainment", "Movies", 50.00));
    addExpense(&head, createExpense("Transportation", "Gas", 200.00));
    addExpense(&head, createExpense("Clothing", "New shoes", 75.00));
    addExpense(&head, createExpense("Other", "Miscellaneous", 50.00));

    // Print the list of expenses
    printf("Expenses:\n");
    printExpenses(head);

    // Get the total amount of expenses
    double totalAmount = getTotalAmount(head);
    printf("Total amount: %.2f\n", totalAmount);

    // Get the average amount of expenses
    double averageAmount = getAverageAmount(head);
    printf("Average amount: %.2f\n", averageAmount);

    // Get the maximum amount of expenses
    double maxAmount = getMaxAmount(head);
    printf("Maximum amount: %.2f\n", maxAmount);

    // Get the minimum amount of expenses
    double minAmount = getMinAmount(head);
    printf("Minimum amount: %.2f\n", minAmount);

    // Get the most expensive category
    char *mostExpensiveCategory = getMostExpensiveCategory(head);
    printf("Most expensive category: %s\n", mostExpensiveCategory);

    // Get the least expensive category
    char *leastExpensiveCategory = getLeastExpensiveCategory(head);
    printf("Least expensive category: %s\n", leastExpensiveCategory);

    // Free the list of expenses
    freeExpenses(head);

    return 0;
}