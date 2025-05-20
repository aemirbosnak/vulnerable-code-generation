//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
  char *name;
  char *email;
  int age;
} Person;

// Create a new person
Person *create_person(char *name, char *email, int age) {
  Person *person = malloc(sizeof(Person));
  person->name = strdup(name);
  person->email = strdup(email);
  person->age = age;
  return person;
}

// Free a person
void free_person(Person *person) {
  free(person->name);
  free(person->email);
  free(person);
}

// Print a person
void print_person(Person *person) {
  printf("Name: %s\n", person->name);
  printf("Email: %s\n", person->email);
  printf("Age: %d\n", person->age);
}

// Database operations
Person **add_person(Person **database, Person *person, int *size) {
  *size = *size + 1;
  database = realloc(database, *size * sizeof(Person *));
  database[*size - 1] = person;
  return database;
}

Person **remove_person(Person **database, int index, int *size) {
  for (int i = index; i < *size - 1; i++) {
    database[i] = database[i + 1];
  }
  *size = *size - 1;
  database = realloc(database, *size * sizeof(Person *));
  return database;
}

Person *find_person(Person **database, char *name, int size) {
  for (int i = 0; i < size; i++) {
    if (strcmp(database[i]->name, name) == 0) {
      return database[i];
    }
  }
  return NULL;
}

// Main program
int main() {
  // Create a database
  Person **database = NULL;
  int size = 0;

  // Add some people to the database
  database = add_person(database, create_person("John", "john@example.com", 30), &size);
  database = add_person(database, create_person("Jane", "jane@example.com", 25), &size);
  database = add_person(database, create_person("Bob", "bob@example.com", 40), &size);

  // Print the database
  for (int i = 0; i < size; i++) {
    print_person(database[i]);
    printf("\n");
  }

  // Find a person in the database
  Person *person = find_person(database, "John", size);
  if (person != NULL) {
    printf("Found person: ");
    print_person(person);
    printf("\n");
  } else {
    printf("Person not found\n");
  }

  // Remove a person from the database
  database = remove_person(database, 1, &size);

  // Print the database again
  for (int i = 0; i < size; i++) {
    print_person(database[i]);
    printf("\n");
  }

  // Free the database
  for (int i = 0; i < size; i++) {
    free_person(database[i]);
  }
  free(database);

  return 0;
}