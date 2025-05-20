//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct node {
  char *word;
  int count;
  struct node *next;
} node;

typedef struct hashtable {
  int size;
  node **table;
} hashtable;

hashtable *create_hashtable(int size) {
  hashtable *ht = malloc(sizeof(hashtable));
  ht->size = size;
  ht->table = malloc(sizeof(node *) * size);
  for (int i = 0; i < size; i++) {
    ht->table[i] = NULL;
  }
  return ht;
}

void destroy_hashtable(hashtable *ht) {
  for (int i = 0; i < ht->size; i++) {
    node *n = ht->table[i];
    while (n != NULL) {
      node *next = n->next;
      free(n->word);
      free(n);
      n = next;
    }
  }
  free(ht->table);
  free(ht);
}

int hash(char *word, int size) {
  int h = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    h = (h * 31 + word[i]) % size;
  }
  return h;
}

void insert(hashtable *ht, char *word) {
  int h = hash(word, ht->size);
  node *n = ht->table[h];
  while (n != NULL) {
    if (strcmp(n->word, word) == 0) {
      n->count++;
      return;
    }
    n = n->next;
  }
  n = malloc(sizeof(node));
  n->word = strdup(word);
  n->count = 1;
  n->next = ht->table[h];
  ht->table[h] = n;
}

void print_hashtable(hashtable *ht) {
  for (int i = 0; i < ht->size; i++) {
    node *n = ht->table[i];
    while (n != NULL) {
      printf("%s: %d\n", n->word, n->count);
      n = n->next;
    }
  }
}

int main() {
  hashtable *ht = create_hashtable(100);
  char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  for (int i = 0; i < sizeof(words) / sizeof(char *); i++) {
    insert(ht, words[i]);
  }
  print_hashtable(ht);
  destroy_hashtable(ht);
  return 0;
}