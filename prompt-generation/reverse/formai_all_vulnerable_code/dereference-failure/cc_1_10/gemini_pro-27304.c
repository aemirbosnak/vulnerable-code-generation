//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Data structures
typedef struct {
    char *name;
    double amount;
} Expense;

typedef struct {
    char *name;
    double amount;
    Expense *expenses;
    int num_expenses;
} Category;

// Function prototypes
void add_expense(Category *category, Expense expense);
void print_expenses(Category *category);
void print_total(Category *category);

// Main function
int main() {
    // Create a new personal finance planner
    Category *finance_planner = malloc(sizeof(Category));
    finance_planner->name = "Personal Finance Planner";
    finance_planner->amount = 0.0;
    finance_planner->expenses = NULL;
    finance_planner->num_expenses = 0;

    // Add some expenses to the planner
    Expense expense1 = {"Rent", 1000.0};
    Expense expense2 = {"Groceries", 200.0};
    add_expense(finance_planner, expense1);
    add_expense(finance_planner, expense2);

    // Print the expenses
    print_expenses(finance_planner);

    // Print the total
    print_total(finance_planner);

    // Free the memory allocated for the planner
    free(finance_planner->expenses);
    free(finance_planner);

    return 0;
}

// Function to add an expense to a category
void add_expense(Category *category, Expense expense) {
    // Allocate memory for the new expense
    category->expenses = realloc(category->expenses, (category->num_expenses + 1) * sizeof(Expense));
    // Copy the expense into the new array
    category->expenses[category->num_expenses] = expense;
    // Increment the number of expenses
    category->num_expenses++;
}

// Function to print the expenses in a category
void print_expenses(Category *category) {
    printf("Expenses in %s:\n", category->name);
    for (int i = 0; i < category->num_expenses; i++) {
        printf(" - %s: $%.2f\n", category->expenses[i].name, category->expenses[i].amount);
    }
}

// Function to print the total amount in a category
void print_total(Category *category) {
    double total = 0.0;
    for (int i = 0; i < category->num_expenses; i++) {
        total += category->expenses[i].amount;
    }
    printf("Total in %s: $%.2f\n", category->name, total);
}