//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Claude Shannon
/* Claude Shannon's Personal Finance Planner */

#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

/* Data structures */
typedef struct Transaction {
    char *date;
    char *description;
    float amount;
} Transaction;

typedef struct Category {
    char *name;
    float total;
} Category;

/* Function declarations */
void add_transaction(Transaction **transactions, int *num_transactions, Transaction transaction);
void add_category(Category **categories, int *num_categories, Category category);
void print_transactions(Transaction *transactions, int num_transactions);
void print_categories(Category *categories, int num_categories);
void free_transactions(Transaction *transactions, int num_transactions);
void free_categories(Category *categories, int num_categories);

/* Main function */
int main() {
    // Initialize variables
    Transaction *transactions = NULL;
    int num_transactions = 0;
    Category *categories = NULL;
    int num_categories = 0;

    // Add some sample transactions
    Transaction transaction1 = {"2023-01-01", "Rent", -1000.00};
    add_transaction(&transactions, &num_transactions, transaction1);
    Transaction transaction2 = {"2023-01-05", "Groceries", -50.00};
    add_transaction(&transactions, &num_transactions, transaction2);
    Transaction transaction3 = {"2023-01-10", "Salary", 2000.00};
    add_transaction(&transactions, &num_transactions, transaction3);

    // Add some sample categories
    Category category1 = {"Rent", 1000.00};
    add_category(&categories, &num_categories, category1);
    Category category2 = {"Groceries", 50.00};
    add_category(&categories, &num_categories, category2);
    Category category3 = {"Salary", 2000.00};
    add_category(&categories, &num_categories, category3);

    // Print the transactions
    printf("Transactions:\n");
    print_transactions(transactions, num_transactions);

    // Print the categories
    printf("\nCategories:\n");
    print_categories(categories, num_categories);

    // Free the memory
    free_transactions(transactions, num_transactions);
    free_categories(categories, num_categories);

    return 0;
}

/* Function definitions */

void add_transaction(Transaction **transactions, int *num_transactions, Transaction transaction) {
    // Allocate memory for the new transaction
    *transactions = realloc(*transactions, (*num_transactions + 1) * sizeof(Transaction));

    // Copy the transaction into the array
    (*transactions)[*num_transactions] = transaction;

    // Increment the number of transactions
    (*num_transactions)++;
}

void add_category(Category **categories, int *num_categories, Category category) {
    // Allocate memory for the new category
    *categories = realloc(*categories, (*num_categories + 1) * sizeof(Category));

    // Copy the category into the array
    (*categories)[*num_categories] = category;

    // Increment the number of categories
    (*num_categories)++;
}

void print_transactions(Transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s %s %f\n", transactions[i].date, transactions[i].description, transactions[i].amount);
    }
}

void print_categories(Category *categories, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        printf("%s %f\n", categories[i].name, categories[i].total);
    }
}

void free_transactions(Transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].date);
        free(transactions[i].description);
    }
    free(transactions);
}

void free_categories(Category *categories, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        free(categories[i].name);
    }
    free(categories);
}