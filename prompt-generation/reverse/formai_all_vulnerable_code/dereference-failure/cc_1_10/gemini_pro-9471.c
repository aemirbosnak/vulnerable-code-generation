//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a single transaction
typedef struct Transaction {
    char* description;
    double amount;
    int day;
    int month;
    int year;
} Transaction;

// Define a struct to represent a list of transactions
typedef struct TransactionList {
    int numTransactions;
    Transaction* transactions;
} TransactionList;

// Create a new transaction
Transaction* createTransaction(char* description, double amount, int day, int month, int year) {
    Transaction* transaction = malloc(sizeof(Transaction));
    transaction->description = malloc(strlen(description) + 1);
    strcpy(transaction->description, description);
    transaction->amount = amount;
    transaction->day = day;
    transaction->month = month;
    transaction->year = year;
    return transaction;
}

// Add a transaction to a list of transactions
void addTransaction(TransactionList* list, Transaction* transaction) {
    list->numTransactions++;
    list->transactions = realloc(list->transactions, list->numTransactions * sizeof(Transaction));
    list->transactions[list->numTransactions - 1] = *transaction;
}

// Print a list of transactions
void printTransactions(TransactionList* list) {
    for (int i = 0; i < list->numTransactions; i++) {
        printf("%s: $%.2f (%d/%d/%d)\n", list->transactions[i].description, list->transactions[i].amount, list->transactions[i].day, list->transactions[i].month, list->transactions[i].year);
    }
}

// Get the total amount of money spent in a list of transactions
double getTotalAmount(TransactionList* list) {
    double total = 0;
    for (int i = 0; i < list->numTransactions; i++) {
        total += list->transactions[i].amount;
    }
    return total;
}

// Get the average amount of money spent in a list of transactions
double getAverageAmount(TransactionList* list) {
    double total = getTotalAmount(list);
    return total / list->numTransactions;
}

// Get the minimum amount of money spent in a list of transactions
double getMinAmount(TransactionList* list) {
    double min = list->transactions[0].amount;
    for (int i = 1; i < list->numTransactions; i++) {
        if (list->transactions[i].amount < min) {
            min = list->transactions[i].amount;
        }
    }
    return min;
}

// Get the maximum amount of money spent in a list of transactions
double getMaxAmount(TransactionList* list) {
    double max = list->transactions[0].amount;
    for (int i = 1; i < list->numTransactions; i++) {
        if (list->transactions[i].amount > max) {
            max = list->transactions[i].amount;
        }
    }
    return max;
}

// Get the most frequent transaction description in a list of transactions
char* getMostFrequentDescription(TransactionList* list) {
    char* mostFrequentDescription = NULL;
    int maxFrequency = 0;
    for (int i = 0; i < list->numTransactions; i++) {
        int frequency = 0;
        for (int j = 0; j < list->numTransactions; j++) {
            if (strcmp(list->transactions[i].description, list->transactions[j].description) == 0) {
                frequency++;
            }
        }
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
            mostFrequentDescription = list->transactions[i].description;
        }
    }
    return mostFrequentDescription;
}

// Get the average amount of money spent per day in a list of transactions
double getAverageAmountPerDay(TransactionList* list) {
    int totalDays = 0;
    for (int i = 0; i < list->numTransactions; i++) {
        totalDays += list->transactions[i].day;
    }
    return getTotalAmount(list) / totalDays;
}

// Get the average amount of money spent per month in a list of transactions
double getAverageAmountPerMonth(TransactionList* list) {
    int totalMonths = 0;
    for (int i = 0; i < list->numTransactions; i++) {
        totalMonths += list->transactions[i].month;
    }
    return getTotalAmount(list) / totalMonths;
}

// Get the average amount of money spent per year in a list of transactions
double getAverageAmountPerYear(TransactionList* list) {
    int totalYears = 0;
    for (int i = 0; i < list->numTransactions; i++) {
        totalYears += list->transactions[i].year;
    }
    return getTotalAmount(list) / totalYears;
}

// Main function
int main() {
    // Create a new transaction list
    TransactionList* list = malloc(sizeof(TransactionList));
    list->numTransactions = 0;
    list->transactions = NULL;

    // Add some transactions to the list
    addTransaction(list, createTransaction("Groceries", 50.00, 1, 1, 2023));
    addTransaction(list, createTransaction("Gas", 25.00, 5, 1, 2023));
    addTransaction(list, createTransaction("Rent", 1000.00, 10, 1, 2023));
    addTransaction(list, createTransaction("Entertainment", 50.00, 15, 1, 2023));
    addTransaction(list, createTransaction("Savings", 200.00, 20, 1, 2023));

    // Print the list of transactions
    printf("Your transactions:\n");
    printTransactions(list);

    // Get the total amount of money spent
    double totalAmount = getTotalAmount(list);
    printf("Total amount spent: $%.2f\n", totalAmount);

    // Get the average amount of money spent
    double averageAmount = getAverageAmount(list);
    printf("Average amount spent: $%.2f\n", averageAmount);

    // Get the minimum amount of money spent
    double minAmount = getMinAmount(list);
    printf("Minimum amount spent: $%.2f\n", minAmount);

    // Get the maximum amount of money spent
    double maxAmount = getMaxAmount(list);
    printf("Maximum amount spent: $%.2f\n", maxAmount);

    // Get the most frequent transaction description
    char* mostFrequentDescription = getMostFrequentDescription(list);
    printf("Most frequent transaction description: %s\n", mostFrequentDescription);

    // Get the average amount of money spent per day
    double averageAmountPerDay = getAverageAmountPerDay(list);
    printf("Average amount spent per day: $%.2f\n", averageAmountPerDay);

    // Get the average amount of money spent per month
    double averageAmountPerMonth = getAverageAmountPerMonth(list);
    printf("Average amount spent per month: $%.2f\n", averageAmountPerMonth);

    // Get the average amount of money spent per year
    double averageAmountPerYear = getAverageAmountPerYear(list);
    printf("Average amount spent per year: $%.2f\n", averageAmountPerYear);

    // Free the memory allocated for the transaction list
    for (int i = 0; i < list->numTransactions; i++) {
        free(list->transactions[i].description);
    }
    free(list->transactions);
    free(list);

    return 0;
}