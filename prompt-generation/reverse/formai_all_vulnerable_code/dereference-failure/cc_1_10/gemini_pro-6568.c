//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an expense
typedef struct {
    char *description;
    double amount;
    int day;
    int month;
    int year;
} Expense;

// Define the structure of a personal finance plan
typedef struct {
    char *name;
    double income;
    double expenses;
    Expense *expenses_list;
    int num_expenses;
} PersonalFinancePlan;

// Create a new personal finance plan
PersonalFinancePlan *create_personal_finance_plan(char *name, double income) {
    PersonalFinancePlan *plan = malloc(sizeof(PersonalFinancePlan));
    plan->name = strdup(name);
    plan->income = income;
    plan->expenses = 0;
    plan->expenses_list = NULL;
    plan->num_expenses = 0;
    return plan;
}

// Add an expense to a personal finance plan
void add_expense(PersonalFinancePlan *plan, char *description, double amount, int day, int month, int year) {
    Expense *expense = malloc(sizeof(Expense));
    expense->description = strdup(description);
    expense->amount = amount;
    expense->day = day;
    expense->month = month;
    expense->year = year;

    plan->expenses += amount;
    plan->expenses_list = realloc(plan->expenses_list, (plan->num_expenses + 1) * sizeof(Expense));
    plan->expenses_list[plan->num_expenses] = *expense;
    plan->num_expenses++;
}

// Print a personal finance plan
void print_personal_finance_plan(PersonalFinancePlan *plan) {
    printf("Personal Finance Plan for %s\n", plan->name);
    printf("Income: $%.2f\n", plan->income);
    printf("Expenses: $%.2f\n", plan->expenses);
    for (int i = 0; i < plan->num_expenses; i++) {
        printf("  %s: $%.2f (%d/%d/%d)\n", plan->expenses_list[i].description, plan->expenses_list[i].amount, plan->expenses_list[i].day, plan->expenses_list[i].month, plan->expenses_list[i].year);
    }
}

// Free the memory allocated for a personal finance plan
void free_personal_finance_plan(PersonalFinancePlan *plan) {
    free(plan->name);
    for (int i = 0; i < plan->num_expenses; i++) {
        free(plan->expenses_list[i].description);
    }
    free(plan->expenses_list);
    free(plan);
}

int main() {
    // Create a new personal finance plan
    PersonalFinancePlan *plan = create_personal_finance_plan("John Doe", 5000);

    // Add some expenses to the plan
    add_expense(plan, "Rent", 1000, 1, 1, 2023);
    add_expense(plan, "Groceries", 500, 7, 1, 2023);
    add_expense(plan, "Utilities", 200, 15, 1, 2023);
    add_expense(plan, "Entertainment", 100, 22, 1, 2023);

    // Print the personal finance plan
    print_personal_finance_plan(plan);

    // Free the memory allocated for the personal finance plan
    free_personal_finance_plan(plan);

    return 0;
}