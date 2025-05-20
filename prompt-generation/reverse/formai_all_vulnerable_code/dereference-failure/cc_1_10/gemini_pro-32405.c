//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  int value;
} KeyValue;

typedef struct {
  int size;
  KeyValue *data;
} Database;

Database *createDatabase() {
  Database *db = malloc(sizeof(Database));
  db->size = 0;
  db->data = NULL;
  return db;
}

void destroyDatabase(Database *db) {
  if (db == NULL) {
    return;
  }
  for (int i = 0; i < db->size; i++) {
    free(db->data[i].key);
  }
  free(db->data);
  free(db);
}

void insert(Database *db, char *key, int value) {
  if (db == NULL) {
    return;
  }
  db->data = realloc(db->data, sizeof(KeyValue) * (db->size + 1));
  db->data[db->size].key = strdup(key);
  db->data[db->size].value = value;
  db->size++;
}

int get(Database *db, char *key) {
  if (db == NULL) {
    return -1;
  }
  for (int i = 0; i < db->size; i++) {
    if (strcmp(db->data[i].key, key) == 0) {
      return db->data[i].value;
    }
  }
  return -1;
}

void printDatabase(Database *db) {
  if (db == NULL) {
    return;
  }
  printf("Database:\n");
  for (int i = 0; i < db->size; i++) {
    printf("\t%s: %d\n", db->data[i].key, db->data[i].value);
  }
}

int main() {
  Database *db = createDatabase();

  insert(db, "name", "John Doe");
  insert(db, "age", 30);
  insert(db, "city", "New York");

  printf("Value of 'name': %d\n", get(db, "name"));
  printf("Value of 'age': %d\n", get(db, "age"));
  printf("Value of 'city': %d\n", get(db, "city"));

  printDatabase(db);

  destroyDatabase(db);

  return 0;
}