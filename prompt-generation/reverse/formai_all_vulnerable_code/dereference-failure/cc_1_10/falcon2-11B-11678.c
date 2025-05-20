//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct for a transaction
typedef struct transaction {
    int date;
    float amount;
    int category;
} Transaction;

// Define a function to add a transaction
void addTransaction(Transaction* transaction) {
    printf("Add a new transaction:\n");
    printf("Date: ");
    scanf("%d", &transaction->date);
    printf("Amount: ");
    scanf("%f", &transaction->amount);
    printf("Category: ");
    scanf("%d", &transaction->category);
    printf("Transaction added successfully.\n");
}

// Define a function to display all transactions
void displayTransactions(Transaction* transactions, int count) {
    for (int i = 0; i < count; i++) {
        printf("Date: %d\n", transactions[i].date);
        printf("Amount: %f\n", transactions[i].amount);
        printf("Category: %d\n", transactions[i].category);
        printf("\n");
    }
}

// Define a function to calculate total expenses
float calculateTotalExpenses(Transaction* transactions, int count) {
    float totalExpenses = 0.0;
    for (int i = 0; i < count; i++) {
        totalExpenses += transactions[i].amount;
    }
    return totalExpenses;
}

// Define a function to calculate total income
float calculateTotalIncome(Transaction* transactions, int count) {
    float totalIncome = 0.0;
    for (int i = 0; i < count; i++) {
        totalIncome += transactions[i].amount;
    }
    return totalIncome;
}

// Define a function to calculate net income
float calculateNetIncome(Transaction* transactions, int count) {
    float totalIncome = calculateTotalIncome(transactions, count);
    float totalExpenses = calculateTotalExpenses(transactions, count);
    return totalIncome - totalExpenses;
}

int main() {
    Transaction* transactions = malloc(100 * sizeof(Transaction));
    
    // Add some transactions
    addTransaction(transactions);
    addTransaction(transactions);
    addTransaction(transactions);
    
    // Display all transactions
    displayTransactions(transactions, 3);
    
    // Calculate total expenses
    float totalExpenses = calculateTotalExpenses(transactions, 3);
    
    // Calculate total income
    float totalIncome = calculateTotalIncome(transactions, 3);
    
    // Calculate net income
    float netIncome = calculateNetIncome(transactions, 3);
    
    printf("Total expenses: %f\n", totalExpenses);
    printf("Total income: %f\n", totalIncome);
    printf("Net income: %f\n", netIncome);
    
    // Free allocated memory
    free(transactions);
    
    return 0;
}