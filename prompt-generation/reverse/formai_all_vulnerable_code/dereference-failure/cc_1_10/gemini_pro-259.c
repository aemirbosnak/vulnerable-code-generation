//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100

typedef struct {
  int id;
  char name[50];
  char email[50];
  int age;
} person_t;

typedef struct {
  person_t people[MAX_ROWS];
  int num_rows;
} database_t;

// Create a new database
database_t* create_database() {
  database_t* db = (database_t*)malloc(sizeof(database_t));
  db->num_rows = 0;
  return db;
}

// Insert a new person into the database
void insert_person(database_t* db, person_t person) {
  db->people[db->num_rows] = person;
  db->num_rows++;
}

// Get a person from the database by id
person_t* get_person(database_t* db, int id) {
  for (int i = 0; i < db->num_rows; i++) {
    if (db->people[i].id == id) {
      return &db->people[i];
    }
  }
  return NULL;
}

// Update a person in the database
void update_person(database_t* db, int id, person_t person) {
  for (int i = 0; i < db->num_rows; i++) {
    if (db->people[i].id == id) {
      db->people[i] = person;
      return;
    }
  }
}

// Delete a person from the database
void delete_person(database_t* db, int id) {
  for (int i = 0; i < db->num_rows; i++) {
    if (db->people[i].id == id) {
      db->people[i] = db->people[db->num_rows - 1];
      db->num_rows--;
      return;
    }
  }
}

// Print the database
void print_database(database_t* db) {
  printf("Database:\n");
  printf("--------------------------------------------------------------------------------\n");
  printf("|%-5s|%-20s|%-20s|%-5s|\n", "ID", "Name", "Email", "Age");
  printf("--------------------------------------------------------------------------------\n");
  for (int i = 0; i < db->num_rows; i++) {
    printf("|%-5d|%-20s|%-20s|%-5d|\n", db->people[i].id, db->people[i].name, db->people[i].email, db->people[i].age);
  }
  printf("--------------------------------------------------------------------------------\n");
}

int main() {
  // Create a new database
  database_t* db = create_database();

  // Insert some people into the database
  person_t person1 = {1, "John Doe", "john.doe@example.com", 30};
  insert_person(db, person1);
  person_t person2 = {2, "Jane Doe", "jane.doe@example.com", 25};
  insert_person(db, person2);
  person_t person3 = {3, "John Smith", "john.smith@example.com", 40};
  insert_person(db, person3);

  // Get a person from the database
  person_t* person = get_person(db, 2);

  // Update the person's email
  strcpy(person->email, "jane.doe@new-example.com");
  update_person(db, 2, *person);

  // Delete the person from the database
  delete_person(db, 1);

  // Print the database
  print_database(db);

  // Free the database
  free(db);

  return 0;
}