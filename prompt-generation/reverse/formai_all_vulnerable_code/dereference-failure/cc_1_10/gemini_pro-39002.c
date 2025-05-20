//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 1024

typedef struct {
  char key[MAX_KEY_SIZE];
  char value[MAX_VALUE_SIZE];
} IndexEntry;

typedef struct {
  IndexEntry entries[MAX_INDEX_SIZE];
  int numEntries;
} Index;

Index* createIndex() {
  Index* index = malloc(sizeof(Index));
  index->numEntries = 0;
  return index;
}

void destroyIndex(Index* index) {
  free(index);
}

int addIndexEntry(Index* index, char* key, char* value) {
  if (index->numEntries >= MAX_INDEX_SIZE) {
    return -1;
  }

  strcpy(index->entries[index->numEntries].key, key);
  strcpy(index->entries[index->numEntries].value, value);
  index->numEntries++;

  return 0;
}

char* getIndexEntryValue(Index* index, char* key) {
  for (int i = 0; i < index->numEntries; i++) {
    if (strcmp(index->entries[i].key, key) == 0) {
      return index->entries[i].value;
    }
  }

  return NULL;
}

int main() {
  Index* index = createIndex();

  addIndexEntry(index, "age", "25");
  addIndexEntry(index, "gender", "male");
  addIndexEntry(index, "location", "USA");

  char* age = getIndexEntryValue(index, "age");
  printf("Age: %s\n", age);

  char* gender = getIndexEntryValue(index, "gender");
  printf("Gender: %s\n", gender);

  char* location = getIndexEntryValue(index, "location");
  printf("Location: %s\n", location);

  destroyIndex(index);

  return 0;
}