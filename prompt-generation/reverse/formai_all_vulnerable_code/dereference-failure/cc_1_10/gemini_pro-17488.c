//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double amount;
} expense_t;

typedef struct {
    char *name;
    double amount;
    int num_expenses;
    expense_t *expenses;
} category_t;

typedef struct {
    int num_categories;
    category_t *categories;
    double total_expenses;
} budget_t;

budget_t *create_budget() {
    budget_t *budget = malloc(sizeof(budget_t));
    budget->num_categories = 0;
    budget->categories = NULL;
    budget->total_expenses = 0;
    return budget;
}

void destroy_budget(budget_t *budget) {
    for (int i = 0; i < budget->num_categories; i++) {
        free(budget->categories[i].name);
        for (int j = 0; j < budget->categories[i].num_expenses; j++) {
            free(budget->categories[i].expenses[j].name);
        }
        free(budget->categories[i].expenses);
    }
    free(budget->categories);
    free(budget);
}

category_t *create_category(char *name) {
    category_t *category = malloc(sizeof(category_t));
    category->name = malloc(strlen(name) + 1);
    strcpy(category->name, name);
    category->amount = 0;
    category->num_expenses = 0;
    category->expenses = NULL;
    return category;
}

void destroy_category(category_t *category) {
    free(category->name);
    for (int i = 0; i < category->num_expenses; i++) {
        free(category->expenses[i].name);
    }
    free(category->expenses);
    free(category);
}

expense_t *create_expense(char *name, double amount) {
    expense_t *expense = malloc(sizeof(expense_t));
    expense->name = malloc(strlen(name) + 1);
    strcpy(expense->name, name);
    expense->amount = amount;
    return expense;
}

void destroy_expense(expense_t *expense) {
    free(expense->name);
    free(expense);
}

void add_category(budget_t *budget, category_t *category) {
    budget->categories = realloc(budget->categories, (budget->num_categories + 1) * sizeof(category_t));
    budget->categories[budget->num_categories++] = *category;
}

void add_expense(category_t *category, expense_t *expense) {
    category->expenses = realloc(category->expenses, (category->num_expenses + 1) * sizeof(expense_t));
    category->expenses[category->num_expenses++] = *expense;
    category->amount += expense->amount;
}

void print_budget(budget_t *budget) {
    printf("Budget:\n");
    for (int i = 0; i < budget->num_categories; i++) {
        printf("  %s: $%.2f\n", budget->categories[i].name, budget->categories[i].amount);
        for (int j = 0; j < budget->categories[i].num_expenses; j++) {
            printf("    %s: $%.2f\n", budget->categories[i].expenses[j].name, budget->categories[i].expenses[j].amount);
        }
    }
    printf("Total expenses: $%.2f\n", budget->total_expenses);
}

int main() {
    budget_t *budget = create_budget();

    category_t *food = create_category("Food");
    add_category(budget, food);
    expense_t *groceries = create_expense("Groceries", 100);
    add_expense(food, groceries);
    expense_t *dining_out = create_expense("Dining out", 50);
    add_expense(food, dining_out);

    category_t *entertainment = create_category("Entertainment");
    add_category(budget, entertainment);
    expense_t *movies = create_expense("Movies", 20);
    add_expense(entertainment, movies);
    expense_t *concerts = create_expense("Concerts", 30);
    add_expense(entertainment, concerts);

    category_t *transportation = create_category("Transportation");
    add_category(budget, transportation);
    expense_t *gas = create_expense("Gas", 50);
    add_expense(transportation, gas);
    expense_t *public_transportation = create_expense("Public transportation", 20);
    add_expense(transportation, public_transportation);

    for (int i = 0; i < budget->num_categories; i++) {
        budget->total_expenses += budget->categories[i].amount;
    }

    print_budget(budget);

    destroy_budget(budget);

    return 0;
}