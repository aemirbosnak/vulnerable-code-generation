//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a database
typedef struct database {
  char** table_names;
  int num_tables;
  char*** data;
  int* num_rows;
  int* num_cols;
} database;

// Function to create a new database
database* create_database() {
  database* db = malloc(sizeof(database));
  db->table_names = NULL;
  db->num_tables = 0;
  db->data = NULL;
  db->num_rows = NULL;
  db->num_cols = NULL;
  return db;
}

// Function to add a table to a database
void add_table(database* db, char* table_name, int num_rows, int num_cols) {
  // Allocate memory for the table name
  char* name = malloc(strlen(table_name) + 1);
  strcpy(name, table_name);

  // Add the table name to the list of table names
  db->table_names = realloc(db->table_names, (db->num_tables + 1) * sizeof(char*));
  db->table_names[db->num_tables] = name;
  db->num_tables++;

  // Allocate memory for the data
  db->data = realloc(db->data, (db->num_tables) * sizeof(char**));
  db->data[db->num_tables - 1] = malloc(num_rows * num_cols * sizeof(char));

  // Set the number of rows and columns
  db->num_rows = realloc(db->num_rows, (db->num_tables) * sizeof(int));
  db->num_rows[db->num_tables - 1] = num_rows;
  db->num_cols = realloc(db->num_cols, (db->num_tables) * sizeof(int));
  db->num_cols[db->num_tables - 1] = num_cols;
}

// Function to get a table from a database
char** get_table(database* db, char* table_name) {
  // Find the index of the table
  int index = -1;
  for (int i = 0; i < db->num_tables; i++) {
    if (strcmp(db->table_names[i], table_name) == 0) {
      index = i;
      break;
    }
  }

  // If the table was not found, return NULL
  if (index == -1) {
    return NULL;
  }

  // Return the data for the table
  return db->data[index];
}

// Function to print a table
void print_table(database* db, char* table_name) {
  // Get the table
  char** table = get_table(db, table_name);

  // If the table was not found, print an error message
  if (table == NULL) {
    printf("Table not found\n");
    return;
  }

  // Print the table header
  printf("| ");
  for (int i = 0; i < db->num_cols[db->num_tables - 1]; i++) {
    printf("%s | ", table[i]);
  }
  printf("\n");

  // Print the table data
  for (int i = 1; i < db->num_rows[db->num_tables - 1]; i++) {
    printf("| ");
    for (int j = 0; j < db->num_cols[db->num_tables - 1]; j++) {
      printf("%s | ", table[i * db->num_cols[db->num_tables - 1] + j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new database
  database* db = create_database();

  // Add tables to the database
  add_table(db, "users", 3, 3);
  add_table(db, "scores", 2, 2);

  // Get a table from the database
  char** users = get_table(db, "users");
  char** scores = get_table(db, "scores");

  // Print the tables
  printf("Users Table:\n");
  print_table(db, "users");
  printf("\nScores Table:\n");
  print_table(db, "scores");

  // Free the memory allocated for the database
  for (int i = 0; i < db->num_tables; i++) {
    free(db->table_names[i]);
    free(db->data[i]);
  }
  free(db->table_names);
  free(db->data);
  free(db->num_rows);
  free(db->num_cols);
  free(db);

  return 0;
}