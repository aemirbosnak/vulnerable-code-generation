//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int key;
  char *value;
} entry_t;

typedef struct {
  int size;
  entry_t *entries;
} index_t;

index_t *create_index() {
  index_t *index = malloc(sizeof(index_t));
  index->size = 0;
  index->entries = NULL;
  return index;
}

void destroy_index(index_t *index) {
  for (int i = 0; i < index->size; i++) {
    free(index->entries[i].value);
  }
  free(index->entries);
  free(index);
}

void insert_into_index(index_t *index, int key, char *value) {
  index->entries = realloc(index->entries, (index->size + 1) * sizeof(entry_t));
  index->entries[index->size].key = key;
  index->entries[index->size].value = malloc(strlen(value) + 1);
  strcpy(index->entries[index->size].value, value);
  index->size++;
}

char *get_from_index(index_t *index, int key) {
  for (int i = 0; i < index->size; i++) {
    if (index->entries[i].key == key) {
      return index->entries[i].value;
    }
  }
  return NULL;
}

void print_index(index_t *index) {
  for (int i = 0; i < index->size; i++) {
    printf("%d: %s\n", index->entries[i].key, index->entries[i].value);
  }
}

int main() {
  index_t *index = create_index();
  insert_into_index(index, 1, "One");
  insert_into_index(index, 2, "Two");
  insert_into_index(index, 3, "Three");
  insert_into_index(index, 4, "Four");
  insert_into_index(index, 5, "Five");
  print_index(index);
  destroy_index(index);
  return 0;
}