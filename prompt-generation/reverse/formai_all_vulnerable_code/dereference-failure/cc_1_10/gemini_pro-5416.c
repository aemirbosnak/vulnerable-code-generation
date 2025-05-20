//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

// Create a node for the trie
typedef struct trie_node {
  char *word;
  struct trie_node *children[26];
} trie_node;

// Create a new trie node
trie_node *create_trie_node() {
  trie_node *new_node = malloc(sizeof(trie_node));
  new_node->word = NULL;
  for (int i = 0; i < 26; i++) {
    new_node->children[i] = NULL;
  }
  return new_node;
}

// Insert a word into the trie
void insert_word(trie_node *root, char *word) {
  trie_node *current = root;
  for (int i = 0; i < strlen(word); i++) {
    int index = tolower(word[i]) - 'a';
    if (current->children[index] == NULL) {
      current->children[index] = create_trie_node();
    }
    current = current->children[index];
  }
  current->word = strdup(word);
}

// Check if a word is in the trie
int find_word(trie_node *root, char *word) {
  trie_node *current = root;
  for (int i = 0; i < strlen(word); i++) {
    int index = tolower(word[i]) - 'a';
    if (current->children[index] == NULL) {
      return 0;
    }
    current = current->children[index];
  }
  return current->word != NULL;
}

// Load the dictionary into the trie
void load_dictionary(trie_node *root, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char word[MAX_WORD_LEN];
  while (fscanf(fp, "%s", word) != EOF) {
    insert_word(root, word);
  }

  fclose(fp);
}

// Check the spelling of a word
int check_spelling(trie_node *root, char *word) {
  return find_word(root, word);
}

// Free the trie
void free_trie(trie_node *root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      free_trie(root->children[i]);
    }
  }
  free(root->word);
  free(root);
}

// Get a word from the user
char *get_word() {
  char *word = malloc(MAX_WORD_LEN);
  printf("Enter a word: ");
  scanf("%s", word);
  return word;
}

// Print a message to the user
void print_message(char *message) {
  printf("%s\n", message);
}

// Main function
int main() {
  // Create the trie
  trie_node *root = create_trie_node();

  // Load the dictionary into the trie
  load_dictionary(root, "dictionary.txt");

  // Get a word from the user
  char *word = get_word();

  // Check the spelling of the word
  int is_correct = check_spelling(root, word);

  // Print a message to the user
  if (is_correct) {
    print_message("The word is spelled correctly.");
  } else {
    print_message("The word is spelled incorrectly.");
  }

  // Free the trie
  free_trie(root);

  // Free the word
  free(word);

  return 0;
}