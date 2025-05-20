//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in a linked list
struct node {
  char* word;
  struct node* next;
};

// A hash table
struct hash_table {
  struct node** table;
  int size;
};

// Create a new hash table
struct hash_table* create_hash_table(int size) {
  struct hash_table* table = malloc(sizeof(struct hash_table));
  table->table = malloc(sizeof(struct node*) * size);
  table->size = size;
  for (int i = 0; i < size; i++) {
    table->table[i] = NULL;
  }
  return table;
}

// Insert a word into a hash table
void insert_word(struct hash_table* table, char* word) {
  int index = hash(word) % table->size;
  struct node* new_node = malloc(sizeof(struct node));
  new_node->word = word;
  new_node->next = table->table[index];
  table->table[index] = new_node;
}

// Check if a word is in a hash table
int is_word_in_table(struct hash_table* table, char* word) {
  int index = hash(word) % table->size;
  struct node* current_node = table->table[index];
  while (current_node != NULL) {
    if (strcmp(current_node->word, word) == 0) {
      return 1;
    }
    current_node = current_node->next;
  }
  return 0;
}

// Hash a word
int hash(char* word) {
  int hash = 0;
  for (int i = 0; i < strlen(word); i++) {
    hash = hash * 31 + word[i];
  }
  return hash;
}

// Load a dictionary into a hash table
void load_dictionary(struct hash_table* table, char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening dictionary file %s\n", filename);
    exit(1);
  }
  char word[1024];
  while (fscanf(file, "%s", word) != EOF) {
    insert_word(table, word);
  }
  fclose(file);
}

// Check the spelling of a word
int check_spelling(char* word, struct hash_table* table) {
  return is_word_in_table(table, word);
}

// Print the suggestions for a misspelled word
void print_suggestions(char* word, struct hash_table* table) {
  int index = hash(word) % table->size;
  struct node* current_node = table->table[index];
  while (current_node != NULL) {
    if (strcmp(current_node->word, word) != 0) {
      printf("%s\n", current_node->word);
    }
    current_node = current_node->next;
  }
}

// Main function
int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: %s <dictionary file> <word to check>\n", argv[0]);
    exit(1);
  }

  // Create a hash table
  struct hash_table* table = create_hash_table(10000);

  // Load the dictionary into the hash table
  load_dictionary(table, argv[1]);

  // Check the spelling of the word
  int is_correct = check_spelling(argv[2], table);

  // Print the result
  if (is_correct) {
    printf("The word \"%s\" is spelled correctly.\n", argv[2]);
  } else {
    printf("The word \"%s\" is spelled incorrectly.\n", argv[2]);
    printf("Suggestions:\n");
    print_suggestions(argv[2], table);
  }

  // Free the hash table
  free(table->table);
  free(table);

  return 0;
}