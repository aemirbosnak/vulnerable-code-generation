//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the size of each record in bytes
#define RECORD_SIZE 100

// Define the structure of a record
typedef struct {
  char name[50];
  int age;
  char address[50];
} Record;

// Define the structure of the database
typedef struct {
  Record records[MAX_RECORDS];
  int num_records;
} Database;

// Create a new database
Database* create_database() {
  Database* db = malloc(sizeof(Database));
  db->num_records = 0;
  return db;
}

// Open an existing database
Database* open_database(char* filename) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    return NULL;
  }

  Database* db = malloc(sizeof(Database));
  fread(&db->num_records, sizeof(int), 1, fp);
  for (int i = 0; i < db->num_records; i++) {
    fread(&db->records[i], RECORD_SIZE, 1, fp);
  }
  fclose(fp);

  return db;
}

// Close a database
void close_database(Database* db) {
  free(db);
}

// Save a database to a file
void save_database(Database* db, char* filename) {
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) {
    return;
  }

  fwrite(&db->num_records, sizeof(int), 1, fp);
  for (int i = 0; i < db->num_records; i++) {
    fwrite(&db->records[i], RECORD_SIZE, 1, fp);
  }
  fclose(fp);
}

// Add a new record to the database
void add_record(Database* db, Record* record) {
  db->records[db->num_records] = *record;
  db->num_records++;
}

// Find a record in the database by name
Record* find_record(Database* db, char* name) {
  for (int i = 0; i < db->num_records; i++) {
    if (strcmp(db->records[i].name, name) == 0) {
      return &db->records[i];
    }
  }

  return NULL;
}

// Delete a record from the database by name
void delete_record(Database* db, char* name) {
  for (int i = 0; i < db->num_records; i++) {
    if (strcmp(db->records[i].name, name) == 0) {
      db->records[i] = db->records[db->num_records - 1];
      db->num_records--;
      return;
    }
  }
}

// Print the database to the console
void print_database(Database* db) {
  for (int i = 0; i < db->num_records; i++) {
    printf("%s, %d, %s\n", db->records[i].name, db->records[i].age, db->records[i].address);
  }
}

// Main function
int main() {
  // Create a new database
  Database* db = create_database();

  // Add some records to the database
  Record record1 = {"John Doe", 30, "123 Main Street"};
  add_record(db, &record1);
  Record record2 = {"Jane Doe", 25, "456 Elm Street"};
  add_record(db, &record2);

  // Find a record in the database
  Record* record3 = find_record(db, "John Doe");
  if (record3 != NULL) {
    printf("Found record: %s, %d, %s\n", record3->name, record3->age, record3->address);
  }

  // Delete a record from the database
  delete_record(db, "Jane Doe");

  // Print the database to the console
  print_database(db);

  // Save the database to a file
  save_database(db, "database.dat");

  // Close the database
  close_database(db);

  return 0;
}