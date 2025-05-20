//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for a transaction
typedef struct transaction {
    int id;
    int num_items;
    int *items;
} transaction;

// Define the data structure for a dataset
typedef struct dataset {
    int num_transactions;
    transaction *transactions;
} dataset;

// Load a dataset from a file
dataset load_dataset(char *filename) {
    FILE *fp;
    dataset dataset;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the number of transactions
    fscanf(fp, "%d", &dataset.num_transactions);

    // Allocate memory for the transactions
    dataset.transactions = malloc(sizeof(transaction) * dataset.num_transactions);

    // Read each transaction
    for (int i = 0; i < dataset.num_transactions; i++) {
        fscanf(fp, "%d", &dataset.transactions[i].id);
        fscanf(fp, "%d", &dataset.transactions[i].num_items);

        // Allocate memory for the items
        dataset.transactions[i].items = malloc(sizeof(int) * dataset.transactions[i].num_items);

        // Read the items
        for (int j = 0; j < dataset.transactions[i].num_items; j++) {
            fscanf(fp, "%d", &dataset.transactions[i].items[j]);
        }
    }

    // Close the file
    fclose(fp);

    return dataset;
}

// Free the memory allocated for a dataset
void free_dataset(dataset dataset) {
    for (int i = 0; i < dataset.num_transactions; i++) {
        free(dataset.transactions[i].items);
    }
    free(dataset.transactions);
}

// Print a dataset
void print_dataset(dataset dataset) {
    for (int i = 0; i < dataset.num_transactions; i++) {
        printf("Transaction %d: ", dataset.transactions[i].id);
        for (int j = 0; j < dataset.transactions[i].num_items; j++) {
            printf("%d ", dataset.transactions[i].items[j]);
        }
        printf("\n");
    }
}

// Find the frequent itemsets in a dataset
void find_frequent_itemsets(dataset dataset, double min_support) {
    // Create a list of all the items in the dataset
    int num_items = 0;
    for (int i = 0; i < dataset.num_transactions; i++) {
        for (int j = 0; j < dataset.transactions[i].num_items; j++) {
            if (dataset.transactions[i].items[j] > num_items) {
                num_items = dataset.transactions[i].items[j];
            }
        }
    }

    // Create a list of all the frequent itemsets
    int num_frequent_itemsets = 0;
    int **frequent_itemsets = malloc(sizeof(int *) * num_items);
    for (int i = 0; i < num_items; i++) {
        frequent_itemsets[i] = malloc(sizeof(int) * num_items);
    }

    // Find the frequent itemsets
    for (int i = 0; i < dataset.num_transactions; i++) {
        for (int j = 0; j < dataset.transactions[i].num_items; j++) {
            for (int k = j + 1; k < dataset.transactions[i].num_items; k++) {
                if (dataset.transactions[i].items[j] != dataset.transactions[i].items[k]) {
                    frequent_itemsets[dataset.transactions[i].items[j]][dataset.transactions[i].items[k]]++;
                }
            }
        }
    }

    // Print the frequent itemsets
    for (int i = 0; i < num_items; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if (frequent_itemsets[i][j] >= min_support * dataset.num_transactions) {
                printf("Frequent itemset: (%d, %d)\n", i, j);
            }
        }
    }

    // Free the memory allocated for the frequent itemsets
    for (int i = 0; i < num_items; i++) {
        free(frequent_itemsets[i]);
    }
    free(frequent_itemsets);
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <filename> <min_support>\n", argv[0]);
        exit(1);
    }

    // Load the dataset
    dataset dataset = load_dataset(argv[1]);

    // Find the frequent itemsets
    find_frequent_itemsets(dataset, atof(argv[2]));

    // Free the memory allocated for the dataset
    free_dataset(dataset);

    return 0;
}