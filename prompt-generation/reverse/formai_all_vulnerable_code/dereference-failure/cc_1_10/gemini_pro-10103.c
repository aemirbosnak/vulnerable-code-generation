//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    double amount;
} Category;

typedef struct {
    char name[50];
    double income;
    double expenses;
    Category categories[MAX_CATEGORIES];
    int num_categories;
} Budget;

// Function to create a new budget
Budget* create_budget(char* name) {
    Budget* budget = malloc(sizeof(Budget));
    strcpy(budget->name, name);
    budget->income = 0;
    budget->expenses = 0;
    budget->num_categories = 0;
    return budget;
}

// Function to add a category to a budget
void add_category(Budget* budget, char* name, double amount) {
    if (budget->num_categories >= MAX_CATEGORIES) {
        printf("Error: Too many categories\n");
        return;
    }

    strcpy(budget->categories[budget->num_categories].name, name);
    budget->categories[budget->num_categories].amount = amount;
    budget->num_categories++;
}

// Function to print a budget
void print_budget(Budget* budget) {
    printf("Budget: %s\n", budget->name);
    printf("Income: %.2f\n", budget->income);
    printf("Expenses: %.2f\n", budget->expenses);
    for (int i = 0; i < budget->num_categories; i++) {
        printf("  %s: %.2f\n", budget->categories[i].name, budget->categories[i].amount);
    }
}

// Function to free the memory allocated for a budget
void free_budget(Budget* budget) {
    free(budget);
}

int main() {
    // Create a new budget
    Budget* budget = create_budget("My Budget");

    // Add some income and expenses
    budget->income = 2000;
    budget->expenses = 1500;

    // Add some categories
    add_category(budget, "Rent", 500);
    add_category(budget, "Food", 300);
    add_category(budget, "Entertainment", 200);

    // Print the budget
    print_budget(budget);

    // Free the memory allocated for the budget
    free_budget(budget);

    return 0;
}