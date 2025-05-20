//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a table
#define MAX_COLUMNS 10

// Define the maximum number of rows in a table
#define MAX_ROWS 100

// Define the maximum length of a column name
#define MAX_COLUMN_NAME_LENGTH 30

// Define the maximum length of a row value
#define MAX_ROW_VALUE_LENGTH 100

// Define the data type of a column
typedef enum {
  INT,
  FLOAT,
  CHAR
} data_type;

// Define the structure of a column
typedef struct {
  char name[MAX_COLUMN_NAME_LENGTH];
  data_type type;
  int size;
} column;

// Define the structure of a table
typedef struct {
  char name[MAX_COLUMN_NAME_LENGTH];
  column columns[MAX_COLUMNS];
  int num_columns;
  int num_rows;
  char rows[MAX_ROWS][MAX_COLUMNS][MAX_ROW_VALUE_LENGTH];
} table;

// Create a new table
table *create_table(char *name) {
  table *t = malloc(sizeof(table));
  strcpy(t->name, name);
  t->num_columns = 0;
  t->num_rows = 0;
  return t;
}

// Add a column to a table
void add_column(table *t, char *name, data_type type, int size) {
  strcpy(t->columns[t->num_columns].name, name);
  t->columns[t->num_columns].type = type;
  t->columns[t->num_columns].size = size;
  t->num_columns++;
}

// Add a row to a table
void add_row(table *t, char **values) {
  for (int i = 0; i < t->num_columns; i++) {
    strcpy(t->rows[t->num_rows][i], values[i]);
  }
  t->num_rows++;
}

// Print a table
void print_table(table *t) {
  printf("Table: %s\n", t->name);
  printf("Columns:\n");
  for (int i = 0; i < t->num_columns; i++) {
    printf(" - %s (%d bytes)\n", t->columns[i].name, t->columns[i].size);
  }
  printf("Rows:\n");
  for (int i = 0; i < t->num_rows; i++) {
    printf(" - ");
    for (int j = 0; j < t->num_columns; j++) {
      printf("%s ", t->rows[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new table
  table *t = create_table("students");

  // Add columns to the table
  add_column(t, "name", CHAR, 30);
  add_column(t, "age", INT, 4);
  add_column(t, "gpa", FLOAT, 8);

  // Add rows to the table
  add_row(t, (char *[]){"John", "20", "3.5"});
  add_row(t, (char *[]){"Jane", "21", "3.7"});
  add_row(t, (char *[]){"Bob", "22", "3.2"});

  // Print the table
  print_table(t);

  return 0;
}