//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an expense
typedef struct {
    char *description;
    float amount;
} Expense;

// Define the structure of a budget
typedef struct {
    char *name;
    float amount;
    Expense *expenses;
    int num_expenses;
} Budget;

// Create a new budget
Budget *create_budget(char *name, float amount) {
    Budget *budget = malloc(sizeof(Budget));
    budget->name = strdup(name);
    budget->amount = amount;
    budget->expenses = NULL;
    budget->num_expenses = 0;
    return budget;
}

// Add an expense to a budget
void add_expense(Budget *budget, char *description, float amount) {
    budget->expenses = realloc(budget->expenses, (budget->num_expenses + 1) * sizeof(Expense));
    budget->expenses[budget->num_expenses].description = strdup(description);
    budget->expenses[budget->num_expenses].amount = amount;
    budget->num_expenses++;
}

// Print a budget
void print_budget(Budget *budget) {
    printf("Budget: %s\n", budget->name);
    printf("Amount: %.2f\n", budget->amount);
    printf("Expenses:\n");
    for (int i = 0; i < budget->num_expenses; i++) {
        printf("  %s: %.2f\n", budget->expenses[i].description, budget->expenses[i].amount);
    }
}

// Free the memory allocated for a budget
void free_budget(Budget *budget) {
    for (int i = 0; i < budget->num_expenses; i++) {
        free(budget->expenses[i].description);
    }
    free(budget->expenses);
    free(budget->name);
    free(budget);
}

// Example usage
int main() {
    // Create a new budget
    Budget *budget = create_budget("My Budget", 1000.00);

    // Add some expenses to the budget
    add_expense(budget, "Rent", 500.00);
    add_expense(budget, "Groceries", 200.00);
    add_expense(budget, "Utilities", 100.00);
    add_expense(budget, "Fun", 200.00);

    // Print the budget
    print_budget(budget);

    // Free the memory allocated for the budget
    free_budget(budget);

    return 0;
}