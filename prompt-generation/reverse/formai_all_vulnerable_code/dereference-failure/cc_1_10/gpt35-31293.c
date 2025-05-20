//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define HASH_TABLE_SIZE 1000

typedef struct Node {
  char word[MAX_WORD_LENGTH];
  int frequency;
  struct Node* next;
} Node;

Node* hash_table[HASH_TABLE_SIZE];

unsigned long hash_function(char* word) {
  unsigned long hash = 5381;
  int c;

  while ((c = *word++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash % HASH_TABLE_SIZE;
}

Node* create_node(char* word) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->frequency = 1;
  strcpy(node->word, word);
  node->next = NULL;
  return node;
}

void insert_word(char* word) {
  unsigned long hash_val = hash_function(word);
  Node* node = hash_table[hash_val];

  while (node != NULL) {
    if (strcmp(node->word, word) == 0) {
      node->frequency++;
      return;
    }
    node = node->next;
  }

  Node* new_node = create_node(word);
  new_node->next = hash_table[hash_val];
  hash_table[hash_val] = new_node;
}

int main() {
  char filename[50];
  char word[MAX_WORD_LENGTH];
  FILE* file;
  
  printf("Please enter the name of a text file: ");
  scanf("%s", filename);

  file = fopen(filename, "r");
  
  if (!file) {
    printf("Could not open file %s", filename);
    return 1;
  }

  while (fscanf(file, "%s", word) != EOF) {
    char* p = word;
    while (*p) {
      *p = tolower(*p);
      p++;
    }
    insert_word(word);
  }

  fclose(file);

  printf("| %-20s | %-10s |\n", "WORD", "FREQUENCY");
  printf("|----------------------|------------|\n");

  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    Node* node = hash_table[i];
    while (node != NULL) {
      printf("| %-20s | %-10d |\n", node->word, node->frequency);
      node = node->next;
    }
  }

  return 0;
}