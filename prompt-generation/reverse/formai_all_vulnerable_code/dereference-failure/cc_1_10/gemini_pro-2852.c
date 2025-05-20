//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters in a name
#define MAX_NAME_LENGTH 50

// Define the maximum number of characters in a key
#define MAX_KEY_LENGTH 10

// Define the maximum number of records in the database
#define MAX_RECORDS 1000

// Define the structure of a record
typedef struct {
  char name[MAX_NAME_LENGTH];
  char key[MAX_KEY_LENGTH];
  int value;
} Record;

// Define the structure of an index
typedef struct {
  char key[MAX_KEY_LENGTH];
  int record_number;
} Index;

// Create a new database
Record* create_database(int num_records) {
  // Allocate memory for the database
  Record* database = malloc(sizeof(Record) * num_records);

  // Initialize the database
  for (int i = 0; i < num_records; i++) {
    database[i].name[0] = '\0';
    database[i].key[0] = '\0';
    database[i].value = 0;
  }

  // Return the database
  return database;
}

// Insert a record into the database
void insert_record(Record* database, int record_number, char* name, char* key, int value) {
  // Copy the name into the record
  strcpy(database[record_number].name, name);

  // Copy the key into the record
  strcpy(database[record_number].key, key);

  // Set the value of the record
  database[record_number].value = value;
}

// Create an index for the database
Index* create_index(Record* database, int num_records) {
  // Allocate memory for the index
  Index* index = malloc(sizeof(Index) * num_records);

  // Initialize the index
  for (int i = 0; i < num_records; i++) {
    index[i].key[0] = '\0';
    index[i].record_number = -1;
  }

  // Populate the index
  for (int i = 0; i < num_records; i++) {
    // Get the key from the record
    char* key = database[i].key;

    // Find the record number in the index
    int record_number = -1;
    for (int j = 0; j < num_records; j++) {
      if (strcmp(index[j].key, key) == 0) {
        record_number = j;
        break;
      }
    }

    // If the record number was not found, create a new entry in the index
    if (record_number == -1) {
      record_number = i;
      strcpy(index[record_number].key, key);
    }

    // Set the record number in the index
    index[record_number].record_number = i;
  }

  // Return the index
  return index;
}

// Search the database using an index
int search_database(Record* database, Index* index, char* key) {
  // Find the record number in the index
  int record_number = -1;
  for (int i = 0; i < MAX_RECORDS; i++) {
    if (strcmp(index[i].key, key) == 0) {
      record_number = index[i].record_number;
      break;
    }
  }

  // Return the record number
  return record_number;
}

// Print the database
void print_database(Record* database, int num_records) {
  for (int i = 0; i < num_records; i++) {
    printf("Record %d:\n", i);
    printf("  Name: %s\n", database[i].name);
    printf("  Key: %s\n", database[i].key);
    printf("  Value: %d\n", database[i].value);
  }
}

// Main function
int main() {
  // Create a database
  Record* database = create_database(MAX_RECORDS);

  // Insert some records into the database
  insert_record(database, 0, "John", "123", 1);
  insert_record(database, 1, "Mary", "456", 2);
  insert_record(database, 2, "Bob", "789", 3);

  // Create an index for the database
  Index* index = create_index(database, MAX_RECORDS);

  // Search the database using the index
  int record_number = search_database(database, index, "456");

  // Print the record that was found
  if (record_number != -1) {
    printf("Record found:\n");
    printf("  Name: %s\n", database[record_number].name);
    printf("  Key: %s\n", database[record_number].key);
    printf("  Value: %d\n", database[record_number].value);
  } else {
    printf("Record not found.\n");
  }

  // Print the entire database
  printf("\nEntire database:\n");
  print_database(database, MAX_RECORDS);

  // Free the memory allocated for the database and the index
  free(database);
  free(index);

  return 0;
}