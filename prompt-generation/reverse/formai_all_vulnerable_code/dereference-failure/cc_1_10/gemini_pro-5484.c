//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Define the record structure
typedef struct {
  char name[MAX_RECORD_LENGTH];
  int age;
  char address[MAX_RECORD_LENGTH];
} Record;

// Define the database structure
typedef struct {
  Record records[MAX_RECORDS];
  int num_records;
} Database;

// Create a new database
Database *create_database() {
  Database *db = malloc(sizeof(Database));
  db->num_records = 0;
  return db;
}

// Add a record to the database
void add_record(Database *db, Record *record) {
  if (db->num_records < MAX_RECORDS) {
    db->records[db->num_records] = *record;
    db->num_records++;
  } else {
    printf("Error: Database is full\n");
  }
}

// Delete a record from the database
void delete_record(Database *db, int index) {
  if (index >= 0 && index < db->num_records) {
    for (int i = index; i < db->num_records - 1; i++) {
      db->records[i] = db->records[i + 1];
    }
    db->num_records--;
  } else {
    printf("Error: Invalid index\n");
  }
}

// Find a record in the database
Record *find_record(Database *db, char *name) {
  for (int i = 0; i < db->num_records; i++) {
    if (strcmp(db->records[i].name, name) == 0) {
      return &db->records[i];
    }
  }
  return NULL;
}

// Print the database
void print_database(Database *db) {
  for (int i = 0; i < db->num_records; i++) {
    printf("%s %d %s\n", db->records[i].name, db->records[i].age, db->records[i].address);
  }
}

// Main function
int main() {
  // Create a new database
  Database *db = create_database();

  // Add some records to the database
  Record record1 = {"John Doe", 30, "123 Main Street"};
  add_record(db, &record1);
  Record record2 = {"Jane Doe", 25, "456 Elm Street"};
  add_record(db, &record2);

  // Print the database
  print_database(db);

  // Find a record in the database
  Record *record = find_record(db, "John Doe");
  if (record != NULL) {
    printf("Found record: %s %d %s\n", record->name, record->age, record->address);
  } else {
    printf("Record not found\n");
  }

  // Delete a record from the database
  delete_record(db, 0);

  // Print the database
  print_database(db);

  return 0;
}