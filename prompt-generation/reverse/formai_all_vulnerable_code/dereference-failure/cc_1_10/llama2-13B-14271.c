//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_SIZE 100
#define REC_SIZE 50

// Structure to represent a record
struct record {
  char name[REC_SIZE];
  int age;
  char address[REC_SIZE];
};

// Function to read a record from the database
struct record *read_record(int index) {
  struct record *rec;
  char line[REC_SIZE];

  // Open the database file in read mode
  FILE *db = fopen("database.dat", "r");

  // Read the record at the specified index
  if (fgets(line, REC_SIZE, db) != NULL) {
    // Extract the record fields from the line
    sscanf(line, "%s %d %s", rec->name, &rec->age, rec->address);

    // Return the record
    return rec;
  }

  // If no record found, return NULL
  return NULL;
}

// Function to write a record to the database
void write_record(struct record *rec) {
  char line[REC_SIZE];

  // Open the database file in write mode
  FILE *db = fopen("database.dat", "w");

  // Write the record to the file
  sprintf(line, "%s %d %s", rec->name, rec->age, rec->address);
  fputs(line, db);

  // Close the database file
  fclose(db);
}

int main() {
  // Create a database with 10 records
  struct record records[DB_SIZE] = {
    {"Alice", 25, "123 Main St"},
    {"Bob", 30, "456 Elm St"},
    {"Charlie", 35, "789 Oak St"},
    {"David", 20, "111 Maple St"},
    {"Eve", 25, "222 Cherry St"},
    {"Frank", 35, "333 Walnut St"},
    {"Grace", 20, "444 Poplar St"},
    {"Helen", 30, "555 Sycamore St"},
    {"Ivy", 25, "666 Pine St"},
    {"Jenny", 35, "777 Birch St"}
  };

  // Loop through the records and print them to the console
  for (int i = 0; i < DB_SIZE; i++) {
    struct record *rec = records + i;
    printf("%s %d %s\n", rec->name, rec->age, rec->address);
  }

  // Add a new record to the database
  struct record new_rec = {"Lily", 28, "888 Oak St"};
  write_record(&new_rec);

  // Read the new record from the database
  struct record *rec = read_record(DB_SIZE - 1);
  printf("%s %d %s\n", rec->name, rec->age, rec->address);

  return 0;
}