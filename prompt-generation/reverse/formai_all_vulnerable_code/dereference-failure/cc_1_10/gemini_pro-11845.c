//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction structure
typedef struct {
    char description[50];
    float amount;
    char type; // 'I' for income, 'E' for expense
} transaction_t;

// Define the personal finance planner structure
typedef struct {
    char name[50];
    float balance;
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner(char* name) {
    personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
    strcpy(planner->name, name);
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner_t* planner, char* description, float amount, char type) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Too many transactions. Please contact customer support.\n");
        return;
    }

    strcpy(planner->transactions[planner->num_transactions].description, description);
    planner->transactions[planner->num_transactions].amount = amount;
    planner->transactions[planner->num_transactions].type = type;
    planner->num_transactions++;
    
    if(type == 'I') {
      printf("Yay! You earned some money!\n");
    } else if (type == 'E') {
      printf("Oh no! You spent some money!\n");
    } else {
      printf("What the heck is this transaction? I'm confused!\n");
    }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner_t* planner) {
    printf("Personal Finance Planner for %s\n", planner->name);
    printf("Balance: $%.2f\n", planner->balance);
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  %s: $%.2f (%c)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
}

// Destroy the personal finance planner
void destroy_personal_finance_planner(personal_finance_planner_t* planner) {
    free(planner);
}

int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner("John Doe");

    // Add some transactions
    add_transaction(planner, "Salary", 2000.00, 'I');
    add_transaction(planner, "Rent", -1000.00, 'E');
    add_transaction(planner, "Groceries", -200.00, 'E');
    add_transaction(planner, "Coffee", -5.00, 'E');
    add_transaction(planner, "Movies", -20.00, 'E');

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Destroy the personal finance planner
    destroy_personal_finance_planner(planner);

    return 0;
}