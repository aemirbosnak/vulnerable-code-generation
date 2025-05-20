//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We don't have a database, but we can simulate one with an array of strings
char *database[100];

// And a counter to keep track of the number of records in the database
int numRecords = 0;

// Function to add a record to the database
void addRecord(char *record) {
  // If the database is full, return an error
  if (numRecords >= 100) {
    printf("Error: Database is full\n");
    return;
  }

  // Add the record to the database
  database[numRecords++] = strdup(record);
}

// Function to remove a record from the database
void removeRecord(int index) {
  // If the index is out of range, return an error
  if (index < 0 || index >= numRecords) {
    printf("Error: Invalid index\n");
    return;
  }

  // Shift the records down to fill the gap
  for (int i = index; i < numRecords - 1; i++) {
    database[i] = database[i + 1];
  }

  // Decrement the number of records
  numRecords--;
}

// Function to print the database
void printDatabase() {
  // Print the records in the database
  for (int i = 0; i < numRecords; i++) {
    printf("%s\n", database[i]);
  }
}

// Main function
int main() {
  // Add some records to the database
  addRecord("John Doe");
  addRecord("Jane Doe");
  addRecord("Bob Smith");

  // Print the database
  printf("Database:\n");
  printDatabase();

  // Remove a record from the database
  removeRecord(1);

  // Print the database again
  printf("\nDatabase after removing a record:\n");
  printDatabase();

  return 0;
}