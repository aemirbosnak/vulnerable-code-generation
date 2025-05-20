//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the struct for each expense category
typedef struct {
    char *name;
    double amount;
} expense_category;

// Define the struct for the personal finance planner
typedef struct {
    char *name;
    double income;
    expense_category *expenses;
    int num_expenses;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner *create_personal_finance_planner(char *name, double income) {
    personal_finance_planner *planner = malloc(sizeof(personal_finance_planner));
    planner->name = name;
    planner->income = income;
    planner->expenses = NULL;
    planner->num_expenses = 0;
    return planner;
}

// Add an expense category to the personal finance planner
void add_expense_category(personal_finance_planner *planner, char *name, double amount) {
    expense_category *new_expense = malloc(sizeof(expense_category));
    new_expense->name = name;
    new_expense->amount = amount;

    // Reallocate the expenses array to make room for the new expense category
    planner->expenses = realloc(planner->expenses, (planner->num_expenses + 1) * sizeof(expense_category));

    // Add the new expense category to the array
    planner->expenses[planner->num_expenses++] = *new_expense;

    free(new_expense);
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner *planner) {
    printf("Personal Finance Planner for %s\n", planner->name);
    printf("Income: $%.2f\n", planner->income);
    printf("Expenses:\n");
    for (int i = 0; i < planner->num_expenses; i++) {
        printf(" - %s: $%.2f\n", planner->expenses[i].name, planner->expenses[i].amount);
    }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner *planner) {
    for (int i = 0; i < planner->num_expenses; i++) {
        free(planner->expenses[i].name);
    }
    free(planner->expenses);
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner *planner = create_personal_finance_planner("Alice", 5000);

    // Add some expense categories to the planner
    add_expense_category(planner, "Rent", 1200);
    add_expense_category(planner, "Food", 500);
    add_expense_category(planner, "Transportation", 300);
    add_expense_category(planner, "Entertainment", 200);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}