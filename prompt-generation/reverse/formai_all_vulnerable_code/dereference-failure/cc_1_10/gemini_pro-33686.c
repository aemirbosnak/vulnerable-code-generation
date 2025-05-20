//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct trie_node {
  bool is_word;
  struct trie_node *children[26];
} trie_node;

trie_node *create_trie_node() {
  trie_node *node = malloc(sizeof(trie_node));
  node->is_word = false;
  for (int i = 0; i < 26; i++) {
    node->children[i] = NULL;
  }
  return node;
}

void insert_word_into_trie(trie_node *root, char *word) {
  trie_node *current = root;
  for (int i = 0; i < strlen(word); i++) {
    int index = tolower(word[i]) - 'a';
    if (current->children[index] == NULL) {
      current->children[index] = create_trie_node();
    }
    current = current->children[index];
  }
  current->is_word = true;
}

bool is_word_in_trie(trie_node *root, char *word) {
  trie_node *current = root;
  for (int i = 0; i < strlen(word); i++) {
    int index = tolower(word[i]) - 'a';
    if (current->children[index] == NULL) {
      return false;
    }
    current = current->children[index];
  }
  return current->is_word;
}

void free_trie(trie_node *root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      free_trie(root->children[i]);
    }
  }
  free(root);
}

int main() {
  trie_node *root = create_trie_node();

  char *words[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "horse", "ice cream", "juice"};
  int num_words = sizeof(words) / sizeof(words[0]);

  for (int i = 0; i < num_words; i++) {
    insert_word_into_trie(root, words[i]);
  }

  char *input = "The quick brown fox jumped over the lazy dog.";
  char *token = strtok(input, " ");

  while (token != NULL) {
    bool is_correct = is_word_in_trie(root, token);
    if (!is_correct) {
      printf("The word '%s' is not spelled correctly.\n", token);
    }
    token = strtok(NULL, " ");
  }

  free_trie(root);

  return 0;
}