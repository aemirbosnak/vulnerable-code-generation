//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a record in the database
typedef struct record {
  int id;
  char name[20];
  int age;
} record;

// Structure to represent the database
typedef struct database {
  record *records;
  int num_records;
  int capacity;
} database;

// Function to create a new database
database *create_database() {
  database *db = malloc(sizeof(database));
  db->records = NULL;
  db->num_records = 0;
  db->capacity = 0;
  return db;
}

// Function to add a new record to the database
void add_record(database *db, record *new_record) {
  // Check if the database has enough capacity
  if (db->num_records == db->capacity) {
    // Double the capacity of the database
    db->capacity *= 2;
    db->records = realloc(db->records, db->capacity * sizeof(record));
  }

  // Add the new record to the database
  db->records[db->num_records] = *new_record;
  db->num_records++;
}

// Function to find a record in the database by its ID
record *find_record_by_id(database *db, int id) {
  for (int i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      return &db->records[i];
    }
  }

  return NULL;
}

// Function to print the database
void print_database(database *db) {
  printf("ID\tName\tAge\n");
  for (int i = 0; i < db->num_records; i++) {
    printf("%d\t%s\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
  }
}

// Main function
int main() {
  // Create a new database
  database *db = create_database();

  // Add some records to the database
  record record1 = {1, "John Doe", 20};
  add_record(db, &record1);
  record record2 = {2, "Jane Doe", 25};
  add_record(db, &record2);
  record record3 = {3, "Peter Parker", 18};
  add_record(db, &record3);

  // Print the database
  print_database(db);

  // Find a record in the database by its ID
  int id = 2;
  record *found_record = find_record_by_id(db, id);
  if (found_record != NULL) {
    printf("Found record: %d\t%s\t%d\n", found_record->id, found_record->name, found_record->age);
  } else {
    printf("Record not found.\n");
  }

  return 0;
}