//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the database structure
typedef struct {
  char *name;
  int age;
  char *occupation;
} person;

// Create a new database
person *create_database(int size) {
  person *db = (person *)malloc(sizeof(person) * size);
  return db;
}

// Insert a new person into the database
void insert_person(person *db, int index, char *name, int age, char *occupation) {
  db[index].name = name;
  db[index].age = age;
  db[index].occupation = occupation;
}

// Print the database
void print_database(person *db, int size) {
  for (int i = 0; i < size; i++) {
    printf("%s, %d, %s\n", db[i].name, db[i].age, db[i].occupation);
  }
}

// Destroy the database
void destroy_database(person *db) {
  free(db);
}

// Main function
int main() {
  // Create a new database with a random size
  int size = rand() % 100;
  person *db = create_database(size);

  // Insert some random people into the database
  for (int i = 0; i < size; i++) {
    char *name = (char *)malloc(sizeof(char) * 10);
    int age = rand() % 100;
    char *occupation = (char *)malloc(sizeof(char) * 10);
    sprintf(name, "Person %d", i);
    sprintf(occupation, "Occupation %d", i);
    insert_person(db, i, name, age, occupation);
  }

  // Print the database
  print_database(db, size);

  // Destroy the database
  destroy_database(db);

  return 0;
}