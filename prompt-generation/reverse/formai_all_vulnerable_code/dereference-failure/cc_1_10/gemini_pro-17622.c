//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

typedef struct node {
  char word[MAX_WORD_LENGTH + 1];
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

void print_dictionary() {
  node_t *current_node = head;
  while (current_node != NULL) {
    printf("%s\n", current_node->word);
    current_node = current_node->next;
  }
}

void free_dictionary() {
  node_t *current_node = head;
  while (current_node != NULL) {
    node_t *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
}

int main() {
  FILE *dictionary_file = fopen("dictionary.txt", "r");
  if (dictionary_file == NULL) {
    perror("Error opening dictionary file");
    return EXIT_FAILURE;
  }

  char line[MAX_WORD_LENGTH + 1];
  while (fgets(line, MAX_WORD_LENGTH + 1, dictionary_file) != NULL) {
    char *word = strtok(line, "\n");
    insert_word(word);
  }

  fclose(dictionary_file);

  char *input_word = "Hello";
  if (is_word_in_dictionary(input_word)) {
    printf("%s is in the dictionary.\n", input_word);
  } else {
    printf("%s is not in the dictionary.\n", input_word);
  }

  print_dictionary();
  free_dictionary();

  return EXIT_SUCCESS;
}