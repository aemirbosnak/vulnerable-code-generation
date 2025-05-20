//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
  char name[MAX_SIZE];
  struct Node* next;
} Node;

struct HashTable {
  int size;
  Node** buckets;
  int (*compare)(char*, char*);
  void (*insert)(char*);
  void (*search)(char*);
};

void insert(struct HashTable* ht, char* name) {
  int hash = ht->compare(name, ht->buckets);
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = ht->buckets[hash];
  ht->buckets[hash] = newNode;
}

void search(struct HashTable* ht, char* name) {
  int hash = ht->compare(name, ht->buckets);
  Node* current = ht->buckets[hash];
  while (current) {
    if (strcmp(current->name, name) == 0) {
      printf("Found!\n");
      return;
    }
    current = current->next;
  }
  printf("Not found.\n");
}

int main() {
  struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
  ht->size = 10;
  ht->buckets = (Node**)malloc(sizeof(Node*) * ht->size);
  ht->compare = strcmp;
  ht->insert = insert;
  ht->search = search;

  insert(ht, "John Doe");
  insert(ht, "Jane Doe");
  insert(ht, "Jack Smith");
  insert(ht, "Mary Johnson");

  search(ht, "Jane Doe");
  search(ht, "Bob Smith");

  return 0;
}