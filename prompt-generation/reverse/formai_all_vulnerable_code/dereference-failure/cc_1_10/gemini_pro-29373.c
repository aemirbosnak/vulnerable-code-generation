//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

typedef struct node {
  char word[MAX_WORD_LENGTH];
  struct node *next;
} node;

// Create a new node with the given word
node *new_node(char *word) {
  node *n = malloc(sizeof(node));
  strcpy(n->word, word);
  n->next = NULL;
  return n;
}

// Insert the given word into the dictionary, keeping it sorted
void insert_word(node **dict, char *word) {
  node *n = new_node(word);
  if (*dict == NULL || strcmp(n->word, (*dict)->word) < 0) {
    n->next = *dict;
    *dict = n;
    return;
  }
  node *prev = *dict;
  node *curr = (*dict)->next;
  while (curr != NULL && strcmp(n->word, curr->word) > 0) {
    prev = curr;
    curr = curr->next;
  }
  n->next = curr;
  prev->next = n;
}

// Check if the given word is in the dictionary
int is_word_in_dict(node *dict, char *word) {
  node *curr = dict;
  while (curr != NULL) {
    if (strcmp(curr->word, word) == 0) {
      return 1;
    }
    curr = curr->next;
  }
  return 0;
}

// Print the words in the dictionary
void print_dict(node *dict) {
  node *curr = dict;
  while (curr != NULL) {
    printf("%s\n", curr->word);
    curr = curr->next;
  }
}

// Free the memory used by the dictionary
void free_dict(node *dict) {
  node *curr = dict;
  while (curr != NULL) {
    node *next = curr->next;
    free(curr);
    curr = next;
  }
}

int main() {
  // Create the dictionary
  node *dict = NULL;

  // Insert some words into the dictionary
  insert_word(&dict, "hello");
  insert_word(&dict, "world");
  insert_word(&dict, "computer");
  insert_word(&dict, "science");
  insert_word(&dict, "programming");

  // Print the dictionary
  printf("Dictionary:\n");
  print_dict(dict);

  // Check if some words are in the dictionary
  printf("\nIs \"hello\" in the dictionary? %s\n", is_word_in_dict(dict, "hello") ? "Yes" : "No");
  printf("Is \"goodbye\" in the dictionary? %s\n", is_word_in_dict(dict, "goodbye") ? "Yes" : "No");

  // Free the memory used by the dictionary
  free_dict(dict);

  return 0;
}