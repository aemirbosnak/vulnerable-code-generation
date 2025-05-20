//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>

#define MAX_WORD_LENGTH 100

typedef struct node {
  char *word;
  struct node *next;
} node_t;

typedef struct dictionary {
  node_t *root;
} dictionary_t;

dictionary_t *dictionary_new() {
  dictionary_t *dictionary = malloc(sizeof(dictionary_t));
  if (dictionary == NULL) {
    fprintf(stderr, "Error: malloc() failed: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  dictionary->root = NULL;
  return dictionary;
}

void dictionary_free(dictionary_t *dictionary) {
  node_t *current = dictionary->root;
  while (current != NULL) {
    node_t *next = current->next;
    free(current->word);
    free(current);
    current = next;
  }
  free(dictionary);
}

bool dictionary_add(dictionary_t *dictionary, const char *word) {
  if (word == NULL) {
    fprintf(stderr, "Error: word is NULL\n");
    return false;
  }
  if (strlen(word) > MAX_WORD_LENGTH) {
    fprintf(stderr, "Error: word is too long\n");
    return false;
  }
  node_t *new_node = malloc(sizeof(node_t));
  if (new_node == NULL) {
    fprintf(stderr, "Error: malloc() failed: %s\n", strerror(errno));
    return false;
  }
  new_node->word = strdup(word);
  if (new_node->word == NULL) {
    fprintf(stderr, "Error: strdup() failed: %s\n", strerror(errno));
    free(new_node);
    return false;
  }
  new_node->next = NULL;
  if (dictionary->root == NULL) {
    dictionary->root = new_node;
  } else {
    node_t *current = dictionary->root;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
  return true;
}

bool dictionary_has_word(dictionary_t *dictionary, const char *word) {
  if (word == NULL) {
    fprintf(stderr, "Error: word is NULL\n");
    return false;
  }
  node_t *current = dictionary->root;
  while (current != NULL) {
    if (strcmp(current->word, word) == 0) {
      return true;
    }
    current = current->next;
  }
  return false;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <dictionary file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  FILE *dictionary_file = fopen(argv[1], "r");
  if (dictionary_file == NULL) {
    fprintf(stderr, "Error: fopen() failed: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  dictionary_t *dictionary = dictionary_new();
  char word[MAX_WORD_LENGTH + 1];
  while (fgets(word, sizeof(word), dictionary_file) != NULL) {
    char *newline = strchr(word, '\n');
    if (newline != NULL) {
      *newline = '\0';
    }
    if (!dictionary_add(dictionary, word)) {
      fprintf(stderr, "Error: dictionary_add() failed\n");
      exit(EXIT_FAILURE);
    }
  }
  fclose(dictionary_file);
  while (true) {
    printf("Enter a word to check, or press Ctrl+D to quit: ");
    if (fgets(word, sizeof(word), stdin) == NULL) {
      break;
    }
    char *newline = strchr(word, '\n');
    if (newline != NULL) {
      *newline = '\0';
    }
    if (dictionary_has_word(dictionary, word)) {
      printf("%s is in the dictionary\n", word);
    } else {
      printf("%s is not in the dictionary\n", word);
    }
  }
  dictionary_free(dictionary);
  return EXIT_SUCCESS;
}