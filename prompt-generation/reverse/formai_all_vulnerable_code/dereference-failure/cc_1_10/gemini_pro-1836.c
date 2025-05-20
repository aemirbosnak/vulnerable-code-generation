//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: brave
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256
#define MAX_DICTIONARY_SIZE 1024

typedef struct node {
  char *word;
  struct node *next;
} node_t;

typedef struct dictionary {
  node_t *head;
  node_t *tail;
  size_t size;
} dictionary_t;

dictionary_t *dictionary_new() {
  dictionary_t *dict = malloc(sizeof(dictionary_t));
  if (!dict) {
    return NULL;
  }

  dict->head = NULL;
  dict->tail = NULL;
  dict->size = 0;

  return dict;
}

void dictionary_free(dictionary_t *dict) {
  if (!dict) {
    return;
  }

  node_t *current = dict->head;
  while (current) {
    node_t *next = current->next;
    free(current->word);
    free(current);
    current = next;
  }

  free(dict);
}

int dictionary_load(dictionary_t *dict, const char *filename) {
  if (!dict || !filename) {
    return -1;
  }

  FILE *file = fopen(filename, "r");
  if (!file) {
    return -1;
  }

  char buffer[MAX_WORD_LENGTH];
  while (fgets(buffer, MAX_WORD_LENGTH, file)) {
    char *word = strdup(buffer);
    if (!word) {
      fclose(file);
      return -1;
    }

    // Remove newline character
    size_t len = strlen(word);
    if (word[len - 1] == '\n') {
      word[len - 1] = '\0';
    }

    node_t *node = malloc(sizeof(node_t));
    if (!node) {
      free(word);
      fclose(file);
      return -1;
    }

    node->word = word;
    node->next = NULL;

    if (!dict->head) {
      dict->head = node;
    } else {
      dict->tail->next = node;
    }
    dict->tail = node;
    dict->size++;
  }

  fclose(file);

  return 0;
}

int dictionary_check(dictionary_t *dict, const char *word) {
  if (!dict || !word) {
    return -1;
  }

  node_t *current = dict->head;
  while (current) {
    if (strcmp(current->word, word) == 0) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <dictionary> <input>\n", argv[0]);
    return -1;
  }

  dictionary_t *dict = dictionary_new();
  if (!dict) {
    fprintf(stderr, "Failed to create dictionary\n");
    return -1;
  }

  if (dictionary_load(dict, argv[1]) != 0) {
    fprintf(stderr, "Failed to load dictionary\n");
    dictionary_free(dict);
    return -1;
  }

  FILE *file = fopen(argv[2], "r");
  if (!file) {
    fprintf(stderr, "Failed to open input file\n");
    dictionary_free(dict);
    return -1;
  }

  char buffer[MAX_WORD_LENGTH];
  while (fgets(buffer, MAX_WORD_LENGTH, file)) {
    // Remove punctuation and convert to lowercase
    char *word = strdup(buffer);
    if (!word) {
      fclose(file);
      dictionary_free(dict);
      return -1;
    }

    size_t len = strlen(word);
    for (size_t i = 0; i < len; i++) {
      word[i] = tolower(word[i]);
      if (ispunct(word[i])) {
        word[i] = '\0';
        break;
      }
    }

    // Check if word is in dictionary
    if (dictionary_check(dict, word) == 0) {
      printf("%s\n", word);
    }

    free(word);
  }

  fclose(file);
  dictionary_free(dict);

  return 0;
}