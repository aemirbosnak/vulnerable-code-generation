//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
  char *name;
  int age;
  char *occupation;
} person_t;

// Create a new person record
person_t *new_person(char *name, int age, char *occupation) {
  person_t *p = malloc(sizeof(person_t));
  p->name = strdup(name);
  p->age = age;
  p->occupation = strdup(occupation);
  return p;
}

// Free a person record
void free_person(person_t *p) {
  free(p->name);
  free(p->occupation);
  free(p);
}

// Print a person record
void print_person(person_t *p) {
  printf("Name: %s\n", p->name);
  printf("Age: %d\n", p->age);
  printf("Occupation: %s\n", p->occupation);
}

// Create a new database
typedef struct {
  person_t **records;
  int size;
} database_t;

// Create a new database
database_t *new_database() {
  database_t *db = malloc(sizeof(database_t));
  db->records = NULL;
  db->size = 0;
  return db;
}

// Free a database
void free_database(database_t *db) {
  for (int i = 0; i < db->size; i++) {
    free_person(db->records[i]);
  }
  free(db->records);
  free(db);
}

// Add a new record to the database
void add_record(database_t *db, person_t *p) {
  db->records = realloc(db->records, sizeof(person_t *) * (db->size + 1));
  db->records[db->size] = p;
  db->size++;
}

// Print the database
void print_database(database_t *db) {
  for (int i = 0; i < db->size; i++) {
    print_person(db->records[i]);
  }
}

// Search the database for a person by name
person_t *find_person(database_t *db, char *name) {
  for (int i = 0; i < db->size; i++) {
    if (strcmp(db->records[i]->name, name) == 0) {
      return db->records[i];
    }
  }
  return NULL;
}

// Delete a person from the database
void delete_person(database_t *db, char *name) {
  for (int i = 0; i < db->size; i++) {
    if (strcmp(db->records[i]->name, name) == 0) {
      free_person(db->records[i]);
      db->records[i] = db->records[db->size - 1];
      db->size--;
      break;
    }
  }
}

int main() {
  // Create a new database
  database_t *db = new_database();

  // Add some records to the database
  add_record(db, new_person("John Doe", 30, "Hacker"));
  add_record(db, new_person("Jane Doe", 25, "Cyberpunk"));
  add_record(db, new_person("Neo", 25, "The One"));

  // Print the database
  print_database(db);

  // Search the database for a person by name
  person_t *p = find_person(db, "Neo");
  if (p != NULL) {
    printf("Found person:\n");
    print_person(p);
  } else {
    printf("Person not found.\n");
  }

  // Delete a person from the database
  delete_person(db, "Jane Doe");

  // Print the database again
  print_database(db);

  // Free the database
  free_database(db);

  return 0;
}