//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_DATA_LEN 1000
#define MAX_INDEX_ENTRIES 1000

typedef struct {
  char key[MAX_KEY_LEN];
  char data[MAX_DATA_LEN];
} IndexEntry;

typedef struct {
  IndexEntry entries[MAX_INDEX_ENTRIES];
  int num_entries;
} Index;

Index* create_index() {
  Index* index = malloc(sizeof(Index));
  index->num_entries = 0;
  return index;
}

void destroy_index(Index* index) {
  free(index);
}

int add_index_entry(Index* index, char* key, char* data) {
  if (index->num_entries >= MAX_INDEX_ENTRIES) {
    return -1;
  }
  strcpy(index->entries[index->num_entries].key, key);
  strcpy(index->entries[index->num_entries].data, data);
  index->num_entries++;
  return 0;
}

int find_index_entry(Index* index, char* key) {
  for (int i = 0; i < index->num_entries; i++) {
    if (strcmp(index->entries[i].key, key) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  Index* index = create_index();
  add_index_entry(index, "foo", "bar");
  add_index_entry(index, "baz", "qux");

  int index_entry_index = find_index_entry(index, "foo");
  if (index_entry_index >= 0) {
    printf("Found data: %s\n", index->entries[index_entry_index].data);
  } else {
    printf("Key not found.\n");
  }

  destroy_index(index);
  return 0;
}