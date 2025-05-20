//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct node {
  char word[MAX_WORD_LENGTH];
  struct node *next;
} node;

node *hash_table[MAX_WORDS];

// Insert a word into the hash table
void insert(char *word) {
  int index = hash(word);
  node *new_node = malloc(sizeof(node));
  strcpy(new_node->word, word);
  new_node->next = hash_table[index];
  hash_table[index] = new_node;
}

// Search for a word in the hash table
bool search(char *word) {
  int index = hash(word);
  node *current = hash_table[index];
  while (current != NULL) {
    if (strcmp(current->word, word) == 0) {
      return true;
    }
    current = current->next;
  }
  return false;
}

// Check if a word is spelled correctly
bool check_spelling(char *word) {
  return search(word);
}

// Read a list of words from a file
void read_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: could not open file %s\n", filename);
    exit(1);
  }
  char buffer[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", buffer) != EOF) {
    insert(buffer);
  }
  fclose(file);
}

// Get the hash value for a word
int hash(char *word) {
  int hash_value = 0;
  for (int i = 0; i < strlen(word); i++) {
    hash_value += word[i];
  }
  return hash_value % MAX_WORDS;
}

// Print the contents of the hash table
void print_hash_table() {
  for (int i = 0; i < MAX_WORDS; i++) {
    node *current = hash_table[i];
    printf("%d: ", i);
    while (current != NULL) {
      printf("%s -> ", current->word);
      current = current->next;
    }
    printf("\n");
  }
}

// Free the memory allocated for the hash table
void free_hash_table() {
  for (int i = 0; i < MAX_WORDS; i++) {
    node *current = hash_table[i];
    while (current != NULL) {
      node *next = current->next;
      free(current);
      current = next;
    }
  }
}

int main() {
  // Read the dictionary into the hash table
  read_dictionary("dictionary.txt");

  // Check the spelling of some words
  char *words[] = {"hello", "world", "computer", "science", "programming"};
  for (int i = 0; i < 5; i++) {
    if (check_spelling(words[i])) {
      printf("%s: Spelling is correct!\n", words[i]);
    } else {
      printf("%s: Spelling is incorrect!\n", words[i]);
    }
  }

  // Print the contents of the hash table
  print_hash_table();

  // Free the memory allocated for the hash table
  free_hash_table();

  return 0;
}