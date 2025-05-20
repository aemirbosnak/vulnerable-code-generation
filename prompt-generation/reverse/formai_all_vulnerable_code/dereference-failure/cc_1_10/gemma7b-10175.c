//Gemma-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_KEY_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Key {
  int size;
  Node** keys;
} Key;

void initialize_key(Key* key) {
  key->size = 0;
  key->keys = NULL;
}

void add_key(Key* key, char data) {
  Node* new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (key->keys == NULL) {
    key->keys = malloc(sizeof(Node*) * MAX_KEY_SIZE);
  }

  key->keys[key->size++] = new_node;
}

void encrypt(Key* key, char message) {
  for (int i = 0; i < key->size; i++) {
    if (key->keys[i]->data == message) {
      message = (message + key->keys[i]->next->data) % 26;
    }
  }

  message += 65;
  printf("%c", message);
}

int main() {
  Key* key = malloc(sizeof(Key));
  initialize_key(key);

  add_key(key, 'a');
  add_key(key, 'b');
  add_key(key, 'c');

  encrypt(key, 'f');

  return 0;
}