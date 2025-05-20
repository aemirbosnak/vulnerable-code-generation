//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction types
#define INCOME 1
#define EXPENSE 2

// Define the transaction categories
#define OTHER 0
#define FOOD 1
#define HOUSING 2
#define TRANSPORTATION 3
#define ENTERTAINMENT 4
#define SAVINGS 5

// Define the struct for a transaction
typedef struct {
    int type;
    int category;
    float amount;
    char *description;
} transaction_t;

// Create an array of transactions
transaction_t transactions[MAX_TRANSACTIONS];

// Create a pointer to the current transaction
transaction_t *current_transaction = NULL;

// Create a function to add a transaction
void add_transaction(int type, int category, float amount, char *description) {
    // Check if the current transaction is NULL
    if (current_transaction == NULL) {
        // If the current transaction is NULL, then create a new transaction
        current_transaction = malloc(sizeof(transaction_t));
    }

    // Set the transaction type
    current_transaction->type = type;

    // Set the transaction category
    current_transaction->category = category;

    // Set the transaction amount
    current_transaction->amount = amount;

    // Set the transaction description
    current_transaction->description = strdup(description);

    // Add the transaction to the array of transactions
    transactions[current_transaction - transactions] = *current_transaction;

    // Increment the current transaction pointer
    current_transaction++;
}

// Create a function to print the transactions
void print_transactions() {
    // Loop through the array of transactions
    for (int i = 0; i < current_transaction - transactions; i++) {
        // Print the transaction type
        if (transactions[i].type == INCOME) {
            printf("Income: ");
        } else {
            printf("Expense: ");
        }

        // Print the transaction category
        switch (transactions[i].category) {
            case FOOD:
                printf("Food: ");
                break;
            case HOUSING:
                printf("Housing: ");
                break;
            case TRANSPORTATION:
                printf("Transportation: ");
                break;
            case ENTERTAINMENT:
                printf("Entertainment: ");
                break;
            case SAVINGS:
                printf("Savings: ");
                break;
            default:
                printf("Other: ");
                break;
        }

        // Print the transaction amount
        printf("$%.2f\n", transactions[i].amount);

        // Print the transaction description
        printf("%s\n", transactions[i].description);
    }
}

// Create a function to calculate the total income
float calculate_total_income() {
    // Create a variable to store the total income
    float total_income = 0;

    // Loop through the array of transactions
    for (int i = 0; i < current_transaction - transactions; i++) {
        // If the transaction type is income, then add the transaction amount to the total income
        if (transactions[i].type == INCOME) {
            total_income += transactions[i].amount;
        }
    }

    // Return the total income
    return total_income;
}

// Create a function to calculate the total expenses
float calculate_total_expenses() {
    // Create a variable to store the total expenses
    float total_expenses = 0;

    // Loop through the array of transactions
    for (int i = 0; i < current_transaction - transactions; i++) {
        // If the transaction type is expense, then add the transaction amount to the total expenses
        if (transactions[i].type == EXPENSE) {
            total_expenses += transactions[i].amount;
        }
    }

    // Return the total expenses
    return total_expenses;
}

// Create a function to calculate the net income
float calculate_net_income() {
    // Create a variable to store the net income
    float net_income = 0;

    // Calculate the total income
    float total_income = calculate_total_income();

    // Calculate the total expenses
    float total_expenses = calculate_total_expenses();

    // Calculate the net income
    net_income = total_income - total_expenses;

    // Return the net income
    return net_income;
}

// Create a function to print the financial report
void print_financial_report() {
    // Print the total income
    printf("Total Income: $%.2f\n", calculate_total_income());

    // Print the total expenses
    printf("Total Expenses: $%.2f\n", calculate_total_expenses());

    // Print the net income
    printf("Net Income: $%.2f\n", calculate_net_income());
}

// Create a function to main
int main() {
    // Add some sample transactions
    add_transaction(INCOME, FOOD, 100.00, "Groceries");
    add_transaction(EXPENSE, HOUSING, 200.00, "Rent");
    add_transaction(EXPENSE, TRANSPORTATION, 50.00, "Gas");
    add_transaction(EXPENSE, ENTERTAINMENT, 25.00, "Movies");
    add_transaction(INCOME, SAVINGS, 50.00, "Savings");

    // Print the transactions
    printf("Transactions:\n");
    print_transactions();

    // Print the financial report
    printf("\nFinancial Report:\n");
    print_financial_report();

    // Return 0
    return 0;
}