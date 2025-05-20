//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct node {
  char *word;
  int count;
  struct node *next;
};

struct node *head = NULL;

void insert(char *word) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->word = strdup(word);
  new_node->count = 1;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
    return;
  }

  struct node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}

void count_words(char *string) {
  char *token = strtok(string, " ");
  while (token != NULL) {
    insert(token);
    token = strtok(NULL, " ");
  }
}

void print_words() {
  struct node *current = head;
  while (current != NULL) {
    printf("%s: %d\n", current->word, current->count);
    current = current->next;
  }
}

void free_list() {
  struct node *current = head;
  while (current != NULL) {
    struct node *next = current->next;
    free(current->word);
    free(current);
    current = next;
  }

  head = NULL;
}

int main() {
  char *string = "The quick brown fox jumps over the lazy dog.";

  count_words(string);
  print_words();
  free_list();

  return 0;
}