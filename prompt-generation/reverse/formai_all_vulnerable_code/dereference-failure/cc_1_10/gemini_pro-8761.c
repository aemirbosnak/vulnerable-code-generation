//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *name;
    double amount;
} expense_t;

typedef struct {
    char *name;
    double amount;
    int num_expenses;
    expense_t *expenses;
} budget_category_t;

typedef struct {
    int num_budget_categories;
    budget_category_t *budget_categories;
} budget_t;

budget_t *create_budget() {
    budget_t *budget = malloc(sizeof(budget_t));
    budget->num_budget_categories = 0;
    budget->budget_categories = NULL;
    return budget;
}

void destroy_budget(budget_t *budget) {
    for (int i = 0; i < budget->num_budget_categories; i++) {
        free(budget->budget_categories[i].name);
        for (int j = 0; j < budget->budget_categories[i].num_expenses; j++) {
            free(budget->budget_categories[i].expenses[j].name);
        }
        free(budget->budget_categories[i].expenses);
    }
    free(budget->budget_categories);
    free(budget);
}

budget_category_t *create_budget_category(char *name) {
    budget_category_t *category = malloc(sizeof(budget_category_t));
    category->name = strdup(name);
    category->amount = 0;
    category->num_expenses = 0;
    category->expenses = NULL;
    return category;
}

void destroy_budget_category(budget_category_t *category) {
    free(category->name);
    for (int i = 0; i < category->num_expenses; i++) {
        free(category->expenses[i].name);
    }
    free(category->expenses);
    free(category);
}

expense_t *create_expense(char *name, double amount) {
    expense_t *expense = malloc(sizeof(expense_t));
    expense->name = strdup(name);
    expense->amount = amount;
    return expense;
}

void destroy_expense(expense_t *expense) {
    free(expense->name);
    free(expense);
}

void add_budget_category(budget_t *budget, budget_category_t *category) {
    budget->budget_categories = realloc(budget->budget_categories, (budget->num_budget_categories + 1) * sizeof(budget_category_t));
    budget->budget_categories[budget->num_budget_categories] = *category;
    budget->num_budget_categories++;
}

void add_expense(budget_category_t *category, expense_t *expense) {
    category->expenses = realloc(category->expenses, (category->num_expenses + 1) * sizeof(expense_t));
    category->expenses[category->num_expenses] = *expense;
    category->num_expenses++;
}

double get_total_budget(budget_t *budget) {
    double total = 0;
    for (int i = 0; i < budget->num_budget_categories; i++) {
        total += budget->budget_categories[i].amount;
    }
    return total;
}

double get_total_expenses(budget_t *budget) {
    double total = 0;
    for (int i = 0; i < budget->num_budget_categories; i++) {
        for (int j = 0; j < budget->budget_categories[i].num_expenses; j++) {
            total += budget->budget_categories[i].expenses[j].amount;
        }
    }
    return total;
}

double get_remaining_budget(budget_t *budget) {
    return get_total_budget(budget) - get_total_expenses(budget);
}

void print_budget(budget_t *budget) {
    printf("Budget:\n");
    for (int i = 0; i < budget->num_budget_categories; i++) {
        printf("  %s: $%.2f\n", budget->budget_categories[i].name, budget->budget_categories[i].amount);
        for (int j = 0; j < budget->budget_categories[i].num_expenses; j++) {
            printf("    %s: $%.2f\n", budget->budget_categories[i].expenses[j].name, budget->budget_categories[i].expenses[j].amount);
        }
    }
    printf("Total budget: $%.2f\n", get_total_budget(budget));
    printf("Total expenses: $%.2f\n", get_total_expenses(budget));
    printf("Remaining budget: $%.2f\n", get_remaining_budget(budget));
}

int main() {
    budget_t *budget = create_budget();

    budget_category_t *food = create_budget_category("Food");
    add_budget_category(budget, food);
    add_expense(food, create_expense("Groceries", 200));
    add_expense(food, create_expense("Restaurants", 100));

    budget_category_t *housing = create_budget_category("Housing");
    add_budget_category(budget, housing);
    add_expense(housing, create_expense("Rent", 1000));
    add_expense(housing, create_expense("Utilities", 200));

    budget_category_t *transportation = create_budget_category("Transportation");
    add_budget_category(budget, transportation);
    add_expense(transportation, create_expense("Car payment", 500));
    add_expense(transportation, create_expense("Gas", 200));

    budget_category_t *entertainment = create_budget_category("Entertainment");
    add_budget_category(budget, entertainment);
    add_expense(entertainment, create_expense("Movies", 50));
    add_expense(entertainment, create_expense("Concerts", 100));

    print_budget(budget);

    destroy_budget(budget);

    return 0;
}