//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash table node
typedef struct node {
  char *word;
  int count;
  struct node *next;
} node;

// Hash table
typedef struct table {
  int size;
  node **buckets;
} table;

// Create a new hash table
table *createTable(int size) {
  table *t = malloc(sizeof(table));
  t->size = size;
  t->buckets = malloc(sizeof(node *) * size);
  for (int i = 0; i < size; i++) {
    t->buckets[i] = NULL;
  }
  return t;
}

// Insert a word into the hash table
void insert(table *t, char *word) {
  int index = hash(word, t->size);
  node *n = malloc(sizeof(node));
  n->word = strdup(word);
  n->count = 1;
  n->next = t->buckets[index];
  t->buckets[index] = n;
}

// Find a word in the hash table
node *find(table *t, char *word) {
  int index = hash(word, t->size);
  node *n = t->buckets[index];
  while (n != NULL) {
    if (strcmp(n->word, word) == 0) {
      return n;
    }
    n = n->next;
  }
  return NULL;
}

// Increment the count of a word in the hash table
void increment(table *t, char *word) {
  node *n = find(t, word);
  if (n == NULL) {
    insert(t, word);
  } else {
    n->count++;
  }
}

// Print the words in the hash table
void printTable(table *t) {
  for (int i = 0; i < t->size; i++) {
    node *n = t->buckets[i];
    while (n != NULL) {
      printf("%s: %d\n", n->word, n->count);
      n = n->next;
    }
  }
}

// Free the hash table
void freeTable(table *t) {
  for (int i = 0; i < t->size; i++) {
    node *n = t->buckets[i];
    while (n != NULL) {
      node *next = n->next;
      free(n->word);
      free(n);
      n = next;
    }
  }
  free(t->buckets);
  free(t);
}

// Hash function
int hash(char *word, int size) {
  int h = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    h = (h << 5) + word[i];
  }
  return h % size;
}

// Main function
int main() {
  // Create a hash table
  table *t = createTable(100);

  // Insert some words into the hash table
  char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  for (int i = 0; i < sizeof(words) / sizeof(char *); i++) {
    insert(t, words[i]);
  }

  // Print the words in the hash table
  printTable(t);

  // Free the hash table
  freeTable(t);

  return 0;
}