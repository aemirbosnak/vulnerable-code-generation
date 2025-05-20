//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *description;
    double amount;
} transaction;

int main() {
    // Initialize the list of transactions
    transaction *transactions = NULL;
    int num_transactions = 0;

    // Get the user's input
    char input[1024];
    printf("Enter your transactions (one per line):\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Parse the input
        char *name = strtok(input, ",");
        char *description = strtok(NULL, ",");
        double amount = atof(strtok(NULL, ","));

        // Create a new transaction
        transaction *new_transaction = malloc(sizeof(transaction));
        new_transaction->name = strdup(name);
        new_transaction->description = strdup(description);
        new_transaction->amount = amount;

        // Add the new transaction to the list of transactions
        transactions = realloc(transactions, (num_transactions + 1) * sizeof(transaction));
        transactions[num_transactions] = *new_transaction;
        num_transactions++;
    }

    // Calculate the total amount of the transactions
    double total_amount = 0;
    for (int i = 0; i < num_transactions; i++) {
        total_amount += transactions[i].amount;
    }

    // Print the list of transactions
    printf("\nYour transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s, %s, %f\n", transactions[i].name, transactions[i].description, transactions[i].amount);
    }

    // Print the total amount of the transactions
    printf("\nTotal amount: %f\n", total_amount);

    // Free the memory allocated for the transactions
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].name);
        free(transactions[i].description);
    }
    free(transactions);

    return 0;
}