//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum number of words to store.
#define MAX_WORDS 10000

// The maximum length of a word.
#define MAX_WORD_LENGTH 100

// The hash table size.
#define HASH_TABLE_SIZE 10000

// The hash table.
struct hash_table {
  char *words[HASH_TABLE_SIZE];
  int counts[HASH_TABLE_SIZE];
};

// Create a new hash table.
struct hash_table *hash_table_new() {
  struct hash_table *hash_table = malloc(sizeof(struct hash_table));
  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    hash_table->words[i] = NULL;
    hash_table->counts[i] = 0;
  }
  return hash_table;
}

// Destroy a hash table.
void hash_table_destroy(struct hash_table *hash_table) {
  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    free(hash_table->words[i]);
  }
  free(hash_table);
}

// Hash a word.
int hash(char *word) {
  int hash_value = 0;
  for (int i = 0; i < strlen(word); i++) {
    hash_value += word[i];
  }
  return hash_value % HASH_TABLE_SIZE;
}

// Insert a word into the hash table.
void hash_table_insert(struct hash_table *hash_table, char *word) {
  int hash_value = hash(word);
  while (hash_table->words[hash_value] != NULL) {
    hash_value++;
  }
  hash_table->words[hash_value] = strdup(word);
  hash_table->counts[hash_value]++;
}

// Find a word in the hash table.
int hash_table_find(struct hash_table *hash_table, char *word) {
  int hash_value = hash(word);
  while (hash_table->words[hash_value] != NULL) {
    if (strcmp(hash_table->words[hash_value], word) == 0) {
      return hash_table->counts[hash_value];
    }
    hash_value++;
  }
  return 0;
}

// Read a file into a string.
char *read_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }
  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);
  char *file_contents = malloc(file_size + 1);
  fread(file_contents, file_size, 1, fp);
  file_contents[file_size] = '\0';
  fclose(fp);
  return file_contents;
}

// Count the words in a string.
struct hash_table *count_words(char *string) {
  struct hash_table *hash_table = hash_table_new();
  char *word = strtok(string, " ");
  while (word != NULL) {
    hash_table_insert(hash_table, word);
    word = strtok(NULL, " ");
  }
  return hash_table;
}

// Print the words and their counts.
void print_words(struct hash_table *hash_table) {
  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    if (hash_table->words[i] != NULL) {
      printf("%s: %d\n", hash_table->words[i], hash_table->counts[i]);
    }
  }
}

// Main function.
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return 1;
  }
  char *file_contents = read_file(argv[1]);
  if (file_contents == NULL) {
    fprintf(stderr, "Error reading file: %s\n", argv[1]);
    return 1;
  }
  struct hash_table *hash_table = count_words(file_contents);
  print_words(hash_table);
  hash_table_destroy(hash_table);
  free(file_contents);
  return 0;
}