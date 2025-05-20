//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rows and columns in the database
#define MAX_ROWS 100
#define MAX_COLS 10

// Define the data types that can be stored in the database
typedef enum {
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_STRING
} data_type;

// Define the structure of a database table
typedef struct {
  char name[32];  // Name of the table
  int num_rows;   // Number of rows in the table
  int num_cols;   // Number of columns in the table
  data_type data_types[MAX_COLS];  // Data types of the columns
  void *data[MAX_ROWS][MAX_COLS];  // Data values of the cells
} table;

// Create a new database table
table *create_table(char *name, int num_rows, int num_cols, data_type *data_types) {
  table *table = malloc(sizeof(table));
  strcpy(table->name, name);
  table->num_rows = num_rows;
  table->num_cols = num_cols;
  for (int i = 0; i < num_cols; i++) {
    table->data_types[i] = data_types[i];
  }
  return table;
}

// Insert a new row into a database table
void insert_row(table *table, int row_index, void **data) {
  for (int i = 0; i < table->num_cols; i++) {
    table->data[row_index][i] = data[i];
  }
}

// Get the value of a cell in a database table
void *get_cell_value(table *table, int row_index, int col_index) {
  return table->data[row_index][col_index];
}

// Print the contents of a database table
void print_table(table *table) {
  printf("Table: %s\n", table->name);
  printf("Number of rows: %d\n", table->num_rows);
  printf("Number of columns: %d\n", table->num_cols);
  for (int i = 0; i < table->num_rows; i++) {
    for (int j = 0; j < table->num_cols; j++) {
      switch (table->data_types[j]) {
        case TYPE_INT:
          printf("%d ", *(int *)table->data[i][j]);
          break;
        case TYPE_FLOAT:
          printf("%f ", *(float *)table->data[i][j]);
          break;
        case TYPE_STRING:
          printf("%s ", (char *)table->data[i][j]);
          break;
      }
    }
    printf("\n");
  }
}

// Free the memory allocated for a database table
void free_table(table *table) {
  for (int i = 0; i < table->num_rows; i++) {
    for (int j = 0; j < table->num_cols; j++) {
      free(table->data[i][j]);
    }
  }
  free(table);
}

// Main function
int main() {
  // Create a new database table
  table *table = create_table("students", 3, 4, (data_type[]){TYPE_INT, TYPE_STRING, TYPE_FLOAT, TYPE_STRING});

  // Insert some data into the table
  insert_row(table, 0, (void *[]){&(int){1}, "John Smith", &(float){3.5}, "Computer Science"});
  insert_row(table, 1, (void *[]){&(int){2}, "Jane Doe", &(float){4.0}, "Mathematics"});
  insert_row(table, 2, (void *[]){&(int){3}, "Bill Jones", &(float){3.8}, "Engineering"});

  // Print the contents of the table
  print_table(table);

  // Free the memory allocated for the table
  free_table(table);

  return 0;
}