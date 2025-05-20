//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Let's define some curious categories for your expenses
#define FRIVOLOUS_FUN "Frivolous Fun"
#define GUILTY_PLEASURES "Guilty Pleasures"
#define NECESSARY_EVILS "Necessary Evils"
#define SAVING_FOR_RAINY_DAYS "Saving for Rainy Days"
#define INVESTING_FOR_SUNNY_TIMES "Investing for Sunny Times"

// Time to set up some colorful characters (structs)
typedef struct {
    char *name;
    double amount;
} Expense;

// Our very own personal finance planner
typedef struct {
    Expense *expenses;
    int num_expenses;
    double total_expenses;
    double total_savings;
    double total_investments;
} FinancePlanner;

// Function to create a new finance planner
FinancePlanner *create_finance_planner() {
    FinancePlanner *planner = malloc(sizeof(FinancePlanner));
    planner->expenses = NULL;
    planner->num_expenses = 0;
    planner->total_expenses = 0;
    planner->total_savings = 0;
    planner->total_investments = 0;
    return planner;
}

// Function to add an expense to the planner
void add_expense(FinancePlanner *planner, char *name, double amount) {
    planner->expenses = realloc(planner->expenses, (planner->num_expenses + 1) * sizeof(Expense));
    planner->expenses[planner->num_expenses].name = name;
    planner->expenses[planner->num_expenses].amount = amount;
    planner->num_expenses++;
    planner->total_expenses += amount;
}

// Function to add savings to the planner
void add_savings(FinancePlanner *planner, double amount) {
    planner->total_savings += amount;
}

// Function to add investments to the planner
void add_investments(FinancePlanner *planner, double amount) {
    planner->total_investments += amount;
}

// Function to print the planner
void print_planner(FinancePlanner *planner) {
    printf("**Personal Finance Planner**\n\n");

    printf("Expenses:\n");
    for (int i = 0; i < planner->num_expenses; i++) {
        printf(" - %s: $%.2f\n", planner->expenses[i].name, planner->expenses[i].amount);
    }

    printf("\nTotal Expenses: $%.2f\n", planner->total_expenses);
    printf("Total Savings: $%.2f\n", planner->total_savings);
    printf("Total Investments: $%.2f\n", planner->total_investments);
}

// Function to free the memory allocated for the planner
void free_planner(FinancePlanner *planner) {
    for (int i = 0; i < planner->num_expenses; i++) {
        free(planner->expenses[i].name);
    }
    free(planner->expenses);
    free(planner);
}

// Let's put our finance planner to work!
int main() {
    // Here's our very own personal finance planner, ready to help us manage our financial adventures
    FinancePlanner *planner = create_finance_planner();

    // Time to add some expenses to our planner
    add_expense(planner, FRIVOLOUS_FUN, 50);
    add_expense(planner, GUILTY_PLEASURES, 20);
    add_expense(planner, NECESSARY_EVILS, 100);

    // Let's not forget about saving for a rainy day
    add_savings(planner, 50);

    // And while we're at it, let's plan for some sunny times by investing
    add_investments(planner, 25);

    // Now, let's see how we're doing
    print_planner(planner);

    // Time to bid farewell to our trusty planner
    free_planner(planner);

    return 0;
}