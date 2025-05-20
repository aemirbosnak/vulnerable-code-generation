//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rows and columns in the database
#define MAX_ROWS 100
#define MAX_COLUMNS 10

// Define the data types that can be stored in the database
typedef enum {
  INT,
  FLOAT,
  CHAR
} data_type;

// Define the structure of a database row
typedef struct {
  data_type type;
  union {
    int i;
    float f;
    char c;
  } value;
} row;

// Define the structure of a database table
typedef struct {
  char *name;
  int num_rows;
  int num_columns;
  row *rows;
} table;

// Create a new database table
table *create_table(char *name, int num_rows, int num_columns) {
  table *t = malloc(sizeof(table));
  t->name = strdup(name);
  t->num_rows = num_rows;
  t->num_columns = num_columns;
  t->rows = malloc(sizeof(row) * num_rows);
  return t;
}

// Insert a row into a database table
void insert_row(table *t, row *r) {
  t->rows[t->num_rows++] = *r;
}

// Print the contents of a database table
void print_table(table *t) {
  for (int i = 0; i < t->num_rows; i++) {
    row *r = &t->rows[i];
    switch (r->type) {
      case INT:
        printf("%d ", r->value.i);
        break;
      case FLOAT:
        printf("%f ", r->value.f);
        break;
      case CHAR:
        printf("%c ", r->value.c);
        break;
    }
  }
  printf("\n");
}

// Main function
int main() {
  // Create a new database table
  table *t = create_table("my_table", 3, 2);

  // Insert some rows into the table
  row r1 = {INT, { .i = 1 }};
  row r2 = {FLOAT, { .f = 2.5 }};
  row r3 = {CHAR, { .c = 'a' }};
  insert_row(t, &r1);
  insert_row(t, &r2);
  insert_row(t, &r3);

  // Print the contents of the table
  print_table(t);

  return 0;
}