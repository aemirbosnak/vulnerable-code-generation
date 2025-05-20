//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[32];
  int age;
  char address[64];
  char phone[16];
} Person;

typedef struct {
  Person *data;
  int size;
} Database;

Database *create_database() {
  Database *db = malloc(sizeof(Database));
  db->data = NULL;
  db->size = 0;
  return db;
}

void free_database(Database *db) {
  if (db->data) {
    free(db->data);
  }
  free(db);
}

int add_person(Database *db, Person *person) {
  db->data = realloc(db->data, (db->size + 1) * sizeof(Person));
  if (!db->data) {
    return -1;
  }
  memcpy(&db->data[db->size], person, sizeof(Person));
  db->size++;
  return 0;
}

int remove_person(Database *db, int index) {
  if (index < 0 || index >= db->size) {
    return -1;
  }
  memmove(&db->data[index], &db->data[index + 1], (db->size - index - 1) * sizeof(Person));
  db->size--;
  return 0;
}

int find_person(Database *db, char *name) {
  for (int i = 0; i < db->size; i++) {
    if (strcmp(db->data[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

void print_database(Database *db) {
  printf("Database:\n");
  for (int i = 0; i < db->size; i++) {
    printf("%d. %s, %d, %s, %s\n", i + 1, db->data[i].name, db->data[i].age, db->data[i].address, db->data[i].phone);
  }
}

int main() {
  Database *db = create_database();

  Person person1 = {"John Doe", 30, "123 Main Street", "555-1212"};
  add_person(db, &person1);

  Person person2 = {"Jane Doe", 25, "456 Elm Street", "555-1213"};
  add_person(db, &person2);

  Person person3 = {"Bob Smith", 40, "789 Oak Street", "555-1214"};
  add_person(db, &person3);

  print_database(db);

  remove_person(db, 1);

  print_database(db);

  int index = find_person(db, "Jane Doe");
  if (index != -1) {
    printf("Found Jane Doe at index %d\n", index);
  } else {
    printf("Jane Doe not found\n");
  }

  free_database(db);

  return 0;
}