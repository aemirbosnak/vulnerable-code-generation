//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_SIZE 1000

// Create a node for the trie
typedef struct trie_node {
  char letter;
  int count;
  struct trie_node *children[26];
} trie_node;

// Create a new trie node
trie_node *create_trie_node(char letter) {
  trie_node *new_node = malloc(sizeof(trie_node));
  new_node->letter = letter;
  new_node->count = 0;
  for (int i = 0; i < 26; i++) {
    new_node->children[i] = NULL;
  }
  return new_node;
}

// Insert a word into the trie
void insert_word_into_trie(trie_node *root, char *word) {
  trie_node *current_node = root;
  for (int i = 0; i < strlen(word); i++) {
    char letter = tolower(word[i]);
    int index = letter - 'a';
    if (current_node->children[index] == NULL) {
      current_node->children[index] = create_trie_node(letter);
    }
    current_node = current_node->children[index];
  }
  current_node->count++;
}

// Search for a word in the trie
int search_word_in_trie(trie_node *root, char *word) {
  trie_node *current_node = root;
  for (int i = 0; i < strlen(word); i++) {
    char letter = tolower(word[i]);
    int index = letter - 'a';
    if (current_node->children[index] == NULL) {
      return 0;
    }
    current_node = current_node->children[index];
  }
  return current_node->count;
}

// Print the words in the trie
void print_words_in_trie(trie_node *root, char *prefix) {
  if (root->count > 0) {
    printf("%s: %d\n", prefix, root->count);
  }
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      char new_prefix[strlen(prefix) + 1];
      strcpy(new_prefix, prefix);
      new_prefix[strlen(prefix)] = root->children[i]->letter;
      print_words_in_trie(root->children[i], new_prefix);
    }
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

// Read a file into a string
char *read_file_into_string(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);
  char *file_contents = malloc(file_size + 1);
  fread(file_contents, file_size, 1, file);
  fclose(file);
  file_contents[file_size] = '\0';
  return file_contents;
}

// Split a string into an array of words
char **split_string_into_words(char *string) {
  char **words = malloc(sizeof(char *) * MAX_DICTIONARY_SIZE);
  int num_words = 0;
  char *word = strtok(string, " ");
  while (word != NULL) {
    words[num_words] = word;
    num_words++;
    word = strtok(NULL, " ");
  }
  return words;
}

// Free an array of words
void free_words(char **words) {
  for (int i = 0; i < MAX_DICTIONARY_SIZE; i++) {
    free(words[i]);
  }
  free(words);
}

// Main function
int main() {
  // Create the root of the trie
  trie_node *root = create_trie_node(' ');

  // Read the file into a string
  char *file_contents = read_file_into_string("text.txt");
  if (file_contents == NULL) {
    printf("Error reading file.\n");
    return 1;
  }

  // Split the string into an array of words
  char **words = split_string_into_words(file_contents);

  // Insert the words into the trie
  for (int i = 0; i < MAX_DICTIONARY_SIZE; i++) {
    if (words[i] != NULL) {
      insert_word_into_trie(root, words[i]);
    }
  }

  // Print the words in the trie
  print_words_in_trie(root, "");

  // Free the trie
  free_trie(root);

  // Free the words
  free_words(words);

  // Free the file contents
  free(file_contents);

  return 0;
}