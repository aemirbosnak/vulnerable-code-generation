//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the hash table
typedef struct node {
  char *word;
  int count;
  struct node *next;
} node_t;

// Hash table structure
typedef struct hash_table {
  int size;
  node_t **table;
} hash_table_t;

// Create a new hash table
hash_table_t *hash_table_create(int size) {
  hash_table_t *table = malloc(sizeof(hash_table_t));
  table->size = size;
  table->table = malloc(sizeof(node_t *) * size);
  for (int i = 0; i < size; i++) {
    table->table[i] = NULL;
  }
  return table;
}

// Destroy a hash table
void hash_table_destroy(hash_table_t *table) {
  for (int i = 0; i < table->size; i++) {
    node_t *node = table->table[i];
    while (node != NULL) {
      node_t *next = node->next;
      free(node->word);
      free(node);
      node = next;
    }
  }
  free(table->table);
  free(table);
}

// Insert a word into the hash table
void hash_table_insert(hash_table_t *table, char *word) {
  int index = hash(word, table->size);
  node_t *node = table->table[index];
  while (node != NULL) {
    if (strcmp(node->word, word) == 0) {
      node->count++;
      return;
    }
    node = node->next;
  }
  node_t *new_node = malloc(sizeof(node_t));
  new_node->word = strdup(word);
  new_node->count = 1;
  new_node->next = table->table[index];
  table->table[index] = new_node;
}

// Print the hash table
void hash_table_print(hash_table_t *table) {
  for (int i = 0; i < table->size; i++) {
    node_t *node = table->table[i];
    while (node != NULL) {
      printf("%s: %d\n", node->word, node->count);
      node = node->next;
    }
  }
}

// Hash function
int hash(char *word, int size) {
  int hash_value = 0;
  for (int i = 0; i < strlen(word); i++) {
    hash_value += word[i];
  }
  return hash_value % size;
}

// Main function
int main() {
  // Create a hash table
  hash_table_t *table = hash_table_create(1000);

  // Get the input text
  char *text = "The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog.";

  // Tokenize the text
  char *token = strtok(text, " ");
  while (token != NULL) {
    // Insert the token into the hash table
    hash_table_insert(table, token);
    token = strtok(NULL, " ");
  }

  // Print the hash table
  hash_table_print(table);

  // Destroy the hash table
  hash_table_destroy(table);

  return 0;
}