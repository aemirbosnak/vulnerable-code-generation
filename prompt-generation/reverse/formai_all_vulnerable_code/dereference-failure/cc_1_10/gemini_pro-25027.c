//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of an expense
typedef struct {
    char *description;
    double amount;
    int day;
    int month;
    int year;
} Expense;

// Define the structure of an income
typedef struct {
    char *description;
    double amount;
    int day;
    int month;
    int year;
} Income;

// Define the structure of a personal finance plan
typedef struct {
    Expense *expenses;
    int num_expenses;
    Income *incomes;
    int num_incomes;
} PersonalFinancePlan;

// Create a new personal finance plan
PersonalFinancePlan *create_personal_finance_plan() {
    PersonalFinancePlan *plan = malloc(sizeof(PersonalFinancePlan));
    plan->expenses = NULL;
    plan->num_expenses = 0;
    plan->incomes = NULL;
    plan->num_incomes = 0;
    return plan;
}

// Add an expense to a personal finance plan
void add_expense(PersonalFinancePlan *plan, Expense *expense) {
    plan->expenses = realloc(plan->expenses, (plan->num_expenses + 1) * sizeof(Expense));
    plan->expenses[plan->num_expenses] = *expense;
    plan->num_expenses++;
}

// Add an income to a personal finance plan
void add_income(PersonalFinancePlan *plan, Income *income) {
    plan->incomes = realloc(plan->incomes, (plan->num_incomes + 1) * sizeof(Income));
    plan->incomes[plan->num_incomes] = *income;
    plan->num_incomes++;
}

// Print a personal finance plan
void print_personal_finance_plan(PersonalFinancePlan *plan) {
    printf("Expenses:\n");
    for (int i = 0; i < plan->num_expenses; i++) {
        printf("  - %s: $%.2f (%d/%d/%d)\n", plan->expenses[i].description, plan->expenses[i].amount, plan->expenses[i].day, plan->expenses[i].month, plan->expenses[i].year);
    }

    printf("Incomes:\n");
    for (int i = 0; i < plan->num_incomes; i++) {
        printf("  - %s: $%.2f (%d/%d/%d)\n", plan->incomes[i].description, plan->incomes[i].amount, plan->incomes[i].day, plan->incomes[i].month, plan->incomes[i].year);
    }
}

// Free the memory allocated for a personal finance plan
void free_personal_finance_plan(PersonalFinancePlan *plan) {
    for (int i = 0; i < plan->num_expenses; i++) {
        free(plan->expenses[i].description);
    }
    free(plan->expenses);

    for (int i = 0; i < plan->num_incomes; i++) {
        free(plan->incomes[i].description);
    }
    free(plan->incomes);

    free(plan);
}

// Main function
int main() {
    // Create a personal finance plan
    PersonalFinancePlan *plan = create_personal_finance_plan();

    // Add some expenses to the plan
    Expense expense1 = {"Rent", 1000.00, 1, 1, 2023};
    add_expense(plan, &expense1);

    Expense expense2 = {"Groceries", 200.00, 5, 1, 2023};
    add_expense(plan, &expense2);

    Expense expense3 = {"Entertainment", 100.00, 10, 1, 2023};
    add_expense(plan, &expense3);

    // Add some incomes to the plan
    Income income1 = {"Salary", 2000.00, 15, 1, 2023};
    add_income(plan, &income1);

    Income income2 = {"Investments", 100.00, 20, 1, 2023};
    add_income(plan, &income2);

    // Print the personal finance plan
    print_personal_finance_plan(plan);

    // Free the memory allocated for the personal finance plan
    free_personal_finance_plan(plan);

    return 0;
}