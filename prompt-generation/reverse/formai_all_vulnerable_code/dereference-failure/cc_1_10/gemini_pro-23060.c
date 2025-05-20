//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct income {
    char *source;
    double amount;
};

struct expense {
    char *category;
    double amount;
};

struct budget {
    struct income *incomes;
    int num_incomes;
    struct expense *expenses;
    int num_expenses;
};

void print_budget(struct budget *budget) {
    printf("Incomes:\n");
    for (int i = 0; i < budget->num_incomes; i++) {
        printf("    %s: %0.2f\n", budget->incomes[i].source, budget->incomes[i].amount);
    }

    printf("Expenses:\n");
    for (int i = 0; i < budget->num_expenses; i++) {
        printf("    %s: %0.2f\n", budget->expenses[i].category, budget->expenses[i].amount);
    }
}

int main() {
    // Initialize the budget
    struct budget budget;
    budget.incomes = malloc(sizeof(struct income) * 3);
    budget.num_incomes = 3;
    budget.expenses = malloc(sizeof(struct expense) * 4);
    budget.num_expenses = 4;

    // Set the incomes
    budget.incomes[0].source = "Salary";
    budget.incomes[0].amount = 5000.00;
    budget.incomes[1].source = "Investments";
    budget.incomes[1].amount = 1000.00;
    budget.incomes[2].source = "Other";
    budget.incomes[2].amount = 500.00;

    // Set the expenses
    budget.expenses[0].category = "Rent";
    budget.expenses[0].amount = 1500.00;
    budget.expenses[1].category = "Food";
    budget.expenses[1].amount = 1000.00;
    budget.expenses[2].category = "Transportation";
    budget.expenses[2].amount = 500.00;
    budget.expenses[3].category = "Other";
    budget.expenses[3].amount = 1000.00;

    // Print the budget
    print_budget(&budget);

    return 0;
}