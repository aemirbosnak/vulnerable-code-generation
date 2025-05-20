//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple database structure
typedef struct {
  int id;
  char *name;
  char *email;
} Person;

// A database of people
Person *database;
int databaseSize = 0;

// Prints the database
void printDatabase() {
  for (int i = 0; i < databaseSize; i++) {
    Person *person = &database[i];
    printf("%d %s %s\n", person->id, person->name, person->email);
  }
}

// Adds a person to the database
void addPerson(int id, char *name, char *email) {
  // Create a new person
  Person *person = malloc(sizeof(Person));
  person->id = id;
  person->name = strdup(name);
  person->email = strdup(email);

  // Add the person to the database
  database = realloc(database, (databaseSize + 1) * sizeof(Person));
  database[databaseSize++] = *person;
}

// Deletes a person from the database
void deletePerson(int id) {
  // Find the person in the database
  int index = -1;
  for (int i = 0; i < databaseSize; i++) {
    if (database[i].id == id) {
      index = i;
      break;
    }
  }

  // If the person was found, delete them
  if (index != -1) {
    // Free the person's memory
    free(database[index].name);
    free(database[index].email);

    // Remove the person from the database
    for (int i = index; i < databaseSize - 1; i++) {
      database[i] = database[i + 1];
    }
    databaseSize--;
  }
}

// Finds a person in the database by their name
Person *findPersonByName(char *name) {
  // Find the person in the database
  for (int i = 0; i < databaseSize; i++) {
    if (strcmp(database[i].name, name) == 0) {
      return &database[i];
    }
  }

  // Return NULL if the person was not found
  return NULL;
}

// Finds a person in the database by their email
Person *findPersonByEmail(char *email) {
  // Find the person in the database
  for (int i = 0; i < databaseSize; i++) {
    if (strcmp(database[i].email, email) == 0) {
      return &database[i];
    }
  }

  // Return NULL if the person was not found
  return NULL;
}

int main() {
  // Add some people to the database
  addPerson(1, "John", "john@example.com");
  addPerson(2, "Jane", "jane@example.com");
  addPerson(3, "Bob", "bob@example.com");

  // Print the database
  printf("Database:\n");
  printDatabase();

  // Find a person by their name
  Person *person = findPersonByName("John");
  if (person != NULL) {
    printf("Found person by name: %s\n", person->name);
  } else {
    printf("Person not found by name\n");
  }

  // Find a person by their email
  person = findPersonByEmail("jane@example.com");
  if (person != NULL) {
    printf("Found person by email: %s\n", person->name);
  } else {
    printf("Person not found by email\n");
  }

  // Delete a person from the database
  deletePerson(2);

  // Print the database
  printf("Database after deletion:\n");
  printDatabase();

  return 0;
}