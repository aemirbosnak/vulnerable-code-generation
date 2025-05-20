//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char *name;
    float amount;
} Expense;

typedef struct ExpenseManager {
    Expense *expenses;
    int num_expenses;
    float total_amount;
} ExpenseManager;

ExpenseManager *create_expense_manager() {
    ExpenseManager *manager = malloc(sizeof(ExpenseManager));
    manager->expenses = malloc(sizeof(Expense));
    manager->num_expenses = 0;
    manager->total_amount = 0;
    return manager;
}

void destroy_expense_manager(ExpenseManager *manager) {
    for (int i = 0; i < manager->num_expenses; i++) {
        free(manager->expenses[i].name);
    }
    free(manager->expenses);
    free(manager);
}

void add_expense(ExpenseManager *manager, char *name, float amount) {
    manager->num_expenses++;
    manager->expenses = realloc(manager->expenses, sizeof(Expense) * manager->num_expenses);
    manager->expenses[manager->num_expenses - 1].name = strdup(name);
    manager->expenses[manager->num_expenses - 1].amount = amount;
    manager->total_amount += amount;
}

void print_expenses(ExpenseManager *manager) {
    for (int i = 0; i < manager->num_expenses; i++) {
        printf("%s: %.2f\n", manager->expenses[i].name, manager->expenses[i].amount);
    }
}

int main() {
    ExpenseManager *manager = create_expense_manager();

    add_expense(manager, "Coffee", 2.50);
    add_expense(manager, "Lunch", 10.00);
    add_expense(manager, "Dinner", 15.00);

    print_expenses(manager);
    printf("Total: %.2f\n", manager->total_amount);

    destroy_expense_manager(manager);

    return 0;
}