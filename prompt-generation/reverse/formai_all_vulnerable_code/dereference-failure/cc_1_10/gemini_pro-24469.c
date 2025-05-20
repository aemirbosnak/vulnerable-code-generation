//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 1024
#define MAX_VALUE_LENGTH 1024

typedef struct metadata_entry {
  char *key;
  char *value;
} metadata_entry;

typedef struct metadata {
  int num_entries;
  metadata_entry *entries;
} metadata;

metadata *metadata_new() {
  metadata *m = malloc(sizeof(metadata));
  m->num_entries = 0;
  m->entries = NULL;
  return m;
}

void metadata_free(metadata *m) {
  for (int i = 0; i < m->num_entries; i++) {
    free(m->entries[i].key);
    free(m->entries[i].value);
  }
  free(m->entries);
  free(m);
}

int metadata_add_entry(metadata *m, char *key, char *value) {
  if (m->num_entries == 0) {
    m->entries = malloc(sizeof(metadata_entry));
  } else {
    m->entries = realloc(m->entries, (m->num_entries + 1) * sizeof(metadata_entry));
  }
  m->entries[m->num_entries].key = strdup(key);
  m->entries[m->num_entries].value = strdup(value);
  m->num_entries++;
  return 0;
}

char *metadata_get_value(metadata *m, char *key) {
  for (int i = 0; i < m->num_entries; i++) {
    if (strcmp(m->entries[i].key, key) == 0) {
      return m->entries[i].value;
    }
  }
  return NULL;
}

int main() {
  metadata *m = metadata_new();
  metadata_add_entry(m, "name", "Donald Knuth");
  metadata_add_entry(m, "birth_date", "1938-01-10");
  metadata_add_entry(m, "occupation", "computer scientist");
  metadata_add_entry(m, "awards", "Turing Award, von Neumann Award, National Medal of Science");
  char *name = metadata_get_value(m, "name");
  printf("Name: %s\n", name);
  char *birth_date = metadata_get_value(m, "birth_date");
  printf("Birth Date: %s\n", birth_date);
  char *occupation = metadata_get_value(m, "occupation");
  printf("Occupation: %s\n", occupation);
  char *awards = metadata_get_value(m, "awards");
  printf("Awards: %s\n", awards);
  metadata_free(m);
  return 0;
}