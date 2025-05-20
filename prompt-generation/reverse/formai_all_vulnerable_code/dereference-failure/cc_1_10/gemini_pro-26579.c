//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Define the structure of a record
typedef struct record {
  char name[MAX_RECORD_LENGTH];
  int age;
  char address[MAX_RECORD_LENGTH];
} record;

// Define the structure of the database
typedef struct database {
  record records[MAX_RECORDS];
  int num_records;
} database;

// Create a new database
database *create_database() {
  database *db = malloc(sizeof(database));
  db->num_records = 0;
  return db;
}

// Add a record to the database
void add_record(database *db, record *record) {
  if (db->num_records >= MAX_RECORDS) {
    fprintf(stderr, "Error: database is full\n");
    return;
  }
  db->records[db->num_records] = *record;
  db->num_records++;
}

// Get a record from the database by index
record *get_record(database *db, int index) {
  if (index < 0 || index >= db->num_records) {
    fprintf(stderr, "Error: invalid index\n");
    return NULL;
  }
  return &db->records[index];
}

// Update a record in the database by index
void update_record(database *db, int index, record *record) {
  if (index < 0 || index >= db->num_records) {
    fprintf(stderr, "Error: invalid index\n");
    return;
  }
  db->records[index] = *record;
}

// Delete a record from the database by index
void delete_record(database *db, int index) {
  if (index < 0 || index >= db->num_records) {
    fprintf(stderr, "Error: invalid index\n");
    return;
  }
  for (int i = index; i < db->num_records - 1; i++) {
    db->records[i] = db->records[i + 1];
  }
  db->num_records--;
}

// Print the database to the console
void print_database(database *db) {
  for (int i = 0; i < db->num_records; i++) {
    record *record = &db->records[i];
    printf("Record %d:\n", i);
    printf("  Name: %s\n", record->name);
    printf("  Age: %d\n", record->age);
    printf("  Address: %s\n", record->address);
  }
}

// Free the memory allocated for the database
void free_database(database *db) {
  free(db);
}

// Main function
int main() {
  // Create a new database
  database *db = create_database();

  // Add some records to the database
  record record1 = {"John Doe", 30, "123 Main Street"};
  add_record(db, &record1);
  record record2 = {"Jane Doe", 25, "456 Elm Street"};
  add_record(db, &record2);

  // Get a record from the database by index
  record *record3 = get_record(db, 1);

  // Update a record in the database by index
  record3->age = 26;
  update_record(db, 1, record3);

  // Delete a record from the database by index
  delete_record(db, 0);

  // Print the database to the console
  print_database(db);

  // Free the memory allocated for the database
  free_database(db);

  return 0;
}