//Gemma-7B DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

struct Database {
  Node* head;
  int size;
  int (*compare)(const void*, const void*);
  void (*print)(const void*);
};

void insert(struct Database* db, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (db->head == NULL) {
    db->head = newNode;
  } else {
    db->head->next = newNode;
  }

  db->size++;
}

void printDatabase(struct Database* db) {
  Node* current = db->head;

  while (current) {
    printf("%c ", current->data);
    current = current->next;
  }

  printf("\n");
}

int compareStrings(const void* a, const void* b) {
  return strcmp((char*)a, (char*)b);
}

int main() {
  struct Database* db = malloc(sizeof(struct Database));
  db->head = NULL;
  db->size = 0;
  db->compare = compareStrings;
  db->print = printDatabase;

  insert(db, 'a');
  insert(db, 'b');
  insert(db, 'c');
  insert(db, 'd');

  printDatabase(db);

  return 0;
}