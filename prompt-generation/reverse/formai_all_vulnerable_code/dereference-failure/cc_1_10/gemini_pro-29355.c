//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Define the structure of a record
typedef struct {
  int id;
  char name[MAX_RECORD_LENGTH];
  char address[MAX_RECORD_LENGTH];
  char phone[MAX_RECORD_LENGTH];
} record_t;

// Define the structure of the database
typedef struct {
  record_t records[MAX_RECORDS];
  int num_records;
} database_t;

// Create a new database
database_t *create_database() {
  database_t *db = malloc(sizeof(database_t));
  db->num_records = 0;
  return db;
}

// Add a record to the database
void add_record(database_t *db, record_t *record) {
  db->records[db->num_records] = *record;
  db->num_records++;
}

// Delete a record from the database
void delete_record(database_t *db, int id) {
  int i;
  for (i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      db->records[i] = db->records[db->num_records - 1];
      db->num_records--;
      break;
    }
  }
}

// Search for a record in the database by id
record_t *search_record_by_id(database_t *db, int id) {
  int i;
  for (i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      return &db->records[i];
    }
  }
  return NULL;
}

// Search for a record in the database by name
record_t *search_record_by_name(database_t *db, char *name) {
  int i;
  for (i = 0; i < db->num_records; i++) {
    if (strcmp(db->records[i].name, name) == 0) {
      return &db->records[i];
    }
  }
  return NULL;
}

// Print the database
void print_database(database_t *db) {
  int i;
  for (i = 0; i < db->num_records; i++) {
    printf("%d %s %s %s\n",
      db->records[i].id,
      db->records[i].name,
      db->records[i].address,
      db->records[i].phone
    );
  }
}

// Destroy the database
void destroy_database(database_t *db) {
  free(db);
}

// Main function
int main() {
  // Create a new database
  database_t *db = create_database();

  // Add some records to the database
  record_t record1 = {1, "John Doe", "123 Main Street", "555-1212"};
  add_record(db, &record1);
  record_t record2 = {2, "Jane Doe", "456 Elm Street", "555-1213"};
  add_record(db, &record2);
  record_t record3 = {3, "John Smith", "789 Oak Street", "555-1214"};
  add_record(db, &record3);

  // Print the database
  printf("Database:\n");
  print_database(db);

  // Search for a record by id
  record_t *record = search_record_by_id(db, 2);
  if (record) {
    printf("Found record by id:\n");
    printf("%d %s %s %s\n",
      record->id,
      record->name,
      record->address,
      record->phone
    );
  } else {
    printf("Record not found.\n");
  }

  // Search for a record by name
  record = search_record_by_name(db, "John Smith");
  if (record) {
    printf("Found record by name:\n");
    printf("%d %s %s %s\n",
      record->id,
      record->name,
      record->address,
      record->phone
    );
  } else {
    printf("Record not found.\n");
  }

  // Delete a record from the database
  delete_record(db, 2);

  // Print the database
  printf("Database after deleting record:\n");
  print_database(db);

  // Destroy the database
  destroy_database(db);

  return 0;
}