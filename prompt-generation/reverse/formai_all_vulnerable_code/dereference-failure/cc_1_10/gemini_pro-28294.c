//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a transaction
typedef struct transaction {
  int id;
  int *items;
  int num_items;
} transaction;

// Function to read transactions from a file
transaction *read_transactions(char *filename, int *num_transactions) {
  FILE *fp;
  char line[1024];
  int i, j;
  transaction *transactions;

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  // Read the number of transactions
  fscanf(fp, "%d", num_transactions);

  // Allocate memory for the transactions
  transactions = (transaction *)malloc(*num_transactions * sizeof(transaction));
  if (transactions == NULL) {
    perror("malloc");
    exit(1);
  }

  // Read each transaction
  for (i = 0; i < *num_transactions; i++) {
    // Read the transaction ID
    fscanf(fp, "%d", &transactions[i].id);

    // Read the number of items in the transaction
    fscanf(fp, "%d", &transactions[i].num_items);

    // Allocate memory for the items in the transaction
    transactions[i].items = (int *)malloc(transactions[i].num_items * sizeof(int));
    if (transactions[i].items == NULL) {
      perror("malloc");
      exit(1);
    }

    // Read the items in the transaction
    for (j = 0; j < transactions[i].num_items; j++) {
      fscanf(fp, "%d", &transactions[i].items[j]);
    }
  }

  // Close the file
  fclose(fp);

  return transactions;
}

// Function to print transactions
void print_transactions(transaction *transactions, int num_transactions) {
  int i, j;

  for (i = 0; i < num_transactions; i++) {
    printf("Transaction %d: ", transactions[i].id);
    for (j = 0; j < transactions[i].num_items; j++) {
      printf("%d ", transactions[i].items[j]);
    }
    printf("\n");
  }
}

// Function to find frequent itemsets
int **find_frequent_itemsets(transaction *transactions, int num_transactions, int min_support) {
  int i, j, k, l;
  int **frequent_itemsets;
  int *itemsets;
  int num_itemsets;
  int support;

  // Find all 1-item itemsets
  itemsets = (int *)malloc(num_transactions * sizeof(int));
  if (itemsets == NULL) {
    perror("malloc");
    exit(1);
  }
  num_itemsets = 0;
  for (i = 0; i < num_transactions; i++) {
    for (j = 0; j < transactions[i].num_items; j++) {
      if (itemsets[transactions[i].items[j]] == 0) {
        itemsets[transactions[i].items[j]] = 1;
        num_itemsets++;
      }
    }
  }

  // Find frequent itemsets
  frequent_itemsets = (int **)malloc(num_itemsets * sizeof(int *));
  if (frequent_itemsets == NULL) {
    perror("malloc");
    exit(1);
  }
  for (i = 0; i < num_itemsets; i++) {
    support = 0;
    for (j = 0; j < num_transactions; j++) {
      for (k = 0; k < transactions[j].num_items; k++) {
        if (itemsets[i] == transactions[j].items[k]) {
          support++;
          break;
        }
      }
    }
    if (support >= min_support) {
      frequent_itemsets[i] = (int *)malloc(2 * sizeof(int));
      if (frequent_itemsets[i] == NULL) {
        perror("malloc");
        exit(1);
      }
      frequent_itemsets[i][0] = itemsets[i];
      frequent_itemsets[i][1] = support;
    }
  }

  // Free memory
  free(itemsets);

  return frequent_itemsets;
}

// Function to print frequent itemsets
void print_frequent_itemsets(int **frequent_itemsets, int num_frequent_itemsets) {
  int i;

  for (i = 0; i < num_frequent_itemsets; i++) {
    printf("Frequent itemset: {%d} (support: %d)\n", frequent_itemsets[i][0], frequent_itemsets[i][1]);
  }
}

int main() {
  int num_transactions;
  transaction *transactions;
  int **frequent_itemsets;
  int num_frequent_itemsets;

  // Read transactions from a file
  transactions = read_transactions("transactions.txt", &num_transactions);

  // Print transactions
  print_transactions(transactions, num_transactions);

  // Find frequent itemsets
  frequent_itemsets = find_frequent_itemsets(transactions, num_transactions, 2);

  // Print frequent itemsets
  print_frequent_itemsets(frequent_itemsets, num_frequent_itemsets);

  return 0;
}