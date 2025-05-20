//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 25

// Define the maximum number of words in a dictionary
#define MAX_WORDS 10000

// Define the maximum number of suggestions to display
#define MAX_SUGGESTIONS 5

// Create a node for the trie
typedef struct node {
  char letter;
  struct node *children[26];
  int is_word;
} node;

// Create a new node
node *create_node(char letter) {
  node *new_node = (node *)malloc(sizeof(node));
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
    char letter = tolower(word[i]);
    int index = letter - 'a';
    if (current->children[index] == NULL) {
      current->children[index] = create_node(letter);
    }
    current = current->children[index];
  }
  current->is_word = 1;
}

// Load the dictionary into the trie
void load_dictionary(node *root, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening dictionary file\n");
    return;
  }
  char word[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", word) != EOF) {
    insert_word(root, word);
  }
  fclose(file);
}

// Check if a word is in the trie
int is_word_in_trie(node *root, char *word) {
  node *current = root;
  for (int i = 0; i < strlen(word); i++) {
    char letter = tolower(word[i]);
    int index = letter - 'a';
    if (current->children[index] == NULL) {
      return 0;
    }
    current = current->children[index];
  }
  return current->is_word;
}

// Find suggestions for a misspelled word
void find_suggestions(node *root, char *word, char *suggestions[]) {
  // Create a queue to store the nodes to be explored
  node *queue[MAX_WORDS];
  int front = 0;
  int rear = 0;

  // Add the root node to the queue
  queue[rear++] = root;

  // Iterate over the queue until it is empty
  while (front < rear) {
    // Get the next node from the queue
    node *current = queue[front++];

    // Check if the current node is a word
    if (current->is_word) {
      // Add the current word to the list of suggestions
      strcpy(suggestions[rear++], word);
    }

    // Iterate over the children of the current node
    for (int i = 0; i < 26; i++) {
      if (current->children[i] != NULL) {
        // Add the child node to the queue
        queue[rear++] = current->children[i];

        // Modify the misspelled word to include the letter of the child node
        word[strlen(word)] = current->children[i]->letter;

        // Check if the modified word is in the trie
        if (is_word_in_trie(root, word)) {
          // Add the modified word to the list of suggestions
          strcpy(suggestions[rear++], word);
        }

        // Remove the last letter from the misspelled word
        word[strlen(word) - 1] = '\0';
      }
    }
  }
}

// Print the suggestions
void print_suggestions(char *suggestions[], int num_suggestions) {
  if (num_suggestions == 0) {
    printf("No suggestions found\n");
  } else {
    printf("Suggestions:\n");
    for (int i = 0; i < num_suggestions; i++) {
      printf("%s\n", suggestions[i]);
    }
  }
}

// Check the spelling of a word
void check_spelling(node *root, char *word) {
  // Check if the word is in the trie
  if (is_word_in_trie(root, word)) {
    printf("%s is spelled correctly\n", word);
  } else {
    // Find suggestions for the misspelled word
    char suggestions[MAX_SUGGESTIONS][MAX_WORD_LENGTH];
    int num_suggestions = 0;
    find_suggestions(root, word, suggestions);

    // Print the suggestions
    print_suggestions(suggestions, num_suggestions);
  }
}

int main() {
  // Create the root node of the trie
  node *root = create_node(' ');

  // Load the dictionary into the trie
  load_dictionary(root, "dictionary.txt");

  // Get the word to check from the user
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to check: ");
  scanf("%s", word);

  // Check the spelling of the word
  check_spelling(root, word);

  return 0;
}