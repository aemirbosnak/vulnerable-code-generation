//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct Index {
  int key;
  int value;
};

struct Database {
  struct Index *index;
  int size;
};

struct Database *createDatabase() {
  struct Database *database = malloc(sizeof(struct Database));
  database->index = malloc(sizeof(struct Index) * 100);
  database->size = 0;
  return database;
}

void insert(struct Database *database, int key, int value) {
  database->index[database->size].key = key;
  database->index[database->size].value = value;
  database->size++;
}

int find(struct Database *database, int key) {
  for (int i = 0; i < database->size; i++) {
    if (database->index[i].key == key) {
      return database->index[i].value;
    }
  }
  return -1;
}

void printDatabase(struct Database *database) {
  for (int i = 0; i < database->size; i++) {
    printf("(%d, %d)\n", database->index[i].key, database->index[i].value);
  }
}

int main() {
  struct Database *database = createDatabase();
  insert(database, 1, 10);
  insert(database, 2, 20);
  insert(database, 3, 30);
  insert(database, 4, 40);
  insert(database, 5, 50);
  printDatabase(database);
  printf("The value for key 3 is: %d\n", find(database, 3));
  return 0;
}