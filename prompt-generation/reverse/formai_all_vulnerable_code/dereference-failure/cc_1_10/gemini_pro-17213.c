//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a transaction
typedef struct {
    int num_items;
    int *items;
} transaction;

// Function to read transactions from a file
transaction *read_transactions(char *filename, int *num_transactions) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the number of transactions
    fscanf(fp, "%d", num_transactions);

    // Allocate memory for the transactions
    transaction *transactions = malloc(*num_transactions * sizeof(transaction));
    if (transactions == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    // Read the transactions
    for (int i = 0; i < *num_transactions; i++) {
        // Read the number of items in the transaction
        fscanf(fp, "%d", &transactions[i].num_items);

        // Allocate memory for the items
        transactions[i].items = malloc(transactions[i].num_items * sizeof(int));
        if (transactions[i].items == NULL) {
            perror("Error allocating memory");
            return NULL;
        }

        // Read the items
        for (int j = 0; j < transactions[i].num_items; j++) {
            fscanf(fp, "%d", &transactions[i].items[j]);
        }
    }

    // Close the file
    fclose(fp);

    // Return the transactions
    return transactions;
}

// Function to free the memory allocated for the transactions
void free_transactions(transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].items);
    }
    free(transactions);
}

// Function to print the transactions
void print_transactions(transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("Transaction %d: ", i + 1);
        for (int j = 0; j < transactions[i].num_items; j++) {
            printf("%d ", transactions[i].items[j]);
        }
        printf("\n");
    }
}

// Function to find the frequent itemsets
int *find_frequent_itemsets(transaction *transactions, int num_transactions, int min_support) {
    // Create a list of all the items
    int num_items = 0;
    for (int i = 0; i < num_transactions; i++) {
        for (int j = 0; j < transactions[i].num_items; j++) {
            if (transactions[i].items[j] > num_items) {
                num_items = transactions[i].items[j];
            }
        }
    }

    // Create a bitset to represent the frequent itemsets
    int *frequent_itemsets = malloc(((num_items + 31) / 32) * sizeof(int));
    if (frequent_itemsets == NULL) {
        perror("Error allocating memory");
        return NULL;
    }
    memset(frequent_itemsets, 0, ((num_items + 31) / 32) * sizeof(int));

    // Find the frequent itemsets
    for (int i = 0; i < num_transactions; i++) {
        for (int j = 0; j < transactions[i].num_items; j++) {
            int item = transactions[i].items[j];
            int index = item / 32;
            int bit = item % 32;
            frequent_itemsets[index] |= (1 << bit);
        }
    }

    // Remove the infrequent itemsets
    for (int i = 0; i < ((num_items + 31) / 32); i++) {
        int count = 0;
        for (int j = 0; j < 32; j++) {
            if (frequent_itemsets[i] & (1 << j)) {
                count++;
            }
        }
        if (count < min_support) {
            frequent_itemsets[i] = 0;
        }
    }

    // Return the frequent itemsets
    return frequent_itemsets;
}

// Function to free the memory allocated for the frequent itemsets
void free_frequent_itemsets(int *frequent_itemsets, int num_items) {
    free(frequent_itemsets);
}

// Function to print the frequent itemsets
void print_frequent_itemsets(int *frequent_itemsets, int num_items) {
    for (int i = 0; i < ((num_items + 31) / 32); i++) {
        for (int j = 0; j < 32; j++) {
            if (frequent_itemsets[i] & (1 << j)) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    // Read the transactions from a file
    int num_transactions;
    transaction *transactions = read_transactions("transactions.txt", &num_transactions);
    if (transactions == NULL) {
        return -1;
    }

    // Print the transactions
    print_transactions(transactions, num_transactions);

    // Find the frequent itemsets
    int *frequent_itemsets = find_frequent_itemsets(transactions, num_transactions, 2);
    if (frequent_itemsets == NULL) {
        return -1;
    }

    // Print the frequent itemsets
    print_frequent_itemsets(frequent_itemsets, num_transactions);

    // Free the memory allocated for the transactions
    free_transactions(transactions, num_transactions);

    // Free the memory allocated for the frequent itemsets
    free_frequent_itemsets(frequent_itemsets, num_transactions);

    return 0;
}