//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table {
  char name[32];
  int num_cols;
  char **cols;
  int *col_types;
  int *col_lengths;
  int num_rows;
  char **rows;
};

struct database {
  char name[32];
  int num_tables;
  struct table **tables;
};

struct query {
  char type;
  char table[32];
  char col[32];
  char value[32];
};

int main() {
  // Create a new database
  struct database *db = malloc(sizeof(struct database));
  strcpy(db->name, "my_database");
  db->num_tables = 0;
  db->tables = NULL;

  // Add a new table to the database
  struct table *table = malloc(sizeof(struct table));
  strcpy(table->name, "my_table");
  table->num_cols = 3;
  table->cols = malloc(3 * sizeof(char *));
  strcpy(table->cols[0], "id");
  strcpy(table->cols[1], "name");
  strcpy(table->cols[2], "age");
  table->col_types = malloc(3 * sizeof(int));
  table->col_types[0] = 'i';
  table->col_types[1] = 's';
  table->col_types[2] = 'i';
  table->col_lengths = malloc(3 * sizeof(int));
  table->col_lengths[0] = 10;
  table->col_lengths[1] = 32;
  table->col_lengths[2] = 10;
  table->num_rows = 0;
  table->rows = NULL;

  // Add the table to the database
  db->tables = realloc(db->tables, (db->num_tables + 1) * sizeof(struct table *));
  db->tables[db->num_tables] = table;
  db->num_tables++;

  // Insert a new row into the table
  char *row = malloc(3 * sizeof(char *));
  strcpy(row[0], "1");
  strcpy(row[1], "John Smith");
  strcpy(row[2], "30");

  table->rows = realloc(table->rows, (table->num_rows + 1) * sizeof(char *));
  table->rows[table->num_rows] = row;
  table->num_rows++;

  // Print the database
  for (int i = 0; i < db->num_tables; i++) {
    printf("Table: %s\n", db->tables[i]->name);
    for (int j = 0; j < db->tables[i]->num_cols; j++) {
      printf("  Column: %s (%c, %d)\n", db->tables[i]->cols[j], db->tables[i]->col_types[j], db->tables[i]->col_lengths[j]);
    }
    for (int k = 0; k < db->tables[i]->num_rows; k++) {
      printf("  Row: ");
      for (int l = 0; l < db->tables[i]->num_cols; l++) {
        printf("%s ", db->tables[i]->rows[k][l]);
      }
      printf("\n");
    }
  }

  // Free the database
  for (int i = 0; i < db->num_tables; i++) {
    for (int j = 0; j < db->tables[i]->num_cols; j++) {
      free(db->tables[i]->cols[j]);
    }
    free(db->tables[i]->cols);
    free(db->tables[i]->col_types);
    free(db->tables[i]->col_lengths);
    for (int k = 0; k < db->tables[i]->num_rows; k++) {
      for (int l = 0; l < db->tables[i]->num_cols; l++) {
        free(db->tables[i]->rows[k][l]);
      }
      free(db->tables[i]->rows[k]);
    }
    free(db->tables[i]->rows);
    free(db->tables[i]);
  }
  free(db->tables);
  free(db);

  return 0;
}