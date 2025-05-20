//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {
  char* key;
  char* value;
};

struct database {
  struct entry** entries;
  int size;
  int capacity;
};

struct database* db_new() {
  struct database* db = malloc(sizeof(struct database));
  db->entries = malloc(sizeof(struct entry*) * 10);
  db->size = 0;
  db->capacity = 10;
  return db;
}

void db_free(struct database* db) {
  for (int i = 0; i < db->size; i++) {
    free(db->entries[i]->key);
    free(db->entries[i]->value);
    free(db->entries[i]);
  }
  free(db->entries);
  free(db);
}

int db_get(struct database* db, char* key) {
  for (int i = 0; i < db->size; i++) {
    if (strcmp(db->entries[i]->key, key) == 0) {
      return i;
    }
  }
  return -1;
}

void db_set(struct database* db, char* key, char* value) {
  int index = db_get(db, key);
  if (index == -1) {
    if (db->size == db->capacity) {
      db->entries = realloc(db->entries, sizeof(struct entry*) * db->capacity * 2);
      db->capacity *= 2;
    }
    db->entries[db->size] = malloc(sizeof(struct entry));
    db->entries[db->size]->key = malloc(strlen(key) + 1);
    strcpy(db->entries[db->size]->key, key);
    db->entries[db->size]->value = malloc(strlen(value) + 1);
    strcpy(db->entries[db->size]->value, value);
    db->size++;
  } else {
    free(db->entries[index]->value);
    db->entries[index]->value = malloc(strlen(value) + 1);
    strcpy(db->entries[index]->value, value);
  }
}

int main() {
  struct database* db = db_new();
  db_set(db, "name", "John Doe");
  db_set(db, "age", "30");
  db_set(db, "city", "New York");
  printf("Name: %s\n", db->entries[db_get(db, "name")]->value);
  printf("Age: %s\n", db->entries[db_get(db, "age")]->value);
  printf("City: %s\n", db->entries[db_get(db, "city")]->value);
  db_free(db);
  return 0;
}