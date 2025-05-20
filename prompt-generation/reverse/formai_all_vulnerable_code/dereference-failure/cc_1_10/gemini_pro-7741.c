//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the shock factor
#define SHOCK_FACTOR 10

// Define the income and expense categories
enum category_t {
    INCOME,
    EXPENSE
};

// Define the income and expense types
enum type_t {
    SALARY,
    BONUS,
    RENT,
    UTILITIES,
    GROCERIES
};

// Define the transaction struct
typedef struct transaction_t {
    enum category_t category;
    enum type_t type;
    char* description;
    double amount;
} transaction_t;

// Declare the global variables
transaction_t* transactions;
int num_transactions;

// Declare the functions
void add_transaction(enum category_t category, enum type_t type, char* description, double amount);
void print_transactions();
void calculate_net_worth();

// Main function
int main() {
    // Initialize the global variables
    transactions = NULL;
    num_transactions = 0;

    // Add some sample transactions
    add_transaction(INCOME, SALARY, "Paycheck", 5000.00);
    add_transaction(EXPENSE, RENT, "Rent", 1200.00);
    add_transaction(EXPENSE, UTILITIES, "Utilities", 200.00);
    add_transaction(EXPENSE, GROCERIES, "Groceries", 300.00);

    // Print the transactions
    print_transactions();

    // Calculate the net worth
    calculate_net_worth();

    return 0;
}

// Add a transaction to the list of transactions
void add_transaction(enum category_t category, enum type_t type, char* description, double amount) {
    // Allocate memory for the new transaction
    transaction_t* new_transaction = malloc(sizeof(transaction_t));

    // Set the values of the new transaction
    new_transaction->category = category;
    new_transaction->type = type;
    new_transaction->description = description;
    new_transaction->amount = amount;

    // Add the new transaction to the list of transactions
    transactions = realloc(transactions, (num_transactions + 1) * sizeof(transaction_t));
    transactions[num_transactions] = *new_transaction;
    num_transactions++;
}

// Print the list of transactions
void print_transactions() {
    // Print the header
    printf("Transactions:\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Category | Type | Description | Amount | Date | Time |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Print each transaction
    for (int i = 0; i < num_transactions; i++) {
        printf("| %s | %s | %s | %.2f | %s | %s |\n",
            transactions[i].category == INCOME ? "Income" : "Expense",
            transactions[i].type == SALARY ? "Salary" : transactions[i].type == BONUS ? "Bonus" : transactions[i].type == RENT ? "Rent" : transactions[i].type == UTILITIES ? "Utilities" : transactions[i].type == GROCERIES ? "Groceries" : "Other",
            transactions[i].description,
            transactions[i].amount,
            "2023-03-08",
            "12:00:00 PM");
    }

    // Print the footer
    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

// Calculate the net worth
void calculate_net_worth() {
    // Calculate the total income
    double total_income = 0.0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].category == INCOME) {
            total_income += transactions[i].amount;
        }
    }

    // Calculate the total expenses
    double total_expenses = 0.0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].category == EXPENSE) {
            total_expenses += transactions[i].amount;
        }
    }

    // Calculate the net worth
    double net_worth = total_income - total_expenses;

    // Print the net worth
    printf("Net worth: %.2f\n", net_worth);
}