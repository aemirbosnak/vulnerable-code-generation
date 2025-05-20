//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char *category;
    double amount;
};

struct income {
    char *source;
    double amount;
};

struct budget {
    struct expense *expenses;
    int num_expenses;
    struct income *incomes;
    int num_incomes;
};

struct budget *create_budget() {
    struct budget *budget = malloc(sizeof(struct budget));
    budget->expenses = malloc(sizeof(struct expense) * 10);
    budget->num_expenses = 0;
    budget->incomes = malloc(sizeof(struct income) * 10);
    budget->num_incomes = 0;
    return budget;
}

void add_expense(struct budget *budget, char *category, double amount) {
    budget->expenses[budget->num_expenses].category = category;
    budget->expenses[budget->num_expenses].amount = amount;
    budget->num_expenses++;
}

void add_income(struct budget *budget, char *source, double amount) {
    budget->incomes[budget->num_incomes].source = source;
    budget->incomes[budget->num_incomes].amount = amount;
    budget->num_incomes++;
}

void print_budget(struct budget *budget) {
    printf("Expenses:\n");
    for (int i = 0; i < budget->num_expenses; i++) {
        printf("  %s: %f\n", budget->expenses[i].category, budget->expenses[i].amount);
    }
    printf("Incomes:\n");
    for (int i = 0; i < budget->num_incomes; i++) {
        printf("  %s: %f\n", budget->incomes[i].source, budget->incomes[i].amount);
    }
}

void free_budget(struct budget *budget) {
    for (int i = 0; i < budget->num_expenses; i++) {
        free(budget->expenses[i].category);
    }
    free(budget->expenses);
    for (int i = 0; i < budget->num_incomes; i++) {
        free(budget->incomes[i].source);
    }
    free(budget->incomes);
    free(budget);
}

int main() {
    struct budget *budget = create_budget();
    add_expense(budget, "Rent", 1000);
    add_expense(budget, "Groceries", 200);
    add_expense(budget, "Utilities", 150);
    add_income(budget, "Salary", 2500);
    add_income(budget, "Investments", 100);
    print_budget(budget);
    free_budget(budget);
    return 0;
}