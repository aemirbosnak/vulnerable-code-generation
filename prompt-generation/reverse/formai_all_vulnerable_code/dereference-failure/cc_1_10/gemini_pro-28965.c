//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 100
#define MAX_INDEX_SIZE 100

typedef struct {
  int key;
  char *value;
} Entry;

typedef struct {
  Entry *entries;
  int size;
} Table;

typedef struct {
  char *key;
  int value;
} IndexEntry;

typedef struct {
  IndexEntry *entries;
  int size;
} Index;

Table *table_create() {
  Table *table = malloc(sizeof(Table));
  table->entries = malloc(sizeof(Entry) * MAX_TABLE_SIZE);
  table->size = 0;
  return table;
}

void table_destroy(Table *table) {
  for (int i = 0; i < table->size; i++) {
    free(table->entries[i].value);
  }
  free(table->entries);
  free(table);
}

int table_insert(Table *table, int key, char *value) {
  if (table->size == MAX_TABLE_SIZE) {
    return -1;
  }
  table->entries[table->size].key = key;
  table->entries[table->size].value = strdup(value);
  table->size++;
  return 0;
}

char *table_get(Table *table, int key) {
  for (int i = 0; i < table->size; i++) {
    if (table->entries[i].key == key) {
      return table->entries[i].value;
    }
  }
  return NULL;
}

Index *index_create() {
  Index *index = malloc(sizeof(Index));
  index->entries = malloc(sizeof(IndexEntry) * MAX_INDEX_SIZE);
  index->size = 0;
  return index;
}

void index_destroy(Index *index) {
  for (int i = 0; i < index->size; i++) {
    free(index->entries[i].key);
  }
  free(index->entries);
  free(index);
}

int index_insert(Index *index, char *key, int value) {
  if (index->size == MAX_INDEX_SIZE) {
    return -1;
  }
  index->entries[index->size].key = strdup(key);
  index->entries[index->size].value = value;
  index->size++;
  return 0;
}

int index_get(Index *index, char *key) {
  for (int i = 0; i < index->size; i++) {
    if (strcmp(index->entries[i].key, key) == 0) {
      return index->entries[i].value;
    }
  }
  return -1;
}

int main() {
  Table *table = table_create();
  Index *index = index_create();

  table_insert(table, 1, "one");
  table_insert(table, 2, "two");
  table_insert(table, 3, "three");

  index_insert(index, "one", 1);
  index_insert(index, "two", 2);
  index_insert(index, "three", 3);

  printf("%s\n", table_get(table, 2));  // two
  printf("%d\n", index_get(index, "three"));  // 3

  table_destroy(table);
  index_destroy(index);

  return 0;
}