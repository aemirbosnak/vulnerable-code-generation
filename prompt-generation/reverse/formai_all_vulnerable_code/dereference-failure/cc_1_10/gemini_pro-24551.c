//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Data structure to store a transaction
typedef struct transaction {
  int *items;
  int length;
} transaction;

// Data structure to store the database of transactions
typedef struct database {
  transaction *transactions;
  int num_transactions;
} database;

// Function to create a new database
database *create_database(int num_transactions) {
  database *db = (database *)malloc(sizeof(database));
  if (db == NULL) {
    perror("malloc");
    exit(1);
  }
  db->transactions = (transaction *)malloc(num_transactions * sizeof(transaction));
  if (db->transactions == NULL) {
    perror("malloc");
    exit(1);
  }
  db->num_transactions = num_transactions;
  return db;
}

// Function to free the memory allocated for a database
void free_database(database *db) {
  for (int i = 0; i < db->num_transactions; i++) {
    free(db->transactions[i].items);
  }
  free(db->transactions);
  free(db);
}

// Function to print a database
void print_database(database *db) {
  for (int i = 0; i < db->num_transactions; i++) {
    printf("Transaction %d: ", i + 1);
    for (int j = 0; j < db->transactions[i].length; j++) {
      printf("%d ", db->transactions[i].items[j]);
    }
    printf("\n");
  }
}

// Function to create a new transaction
transaction create_transaction(int length) {
  transaction t;
  t.items = malloc (length * sizeof(int));
  t.length = length;
  return t;
}

// Function to set item in a transaction
void setItem(transaction *t, int index, int value) {
  t->items[index] = value;
}

// Function to add a transaction to a database
void add_transaction(database *db, transaction t) {
  db->transactions[db->num_transactions] = t;
  db->num_transactions++;
}

// Function to find frequent itemsets
void find_frequent_itemsets(database *db, float min_support) {
  printf("Frequent itemsets:\n");
  printf("Itemset | Support\n");
  for (int i = 1; i <= MAX_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < db->num_transactions; j++) {
      int found = 1;
      for (int k = 0; k < i; k++) {
        int item = 0; // Initialize item to 0
        if (k < db->transactions[j].length) {
          item = db->transactions[j].items[k];
        }
        if (!item) {
          found = 0;
          break;
        }
      }
      if (found) {
        count++;
      }
    }
    float support = (float)count / db->num_transactions;
    if (support >= min_support) {
      printf("{");
      for (int k = 0; k < i; k++) {
        if (k > 0) {
          printf(", ");
        }
        printf("%d", k + 1);
      }
      printf("} | %.2f\n", support);
    }
  }
}

int main() {
  // Create a database
  database *db = create_database(5);

  // Add transactions to the database
  transaction t1 = create_transaction(3);
  setItem(&t1, 0, 1);
  setItem(&t1, 1, 2);
  setItem(&t1, 2, 3);
  add_transaction(db, t1);

  transaction t2 = create_transaction(4);
  setItem(&t2, 0, 1);
  setItem(&t2, 1, 2);
  setItem(&t2, 2, 3);
  setItem(&t2, 3, 4);
  add_transaction(db, t2);

  transaction t3 = create_transaction(3);
  setItem(&t3, 0, 1);
  setItem(&t3, 1, 3);
  setItem(&t3, 2, 4);
  add_transaction(db, t3);

  transaction t4 = create_transaction(2);
  setItem(&t4, 0, 2);
  setItem(&t4, 1, 4);
  add_transaction(db, t4);

  transaction t5 = create_transaction(3);
  setItem(&t5, 0, 1);
  setItem(&t5, 1, 2);
  setItem(&t5, 2, 4);
  add_transaction(db, t5);

  // Print the database
  print_database(db);

  // Find frequent itemsets
  float min_support = 0.6;
  find_frequent_itemsets(db, min_support);

  // Free the memory allocated for the database
  free_database(db);

  return 0;
}