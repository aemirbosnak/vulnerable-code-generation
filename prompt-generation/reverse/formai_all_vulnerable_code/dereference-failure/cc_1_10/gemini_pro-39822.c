//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an expense
typedef struct expense {
    char* category;
    double amount;
    struct expense* next;
} expense;

// Define the structure of a budget
typedef struct budget {
    char* name;
    double total;
    struct expense* expenses;
    struct budget* next;
} budget;

// Create a new expense
expense* new_expense(char* category, double amount) {
    expense* e = malloc(sizeof(expense));
    e->category = strdup(category);
    e->amount = amount;
    e->next = NULL;
    return e;
}

// Create a new budget
budget* new_budget(char* name, double total) {
    budget* b = malloc(sizeof(budget));
    b->name = strdup(name);
    b->total = total;
    b->expenses = NULL;
    b->next = NULL;
    return b;
}

// Add an expense to a budget
void add_expense(budget* b, expense* e) {
    if (b->expenses == NULL) {
        b->expenses = e;
    } else {
        expense* curr = b->expenses;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = e;
    }
}

// Print a budget
void print_budget(budget* b) {
    printf("Budget: %s\n", b->name);
    printf("Total: %.2f\n", b->total);
    expense* curr = b->expenses;
    while (curr != NULL) {
        printf("\t%s: %.2f\n", curr->category, curr->amount);
        curr = curr->next;
    }
}

// Free a budget
void free_budget(budget* b) {
    free(b->name);
    expense* curr = b->expenses;
    while (curr != NULL) {
        expense* next = curr->next;
        free(curr->category);
        free(curr);
        curr = next;
    }
    free(b);
}

// Main function
int main() {
    // Create a new budget
    budget* b = new_budget("My Budget", 1000);

    // Add some expenses to the budget
    add_expense(b, new_expense("Rent", 500));
    add_expense(b, new_expense("Groceries", 200));
    add_expense(b, new_expense("Entertainment", 100));
    add_expense(b, new_expense("Savings", 200));

    // Print the budget
    print_budget(b);

    // Free the budget
    free_budget(b);

    return 0;
}