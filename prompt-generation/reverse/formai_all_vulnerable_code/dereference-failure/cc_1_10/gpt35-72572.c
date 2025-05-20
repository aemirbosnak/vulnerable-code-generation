//FormAI DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to simulate a database table
struct table {
  char name[30];
  int rows;
  int columns;
  char **data;
};

// Function to create a new table
struct table create_table(char *name, int rows, int columns) {
  struct table new_table;
  strcpy(new_table.name, name);
  new_table.rows = rows;
  new_table.columns = columns;
  new_table.data = (char **)malloc(rows * sizeof(char *));
  for(int i=0; i<rows; i++) {
    new_table.data[i] = (char *)malloc(columns * sizeof(char));
  }
  return new_table;
}

// Function to insert data into a table
void insert_data(struct table *t, int row, int column, char *data) {
  strcpy(t->data[row][column], data);
}

// Function to print the contents of a table
void print_table(struct table t) {
  printf("Table: %s\n", t.name);
  for(int i=0; i<t.rows; i++) {
    for(int j=0; j<t.columns; j++) {
      printf("%s\t", t.data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  struct table my_table = create_table("My_Table", 5, 3);
  printf("Created a new table with name %s and dimensions %d x %d\n", my_table.name, my_table.rows, my_table.columns);
  printf("Inserting data into the table...\n");
  insert_data(&my_table, 0, 0, "Hello");
  insert_data(&my_table, 0, 1, "world");
  insert_data(&my_table, 0, 2, "!");
  printf("Printing the contents of the table...\n");
  print_table(my_table);
  return 0;
}