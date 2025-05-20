//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char *name;
    float amount;
    struct expense *next;
};

struct income {
    char *source;
    float amount;
    struct income *next;
};

struct budget {
    struct expense *expenses;
    struct income *incomes;
};

void add_expense(struct budget *budget, char *name, float amount) {
    struct expense *new_expense = malloc(sizeof(struct expense));
    new_expense->name = malloc(strlen(name) + 1);
    strcpy(new_expense->name, name);
    new_expense->amount = amount;
    new_expense->next = budget->expenses;
    budget->expenses = new_expense;
}

void add_income(struct budget *budget, char *source, float amount) {
    struct income *new_income = malloc(sizeof(struct income));
    new_income->source = malloc(strlen(source) + 1);
    strcpy(new_income->source, source);
    new_income->amount = amount;
    new_income->next = budget->incomes;
    budget->incomes = new_income;
}

float calculate_total_expenses(struct budget *budget) {
    float total = 0;
    struct expense *current = budget->expenses;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

float calculate_total_incomes(struct budget *budget) {
    float total = 0;
    struct income *current = budget->incomes;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

float calculate_net_income(struct budget *budget) {
    return calculate_total_incomes(budget) - calculate_total_expenses(budget);
}

void print_budget(struct budget *budget) {
    printf("Expenses:\n");
    struct expense *current = budget->expenses;
    while (current != NULL) {
        printf(" - %s: $%.2f\n", current->name, current->amount);
        current = current->next;
    }
    printf("Incomes:\n");
    struct income *current_income = budget->incomes;
    while (current_income != NULL) {
        printf(" - %s: $%.2f\n", current_income->source, current_income->amount);
        current_income = current_income->next;
    }
    printf("Net income: $%.2f\n", calculate_net_income(budget));
}

int main() {
    struct budget budget;
    budget.expenses = NULL;
    budget.incomes = NULL;
    add_expense(&budget, "Rent", 1000);
    add_expense(&budget, "Groceries", 200);
    add_expense(&budget, "Utilities", 150);
    add_income(&budget, "Salary", 2500);
    add_income(&budget, "Investments", 100);
    print_budget(&budget);
    return 0;
}