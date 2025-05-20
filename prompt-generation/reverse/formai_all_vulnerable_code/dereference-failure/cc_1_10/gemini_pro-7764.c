//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
  char *name;
  int age;
  char *occupation;
} person;

// Initialize the database
person *database = NULL;
int num_people = 0;

// Create a new person
person *create_person(char *name, int age, char *occupation) {
  person *p = malloc(sizeof(person));
  p->name = strdup(name);
  p->age = age;
  p->occupation = strdup(occupation);
  return p;
}

// Add a person to the database
void add_person(person *p) {
  database = realloc(database, (num_people + 1) * sizeof(person));
  database[num_people++] = *p;
}

// Print the database
void print_database() {
  for (int i = 0; i < num_people; i++) {
    printf("%s (%d) - %s\n", database[i].name, database[i].age, database[i].occupation);
  }
}

// Free the memory allocated for the database
void free_database() {
  for (int i = 0; i < num_people; i++) {
    free(database[i].name);
    free(database[i].occupation);
  }
  free(database);
}

int main() {
  // Create some people
  person *p1 = create_person("John", 30, "Software Engineer");
  person *p2 = create_person("Jane", 25, "Doctor");
  person *p3 = create_person("Bob", 40, "Teacher");

  // Add the people to the database
  add_person(p1);
  add_person(p2);
  add_person(p3);

  // Print the database
  print_database();

  // Free the memory allocated for the database
  free_database();

  return 0;
}