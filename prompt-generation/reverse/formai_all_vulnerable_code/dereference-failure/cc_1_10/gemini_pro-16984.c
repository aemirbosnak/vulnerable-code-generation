//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple struct to represent a transaction
typedef struct {
  int id;
  char *items;
} transaction;

// A simple hash table to store the transactions
typedef struct {
  int size;
  transaction *data;
} hash_table;

// Create a new hash table
hash_table *create_hash_table(int size) {
  hash_table *ht = malloc(sizeof(hash_table));
  ht->size = size;
  ht->data = malloc(sizeof(transaction) * size);
  return ht;
}

// Destroy a hash table
void destroy_hash_table(hash_table *ht) {
  free(ht->data);
  free(ht);
}

// Hash a string
int hash(char *str) {
  int h = 0;
  while (*str) {
    h = h * 31 + *str++;
  }
  return h;
}

// Insert a transaction into a hash table
void insert_transaction(hash_table *ht, transaction *t) {
  int h = hash(t->items);
  int i = h % ht->size;
  while (ht->data[i].id != 0) {
    i = (i + 1) % ht->size;
  }
  ht->data[i] = *t;
}

// Get a transaction from a hash table
transaction *get_transaction(hash_table *ht, int id) {
  int h = hash(id);
  int i = h % ht->size;
  while (ht->data[i].id != id) {
    i = (i + 1) % ht->size;
    if (ht->data[i].id == 0) {
      return NULL;
    }
  }
  return &ht->data[i];
}

// Print a transaction
void print_transaction(transaction *t) {
  printf("id: %d, items: %s\n", t->id, t->items);
}

// Main function
int main() {
  // Create a hash table
  hash_table *ht = create_hash_table(100);

  // Insert some transactions
  transaction t1 = {1, "apple,banana,orange"};
  insert_transaction(ht, &t1);
  transaction t2 = {2, "banana,cherry,grape"};
  insert_transaction(ht, &t2);
  transaction t3 = {3, "cherry,grape,mango"};
  insert_transaction(ht, &t3);

  // Get a transaction
  transaction *t = get_transaction(ht, 2);
  if (t) {
    print_transaction(t);
  } else {
    printf("Transaction not found\n");
  }

  // Destroy the hash table
  destroy_hash_table(ht);

  return 0;
}