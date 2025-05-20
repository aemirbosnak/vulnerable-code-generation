//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a transaction
typedef struct transaction {
  int tid; // Transaction ID
  int *items; // Array of item IDs
  int num_items; // Number of items in the transaction
} transaction;

// Structure to store a customer
typedef struct customer {
  int cid; // Customer ID
  transaction *transactions; // Array of transactions made by the customer
  int num_transactions; // Number of transactions made by the customer
} customer;

// Structure to store a database of customers
typedef struct customer_db {
  customer *customers; // Array of customers
  int num_customers; // Number of customers in the database
} customer_db;

// Read customer database from a file
customer_db *read_customer_db(char *filename) {
  FILE *fp;
  customer_db *db;
  int i, j, k;

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Read the number of customers
  fscanf(fp, "%d", &db->num_customers);

  // Allocate memory for the customers
  db->customers = (customer *)malloc(db->num_customers * sizeof(customer));

  // Read each customer's data
  for (i = 0; i < db->num_customers; i++) {
    // Read the customer's ID
    fscanf(fp, "%d", &db->customers[i].cid);

    // Read the number of transactions made by the customer
    fscanf(fp, "%d", &db->customers[i].num_transactions);

    // Allocate memory for the customer's transactions
    db->customers[i].transactions = (transaction *)malloc(db->customers[i].num_transactions * sizeof(transaction));

    // Read each transaction's data
    for (j = 0; j < db->customers[i].num_transactions; j++) {
      // Read the transaction's ID
      fscanf(fp, "%d", &db->customers[i].transactions[j].tid);

      // Read the number of items in the transaction
      fscanf(fp, "%d", &db->customers[i].transactions[j].num_items);

      // Allocate memory for the transaction's items
      db->customers[i].transactions[j].items = (int *)malloc(db->customers[i].transactions[j].num_items * sizeof(int));

      // Read the items in the transaction
      for (k = 0; k < db->customers[i].transactions[j].num_items; k++) {
        fscanf(fp, "%d", &db->customers[i].transactions[j].items[k]);
      }
    }
  }

  // Close the file
  fclose(fp);

  // Return the customer database
  return db;
}

// Print customer database
void print_customer_db(customer_db *db) {
  int i, j, k;

  // Print each customer's data
  for (i = 0; i < db->num_customers; i++) {
    printf("Customer ID: %d\n", db->customers[i].cid);
    printf("Number of transactions: %d\n", db->customers[i].num_transactions);

    // Print each transaction's data
    for (j = 0; j < db->customers[i].num_transactions; j++) {
      printf("Transaction ID: %d\n", db->customers[i].transactions[j].tid);
      printf("Number of items: %d\n", db->customers[i].transactions[j].num_items);

      // Print the items in the transaction
      for (k = 0; k < db->customers[i].transactions[j].num_items; k++) {
        printf("Item ID: %d\n", db->customers[i].transactions[j].items[k]);
      }
    }
  }
}

// Free customer database
void free_customer_db(customer_db *db) {
  int i, j;

  // Free each customer's data
  for (i = 0; i < db->num_customers; i++) {
    // Free each transaction's data
    for (j = 0; j < db->customers[i].num_transactions; j++) {
      free(db->customers[i].transactions[j].items);
    }

    // Free the customer's transactions
    free(db->customers[i].transactions);
  }

  // Free the customers
  free(db->customers);

  // Free the customer database
  free(db);
}

// Main function
int main() {
  customer_db *db;

  // Read customer database from file
  db = read_customer_db("customer_db.txt");

  // Print customer database
  print_customer_db(db);

  // Free customer database
  free_customer_db(db);

  return 0;
}