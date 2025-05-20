//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    char *description;
    double amount;
} Expense;

typedef struct {
    char *name;
    char *description;
    double total;
    Expense **expenses;
    int num_expenses;
} Category;

// Function prototypes
Category *create_category(char *name, char *description);
Expense *create_expense(char *name, char *description, double amount);
void add_expense_to_category(Category *category, Expense *expense);
void print_category(Category *category);
void free_category(Category *category);

int main() {
    // Create a new category
    Category *category = create_category("My Expenses", "This is a category of my expenses");

    // Add some expenses to the category
    Expense *expense1 = create_expense("Rent", "My rent for the month", 1200.00);
    Expense *expense2 = create_expense("Groceries", "My groceries for the week", 200.00);
    Expense *expense3 = create_expense("Transportation", "My transportation costs for the month", 300.00);
    add_expense_to_category(category, expense1);
    add_expense_to_category(category, expense2);
    add_expense_to_category(category, expense3);

    // Print the category
    print_category(category);

    // Free the category
    free_category(category);

    return 0;
}

// Function definitions
Category *create_category(char *name, char *description) {
    Category *category = malloc(sizeof(Category));
    category->name = strdup(name);
    category->description = strdup(description);
    category->total = 0.00;
    category->expenses = NULL;
    category->num_expenses = 0;
    return category;
}

Expense *create_expense(char *name, char *description, double amount) {
    Expense *expense = malloc(sizeof(Expense));
    expense->name = strdup(name);
    expense->description = strdup(description);
    expense->amount = amount;
    return expense;
}

void add_expense_to_category(Category *category, Expense *expense) {
    category->expenses = realloc(category->expenses, (category->num_expenses + 1) * sizeof(Expense *));
    category->expenses[category->num_expenses++] = expense;
    category->total += expense->amount;
}

void print_category(Category *category) {
    printf("Category: %s\n", category->name);
    printf("Description: %s\n", category->description);
    printf("Total: %.2f\n", category->total);
    for (int i = 0; i < category->num_expenses; i++) {
        printf("Expense: %s\n", category->expenses[i]->name);
        printf("Description: %s\n", category->expenses[i]->description);
        printf("Amount: %.2f\n", category->expenses[i]->amount);
        printf("\n");
    }
}

void free_category(Category *category) {
    for (int i = 0; i < category->num_expenses; i++) {
        free(category->expenses[i]->name);
        free(category->expenses[i]->description);
        free(category->expenses[i]);
    }
    free(category->expenses);
    free(category->name);
    free(category->description);
    free(category);
}