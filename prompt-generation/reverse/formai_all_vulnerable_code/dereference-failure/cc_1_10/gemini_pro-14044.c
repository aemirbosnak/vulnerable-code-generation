//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structure for a transaction
typedef struct transaction {
    int id;
    int num_items;
    int *items;
} transaction;

// Define the data structure for a database of transactions
typedef struct database {
    int num_transactions;
    transaction *transactions;
} database;

// Function to read a database of transactions from a file
database *read_database(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the number of transactions
    int num_transactions;
    fscanf(file, "%d", &num_transactions);

    // Allocate memory for the database
    database *db = malloc(sizeof(database));
    db->num_transactions = num_transactions;
    db->transactions = malloc(num_transactions * sizeof(transaction));

    // Read each transaction
    for (int i = 0; i < num_transactions; i++) {
        // Read the transaction ID
        fscanf(file, "%d", &db->transactions[i].id);

        // Read the number of items in the transaction
        fscanf(file, "%d", &db->transactions[i].num_items);

        // Allocate memory for the items in the transaction
        db->transactions[i].items = malloc(db->transactions[i].num_items * sizeof(int));

        // Read the items in the transaction
        for (int j = 0; j < db->transactions[i].num_items; j++) {
            fscanf(file, "%d", &db->transactions[i].items[j]);
        }
    }

    // Close the file
    fclose(file);

    return db;
}

// Function to free the memory allocated for a database of transactions
void free_database(database *db) {
    for (int i = 0; i < db->num_transactions; i++) {
        free(db->transactions[i].items);
    }
    free(db->transactions);
    free(db);
}

// Function to print a database of transactions
void print_database(database *db) {
    for (int i = 0; i < db->num_transactions; i++) {
        printf("Transaction %d:\n", db->transactions[i].id);
        for (int j = 0; j < db->transactions[i].num_items; j++) {
            printf("%d ", db->transactions[i].items[j]);
        }
        printf("\n");
    }
}

// Function to find the frequent itemsets in a database of transactions
void find_frequent_itemsets(database *db, int min_support) {
    // Create a list of all the unique items in the database
    int num_unique_items = 0;
    int *unique_items = NULL;
    for (int i = 0; i < db->num_transactions; i++) {
        for (int j = 0; j < db->transactions[i].num_items; j++) {
            int item = db->transactions[i].items[j];
            int found = 0;
            for (int k = 0; k < num_unique_items; k++) {
                if (unique_items[k] == item) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                num_unique_items++;
                unique_items = realloc(unique_items, num_unique_items * sizeof(int));
                unique_items[num_unique_items - 1] = item;
            }
        }
    }

    // Create a list of all the frequent itemsets
    int num_frequent_itemsets = 0;
    int **frequent_itemsets = NULL;
    for (int i = 0; i < num_unique_items; i++) {
        int item = unique_items[i];
        int support = 0;
        for (int j = 0; j < db->num_transactions; j++) {
            int found = 0;
            for (int k = 0; k < db->transactions[j].num_items; k++) {
                if (db->transactions[j].items[k] == item) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                support++;
            }
        }
        if (support >= min_support) {
            num_frequent_itemsets++;
            frequent_itemsets = realloc(frequent_itemsets, num_frequent_itemsets * sizeof(int *));
            frequent_itemsets[num_frequent_itemsets - 1] = malloc(2 * sizeof(int));
            frequent_itemsets[num_frequent_itemsets - 1][0] = 1;
            frequent_itemsets[num_frequent_itemsets - 1][1] = item;
        }
    }

    // Print the frequent itemsets
    for (int i = 0; i < num_frequent_itemsets; i++) {
        printf("Frequent itemset: ");
        for (int j = 1; j < frequent_itemsets[i][0] + 1; j++) {
            printf("%d ", frequent_itemsets[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the frequent itemsets
    for (int i = 0; i < num_frequent_itemsets; i++) {
        free(frequent_itemsets[i]);
    }
    free(frequent_itemsets);

    // Free the memory allocated for the unique items
    free(unique_items);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <filename> <min_support>\n", argv[0]);
        return 1;
    }

    // Read the database of transactions from the file
    database *db = read_database(argv[1]);
    if (db == NULL) {
        return 1;
    }

    // Find the frequent itemsets in the database of transactions
    find_frequent_itemsets(db, atoi(argv[2]));

    // Free the memory allocated for the database of transactions
    free_database(db);

    return 0;
}