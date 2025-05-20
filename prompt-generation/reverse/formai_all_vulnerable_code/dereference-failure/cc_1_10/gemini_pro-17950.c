//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

typedef struct {
  char *name;
  char *value;
} metadata_entry;

typedef struct {
  int num_entries;
  metadata_entry entries[MAX_METADATA_SIZE];
} metadata;

metadata *create_metadata() {
  metadata *m = malloc(sizeof(metadata));
  m->num_entries = 0;
  return m;
}

void add_metadata_entry(metadata *m, char *name, char *value) {
  if (m->num_entries == MAX_METADATA_SIZE) {
    fprintf(stderr, "Error: maximum number of metadata entries reached\n");
    return;
  }

  m->entries[m->num_entries].name = strdup(name);
  m->entries[m->num_entries].value = strdup(value);
  m->num_entries++;
}

char *get_metadata_value(metadata *m, char *name) {
  for (int i = 0; i < m->num_entries; i++) {
    if (strcmp(m->entries[i].name, name) == 0) {
      return m->entries[i].value;
    }
  }

  return NULL;
}

void free_metadata(metadata *m) {
  for (int i = 0; i < m->num_entries; i++) {
    free(m->entries[i].name);
    free(m->entries[i].value);
  }

  free(m);
}

int main() {
  metadata *m = create_metadata();

  add_metadata_entry(m, "title", "My Awesome Movie");
  add_metadata_entry(m, "director", "Steven Spielberg");
  add_metadata_entry(m, "release_date", "2023-01-01");

  char *title = get_metadata_value(m, "title");
  char *director = get_metadata_value(m, "director");
  char *release_date = get_metadata_value(m, "release_date");

  printf("Title: %s\n", title);
  printf("Director: %s\n", director);
  printf("Release date: %s\n", release_date);

  free_metadata(m);

  return 0;
}