//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char* description;
    float amount;
};

struct income {
    char* source;
    float amount;
};

struct budget {
    struct expense* expenses;
    int num_expenses;
    struct income* incomes;
    int num_incomes;
};

void add_expense(struct budget* budget, char* description, float amount) {
    budget->expenses = realloc(budget->expenses, (budget->num_expenses + 1) * sizeof(struct expense));
    budget->expenses[budget->num_expenses].description = description;
    budget->expenses[budget->num_expenses].amount = amount;
    budget->num_expenses++;
}

void add_income(struct budget* budget, char* source, float amount) {
    budget->incomes = realloc(budget->incomes, (budget->num_incomes + 1) * sizeof(struct income));
    budget->incomes[budget->num_incomes].source = source;
    budget->incomes[budget->num_incomes].amount = amount;
    budget->num_incomes++;
}

void print_budget(struct budget* budget) {
    printf("Expenses:\n");
    for (int i = 0; i < budget->num_expenses; i++) {
        printf("  %s: $%.2f\n", budget->expenses[i].description, budget->expenses[i].amount);
    }

    printf("Incomes:\n");
    for (int i = 0; i < budget->num_incomes; i++) {
        printf("  %s: $%.2f\n", budget->incomes[i].source, budget->incomes[i].amount);
    }

    float total_expenses = 0;
    for (int i = 0; i < budget->num_expenses; i++) {
        total_expenses += budget->expenses[i].amount;
    }

    float total_incomes = 0;
    for (int i = 0; i < budget->num_incomes; i++) {
        total_incomes += budget->incomes[i].amount;
    }

    float balance = total_incomes - total_expenses;
    printf("Balance: $%.2f\n", balance);
}

int main() {
    struct budget budget;
    budget.expenses = NULL;
    budget.num_expenses = 0;
    budget.incomes = NULL;
    budget.num_incomes = 0;

    add_expense(&budget, "Rent", 1200);
    add_expense(&budget, "Groceries", 300);
    add_expense(&budget, "Utilities", 150);
    add_expense(&budget, "Transportation", 200);
    add_expense(&budget, "Entertainment", 100);

    add_income(&budget, "Salary", 2500);
    add_income(&budget, "Investments", 500);

    print_budget(&budget);

    return 0;
}