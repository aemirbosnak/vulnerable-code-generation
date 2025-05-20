//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_WORD_LEN 64
#define MAX_WORDS 100000

// Linked list node for storing words
typedef struct node {
  char *word;
  struct node *next;
} node_t;

// Hash table for storing words
typedef struct hash_table {
  node_t **table;
  int size;
} hash_table_t;

// Create a new hash table
hash_table_t *create_hash_table(int size) {
  hash_table_t *ht = malloc(sizeof(hash_table_t));
  ht->size = size;
  ht->table = malloc(sizeof(node_t *) * size);
  for (int i = 0; i < size; i++) {
    ht->table[i] = NULL;
  }
  return ht;
}

// Destroy a hash table
void destroy_hash_table(hash_table_t *ht) {
  for (int i = 0; i < ht->size; i++) {
    node_t *node = ht->table[i];
    while (node != NULL) {
      node_t *next = node->next;
      free(node->word);
      free(node);
      node = next;
    }
  }
  free(ht->table);
  free(ht);
}

// Hash function
int hash_function(char *word, int size) {
  int hash = 0;
  for (int i = 0; i < strlen(word); i++) {
    hash = (hash * 31 + tolower(word[i])) % size;
  }
  return hash;
}

// Insert a word into the hash table
void insert_word(hash_table_t *ht, char *word) {
  int hash = hash_function(word, ht->size);
  node_t *node = malloc(sizeof(node_t));
  node->word = strdup(word);
  node->next = ht->table[hash];
  ht->table[hash] = node;
}

// Check if a word is in the hash table
int is_in_dictionary(hash_table_t *ht, char *word) {
  int hash = hash_function(word, ht->size);
  node_t *node = ht->table[hash];
  while (node != NULL) {
    if (strcmp(word, node->word) == 0) {
      return 1;
    }
    node = node->next;
  }
  return 0;
}

// Load words from a file into the hash table
void load_dictionary(hash_table_t *ht, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char word[MAX_WORD_LEN];
  while (fscanf(file, "%s", word) != EOF) {
    insert_word(ht, word);
  }

  fclose(file);
}

// Check the spelling of a word
int check_spelling(hash_table_t *ht, char *word) {
  return is_in_dictionary(ht, word);
}

// Get suggestions for a misspelled word
char **get_suggestions(hash_table_t *ht, char *word) {
  char **suggestions = malloc(sizeof(char *) * MAX_WORDS);
  int num_suggestions = 0;

  // Try all possible edits of the word
  for (int i = 0; i < strlen(word); i++) {
    // Delete a character
    char *new_word = malloc(strlen(word) + 1);
    strcpy(new_word, word);
    new_word[i] = '\0';
    if (is_in_dictionary(ht, new_word)) {
      suggestions[num_suggestions++] = new_word;
    }
    free(new_word);

    // Insert a character
    for (int j = 0; j <= strlen(word); j++) {
      new_word = malloc(strlen(word) + 2);
      strcpy(new_word, word);
      new_word[j] = 'a';
      new_word[j + 1] = '\0';
      if (is_in_dictionary(ht, new_word)) {
        suggestions[num_suggestions++] = new_word;
      }
      free(new_word);
    }

    // Replace a character
    for (char c = 'a'; c <= 'z'; c++) {
      new_word = malloc(strlen(word) + 1);
      strcpy(new_word, word);
      new_word[i] = c;
      if (is_in_dictionary(ht, new_word)) {
        suggestions[num_suggestions++] = new_word;
      }
      free(new_word);
    }

    // Swap two characters
    if (i < strlen(word) - 1) {
      new_word = malloc(strlen(word) + 1);
      strcpy(new_word, word);
      char tmp = new_word[i];
      new_word[i] = new_word[i + 1];
      new_word[i + 1] = tmp;
      if (is_in_dictionary(ht, new_word)) {
        suggestions[num_suggestions++] = new_word;
      }
      free(new_word);
    }
  }

  return suggestions;
}

// Print the suggestions for a misspelled word
void print_suggestions(char **suggestions, int num_suggestions) {
  printf("Did you mean:\n");
  for (int i = 0; i < num_suggestions; i++) {
    printf("%s ", suggestions[i]);
    free(suggestions[i]);
  }
  printf("\n");
}

// Main function
int main(int argc, char **argv) {
  // Create a hash table to store the dictionary
  hash_table_t *ht = create_hash_table(100000);

  // Load the dictionary into the hash table
  load_dictionary(ht, "dictionary.txt");

  // Get the word to check from the user
  char word[MAX_WORD_LEN];
  printf("Enter a word to check: ");
  scanf("%s", word);

  // Check the spelling of the word
  int is_correct = check_spelling(ht, word);

  // If the word is misspelled, get suggestions
  char **suggestions;
  int num_suggestions;
  if (!is_correct) {
    suggestions = get_suggestions(ht, word);
    num_suggestions = 0;
    while (suggestions[num_suggestions] != NULL) {
      num_suggestions++;
    }
  }

  // Print the results
  if (is_correct) {
    printf("The word is spelled correctly.\n");
  } else {
    printf("The word is spelled incorrectly.\n");
    print_suggestions(suggestions, num_suggestions);
  }

  // Destroy the hash table
  destroy_hash_table(ht);

  return 0;
}