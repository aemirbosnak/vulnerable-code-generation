//FormAI DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int key;
  int value;
} Data;

typedef struct {
  Data* data;
  int size;
  int capacity;
} Database;

typedef struct {
  int* index;
  Database* database;
  int size;
  int capacity;
} Index;

Database* create_database(int capacity);
void destroy_database(Database* db);
void add_data(Database* db, int key, int value);
void print_database(Database* db);

Index* create_index(Database* db, int capacity);
void destroy_index(Index* index);
void add_index(Index* index, int key);
void print_index(Index* index);

int main() {
  /* create database */
  printf("Creating database...\n");
  Database* db = create_database(5);
  add_data(db, 1, 100);
  add_data(db, 2, 200);
  add_data(db, 3, 300);
  add_data(db, 4, 400);
  add_data(db, 5, 500);
  print_database(db);

  /* create index */
  printf("\nCreating index...\n");
  Index* index = create_index(db, 5);
  add_index(index, 1);
  print_index(index);

  /* destroy database and index */
  printf("\nDestroying database and index...\n");
  destroy_database(db);
  destroy_index(index);

  return 0;
}

Database* create_database(int capacity) {
  Database* db = malloc(sizeof(Database));
  db->data = malloc(sizeof(Data) * capacity);
  db->size = 0;
  db->capacity = capacity;
  return db;
}

void destroy_database(Database* db) {
  free(db->data);
  free(db);
}

void add_data(Database* db, int key, int value) {
  db->data[db->size].key = key;
  db->data[db->size].value = value;
  db->size++;
}

void print_database(Database* db) {
  printf("Printing database:\n");
  for (int i = 0; i < db->size; i++) {
    printf("key: %d, value: %d\n", db->data[i].key, db->data[i].value);
  }
}

Index* create_index(Database* db, int capacity) {
  Index* index = malloc(sizeof(Index));
  index->index = malloc(sizeof(int) * capacity);
  index->database = db;
  index->size = 0;
  index->capacity = capacity;
  return index;
}

void destroy_index(Index* index) {
  free(index->index);
  free(index);
}

void add_index(Index* index, int key) {
  for (int i = 0; i < index->database->size; i++) {
    if (index->database->data[i].key == key) {
      index->index[index->size] = i;
      index->size++;
      break;
    }
  }
}

void print_index(Index* index) {
  printf("Printing index:\n");
  for (int i = 0; i < index->size; i++) {
    Data data = index->database->data[index->index[i]];
    printf("key: %d, value: %d\n", data.key, data.value);
  }
}