//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256
#define MAX_WORDS 1000

// Create a node for the trie
typedef struct node {
  char letter;
  struct node *children[26];
  int is_word;
} node;

// Create a new node
node *create_node(char letter) {
  node *new_node = malloc(sizeof(node));
  new_node->letter = letter;
  for (int i = 0; i < 26; i++) {
    new_node->children[i] = NULL;
  }
  new_node->is_word = 0;
  return new_node;
}

// Insert a word into the trie
void insert_word(node *root, char *word) {
  node *current = root;
  for (int i = 0; i < strlen(word); i++) {
    int index = word[i] - 'a';
    if (current->children[index] == NULL) {
      current->children[index] = create_node(word[i]);
    }
    current = current->children[index];
  }
  current->is_word = 1;
}

// Load the dictionary into the trie
node *load_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening dictionary file: %s\n", filename);
    exit(1);
  }

  node *root = create_node('\0');
  char word[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", word) != EOF) {
    insert_word(root, word);
  }

  fclose(file);

  return root;
}

// Check if a word is in the trie
int is_word(node *root, char *word) {
  node *current = root;
  for (int i = 0; i < strlen(word); i++) {
    int index = word[i] - 'a';
    if (current->children[index] == NULL) {
      return 0;
    }
    current = current->children[index];
  }
  return current->is_word;
}

// Check if a word is spelled correctly
int is_spelled_correctly(node *dictionary, char *word) {
  return is_word(dictionary, word);
}

// Print all the words in the trie
void print_words(node *root, char *prefix) {
  if (root->is_word) {
    printf("%s\n", prefix);
  }

  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      char new_prefix[MAX_WORD_LENGTH];
      sprintf(new_prefix, "%s%c", prefix, root->children[i]->letter);
      print_words(root->children[i], new_prefix);
    }
  }
}

// Free the trie
void free_trie(node *root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      free_trie(root->children[i]);
    }
  }
  free(root);
}

// Main function
int main() {
  // Load the dictionary into the trie
  node *dictionary = load_dictionary("dictionary.txt");

  // Check if a word is spelled correctly
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to check: ");
  scanf("%s", word);
  if (is_spelled_correctly(dictionary, word)) {
    printf("%s is spelled correctly.\n", word);
  } else {
    printf("%s is not spelled correctly.\n", word);
  }

  // Print all the words in the trie
  printf("All the words in the dictionary:\n");
  print_words(dictionary, "");

  // Free the trie
  free_trie(dictionary);

  return 0;
}