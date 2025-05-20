//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

struct trie_node {
  int is_word;
  struct trie_node *children[26];
};

struct trie_node *create_trie_node() {
  struct trie_node *node = malloc(sizeof(struct trie_node));
  node->is_word = 0;
  for (int i = 0; i < 26; i++) {
    node->children[i] = NULL;
  }
  return node;
}

void insert_word(struct trie_node *root, char *word) {
  if (*word == '\0') {
    root->is_word = 1;
    return;
  }

  int index = *word - 'a';
  if (root->children[index] == NULL) {
    root->children[index] = create_trie_node();
  }
  insert_word(root->children[index], word + 1);
}

int search_word(struct trie_node *root, char *word) {
  if (*word == '\0') {
    return root->is_word;
  }

  int index = *word - 'a';
  if (root->children[index] == NULL) {
    return 0;
  }
  return search_word(root->children[index], word + 1);
}

void suggest_corrections(struct trie_node *root, char *word, int depth, char *suggestions[]) {
  if (root->is_word) {
    suggestions[depth] = malloc(strlen(word) + 1);
    strcpy(suggestions[depth], word);
  }

  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      char new_word[depth + 2];
      strcpy(new_word, word);
      new_word[depth] = 'a' + i;
      new_word[depth + 1] = '\0';
      suggest_corrections(root->children[i], new_word, depth + 1, suggestions);
    }
  }
}

int main() {
  struct trie_node *root = create_trie_node();

  char *words[] = {
    "apple", "banana", "cherry", "dog", "elephant", "fox", "grape", "horse", "ice cream", "juice"
  };

  for (int i = 0; i < 10; i++) {
    insert_word(root, words[i]);
  }

  char *misspelled_word = "aple";
  int depth = strlen(misspelled_word);
  char *suggestions[depth + 1];

  suggest_corrections(root, misspelled_word, 0, suggestions);

  printf("Suggestions for '%s':\n", misspelled_word);
  for (int i = 0; i < depth + 1; i++) {
    if (suggestions[i] != NULL) {
      printf("  %s\n", suggestions[i]);
      free(suggestions[i]);
    }
  }

  return 0;
}