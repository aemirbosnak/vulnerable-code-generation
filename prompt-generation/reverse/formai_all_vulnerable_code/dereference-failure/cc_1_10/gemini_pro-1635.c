//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node for the dictionary tree
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

// Insert a word into the dictionary tree
void insert_word(node *root, char *word) {
  node *current_node = root;
  int index;
  
  // Walk through the word, creating nodes as needed
  for (int i = 0; i < strlen(word); i++) {
    index = word[i] - 'a';
    if (current_node->children[index] == NULL) {
      current_node->children[index] = create_node(word[i]);
    }
    current_node = current_node->children[index];
}

// Mark the last node as a word
  current_node->is_word = 1;
}

// Spell check a word
int spell_check(node *root, char *word) {
  node *current_node = root;
  int index;

  // Walk through the word and check if the nodes exist
  for (int i = 0; i < strlen(word); i++) {
    index = word[i] - 'a';
    if (current_node->children[index] == NULL) {
      return 0;
    }
    current_node = current_node->children[index];
}

// Return if the word is found in the dictionary
return current_node->is_word;
}

// Free the dictionary tree
void free_tree(node *root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      free_tree(root->children[i]);
    }
  }
  free(root);
}

// Main function
int main() {
  // Create a dictionary tree
  node *root = create_node('-'); // Use a dummy root node to simplify the code

  // Insert some words into the dictionary
  insert_word(root, "hello");
  insert_word(root, "world");
  insert_word(root, "programming");
  insert_word(root, "is");
  insert_word(root, "fun");

  // Spell check some words
  int result1 = spell_check(root, "hello");
  int result2 = spell_check(root, "worl");
  int result3 = spell_check(root, "programing");

  // Print the results
  printf("hello: %s\n", result1 ? "Correct" : "Incorrect");
  printf("worl: %s\n", result2 ? "Correct" : "Incorrect");
  printf("programing: %s\n", result3 ? "Correct" : "Incorrect");

  // Free the dictionary tree
  free_tree(root);

  return 0;
}