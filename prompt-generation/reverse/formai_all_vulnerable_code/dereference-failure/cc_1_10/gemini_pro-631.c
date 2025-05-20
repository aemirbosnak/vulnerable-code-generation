//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// This structure represents a node in the trie
typedef struct trie_node {
  char letter;
  int is_word;
  struct trie_node *children[26];
} trie_node;

// This function creates a new trie node
trie_node *create_trie_node(char letter) {
  trie_node *node = malloc(sizeof(trie_node));
  node->letter = letter;
  node->is_word = 0;
  for (int i = 0; i < 26; i++) {
    node->children[i] = NULL;
  }
  return node;
}

// This function inserts a word into the trie
void insert_word(trie_node *root, char *word) {
  if (*word == '\0') {
    root->is_word = 1;
    return;
  }
  int index = *word - 'a';
  if (root->children[index] == NULL) {
    root->children[index] = create_trie_node(*word);
  }
  insert_word(root->children[index], word + 1);
}

// This function checks if a word is in the trie
int is_word_in_trie(trie_node *root, char *word) {
  if (*word == '\0') {
    return root->is_word;
  }
  int index = *word - 'a';
  if (root->children[index] == NULL) {
    return 0;
  }
  return is_word_in_trie(root->children[index], word + 1);
}

// This function prints all the words in the trie
void print_words(trie_node *root, char *prefix) {
  if (root->is_word) {
    printf("%s\n", prefix);
  }
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      char new_prefix[MAX_WORD_LENGTH];
      strcpy(new_prefix, prefix);
      new_prefix[strlen(new_prefix)] = root->children[i]->letter;
      print_words(root->children[i], new_prefix);
    }
  }
}

// This function frees the trie
void free_trie(trie_node *root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      free_trie(root->children[i]);
    }
  }
  free(root);
}

// This function checks if a word is spelled correctly
int is_word_spelled_correctly(trie_node *root, char *word) {
  if (*word == '\0') {
    return 1;
  }
  int index = *word - 'a';
  if (root->children[index] == NULL) {
    return 0;
  }
  return is_word_spelled_correctly(root->children[index], word + 1);
}

int main() {
  // Create the root of the trie
  trie_node *root = create_trie_node('\0');

  // Insert some words into the trie
  insert_word(root, "hello");
  insert_word(root, "world");
  insert_word(root, "computer");
  insert_word(root, "science");

  // Print all the words in the trie
  print_words(root, "");

  // Check if a word is spelled correctly
  printf("Is \"hello\" spelled correctly? %d\n", is_word_spelled_correctly(root, "hello"));
  printf("Is \"helloworld\" spelled correctly? %d\n", is_word_spelled_correctly(root, "helloworld"));

  // Free the trie
  free_trie(root);

  return 0;
}