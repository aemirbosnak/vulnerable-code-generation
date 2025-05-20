//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct Transaction {
    char* date;
    char* description;
    int amount;
    char* category;
} Transaction;

// Create an array of transactions
Transaction transactions[MAX_TRANSACTIONS];

// Initialize the number of transactions to 0
int num_transactions = 0;

// Function to add a transaction to the array
void add_transaction(char* date, char* description, int amount, char* category) {
    // Check if the array is full
    if (num_transactions == MAX_TRANSACTIONS) {
        printf("Error: The array of transactions is full.\n");
        return;
    }

    // Allocate memory for the transaction
    Transaction* transaction = (Transaction*)malloc(sizeof(Transaction));

    // Copy the data into the transaction
    transaction->date = strdup(date);
    transaction->description = strdup(description);
    transaction->amount = amount;
    transaction->category = strdup(category);

    // Add the transaction to the array
    transactions[num_transactions++] = *transaction;
}

// Function to print the transactions
void print_transactions() {
    // Iterate over the transactions
    for (int i = 0; i < num_transactions; i++) {
        // Print the transaction
        printf("%s %s %d %s\n", transactions[i].date, transactions[i].description, transactions[i].amount, transactions[i].category);
    }
}

// Function to get the total amount of transactions
int get_total_amount() {
    // Initialize the total amount to 0
    int total_amount = 0;

    // Iterate over the transactions
    for (int i = 0; i < num_transactions; i++) {
        // Add the amount of the transaction to the total amount
        total_amount += transactions[i].amount;
    }

    // Return the total amount
    return total_amount;
}

// Function to get the average amount of transactions
double get_average_amount() {
    // Get the total amount of transactions
    int total_amount = get_total_amount();

    // Calculate the average amount of transactions
    double average_amount = (double)total_amount / num_transactions;

    // Return the average amount
    return average_amount;
}

// Function to get the most frequent category
char* get_most_frequent_category() {
    // Initialize the most frequent category to NULL
    char* most_frequent_category = NULL;

    // Initialize the count of the most frequent category to 0
    int count_most_frequent_category = 0;

    // Iterate over the transactions
    for (int i = 0; i < num_transactions; i++) {
        // Get the category of the transaction
        char* category = transactions[i].category;

        // Initialize the count of the category to 0
        int count_category = 0;

        // Iterate over the transactions
        for (int j = 0; j < num_transactions; j++) {
            // Check if the category of the transaction is the same as the category of the current transaction
            if (strcmp(transactions[j].category, category) == 0) {
                // Increment the count of the category
                count_category++;
            }
        }

        // Check if the count of the category is greater than the count of the most frequent category
        if (count_category > count_most_frequent_category) {
            // Update the most frequent category
            most_frequent_category = category;

            // Update the count of the most frequent category
            count_most_frequent_category = count_category;
        }
    }

    // Return the most frequent category
    return most_frequent_category;
}

// Main function
int main() {
    // Add some transactions to the array
    add_transaction("2023-01-01", "Salary", 1000, "Income");
    add_transaction("2023-01-02", "Groceries", -200, "Food");
    add_transaction("2023-01-03", "Entertainment", -100, "Entertainment");
    add_transaction("2023-01-04", "Gas", -50, "Transportation");
    add_transaction("2023-01-05", "Rent", -800, "Housing");

    // Print the transactions
    print_transactions();

    // Get the total amount of transactions
    int total_amount = get_total_amount();
    printf("Total amount: %d\n", total_amount);

    // Get the average amount of transactions
    double average_amount = get_average_amount();
    printf("Average amount: %.2f\n", average_amount);

    // Get the most frequent category
    char* most_frequent_category = get_most_frequent_category();
    printf("Most frequent category: %s\n", most_frequent_category);

    return 0;
}