//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdint.h>

//-----------------
// paranoid hashmap
//-----------------

// the hash function
#define HASH(s) ((s[0] - 32) % 127)
#define HASH_SIZE 127

// the node
typedef struct node {
  char *key;
  int value;
  struct node *next;
} node_t;

// the hashmap
node_t *hashmap[HASH_SIZE];

// insert a key/value pair into the hashmap
void hashmap_insert(char *key, int value) {
  // get the hash value
  int h = HASH(key);

  // create a new node
  node_t *node = malloc(sizeof(node_t));
  node->key = strdup(key);
  node->value = value;
  node->next = NULL;

  // insert the node into the hashmap
  node->next = hashmap[h];
  hashmap[h] = node;
}

// get the value associated with a key from the hashmap
int hashmap_get(char *key) {
  // get the hash value
  int h = HASH(key);

  // iterate over the linked list
  node_t *node = hashmap[h];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      return node->value;
    }
    node = node->next;
  }

  // the key was not found
  return 0;
}

// print the contents of the hashmap
void hashmap_print() {
  for (int i = 0; i < HASH_SIZE; i++) {
    node_t *node = hashmap[i];
    while (node != NULL) {
      printf("%s: %d\n", node->key, node->value);
      node = node->next;
    }
  }
}

//-----------------
// main function
//-----------------

int main() {
  char *input = "the quick brown fox jumps over the lazy dog";

  // tokenize the input
  char *token = strtok(input, " ");
  while (token != NULL) {
    // remove non-alphabetic characters
    for (char *p = token; *p != '\0'; p++) {
      *p = tolower(*p);
      if (!isalpha(*p)) {
        *p = '\0';
      }
    }

    // insert the token into the hashmap
    int count = hashmap_get(token);
    hashmap_insert(token, count + 1);

    // get the next token
    token = strtok(NULL, " ");
  }

  // print the contents of the hashmap
  hashmap_print();

  return 0;
}