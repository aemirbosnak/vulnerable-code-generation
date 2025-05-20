//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 30

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_SIZE 10000

// Create a node for the trie data structure
typedef struct trie_node {
  char letter;
  struct trie_node *children[26];
  int is_word;
} trie_node;

// Create a new trie node
trie_node *create_trie_node(char letter) {
  trie_node *new_node = malloc(sizeof(trie_node));
  new_node->letter = letter;
  for (int i = 0; i < 26; i++) {
    new_node->children[i] = NULL;
  }
  new_node->is_word = 0;
  return new_node;
}

// Insert a word into the trie
void insert_into_trie(trie_node *root, char *word) {
  trie_node *current_node = root;
  for (int i = 0; word[i] != '\0'; i++) {
    int index = word[i] - 'a';
    if (current_node->children[index] == NULL) {
      current_node->children[index] = create_trie_node(word[i]);
    }
    current_node = current_node->children[index];
  }
  current_node->is_word = 1;
}

// Check if a word is in the trie
int is_in_trie(trie_node *root, char *word) {
  trie_node *current_node = root;
  for (int i = 0; word[i] != '\0'; i++) {
    int index = word[i] - 'a';
    if (current_node->children[index] == NULL) {
      return 0;
    }
    current_node = current_node->children[index];
  }
  return current_node->is_word;
}

// Load the dictionary into the trie
void load_dictionary(trie_node *root, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening dictionary file!\n");
    exit(1);
  }
  char word[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", word) != EOF) {
    insert_into_trie(root, word);
  }
  fclose(file);
}

// Check the spelling of a word
void check_spelling(trie_node *root, char *word) {
  if (is_in_trie(root, word)) {
    printf("%s is spelled correctly.\n", word);
  } else {
    printf("%s is spelled incorrectly.\n", word);
  }
}

// Free the trie
void free_trie(trie_node *root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      free_trie(root->children[i]);
    }
  }
  free(root);
}

// Main function
int main() {
  // Create the root node of the trie
  trie_node *root = create_trie_node(' ');

  // Load the dictionary into the trie
  load_dictionary(root, "dictionary.txt");

  // Check the spelling of a word
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to check its spelling: ");
  scanf("%s", word);

  check_spelling(root, word);

  // Free the trie
  free_trie(root);

  return 0;
}