//FormAI DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 500
#define MAX_STR_LEN 100

typedef struct {
  char name[MAX_STR_LEN];
  int id;
} Entry;

typedef struct {
  Entry* data[MAX_INDEX];
  int size;
} Index;

// function to insert a new entry into the index
void insert(Index* index, Entry* entry) {
  if (index->size >= MAX_INDEX) {
    fprintf(stderr, "Index is full!\n");
    return;
  }
  index->data[index->size++] = entry;
}

// function to search for an entry by name in the index
Entry* search(Index* index, char* name) {
  for (int i = 0; i < index->size; i++) {
    if (strcmp(index->data[i]->name, name) == 0)
      return index->data[i];
  }
  return NULL;
}

int main(void) {
  Index myIndex;
  myIndex.size = 0;

  // adding some sample entries to the index
  Entry* entry1 = malloc(sizeof(Entry));
  strcpy(entry1->name, "John");
  entry1->id = 1;
  insert(&myIndex, entry1);

  Entry* entry2 = malloc(sizeof(Entry));
  strcpy(entry2->name, "Mary");
  entry2->id = 2;
  insert(&myIndex, entry2);

  Entry* entry3 = malloc(sizeof(Entry));
  strcpy(entry3->name, "Peter");
  entry3->id = 3;
  insert(&myIndex, entry3);

  // search for an entry by name
  char searchName[MAX_STR_LEN] = "Mary";
  Entry* result = search(&myIndex, searchName);

  if (result != NULL)
    printf("Found entry with ID: %d\n", result->id);
  else
    printf("Entry with name '%s' not found!\n", searchName);

  return 0;
}