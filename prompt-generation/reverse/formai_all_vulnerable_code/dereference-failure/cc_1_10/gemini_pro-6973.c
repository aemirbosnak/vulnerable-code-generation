//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define the struct for each transaction
typedef struct {
    char *description;
    double amount;
    int type; // 0 for expense, 1 for income
} transaction;

// Define the struct for the personal finance planner
typedef struct {
    char *name;
    double balance;
    int num_transactions;
    transaction *transactions;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner *new_personal_finance_planner(char *name) {
    personal_finance_planner *planner = malloc(sizeof(personal_finance_planner));
    planner->name = name;
    planner->balance = 0;
    planner->num_transactions = 0;
    planner->transactions = NULL;
    return planner;
}

// Add a new transaction to the personal finance planner
void add_transaction(personal_finance_planner *planner, char *description, double amount, int type) {
    // Reallocate memory for the transactions array if necessary
    if (planner->num_transactions % 10 == 0) {
        planner->transactions = realloc(planner->transactions, (planner->num_transactions + 10) * sizeof(transaction));
    }

    // Add the new transaction to the array
    planner->transactions[planner->num_transactions].description = description;
    planner->transactions[planner->num_transactions].amount = amount;
    planner->transactions[planner->num_transactions].type = type;
    planner->num_transactions++;

    // Update the balance
    if (type == 0) {
        planner->balance -= amount;
    } else {
        planner->balance += amount;
    }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner *planner) {
    printf("Name: %s\n", planner->name);
    printf("Balance: $%.2f\n", planner->balance);
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  %s: $%.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner *planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        free(planner->transactions[i].description);
    }
    free(planner->transactions);
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner *planner = new_personal_finance_planner("John Doe");

    // Add some transactions to the planner
    add_transaction(planner, "Salary", 2000, 1);
    add_transaction(planner, "Rent", 1000, 0);
    add_transaction(planner, "Groceries", 200, 0);
    add_transaction(planner, "Entertainment", 100, 0);
    add_transaction(planner, "Savings", 500, 1);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}