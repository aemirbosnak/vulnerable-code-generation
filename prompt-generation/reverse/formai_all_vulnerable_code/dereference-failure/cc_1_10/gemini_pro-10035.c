//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char *name;
    double amount;
};

struct budget {
    char *name;
    double amount;
    struct expense *expenses;
    int num_expenses;
};

struct personal_finance_plan {
    char *name;
    struct budget *budgets;
    int num_budgets;
};

void print_expense(struct expense *expense) {
    printf("%s: %.2f\n", expense->name, expense->amount);
}

void print_budget(struct budget *budget) {
    printf("%s: %.2f\n", budget->name, budget->amount);
    for (int i = 0; i < budget->num_expenses; i++) {
        print_expense(&budget->expenses[i]);
    }
}

void print_personal_finance_plan(struct personal_finance_plan *plan) {
    printf("%s\n", plan->name);
    for (int i = 0; i < plan->num_budgets; i++) {
        print_budget(&plan->budgets[i]);
    }
}

int main() {
    struct expense expense1 = {
        .name = "Rent",
        .amount = 1000.00
    };

    struct expense expense2 = {
        .name = "Utilities",
        .amount = 200.00
    };

    struct budget budget1 = {
        .name = "Housing",
        .amount = 1200.00,
        .expenses = &expense1,
        .num_expenses = 1
    };

    struct budget budget2 = {
        .name = "Transportation",
        .amount = 400.00,
        .expenses = &expense2,
        .num_expenses = 1
    };

    struct personal_finance_plan plan = {
        .name = "My Personal Finance Plan",
        .budgets = &budget1,
        .num_budgets = 2
    };

    print_personal_finance_plan(&plan);

    return 0;
}