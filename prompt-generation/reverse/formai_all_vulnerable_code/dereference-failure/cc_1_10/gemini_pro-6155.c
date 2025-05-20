//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int age;
  char *email;
} Person;

typedef struct {
  Person *people;
  int size;
  int capacity;
} Database;

Database *createDatabase() {
  Database *db = malloc(sizeof(Database));
  db->people = malloc(sizeof(Person) * 10);
  db->size = 0;
  db->capacity = 10;
  return db;
}

void addPerson(Database *db, Person person) {
  if (db->size >= db->capacity) {
    db->people = realloc(db->people, sizeof(Person) * db->capacity * 2);
    db->capacity *= 2;
  }
  db->people[db->size++] = person;
}

Person *getPerson(Database *db, char *name) {
  for (int i = 0; i < db->size; i++) {
    if (strcmp(db->people[i].name, name) == 0) {
      return &db->people[i];
    }
  }
  return NULL;
}

void printDatabase(Database *db) {
  for (int i = 0; i < db->size; i++) {
    printf("Name: %s\n", db->people[i].name);
    printf("Age: %d\n", db->people[i].age);
    printf("Email: %s\n", db->people[i].email);
    printf("\n");
  }
}

int main() {
  Database *db = createDatabase();

  Person person1 = {"John Doe", 30, "john.doe@example.com"};
  addPerson(db, person1);

  Person person2 = {"Jane Doe", 25, "jane.doe@example.com"};
  addPerson(db, person2);

  Person *person3 = getPerson(db, "John Doe");
  if (person3 != NULL) {
    printf("Found person: %s\n", person3->name);
  } else {
    printf("Person not found.\n");
  }

  printDatabase(db);

  return 0;
}