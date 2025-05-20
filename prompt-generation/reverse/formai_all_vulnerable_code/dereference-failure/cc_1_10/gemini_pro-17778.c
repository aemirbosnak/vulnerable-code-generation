//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct word {
//   char *word;
//   int count;
// } word_t;

typedef struct node {
  char *word;
  int count;
  struct node *next;
} node_t;

node_t *head = NULL;

void insert_word(char *word) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->word = strdup(word);
  new_node->count = 1;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    node_t *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void count_words(char *text) {
  char *delim = " ";
  char *word = strtok(text, delim);
  while (word != NULL) {
    insert_word(word);
    word = strtok(NULL, delim);
  }
}

void print_word_counts() {
  node_t *current = head;
  while (current != NULL) {
    printf("%s: %d\n", current->word, current->count);
    current = current->next;
  }
}

int main() {
  char *text = "The quick brown fox jumps over the lazy dog";
  count_words(text);
  print_word_counts();
  return 0;
}