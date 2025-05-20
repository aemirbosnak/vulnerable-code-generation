//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

typedef struct node {
  char *word;
  struct node *next;
} node_t;

typedef struct {
  size_t words;
  node_t *head;
} dictionary_t;

dictionary_t *create_dictionary() {
  dictionary_t *dict = calloc(1, sizeof(*dict));
  return dict;
}

void destroy_dictionary(dictionary_t *dict) {
  node_t *node = dict->head;
  while (node) {
    node_t *next = node->next;
    free(node->word);
    free(node);
    node = next;
  }
  free(dict);
}

bool load_dictionary(dictionary_t *dict, const char *path) {
  FILE *file = fopen(path, "r");
  if (!file) {
    perror("fopen");
    return false;
  }
  char word[1024];
  while (fgets(word, sizeof(word), file)) {
    size_t len = strlen(word);
    if (len > 0 && word[len - 1] == '\n') {
      word[len - 1] = '\0';
    }
    char *w = strdup(word);
    if (!w) {
      perror("strdup");
      fclose(file);
      return false;
    }
    node_t *node = calloc(1, sizeof(*node));
    if (!node) {
      perror("calloc");
      free(w);
      fclose(file);
      return false;
    }
    node->word = w;
    node->next = dict->head;
    dict->head = node;
    dict->words++;
  }
  fclose(file);
  return true;
}

bool check_spelling(dictionary_t *dict, const char *word) {
  node_t *node = dict->head;
  while (node) {
    if (!strcmp(node->word, word)) {
      return true;
    }
    node = node->next;
  }
  return false;
}

int main() {
  dictionary_t *dict = create_dictionary();
  if (!load_dictionary(dict, "words.txt")) {
    fprintf(stderr, "Failed to load dictionary\n");
    destroy_dictionary(dict);
    return EXIT_FAILURE;
  }
  char word[1024];
  while (true) {
    printf("Enter a word (or q to quit): ");
    if (!fgets(word, sizeof(word), stdin)) {
      break;
    }
    size_t len = strlen(word);
    if (len > 0 && word[len - 1] == '\n') {
      word[len - 1] = '\0';
    }
    if (!strcmp(word, "q")) {
      break;
    }
    bool correct = check_spelling(dict, word);
    if (correct) {
      printf("Correct\n");
    } else {
      printf("Incorrect\n");
    }
  }
  destroy_dictionary(dict);
  return EXIT_SUCCESS;
}