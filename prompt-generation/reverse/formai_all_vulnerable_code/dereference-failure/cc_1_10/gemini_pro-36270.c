//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct node {
  char word[MAX_WORD_LENGTH];
  struct node *next;
} node_t;

node_t *head = NULL;

void insert_word(char *word) {
  node_t *new_node = malloc(sizeof(node_t));
  strcpy(new_node->word, word);
  new_node->next = head;
  head = new_node;
}

int is_word_in_dictionary(char *word) {
  node_t *current_node = head;
  while (current_node != NULL) {
    if (strcmp(current_node->word, word) == 0) {
      return 1;
    }
    current_node = current_node->next;
  }
  return 0;
}

void check_spelling(char *text) {
  char *word = strtok(text, " ");
  while (word != NULL) {
    if (!is_word_in_dictionary(word)) {
      printf("The word '%s' is not in the dictionary.\n", word);
    }
    word = strtok(NULL, " ");
  }
}

int main() {
  // Insert some words into the dictionary.
  insert_word("the");
  insert_word("quick");
  insert_word("brown");
  insert_word("fox");
  insert_word("jumps");
  insert_word("over");
  insert_word("the");
  insert_word("lazy");
  insert_word("dog");

  // Check the spelling of some text.
  char text[] = "The quick brown fox jumps over the lazy dog.";
  check_spelling(text);

  return 0;
}