//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 1024

// Define the maximum number of records in the database
#define MAX_RECORDS 1000

// Define the structure of a record
typedef struct {
  char name[50];
  char email[50];
  char phone[20];
} Record;

// Define the structure of a database
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

// Open a database from a file
Database* open_database(const char* filename) {
  FILE* file = fopen(filename, "rb");
  if (file == NULL) {
    return NULL;
  }

  Database* db = malloc(sizeof(Database));
  db->num_records = 0;

  // Read the records from the file
  while (!feof(file)) {
    Record record;
    fread(&record, sizeof(Record), 1, file);
    if (feof(file)) {
      break;
    }

    db->records[db->num_records++] = record;
  }

  fclose(file);

  return db;
}

// Save a database to a file
void save_database(Database* db, const char* filename) {
  FILE* file = fopen(filename, "wb");
  if (file == NULL) {
    return;
  }

  // Write the records to the file
  for (int i = 0; i < db->num_records; i++) {
    fwrite(&db->records[i], sizeof(Record), 1, file);
  }

  fclose(file);
}

// Add a record to a database
void add_record(Database* db, Record record) {
  db->records[db->num_records++] = record;
}

// Delete a record from a database
void delete_record(Database* db, int index) {
  for (int i = index; i < db->num_records - 1; i++) {
    db->records[i] = db->records[i + 1];
  }

  db->num_records--;
}

// Find a record in a database by name
int find_record_by_name(Database* db, const char* name) {
  for (int i = 0; i < db->num_records; i++) {
    if (strcmp(db->records[i].name, name) == 0) {
      return i;
    }
  }

  return -1;
}

// Find a record in a database by email
int find_record_by_email(Database* db, const char* email) {
  for (int i = 0; i < db->num_records; i++) {
    if (strcmp(db->records[i].email, email) == 0) {
      return i;
    }
  }

  return -1;
}

// Find a record in a database by phone
int find_record_by_phone(Database* db, const char* phone) {
  for (int i = 0; i < db->num_records; i++) {
    if (strcmp(db->records[i].phone, phone) == 0) {
      return i;
    }
  }

  return -1;
}

// Print a record
void print_record(Record record) {
  printf("Name: %s\n", record.name);
  printf("Email: %s\n", record.email);
  printf("Phone: %s\n", record.phone);
}

// Print a database
void print_database(Database* db) {
  for (int i = 0; i < db->num_records; i++) {
    print_record(db->records[i]);
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new database
  Database* db = create_database();

  // Add some records to the database
  Record record1 = {"John Doe", "john.doe@example.com", "123-456-7890"};
  add_record(db, record1);
  Record record2 = {"Jane Doe", "jane.doe@example.com", "098-765-4321"};
  add_record(db, record2);

  // Print the database
  print_database(db);

  // Find a record in the database by name
  int index = find_record_by_name(db, "John Doe");
  if (index >= 0) {
    printf("Found record with name John Doe at index %d\n", index);
  } else {
    printf("Record with name John Doe not found\n");
  }

  // Delete a record from the database
  delete_record(db, index);

  // Print the database again
  print_database(db);

  // Save the database to a file
  save_database(db, "database.dat");

  // Open the database from a file
  Database* db2 = open_database("database.dat");

  // Print the database again
  print_database(db2);

  // Free the memory allocated for the databases
  free(db);
  free(db2);

  return 0;
}