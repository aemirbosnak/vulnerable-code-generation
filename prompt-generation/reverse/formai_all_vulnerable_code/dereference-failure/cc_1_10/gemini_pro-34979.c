//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20

typedef struct node {
  char word[MAX_WORD_LENGTH + 1];
  struct node *next;
} node_t;

node_t *head = NULL;

void insert(char *word) {
  node_t *new_node = malloc(sizeof(node_t));
  strcpy(new_node->word, word);
  new_node->next = head;
  head = new_node;
}

bool search(char *word) {
  node_t *current = head;
  while (current != NULL) {
    if (strcmp(current->word, word) == 0) {
      return true;
    }
    current = current->next;
  }
  return false;
}

int main() {
  // Initialize the dictionary
  insert("Romeo");
  insert("Juliet");
  insert("Tybalt");
  insert("Mercutio");
  insert("Friar Laurence");
  insert("Nurse");
  insert("Lady Capulet");
  insert("Lord Capulet");
  insert("Paris");
  insert("Balthasar");

  // Get the input text
  char text[1000];
  printf("Enter the text you want to check for spelling errors: ");
  gets(text);

  // Tokenize the text
  char *token = strtok(text, " ");
  while (token != NULL) {
    // Check if the token is in the dictionary
    if (!search(token)) {
      printf("The word \"%s\" is not in the dictionary.\n", token);
    }
    token = strtok(NULL, " ");
  }

  return 0;
}