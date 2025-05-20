//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: multivariable
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

// Define the structure of a database row
typedef struct {
  data_type type;
  union {
    int ival;
    float fval;
    char *sval;
  } value;
} row;

// Define the structure of a database table
typedef struct {
  char *name;
  int num_rows;
  int num_cols;
  row *rows;
} table;

// Create a new database table
table *create_table(char *name, int num_rows, int num_cols) {
  table *t = malloc(sizeof(table));
  t->name = strdup(name);
  t->num_rows = num_rows;
  t->num_cols = num_cols;
  t->rows = malloc(sizeof(row) * num_rows);
  return t;
}

// Insert a row into a database table
void insert_row(table *t, int row_index, row *row) {
  t->rows[row_index] = *row;
}

// Get a row from a database table
row *get_row(table *t, int row_index) {
  return &t->rows[row_index];
}

// Print a database table
void print_table(table *t) {
  printf("Table: %s\n", t->name);
  printf("Rows: %d\n", t->num_rows);
  printf("Cols: %d\n", t->num_cols);
  for (int i = 0; i < t->num_rows; i++) {
    row *r = get_row(t, i);
    printf("%d: ", i);
    switch (r->type) {
      case TYPE_INT:
        printf("%d\n", r->value.ival);
        break;
      case TYPE_FLOAT:
        printf("%f\n", r->value.fval);
        break;
      case TYPE_STRING:
        printf("%s\n", r->value.sval);
        break;
    }
  }
}

// Free the memory allocated for a database table
void free_table(table *t) {
  free(t->name);
  free(t->rows);
  free(t);
}

// Main function
int main() {
  // Create a new database table
  table *t = create_table("my_table", 3, 2);

  // Insert some rows into the table
  row r1 = {TYPE_INT, .value.ival = 1};
  insert_row(t, 0, &r1);
  row r2 = {TYPE_FLOAT, .value.fval = 3.14};
  insert_row(t, 1, &r2);
  row r3 = {TYPE_STRING, .value.sval = "Hello, world!"};
  insert_row(t, 2, &r3);

  // Print the table
  print_table(t);

  // Free the memory allocated for the table
  free_table(t);

  return 0;
}