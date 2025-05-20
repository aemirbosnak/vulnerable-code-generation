//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node {
  char data[100];
  struct Node* next;
  struct Node* prev;
  struct Index* idx;
};

struct Index {
  char key[20];
  struct Node* head;
  struct Index* next;
};

struct Database {
  struct Index* head;
  struct Index* tail;
  int size;
};

void Insert(struct Database* db, char* data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->data, data);
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->idx = NULL;

  if (db->head == NULL) {
    db->head = newNode;
    db->tail = newNode;
  } else {
    db->tail->next = newNode;
    db->tail = newNode;
  }

  db->size++;
}

void IndexInsert(struct Database* db, char* key, char* data) {
  struct Index* newIndex = malloc(sizeof(struct Index));
  strcpy(newIndex->key, key);
  newIndex->head = NULL;
  newIndex->next = NULL;

  if (db->head == NULL) {
    db->head = newIndex;
    db->tail = newIndex;
  } else {
    db->tail->next = newIndex;
    db->tail = newIndex;
  }

  db->size++;
}

int main() {
  struct Database* db = malloc(sizeof(struct Database));
  db->head = NULL;
  db->tail = NULL;
  db->size = 0;

  Insert(db, "John Doe");
  Insert(db, "Jane Doe");
  Insert(db, "Peter Pan");

  IndexInsert(db, "Age", "25");
  IndexInsert(db, "Occupation", "Teacher");

  struct Index* idx = db->head;
  while (idx) {
    printf("%s - %s\n", idx->key, idx->head->data);
    idx = idx->next;
  }

  return 0;
}