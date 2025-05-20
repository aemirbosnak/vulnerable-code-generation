//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for a transaction
typedef struct transaction {
    char date[11];
    char description[51];
    float amount;
    char type[11];
} transaction;

// Define the struct for a budget category
typedef struct budget_category {
    char name[21];
    float budgeted_amount;
    float actual_amount;
} budget_category;

// Define the struct for the personal finance planner
typedef struct personal_finance_planner {
    char name[21];
    float starting_balance;
    float current_balance;
    transaction transactions[100];
    int num_transactions;
    budget_category budget_categories[10];
    int num_budget_categories;
} personal_finance_planner;

// Function to create a new personal finance planner
personal_finance_planner* create_personal_finance_planner(char* name, float starting_balance) {
    personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
    strcpy(planner->name, name);
    planner->starting_balance = starting_balance;
    planner->current_balance = starting_balance;
    planner->num_transactions = 0;
    planner->num_budget_categories = 0;
    return planner;
}

// Function to add a transaction to a personal finance planner
void add_transaction(personal_finance_planner* planner, char* date, char* description, float amount, char* type) {
    strcpy(planner->transactions[planner->num_transactions].date, date);
    strcpy(planner->transactions[planner->num_transactions].description, description);
    planner->transactions[planner->num_transactions].amount = amount;
    strcpy(planner->transactions[planner->num_transactions].type, type);
    planner->num_transactions++;
    
    // Update the current balance
    if (strcmp(type, "Income") == 0) {
        planner->current_balance += amount;
    } else {
        planner->current_balance -= amount;
    }
}

// Function to add a budget category to a personal finance planner
void add_budget_category(personal_finance_planner* planner, char* name, float budgeted_amount) {
    strcpy(planner->budget_categories[planner->num_budget_categories].name, name);
    planner->budget_categories[planner->num_budget_categories].budgeted_amount = budgeted_amount;
    planner->budget_categories[planner->num_budget_categories].actual_amount = 0;
    planner->num_budget_categories++;
}

// Function to print the transactions for a personal finance planner
void print_transactions(personal_finance_planner* planner) {
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s %s %.2f %s\n", planner->transactions[i].date, planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
}

// Function to print the budget categories for a personal finance planner
void print_budget_categories(personal_finance_planner* planner) {
    printf("Budget Categories:\n");
    for (int i = 0; i < planner->num_budget_categories; i++) {
        printf("%s %.2f %.2f\n", planner->budget_categories[i].name, planner->budget_categories[i].budgeted_amount, planner->budget_categories[i].actual_amount);
    }
}

// Function to print the summary for a personal finance planner
void print_summary(personal_finance_planner* planner) {
    printf("Summary:\n");
    printf("Name: %s\n", planner->name);
    printf("Starting Balance: %.2f\n", planner->starting_balance);
    printf("Current Balance: %.2f\n", planner->current_balance);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_personal_finance_planner("My Planner", 1000.00);

    // Add some transactions to the planner
    add_transaction(planner, "2023-01-01", "Salary", 2000.00, "Income");
    add_transaction(planner, "2023-01-05", "Rent", -500.00, "Expense");
    add_transaction(planner, "2023-01-10", "Groceries", -100.00, "Expense");
    add_transaction(planner, "2023-01-15", "Entertainment", -50.00, "Expense");
    add_transaction(planner, "2023-01-20", "Savings", -200.00, "Expense");

    // Add some budget categories to the planner
    add_budget_category(planner, "Groceries", 200.00);
    add_budget_category(planner, "Entertainment", 100.00);
    add_budget_category(planner, "Savings", 500.00);

    // Print the transactions
    print_transactions(planner);

    // Print the budget categories
    print_budget_categories(planner);

    // Print the summary
    print_summary(planner);

    return 0;
}