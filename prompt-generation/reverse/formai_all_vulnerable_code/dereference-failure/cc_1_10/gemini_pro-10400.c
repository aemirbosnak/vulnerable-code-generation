//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
  char *data[MAX_COLS];
} Row;

typedef struct {
  Row rows[MAX_ROWS];
  int num_rows;
  int num_cols;
} Database;

Database *create_database(int num_cols) {
  Database *db = malloc(sizeof(Database));
  db->num_cols = num_cols;
  db->num_rows = 0;
  return db;
}

void destroy_database(Database *db) {
  for (int i = 0; i < db->num_rows; i++) {
    for (int j = 0; j < db->num_cols; j++) {
      free(db->rows[i].data[j]);
    }
  }
  free(db);
}

void insert_row(Database *db, char **data) {
  if (db->num_rows == MAX_ROWS) {
    printf("Error: Database is full.\n");
    return;
  }
  for (int i = 0; i < db->num_cols; i++) {
    db->rows[db->num_rows].data[i] = strdup(data[i]);
  }
  db->num_rows++;
}

void print_database(Database *db) {
  for (int i = 0; i < db->num_rows; i++) {
    for (int j = 0; j < db->num_cols; j++) {
      printf("%s ", db->rows[i].data[j]);
    }
    printf("\n");
  }
}

int main() {
  Database *db = create_database(3);
  insert_row(db, (char *[]){"John", "Doe", "123 Main Street"});
  insert_row(db, (char *[]){"Jane", "Smith", "456 Elm Street"});
  print_database(db);
  destroy_database(db);
  return 0;
}