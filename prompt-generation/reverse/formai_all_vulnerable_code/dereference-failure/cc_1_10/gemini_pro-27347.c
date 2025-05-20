//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Data structure to represent a transaction
typedef struct transaction {
    int id;
    int num_items;
    int *items;
} transaction_t;

// Data structure to represent a frequent itemset
typedef struct frequent_itemset {
    int *items;
    int num_items;
    int support_count;
} frequent_itemset_t;

// Function to create a new transaction
transaction_t *create_transaction(int id, int num_items, int *items) {
    transaction_t *transaction = malloc(sizeof(transaction_t));
    transaction->id = id;
    transaction->num_items = num_items;
    transaction->items = malloc(sizeof(int) * num_items);
    for (int i = 0; i < num_items; i++) {
        transaction->items[i] = items[i];
    }
    return transaction;
}

// Function to create a new frequent itemset
frequent_itemset_t *create_frequent_itemset(int *items, int num_items, int support_count) {
    frequent_itemset_t *frequent_itemset = malloc(sizeof(frequent_itemset_t));
    frequent_itemset->items = malloc(sizeof(int) * num_items);
    for (int i = 0; i < num_items; i++) {
        frequent_itemset->items[i] = items[i];
    }
    frequent_itemset->num_items = num_items;
    frequent_itemset->support_count = support_count;
    return frequent_itemset;
}

// Function to print a transaction
void print_transaction(transaction_t *transaction) {
    printf("Transaction ID: %d, Number of items: %d, Items: ", transaction->id, transaction->num_items);
    for (int i = 0; i < transaction->num_items; i++) {
        printf("%d ", transaction->items[i]);
    }
    printf("\n");
}

// Function to print a frequent itemset
void print_frequent_itemset(frequent_itemset_t *frequent_itemset) {
    printf("Frequent itemset: ");
    for (int i = 0; i < frequent_itemset->num_items; i++) {
        printf("%d ", frequent_itemset->items[i]);
    }
    printf(", Support count: %d\n", frequent_itemset->support_count);
}

// Function to find all frequent itemsets in a set of transactions
void find_frequent_itemsets(transaction_t **transactions, int num_transactions, int min_support) {
    // Create a list of all items in the transactions
    int *items = NULL;
    int num_items = 0;
    for (int i = 0; i < num_transactions; i++) {
        for (int j = 0; j < transactions[i]->num_items; j++) {
            bool found = false;
            for (int k = 0; k < num_items; k++) {
                if (transactions[i]->items[j] == items[k]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                items = realloc(items, sizeof(int) * (num_items + 1));
                items[num_items++] = transactions[i]->items[j];
            }
        }
    }

    // Create a hash table to store the support count for each item
    int *support_counts = malloc(sizeof(int) * num_items);
    for (int i = 0; i < num_items; i++) {
        support_counts[i] = 0;
    }
    for (int i = 0; i < num_transactions; i++) {
        for (int j = 0; j < transactions[i]->num_items; j++) {
            for (int k = 0; k < num_items; k++) {
                if (transactions[i]->items[j] == items[k]) {
                    support_counts[k]++;
                    break;
                }
            }
        }
    }

    // Create a list of all frequent itemsets
    frequent_itemset_t **frequent_itemsets = NULL;
    int num_frequent_itemsets = 0;
    for (int i = 0; i < num_items; i++) {
        if (support_counts[i] >= min_support) {
            frequent_itemsets = realloc(frequent_itemsets, sizeof(frequent_itemset_t *) * (num_frequent_itemsets + 1));
            frequent_itemsets[num_frequent_itemsets++] = create_frequent_itemset(&items[i], 1, support_counts[i]);
        }
    }

    // Print all frequent itemsets
    for (int i = 0; i < num_frequent_itemsets; i++) {
        print_frequent_itemset(frequent_itemsets[i]);
    }

    // Free memory
    free(items);
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i]->items);
        free(transactions[i]);
    }
    free(transactions);
    for (int i = 0; i < num_frequent_itemsets; i++) {
        free(frequent_itemsets[i]->items);
        free(frequent_itemsets[i]);
    }
    free(frequent_itemsets);
}

int main() {
    // Create a set of transactions
    transaction_t *transactions[] = {
        create_transaction(1, 3, (int[]){1, 2, 3}),
        create_transaction(2, 4, (int[]){1, 2, 3, 4}),
        create_transaction(3, 2, (int[]){1, 2}),
        create_transaction(4, 3, (int[]){2, 3, 4}),
        create_transaction(5, 2, (int[]){1, 3}),
    };
    int num_transactions = 5;

    // Find all frequent itemsets with a minimum support of 2
    find_frequent_itemsets(transactions, num_transactions, 2);

    return 0;
}