//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a field
#define MAX_FIELD_LENGTH 50

// Define the structure of a record
typedef struct {
  int id;
  char name[MAX_FIELD_LENGTH];
  char address[MAX_FIELD_LENGTH];
  char phone[MAX_FIELD_LENGTH];
} record;

// Define the structure of the database
typedef struct {
  record records[MAX_RECORDS];
  int num_records;
} database;

// Create a new database
database* create_database() {
  database* db = malloc(sizeof(database));
  db->num_records = 0;
  return db;
}

// Add a new record to the database
void add_record(database* db, record* record) {
  db->records[db->num_records] = *record;
  db->num_records++;
}

// Find a record in the database by its id
record* find_record_by_id(database* db, int id) {
  for (int i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      return &db->records[i];
    }
  }
  return NULL;
}

// Delete a record from the database by its id
void delete_record_by_id(database* db, int id) {
  for (int i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      // Shift the remaining records down one
      for (int j = i; j < db->num_records - 1; j++) {
        db->records[j] = db->records[j + 1];
      }
      db->num_records--;
      return;
    }
  }
}

// Print the database to the console
void print_database(database* db) {
  printf("ID\tName\tAddress\t\tPhone\n");
  for (int i = 0; i < db->num_records; i++) {
    printf("%d\t%s\t%s\t\t%s\n", db->records[i].id, db->records[i].name, db->records[i].address, db->records[i].phone);
  }
}

// Get a user's input
char* get_input(char* prompt) {
  char* input = malloc(100);
  printf("%s", prompt);
  scanf("%s", input);
  return input;
}

// Main function
int main() {
  // Create a new database
  database* db = create_database();

  // Add some records to the database
  record record1 = {1, "John Doe", "123 Main Street", "555-1212"};
  add_record(db, &record1);
  record record2 = {2, "Jane Doe", "456 Elm Street", "555-1213"};
  add_record(db, &record2);
  record record3 = {3, "John Smith", "789 Oak Street", "555-1214"};
  add_record(db, &record3);

  // Print the database to the console
  print_database(db);

  // Get a user's input
  char* input = get_input("Enter the ID of the record you want to delete: ");

  // Delete the record from the database
  int id = atoi(input);
  delete_record_by_id(db, id);

  // Print the database to the console
  print_database(db);

  return 0;
}