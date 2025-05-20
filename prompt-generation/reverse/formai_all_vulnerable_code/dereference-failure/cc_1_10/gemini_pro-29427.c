//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the index
typedef struct node {
  char *key;
  int value;
  struct node *next;
} node;

// Hash table structure
typedef struct hash_table {
  int size;
  struct node **table;
} hash_table;

// Create a new hash table
hash_table *create_hash_table(int size) {
  hash_table *table = (hash_table *)malloc(sizeof(hash_table));
  table->size = size;
  table->table = (node **)malloc(sizeof(node *) * size);
  for (int i = 0; i < size; i++) {
    table->table[i] = NULL;
  }
  return table;
}

// Insert a key-value pair into the hash table
void insert(hash_table *table, char *key, int value) {
  // Calculate the hash value
  int hash = hash_function(key) % table->size;

  // Create a new node
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = strdup(key);
  new_node->value = value;
  new_node->next = NULL;

  // Insert the new node into the hash table
  if (table->table[hash] == NULL) {
    table->table[hash] = new_node;
  } else {
    node *current = table->table[hash];
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Search for a key in the hash table
int search(hash_table *table, char *key) {
  // Calculate the hash value
  int hash = hash_function(key) % table->size;

  // Search for the key in the hash table
  node *current = table->table[hash];
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      return current->value;
    }
    current = current->next;
  }

  // Key not found
  return -1;
}

// Hash function
int hash_function(char *key) {
  int hash = 0;
  int len = strlen(key);
  for (int i = 0; i < len; i++) {
    hash += key[i];
  }
  return hash;
}

// Print the hash table
void print_hash_table(hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    node *current = table->table[i];
    printf("%d: ", i);
    while (current != NULL) {
      printf("%s (%d) -> ", current->key, current->value);
      current = current->next;
    }
    printf("\n");
  }
}

// Free the hash table
void free_hash_table(hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    node *current = table->table[i];
    while (current != NULL) {
      node *next = current->next;
      free(current->key);
      free(current);
      current = next;
    }
  }
  free(table->table);
  free(table);
}

// Main function
int main() {
  // Create a new hash table
  hash_table *table = create_hash_table(10);

  // Insert some key-value pairs into the hash table
  insert(table, "Hello", 1);
  insert(table, "World", 2);
  insert(table, "This", 3);
  insert(table, "Is", 4);
  insert(table, "A", 5);
  insert(table, "Test", 6);

  // Print the hash table
  print_hash_table(table);

  // Search for a key in the hash table
  int value = search(table, "Hello");
  printf("The value for 'Hello' is %d\n", value);

  // Free the hash table
  free_hash_table(table);

  return 0;
}