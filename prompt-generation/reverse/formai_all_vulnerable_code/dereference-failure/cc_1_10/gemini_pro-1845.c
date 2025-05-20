//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of categories and transactions
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

// Define the structure of a category
typedef struct category {
    char name[50];
    double budget;
    double actual;
} category_t;

// Define the structure of a transaction
typedef struct transaction {
    char date[11];
    char description[50];
    double amount;
    int category_index;
} transaction_t;

// Define the structure of a personal finance planner
typedef struct personal_finance_planner {
    category_t categories[MAX_CATEGORIES];
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_categories;
    int num_transactions;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner() {
    personal_finance_planner_t* planner = (personal_finance_planner_t*)malloc(sizeof(personal_finance_planner_t));
    planner->num_categories = 0;
    planner->num_transactions = 0;
    return planner;
}

// Add a category to the planner
void add_category(personal_finance_planner_t* planner, char* name, double budget) {
    if (planner->num_categories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }
    strcpy(planner->categories[planner->num_categories].name, name);
    planner->categories[planner->num_categories].budget = budget;
    planner->categories[planner->num_categories].actual = 0.0;
    planner->num_categories++;
}

// Add a transaction to the planner
void add_transaction(personal_finance_planner_t* planner, char* date, char* description, double amount, int category_index) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }
    strcpy(planner->transactions[planner->num_transactions].date, date);
    strcpy(planner->transactions[planner->num_transactions].description, description);
    planner->transactions[planner->num_transactions].amount = amount;
    planner->transactions[planner->num_transactions].category_index = category_index;
    planner->num_transactions++;
}

// Print the planner to the console
void print_planner(personal_finance_planner_t* planner) {
    // Print the categories
    printf("Categories:\n");
    for (int i = 0; i < planner->num_categories; i++) {
        printf("  %s: $%.2f / $%.2f\n", planner->categories[i].name, planner->categories[i].actual, planner->categories[i].budget);
    }

    // Print the transactions
    printf("\nTransactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  %s: %s: $%.2f\n", planner->transactions[i].date, planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Free the memory allocated for the planner
void free_planner(personal_finance_planner_t* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner();

    // Add some categories to the planner
    add_category(planner, "Food", 200.00);
    add_category(planner, "Entertainment", 100.00);
    add_category(planner, "Rent", 800.00);

    // Add some transactions to the planner
    add_transaction(planner, "2023-01-01", "Groceries", 50.00, 0);
    add_transaction(planner, "2023-01-05", "Movie tickets", 20.00, 1);
    add_transaction(planner, "2023-01-10", "Rent", 800.00, 2);

    // Print the planner to the console
    print_planner(planner);

    // Free the memory allocated for the planner
    free_planner(planner);

    return 0;
}