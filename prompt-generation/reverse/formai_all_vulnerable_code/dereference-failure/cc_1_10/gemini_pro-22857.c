//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of categories and transactions
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

// Define the category names
char *categories[MAX_CATEGORIES] = {
    "Rent",
    "Utilities",
    "Food",
    "Transportation",
    "Entertainment",
    "Personal Care",
    "Shopping",
    "Savings",
    "Investments",
    "Other"
};

// Define the transaction structure
typedef struct {
    char *description;
    double amount;
    char *category;
} transaction_t;

// Define the personal finance planner structure
typedef struct {
    double income;
    double expenses[MAX_CATEGORIES];
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t *create_personal_finance_planner() {
    personal_finance_planner_t *planner = malloc(sizeof(personal_finance_planner_t));
    if (planner == NULL) {
        return NULL;
    }

    planner->income = 0.0;
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        planner->expenses[i] = 0.0;
    }
    planner->num_transactions = 0;

    return planner;
}

// Free the memory allocated for a personal finance planner
void free_personal_finance_planner(personal_finance_planner_t *planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        free(planner->transactions[i].description);
        free(planner->transactions[i].category);
    }

    free(planner);
}

// Add a transaction to a personal finance planner
bool add_transaction(personal_finance_planner_t *planner, char *description, double amount, char *category) {
    if (planner->num_transactions == MAX_TRANSACTIONS) {
        return false;
    }

    planner->transactions[planner->num_transactions].description = malloc(strlen(description) + 1);
    strcpy(planner->transactions[planner->num_transactions].description, description);
    planner->transactions[planner->num_transactions].amount = amount;
    planner->transactions[planner->num_transactions].category = malloc(strlen(category) + 1);
    strcpy(planner->transactions[planner->num_transactions].category, category);

    planner->num_transactions++;

    return true;
}

// Calculate the total expenses for a personal finance planner
double calculate_total_expenses(personal_finance_planner_t *planner) {
    double total_expenses = 0.0;
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        total_expenses += planner->expenses[i];
    }

    return total_expenses;
}

// Calculate the net income for a personal finance planner
double calculate_net_income(personal_finance_planner_t *planner) {
    return planner->income - calculate_total_expenses(planner);
}

// Print the personal finance planner to the console
void print_personal_finance_planner(personal_finance_planner_t *planner) {
    printf("Personal Finance Planner\n");
    printf("=======================\n");

    printf("Income: $%.2f\n", planner->income);

    printf("Expenses:\n");
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("  %s: $%.2f\n", categories[i], planner->expenses[i]);
    }

    printf("Total Expenses: $%.2f\n", calculate_total_expenses(planner));
    printf("Net Income: $%.2f\n", calculate_net_income(planner));

    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  %s: $%.2f (%s)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].category);
    }
}

// The main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t *planner = create_personal_finance_planner();

    // Set the income
    planner->income = 5000.0;

    // Add some transactions
    add_transaction(planner, "Rent", 1000.0, "Rent");
    add_transaction(planner, "Utilities", 200.0, "Utilities");
    add_transaction(planner, "Food", 300.0, "Food");
    add_transaction(planner, "Transportation", 400.0, "Transportation");
    add_transaction(planner, "Entertainment", 100.0, "Entertainment");
    add_transaction(planner, "Personal Care", 50.0, "Personal Care");
    add_transaction(planner, "Shopping", 200.0, "Shopping");
    add_transaction(planner, "Savings", 500.0, "Savings");
    add_transaction(planner, "Investments", 200.0, "Investments");
    add_transaction(planner, "Other", 100.0, "Other");

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}