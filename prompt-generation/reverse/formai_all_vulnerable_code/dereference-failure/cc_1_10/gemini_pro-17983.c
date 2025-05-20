//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store data about a transaction
typedef struct {
    int id;
    int item_id;
    int quantity;
} transaction;

// Function to read transactions from a file
transaction* read_transactions(char* filename, int* num_transactions) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Get the number of transactions
    fscanf(fp, "%d", num_transactions);

    // Allocate memory for the transactions
    transaction* transactions = malloc(*num_transactions * sizeof(transaction));
    if (transactions == NULL) {
        perror("Error allocating memory for transactions");
        exit(EXIT_FAILURE);
    }

    // Read the transactions from the file
    for (int i = 0; i < *num_transactions; i++) {
        fscanf(fp, "%d %d %d", &transactions[i].id, &transactions[i].item_id, &transactions[i].quantity);
    }

    // Close the file
    fclose(fp);

    return transactions;
}

// Function to print transactions
void print_transactions(transaction* transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("Transaction %d: item %d, quantity %d\n", transactions[i].id, transactions[i].item_id, transactions[i].quantity);
    }
}

// Function to find frequent itemsets
void find_frequent_itemsets(transaction* transactions, int num_transactions, float min_support) {
    // Create a hash table to store the itemsets
    int hash_table_size = num_transactions;
    int hash_table[hash_table_size];
    for (int i = 0; i < hash_table_size; i++) {
        hash_table[i] = -1;
    }

    // Insert the transactions into the hash table
    for (int i = 0; i < num_transactions; i++) {
        int item_id = transactions[i].item_id;
        int index = item_id % hash_table_size;
        while (hash_table[index] != -1) {
            index = (index + 1) % hash_table_size;
        }
        hash_table[index] = i;
    }

    // Create a list of frequent itemsets
    int num_frequent_itemsets = 0;
    int* frequent_itemsets = malloc(num_transactions * sizeof(int));
    if (frequent_itemsets == NULL) {
        perror("Error allocating memory for frequent itemsets");
        exit(EXIT_FAILURE);
    }

    // Find the frequent itemsets
    for (int i = 0; i < hash_table_size; i++) {
        if (hash_table[i] != -1) {
            int item_id = transactions[hash_table[i]].item_id;
            int support = 0;
            for (int j = 0; j < num_transactions; j++) {
                if (transactions[j].item_id == item_id) {
                    support++;
                }
            }
            if (support >= (min_support * num_transactions)) {
                frequent_itemsets[num_frequent_itemsets] = item_id;
                num_frequent_itemsets++;
            }
        }
    }

    // Print the frequent itemsets
    printf("Frequent itemsets:\n");
    for (int i = 0; i < num_frequent_itemsets; i++) {
        printf("Item %d\n", frequent_itemsets[i]);
    }

    // Free the memory
    free(frequent_itemsets);
}

int main() {
    // Read the transactions from the file
    int num_transactions;
    transaction* transactions = read_transactions("transactions.txt", &num_transactions);

    // Print the transactions
    print_transactions(transactions, num_transactions);

    // Find the frequent itemsets
    float min_support = 0.5;
    find_frequent_itemsets(transactions, num_transactions, min_support);

    // Free the memory
    free(transactions);

    return 0;
}