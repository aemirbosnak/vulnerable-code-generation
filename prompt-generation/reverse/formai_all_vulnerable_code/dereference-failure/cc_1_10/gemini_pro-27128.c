//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *key;
  int value;
} entry_t;

typedef struct {
  entry_t *entries;
  int size;
} database_t;

database_t *create_database() {
  database_t *db = malloc(sizeof(database_t));
  db->entries = NULL;
  db->size = 0;
  return db;
}

void destroy_database(database_t *db) {
  for (int i = 0; i < db->size; i++) {
    free(db->entries[i].key);
  }
  free(db->entries);
  free(db);
}

int add_entry(database_t *db, char *key, int value) {
  db->entries = realloc(db->entries, (db->size + 1) * sizeof(entry_t));
  db->entries[db->size].key = strdup(key);
  db->entries[db->size].value = value;
  db->size++;
  return 0;
}

int get_value(database_t *db, char *key) {
  for (int i = 0; i < db->size; i++) {
    if (strcmp(db->entries[i].key, key) == 0) {
      return db->entries[i].value;
    }
  }
  return -1;
}

int main() {
  database_t *db = create_database();
  add_entry(db, "Ada Lovelace", 1815);
  add_entry(db, "Charles Babbage", 1791);
  add_entry(db, "Grace Hopper", 1906);
  printf("%d\n", get_value(db, "Ada Lovelace"));
  printf("%d\n", get_value(db, "Charles Babbage"));
  printf("%d\n", get_value(db, "Grace Hopper"));
  destroy_database(db);
  return 0;
}