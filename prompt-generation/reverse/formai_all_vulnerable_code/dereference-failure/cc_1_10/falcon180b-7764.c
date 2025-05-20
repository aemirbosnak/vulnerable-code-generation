//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void add_expense(double amount, char* category);
void view_expenses();
void view_expenses_by_category(char* category);

struct expense {
    char* category;
    double amount;
};

// Global variables
int num_expenses = 0;
struct expense* expenses = NULL;

// Function to add an expense
void add_expense(double amount, char* category) {
    struct expense* new_expense = malloc(sizeof(struct expense));
    new_expense->category = category;
    new_expense->amount = amount;
    expenses = realloc(expenses, sizeof(struct expense) * ++num_expenses);
    expenses[num_expenses - 1] = *new_expense;
    free(new_expense);
}

// Function to view all expenses
void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
    }
}

// Function to view expenses by category
void view_expenses_by_category(char* category) {
    printf("Expenses in %s:\n", category);
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
        }
    }
}

int main() {
    // Initialize expenses array
    expenses = malloc(sizeof(struct expense));
    num_expenses = 0;

    // Example usage
    add_expense(25.50, "Groceries");
    add_expense(50.00, "Clothing");
    add_expense(75.25, "Entertainment");

    // View all expenses
    view_expenses();

    // View expenses in a specific category
    view_expenses_by_category("Groceries");

    free(expenses);
    return 0;
}