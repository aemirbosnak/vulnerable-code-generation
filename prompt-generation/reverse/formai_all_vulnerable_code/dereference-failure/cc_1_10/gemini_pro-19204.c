//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define a struct to represent a database record
typedef struct {
  int id;
  char *name;
  char *email;
} record_t;

// Define a struct to represent a database
typedef struct {
  record_t *records;
  int num_records;
} database_t;

// Create a new database
database_t *create_database() {
  database_t *db = malloc(sizeof(database_t));
  db->records = NULL;
  db->num_records = 0;
  return db;
}

// Destroy a database
void destroy_database(database_t *db) {
  for (int i = 0; i < db->num_records; i++) {
    free(db->records[i].name);
    free(db->records[i].email);
  }
  free(db->records);
  free(db);
}

// Add a record to a database
void add_record(database_t *db, int id, char *name, char *email) {
  // Allocate memory for the new record
  record_t *record = malloc(sizeof(record_t));
  record->id = id;
  record->name = strdup(name);
  record->email = strdup(email);

  // Add the new record to the database
  db->records = realloc(db->records, sizeof(record_t) * (db->num_records + 1));
  db->records[db->num_records++] = *record;
}

// Find a record in a database by ID
record_t *find_record_by_id(database_t *db, int id) {
  for (int i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      return &db->records[i];
    }
  }
  return NULL;
}

// Print a database
void print_database(database_t *db) {
  for (int i = 0; i < db->num_records; i++) {
    printf("Record %d: %s (%s)\n", db->records[i].id, db->records[i].name, db->records[i].email);
  }
}

// Main function
int main() {
  // Create a new database
  database_t *db = create_database();

  // Add some records to the database
  add_record(db, 1, "John Doe", "john.doe@example.com");
  add_record(db, 2, "Jane Doe", "jane.doe@example.com");
  add_record(db, 3, "John Smith", "john.smith@example.com");

  // Print the database
  print_database(db);

  // Find a record in the database by ID
  record_t *record = find_record_by_id(db, 2);
  if (record) {
    printf("Found record: %s (%s)\n", record->name, record->email);
  } else {
    printf("Record not found.\n");
  }

  // Destroy the database
  destroy_database(db);

  return 0;
}