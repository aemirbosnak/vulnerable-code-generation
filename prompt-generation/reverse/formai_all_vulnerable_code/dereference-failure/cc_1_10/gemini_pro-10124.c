//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Create a node for the trie
typedef struct node {
  char* word;
  struct node* children[26];
  int is_word;
} node;

// Create a new node
node* new_node(char* word) {
  node* n = (node*)malloc(sizeof(node));
  n->word = strdup(word);
  for (int i = 0; i < 26; i++) {
    n->children[i] = NULL;
  }
  n->is_word = 0;
  return n;
}

// Insert a word into the trie
void insert(node* root, char* word) {
  node* current = root;
  for (int i = 0; i < strlen(word); i++) {
    int index = tolower(word[i]) - 'a';
    if (current->children[index] == NULL) {
      current->children[index] = new_node(word);
    }
    current = current->children[index];
  }
  current->is_word = 1;
}

// Load the dictionary into the trie
void load_dictionary(node* root, char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(1);
  }

  char word[MAX_WORD_LENGTH];
  while (fgets(word, MAX_WORD_LENGTH, fp) != NULL) {
    word[strlen(word) - 1] = '\0';  // Remove the newline character
    insert(root, word);
  }

  fclose(fp);
}

// Check if a word is in the trie
int is_in_trie(node* root, char* word) {
  node* current = root;
  for (int i = 0; i < strlen(word); i++) {
    int index = tolower(word[i]) - 'a';
    if (current->children[index] == NULL) {
      return 0;
    }
    current = current->children[index];
  }
  return current->is_word;
}

// Print all the words in the trie
void print_trie(node* root) {
  if (root->is_word) {
    printf("%s\n", root->word);
  }
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      print_trie(root->children[i]);
    }
  }
}

// Free the trie
void free_trie(node* root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      free_trie(root->children[i]);
    }
  }
  free(root->word);
  free(root);
}

int main() {
  // Create the root of the trie
  node* root = new_node("");

  // Load the dictionary into the trie
  load_dictionary(root, "dictionary.txt");

  // Print all the words in the trie
  print_trie(root);

  // Free the trie
  free_trie(root);

  return 0;
}