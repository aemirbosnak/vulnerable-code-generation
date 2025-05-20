//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *word;
  int count;
  struct node *next;
} node;

typedef struct table {
  int size;
  node **nodes;
} table;

table *table_new(int size) {
  table *t = malloc(sizeof(table));
  t->size = size;
  t->nodes = malloc(sizeof(node *) * size);
  for (int i = 0; i < size; i++) {
    t->nodes[i] = NULL;
  }
  return t;
}

void table_free(table *t) {
  for (int i = 0; i < t->size; i++) {
    node *n = t->nodes[i];
    while (n != NULL) {
      node *next = n->next;
      free(n->word);
      free(n);
      n = next;
    }
  }
  free(t->nodes);
  free(t);
}

int table_hash(table *t, char *word) {
  int h = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    h = (h << 5) - h + word[i];
  }
  return h % t->size;
}

void table_insert(table *t, char *word) {
  int h = table_hash(t, word);
  node *n = malloc(sizeof(node));
  n->word = strdup(word);
  n->count = 1;
  n->next = t->nodes[h];
  t->nodes[h] = n;
}

int table_get(table *t, char *word) {
  int h = table_hash(t, word);
  node *n = t->nodes[h];
  while (n != NULL) {
    if (strcmp(n->word, word) == 0) {
      return n->count;
    }
    n = n->next;
  }
  return 0;
}

void table_print(table *t) {
  for (int i = 0; i < t->size; i++) {
    node *n = t->nodes[i];
    while (n != NULL) {
      printf("%s: %d\n", n->word, n->count);
      n = n->next;
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    return 1;
  }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("fopen");
    return 1;
  }

  table *t = table_new(10000);
  char word[100];
  while (fscanf(f, "%s", word) != EOF) {
    table_insert(t, word);
  }
  fclose(f);

  table_print(t);
  table_free(t);

  return 0;
}