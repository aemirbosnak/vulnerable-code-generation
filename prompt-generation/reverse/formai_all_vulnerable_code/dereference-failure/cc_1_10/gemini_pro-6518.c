//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to represent a database record
typedef struct {
  int id;
  char *name;
  char *email;
} record;

// Create a struct to represent the database
typedef struct {
  record *records;
  int num_records;
} database;

// Create a function to initialize the database
void init_database(database *db) {
  db->records = malloc(sizeof(record) * 10);
  db->num_records = 0;
}

// Create a function to add a record to the database
void add_record(database *db, int id, char *name, char *email) {
  if (db->num_records >= 10) {
    printf("Database is full!\n");
    return;
  }

  db->records[db->num_records].id = id;
  db->records[db->num_records].name = malloc(strlen(name) + 1);
  strcpy(db->records[db->num_records].name, name);
  db->records[db->num_records].email = malloc(strlen(email) + 1);
  strcpy(db->records[db->num_records].email, email);

  db->num_records++;
}

// Create a function to find a record in the database by ID
record *find_record_by_id(database *db, int id) {
  for (int i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      return &db->records[i];
    }
  }

  return NULL;
}

// Create a function to print a record
void print_record(record *record) {
  printf("ID: %d\n", record->id);
  printf("Name: %s\n", record->name);
  printf("Email: %s\n", record->email);
}

// Create a function to test the database
void test_database(database *db) {
  // Add some records to the database
  add_record(db, 1, "John Doe", "johndoe@example.com");
  add_record(db, 2, "Jane Doe", "janedoe@example.com");
  add_record(db, 3, "Peter Parker", "peterparker@example.com");

  // Find a record in the database by ID
  record *record = find_record_by_id(db, 2);

  // Print the record
  print_record(record);
}

int main() {
  // Initialize the database
  database db;
  init_database(&db);

  // Test the database
  test_database(&db);

  return 0;
}