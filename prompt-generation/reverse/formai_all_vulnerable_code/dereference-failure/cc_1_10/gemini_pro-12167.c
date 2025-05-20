//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: random
// Personal Finance Planner in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Income {
    char *source;
    float amount;
};

struct Expense {
    char *category;
    float amount;
};

struct Budget {
    float income;
    float expenses;
    float savings;
};

int main() {
    // Create a budget
    struct Budget budget;
    budget.income = 0;
    budget.expenses = 0;
    budget.savings = 0;

    // Add income
    int num_incomes;
    printf("Enter the number of income sources: ");
    scanf("%d", &num_incomes);

    struct Income *incomes = malloc(sizeof(struct Income) * num_incomes);
    for (int i = 0; i < num_incomes; i++) {
        printf("Enter income source: ");
        char *source = malloc(256);
        scanf("%s", source);

        printf("Enter income amount: ");
        float amount;
        scanf("%f", &amount);

        incomes[i].source = source;
        incomes[i].amount = amount;

        budget.income += amount;
    }

    // Add expenses
    int num_expenses;
    printf("Enter the number of expense categories: ");
    scanf("%d", &num_expenses);

    struct Expense *expenses = malloc(sizeof(struct Expense) * num_expenses);
    for (int i = 0; i < num_expenses; i++) {
        printf("Enter expense category: ");
        char *category = malloc(256);
        scanf("%s", category);

        printf("Enter expense amount: ");
        float amount;
        scanf("%f", &amount);

        expenses[i].category = category;
        expenses[i].amount = amount;

        budget.expenses += amount;
    }

    // Calculate savings
    budget.savings = budget.income - budget.expenses;

    // Print budget
    printf("\nBudget Summary:\n");
    printf("Income: $%.2f\n", budget.income);
    printf("Expenses: $%.2f\n", budget.expenses);
    printf("Savings: $%.2f\n", budget.savings);

    // Free memory
    for (int i = 0; i < num_incomes; i++) {
        free(incomes[i].source);
    }
    free(incomes);

    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i].category);
    }
    free(expenses);

    return 0;
}