//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char* name;
    float amount;
};

struct income {
    char* source;
    float amount;
};

struct budget {
    float totalIncome;
    float totalExpense;
    struct expense* expenses;
    int numExpenses;
    struct income* incomes;
    int numIncomes;
};

void addExpense(struct budget* budget, char* name, float amount) {
    budget->expenses = realloc(budget->expenses, (budget->numExpenses + 1) * sizeof(struct expense));
    budget->expenses[budget->numExpenses].name = malloc(strlen(name) + 1);
    strcpy(budget->expenses[budget->numExpenses].name, name);
    budget->expenses[budget->numExpenses].amount = amount;
    budget->numExpenses++;
    budget->totalExpense += amount;
}

void addIncome(struct budget* budget, char* source, float amount) {
    budget->incomes = realloc(budget->incomes, (budget->numIncomes + 1) * sizeof(struct income));
    budget->incomes[budget->numIncomes].source = malloc(strlen(source) + 1);
    strcpy(budget->incomes[budget->numIncomes].source, source);
    budget->incomes[budget->numIncomes].amount = amount;
    budget->numIncomes++;
    budget->totalIncome += amount;
}

void printBudget(struct budget* budget) {
    printf("Total Income: $%.2f\n", budget->totalIncome);
    printf("Total Expense: $%.2f\n", budget->totalExpense);
    printf("Net Income: $%.2f\n", budget->totalIncome - budget->totalExpense);
    printf("\nExpenses:\n");
    for (int i = 0; i < budget->numExpenses; i++) {
        printf(" - %s: $%.2f\n", budget->expenses[i].name, budget->expenses[i].amount);
    }
    printf("\nIncomes:\n");
    for (int i = 0; i < budget->numIncomes; i++) {
        printf(" - %s: $%.2f\n", budget->incomes[i].source, budget->incomes[i].amount);
    }
}

int main() {
    struct budget budget = {0};

    addExpense(&budget, "Rent", 1000);
    addExpense(&budget, "Groceries", 200);
    addExpense(&budget, "Transportation", 300);
    addExpense(&budget, "Entertainment", 100);

    addIncome(&budget, "Salary", 2000);
    addIncome(&budget, "Investments", 100);

    printBudget(&budget);

    return 0;
}