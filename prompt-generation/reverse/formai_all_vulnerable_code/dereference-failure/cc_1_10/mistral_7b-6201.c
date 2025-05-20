//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of transactions and the maximum length of a transaction description
#define MAX_TRANSACTIONS 100
#define MAX_DESCRIPTION_LENGTH 50

// Define a struct for a transaction
typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    struct Transaction *next;
} Transaction;

// Define a global variable for the head of the transaction list
Transaction *transactions = NULL;

// Function to add a new transaction to the list
void addTransaction(char *description, float amount) {
    Transaction *newTransaction = (Transaction *) malloc(sizeof(Transaction));
    strcpy(newTransaction->description, description);
    newTransaction->amount = amount;
    newTransaction->next = transactions;
    transactions = newTransaction;
}

// Function to display the current balance and the list of transactions
void displayTransactions() {
    float balance = 0.0;
    Transaction *currentTransaction = transactions;

    printf("Current Balance: %.2f\n", balance);
    printf("----------------------------------\n");
    printf("| Description                | Amount |\n");
    printf("----------------------------------\n");

    while (currentTransaction != NULL) {
        balance += currentTransaction->amount;
        printf("| %-40s | %.2f |\n", currentTransaction->description, currentTransaction->amount);
        currentTransaction = currentTransaction->next;
    }

    printf("----------------------------------\n");
}

int main() {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;

    // Example transactions
    addTransaction("Groceries", 50.0);
    addTransaction("Gasoline", 30.0);
    addTransaction("Dinner out", 75.0);

    // Display the current balance and the list of transactions
    displayTransactions();

    // Add a new transaction and display the updated balance and transactions
    printf("Enter transaction description: ");
    scanf("%s", description);
    printf("Enter transaction amount: ");
    scanf("%f", &amount);
    addTransaction(description, amount);
    displayTransactions();

    return 0;
}