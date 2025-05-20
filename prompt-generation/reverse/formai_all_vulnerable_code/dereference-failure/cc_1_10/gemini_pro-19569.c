//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: interoperable
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

// Destroy a database
void destroy_database(database *db) {
  free(db);
}

// Add a record to the database
void add_record(database *db, record *record) {
  if (db->num_records < MAX_RECORDS) {
    db->records[db->num_records] = *record;
    db->num_records++;
  } else {
    printf("Error: Database is full.\n");
  }
}

// Delete a record from the database
void delete_record(database *db, int index) {
  if (index >= 0 && index < db->num_records) {
    for (int i = index; i < db->num_records - 1; i++) {
      db->records[i] = db->records[i + 1];
    }
    db->num_records--;
  } else {
    printf("Error: Invalid index.\n");
  }
}

// Print the database
void print_database(database *db) {
  for (int i = 0; i < db->num_records; i++) {
    printf("%s, %d, %s\n", db->records[i].name, db->records[i].age, db->records[i].address);
  }
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

  // Print the database
  print_database(db);

  // Delete a record from the database
  delete_record(db, 1);

  // Print the database
  print_database(db);

  // Destroy the database
  destroy_database(db);

  return 0;
}