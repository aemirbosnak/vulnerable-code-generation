//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a transaction
typedef struct {
    char *description;
    double amount;
    char *category;
} Transaction;

// Function to add a transaction to the list
void add_transaction(Transaction **list, int *size, char *description, double amount, char *category) {
    // Allocate memory for the new transaction
    Transaction *new_transaction = (Transaction *) malloc(sizeof(Transaction));

    // Set the values of the new transaction
    new_transaction->description = description;
    new_transaction->amount = amount;
    new_transaction->category = category;

    // Add the new transaction to the list
    (*list)[*size] = *new_transaction;
    (*size)++;
}

// Function to print the list of transactions
void print_transactions(Transaction *list, int size) {
    int i;

    // Loop through the list of transactions
    for (i = 0; i < size; i++) {
        // Print the details of each transaction
        printf("Description: %s\n", list[i].description);
        printf("Amount: $%.2f\n", list[i].amount);
        printf("Category: %s\n\n", list[i].category);
    }
}

// Function to calculate the total income and expenses
double calculate_totals(Transaction *list, int size) {
    double income = 0.0;
    double expenses = 0.0;
    int i;

    // Loop through the list of transactions
    for (i = 0; i < size; i++) {
        // Check if the transaction is income or expense
        if (strcmp(list[i].category, "Income") == 0) {
            income += list[i].amount;
        } else {
            expenses += list[i].amount;
        }
    }

    // Return the total income and expenses
    return income - expenses;
}

int main() {
    Transaction *transactions = NULL;
    int size = 0;

    // Add some sample transactions
    add_transaction(&transactions, &size, "Salary", 2000.00, "Income");
    add_transaction(&transactions, &size, "Groceries", 100.00, "Expense");
    add_transaction(&transactions, &size, "Rent", 800.00, "Expense");
    add_transaction(&transactions, &size, "Utility Bill", 150.00, "Expense");

    // Print the list of transactions
    printf("List of Transactions:\n");
    print_transactions(transactions, size);

    // Calculate the total income and expenses
    double total = calculate_totals(transactions, size);

    // Print the total income and expenses
    printf("\nTotal Income: $%.2f\n", total);

    return 0;
}