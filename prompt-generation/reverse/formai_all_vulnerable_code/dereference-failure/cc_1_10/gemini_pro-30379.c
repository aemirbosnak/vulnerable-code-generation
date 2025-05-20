//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Structure to hold expense categories
typedef struct expense_category {
    char *name;
    double amount;
} expense_category;

// Structure to hold income categories
typedef struct income_category {
    char *name;
    double amount;
} income_category;

// Function to create a new expense category
expense_category *create_expense_category(char *name, double amount) {
    expense_category *category = malloc(sizeof(expense_category));
    category->name = name;
    category->amount = amount;
    return category;
}

// Function to create a new income category
income_category *create_income_category(char *name, double amount) {
    income_category *category = malloc(sizeof(income_category));
    category->name = name;
    category->amount = amount;
    return category;
}

// Function to print a list of expense categories
void print_expense_categories(expense_category **categories, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        printf("%s: $%.2f\n", categories[i]->name, categories[i]->amount);
    }
}

// Function to print a list of income categories
void print_income_categories(income_category **categories, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        printf("%s: $%.2f\n", categories[i]->name, categories[i]->amount);
    }
}

// Main function
int main() {
    // Create some expense categories
    expense_category *housing = create_expense_category("Housing", 1000);
    expense_category *food = create_expense_category("Food", 200);
    expense_category *transportation = create_expense_category("Transportation", 300);
    expense_category *entertainment = create_expense_category("Entertainment", 100);

    // Create some income categories
    income_category *salary = create_income_category("Salary", 4000);
    income_category *investments = create_income_category("Investments", 500);
    income_category *other = create_income_category("Other", 100);

    // Print the expense categories
    printf("Expense Categories:\n");
    print_expense_categories(&housing, 1);
    print_expense_categories(&food, 1);
    print_expense_categories(&transportation, 1);
    print_expense_categories(&entertainment, 1);

    // Print the income categories
    printf("Income Categories:\n");
    print_income_categories(&salary, 1);
    print_income_categories(&investments, 1);
    print_income_categories(&other, 1);

    return 0;
}