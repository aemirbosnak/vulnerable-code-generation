//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in a linked list
typedef struct node {
  char* word;
  int count;
  struct node* next;
} node_t;

// A linked list of words
typedef struct word_list {
  node_t* head;
  node_t* tail;
} word_list_t;

// Create a new word list
word_list_t* create_word_list() {
  word_list_t* list = malloc(sizeof(word_list_t));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

// Add a word to a word list
void add_word_to_list(word_list_t* list, char* word) {
  // Create a new node
  node_t* node = malloc(sizeof(node_t));
  node->word = strdup(word);
  node->count = 1;
  node->next = NULL;

  // If the list is empty, set the head and tail to the new node
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    // Add the new node to the end of the list
    list->tail->next = node;
    list->tail = node;
  }
}

// Get the count of a word in a word list
int get_word_count(word_list_t* list, char* word) {
  // Iterate over the list and find the word
  node_t* node = list->head;
  while (node != NULL) {
    if (strcmp(node->word, word) == 0) {
      return node->count;
    }
    node = node->next;
  }

  // The word was not found in the list
  return 0;
}

// Print a word list
void print_word_list(word_list_t* list) {
  // Iterate over the list and print each word and its count
  node_t* node = list->head;
  while (node != NULL) {
    printf("%s: %d\n", node->word, node->count);
    node = node->next;
  }
}

// Free a word list
void free_word_list(word_list_t* list) {
  // Iterate over the list and free each node
  node_t* node = list->head;
  while (node != NULL) {
    node_t* next = node->next;
    free(node->word);
    free(node);
    node = next;
  }

  // Free the list itself
  free(list);
}

// Read a file into a word list
word_list_t* read_file_into_word_list(char* filename) {
  // Open the file
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Create a new word list
  word_list_t* list = create_word_list();

  // Read the file line by line
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    // Tokenize the line
    char* token = strtok(line, " ");
    while (token != NULL) {
      // Add the token to the word list
      add_word_to_list(list, token);

      // Get the next token
      token = strtok(NULL, " ");
    }
  }

  // Close the file
  fclose(file);

  // Return the word list
  return list;
}

// Main function
int main(int argc, char** argv) {
  // Check if a filename was specified
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Read the file into a word list
  word_list_t* list = read_file_into_word_list(argv[1]);

  // Print the word list
  print_word_list(list);

  // Free the word list
  free_word_list(list);

  return 0;
}