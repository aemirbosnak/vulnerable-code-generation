//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom hash function that maps characters to numbers
int hash(char c) {
  return (int)c - 97;
}

// A custom linked list node structure for storing words
struct node {
  char *word;
  struct node *next;
};

// A custom linked list structure for storing words
struct list {
  struct node *head;
  struct node *tail;
};

// Create a new linked list
struct list *new_list() {
  struct list *list = malloc(sizeof(struct list));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

// Insert a word into a linked list
void insert(struct list *list, char *word) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->word = strdup(word);
  new_node->next = NULL;
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

// Print a linked list of words
void print_list(struct list *list) {
  struct node *current = list->head;
  while (current != NULL) {
    printf("%s\n", current->word);
    current = current->next;
  }
}

// Free a linked list of words
void free_list(struct list *list) {
  struct node *current = list->head;
  while (current != NULL) {
    struct node *next = current->next;
    free(current->word);
    free(current);
    current = next;
  }
  free(list);
}

// Create a hash table of words
struct hash_table {
  struct list **table;
  int size;
};

// Create a new hash table
struct hash_table *new_hash_table(int size) {
  struct hash_table *table = malloc(sizeof(struct hash_table));
  table->table = malloc(sizeof(struct list *) * size);
  table->size = size;
  for (int i = 0; i < size; i++) {
    table->table[i] = new_list();
  }
  return table;
}

// Insert a word into a hash table
void insert_hash(struct hash_table *table, char *word) {
  int index = hash(word[0]);
  insert(table->table[index], word);
}

// Print a hash table of words
void print_hash(struct hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    printf("Bucket %d:\n", i);
    print_list(table->table[i]);
    printf("\n");
  }
}

// Free a hash table of words
void free_hash(struct hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    free_list(table->table[i]);
  }
  free(table->table);
  free(table);
}

// Read a text file into a linked list of words
struct list *read_file(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", filename);
    return NULL;
  }

  struct list *list = new_list();
  char word[100];
  while (fscanf(file, "%s", word) != EOF) {
    insert(list, word);
  }

  fclose(file);
  return list;
}

// Print the unique words in a text file
void print_unique_words(char *filename) {
  struct list *list = read_file(filename);
  if (list == NULL) {
    return;
  }

  struct hash_table *table = new_hash_table(100);
  struct node *current = list->head;
  while (current != NULL) {
    insert_hash(table, current->word);
    current = current->next;
  }

  print_hash(table);

  free_hash(table);
  free_list(list);
}

int main() {
  print_unique_words("text.txt");
  return 0;
}