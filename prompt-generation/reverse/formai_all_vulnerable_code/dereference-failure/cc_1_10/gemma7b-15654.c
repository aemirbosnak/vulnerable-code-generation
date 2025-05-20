//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
  char data[MAX_INDEX_SIZE];
  struct Node* next;
} Node;

struct Index {
  Node* head;
  int size;
  time_t last_updated;
};

void insert_index(struct Index* index, char* data) {
  Node* new_node = malloc(sizeof(Node));
  strcpy(new_node->data, data);
  new_node->next = NULL;

  if (index->head == NULL) {
    index->head = new_node;
  } else {
    index->head->next = new_node;
  }

  index->size++;
  index->last_updated = time(NULL);
}

void search_index(struct Index* index, char* data) {
  Node* current_node = index->head;

  while (current_node) {
    if (strcmp(current_node->data, data) == 0) {
      printf("Data found: %s\n", current_node->data);
      return;
    }

    current_node = current_node->next;
  }

  printf("Data not found.\n");
}

int main() {
  struct Index index;
  index.head = NULL;
  index.size = 0;
  index.last_updated = time(NULL);

  insert_index(&index, "John Doe");
  insert_index(&index, "Jane Doe");
  insert_index(&index, "Peter Pan");

  search_index(&index, "Jane Doe");

  return 0;
}