//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define the maximum number of rows and columns in the database
#define MAX_ROWS 100
#define MAX_COLUMNS 10

// Define the data types that can be stored in the database
typedef enum {
  TYPE_INTEGER,
  TYPE_FLOAT,
  TYPE_STRING
} data_type;

// Define the structure of a database table
typedef struct {
  char *name;              // The name of the table
  int num_rows;            // The number of rows in the table
  int num_columns;         // The number of columns in the table
  data_type *data_types;   // The data types of the columns in the table
  void **data;             // The data stored in the table
} table;

// Create a new database table
table *create_table(char *name, int num_rows, int num_columns, data_type *data_types) {
  table *t = malloc(sizeof(table));
  t->name = strdup(name);
  t->num_rows = num_rows;
  t->num_columns = num_columns;
  t->data_types = malloc(sizeof(data_type) * num_columns);
  memcpy(t->data_types, data_types, sizeof(data_type) * num_columns);
  t->data = malloc(sizeof(void *) * num_rows * num_columns);
  return t;
}

// Free the memory allocated for a database table
void free_table(table *t) {
  free(t->name);
  free(t->data_types);
  free(t->data);
  free(t);
}

// Insert a row into a database table
void insert_row(table *t, int row_index, void **data) {
  assert(row_index >= 0 && row_index < t->num_rows);
  for (int i = 0; i < t->num_columns; i++) {
    switch (t->data_types[i]) {
    case TYPE_INTEGER:
      ((int **)t->data)[row_index][i] = *(int *)data[i];
      break;
    case TYPE_FLOAT:
      ((float **)t->data)[row_index][i] = *(float *)data[i];
      break;
    case TYPE_STRING:
      ((char **)t->data)[row_index][i] = strdup(*(char **)data[i]);
      break;
    }
  }
}

// Get the value of a cell in a database table
void *get_cell(table *t, int row_index, int column_index) {
  assert(row_index >= 0 && row_index < t->num_rows);
  assert(column_index >= 0 && column_index < t->num_columns);
  switch (t->data_types[column_index]) {
  case TYPE_INTEGER:
    return &((int **)t->data)[row_index][column_index];
  case TYPE_FLOAT:
    return &((float **)t->data)[row_index][column_index];
  case TYPE_STRING:
    return ((char **)t->data)[row_index][column_index];
  }
  return NULL;
}

// Print the contents of a database table
void print_table(table *t) {
  printf("%s:\n", t->name);
  for (int i = 0; i < t->num_rows; i++) {
    for (int j = 0; j < t->num_columns; j++) {
      switch (t->data_types[j]) {
      case TYPE_INTEGER:
        printf("%d ", ((int **)t->data)[i][j]);
        break;
      case TYPE_FLOAT:
        printf("%f ", ((float **)t->data)[i][j]);
        break;
      case TYPE_STRING:
        printf("%s ", ((char **)t->data)[i][j]);
        break;
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new database table
  table *t = create_table("students", 3, 3, (data_type[]){TYPE_INTEGER, TYPE_FLOAT, TYPE_STRING});

  // Insert some rows into the table
  insert_row(t, 0, (void *[]){&(int){1}, &(float){3.5}, &(char *){"John Doe"}});
  insert_row(t, 1, (void *[]){&(int){2}, &(float){4.0}, &(char *){"Jane Doe"}});
  insert_row(t, 2, (void *[]){&(int){3}, &(float){4.5}, &(char *){"Bob Smith"}});

  // Print the contents of the table
  print_table(t);

  // Get the value of a cell in the table
  printf("The value of the cell in row 1, column 2 is: %f\n", *(float *)get_cell(t, 1, 1));

  // Free the memory allocated for the table
  free_table(t);

  return 0;
}