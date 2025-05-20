//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_CAPACITY 10000 // number of buckets in hash table

typedef struct Node {
  char* word; // pointer to the word string
  int count; // frequency count of a word
  struct Node* next; // pointer to the next node in the list
} Node;

Node* hashTable[HASH_CAPACITY] = {0}; // initialize hash table with null pointers

// Hash function based on djb2 algorithm
unsigned long hash(const char* str) {
  unsigned long hash = 5381;
  int c;

  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash % HASH_CAPACITY;
}

// Create a new node with the given word and count
Node* newNode(const char* word, const int count) {
  Node* node = (Node*) malloc(sizeof(Node));

  node->word = (char*) malloc(strlen(word) + 1);
  strcpy(node->word, word);

  node->count = count;
  node->next = NULL;

  return node;
}

// Insert the node with the given word and count into the hash table
void insert(Node** hashTable, const char* word, const int count) {
  const unsigned long index = hash(word);

  if (!hashTable[index]) { // no collision
    hashTable[index] = newNode(word, count);
  } else { // collision occurred, add to linked list
    Node* curr = hashTable[index];

    while (curr) {
      if (strcmp(curr->word, word) == 0) { // found the same word, increment the count
        curr->count += count;
        return;
      }

      if (!curr->next) { // end of the list, append a new node
        curr->next = newNode(word, count);
        return;
      }

      curr = curr->next;
    }
  }
}

// Destroy the hash table and release memory
void destroyTable(Node** hashTable) {
  for (int i = 0; i < HASH_CAPACITY; i++) {
    Node* curr = hashTable[i];

    while (curr) {
      Node* next = curr->next;

      free(curr->word);
      free(curr);

      curr = next;
    }
  }
}

// Convert the word string to lowercase
void toLower(char* str) {
  for (int i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
}

// Tokenize the input string into words and update the frequency counts
void countWords(Node** hashTable, const char* str) {
  const char delimiter[] = " \n\t\r\v\f"; // whitespace characters
  char* copy = (char*) malloc(strlen(str) + 1);
  strcpy(copy, str);

  char* token = strtok(copy, delimiter);

  while (token) {
    toLower(token);
    insert(hashTable, token, 1);
    token = strtok(NULL, delimiter);
  }

  free(copy);
}

int main() {
  printf("Enter a text string:\n");
  char input[256];
  fgets(input, 256, stdin);

  countWords(hashTable, input);

  printf("Word frequency counts:\n");

  for (int i = 0; i < HASH_CAPACITY; i++) {
    Node* curr = hashTable[i];

    while (curr) {
      printf("%-20s %d\n", curr->word, curr->count);
      curr = curr->next;
    }
  }

  destroyTable(hashTable);

  return 0;
}