//FormAI DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define VALUE_SIZE 256
#define HASH_SIZE 997

typedef struct node {
  char key[KEY_SIZE];
  char value[VALUE_SIZE];
  struct node* next;
} Node;

Node* hash_table[HASH_SIZE];

int hash(char* key) {
  int sum = 0;
  for (int i = 0; i < KEY_SIZE; i++) {
    sum += key[i];
  }
  return sum % HASH_SIZE;
}

void insert(char* key, char* value) {
  int index = hash(key);
  Node* new_node = (Node*)malloc(sizeof(Node));
  strcpy(new_node->key, key);
  strcpy(new_node->value, value);
  new_node->next = hash_table[index];
  hash_table[index] = new_node;
}

char* search(char* key) {
  int index = hash(key);
  Node* current_node = hash_table[index];
  while (current_node != NULL) {
    if (strcmp(current_node->key, key) == 0) {
      return current_node->value;
    }
    current_node = current_node->next;
  }
  return NULL;
}

void print_table() {
  for (int i = 0; i < HASH_SIZE; i++) {
    if (hash_table[i] != NULL) {
      printf("%d: ", i);
      Node* current_node = hash_table[i];
      while (current_node != NULL) {
        printf("(%s, %s) ", current_node->key, current_node->value);
        current_node = current_node->next;
      }
      printf("\n");
    }
  }
}

int main() {
  memset(hash_table, 0, sizeof(hash_table));

  insert("John Smith", "jsmith@gmail.com");
  insert("Sarah Williams", "swilliams@yahoo.com");
  insert("Tom Jones", "tjones@hotmail.com");
  insert("Emily Wilson", "ewilson@gmail.com");

  printf("Search results:\n");
  printf("John Smith: %s\n", search("John Smith"));
  printf("Sarah Williams: %s\n", search("Sarah Williams"));
  printf("Tom Jones: %s\n", search("Tom Jones"));
  printf("Emily Wilson: %s\n", search("Emily Wilson"));

  printf("\nHash table:\n");
  print_table();

  return 0;
}