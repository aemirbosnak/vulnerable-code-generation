//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LEN 100

typedef struct {
  int id;
  char name[MAX_LEN];
  char email[MAX_LEN];
} row;

typedef struct {
  row rows[MAX_ROWS];
  int num_rows;
  int num_cols;
} database;

database *create_database() {
  database *db = malloc(sizeof(database));
  db->num_rows = 0;
  db->num_cols = 0;
  return db;
}

void insert_row(database *db, row *r) {
  if (db->num_rows == MAX_ROWS) {
    printf("Error: Database is full.\n");
    return;
  }
  db->rows[db->num_rows++] = *r;
}

row *find_row(database *db, int id) {
  for (int i = 0; i < db->num_rows; i++) {
    if (db->rows[i].id == id) {
      return &db->rows[i];
    }
  }
  return NULL;
}

void delete_row(database *db, int id) {
  row *r = find_row(db, id);
  if (r == NULL) {
    printf("Error: Row not found.\n");
    return;
  }
  for (int i = r - db->rows; i < db->num_rows - 1; i++) {
    db->rows[i] = db->rows[i + 1];
  }
  db->num_rows--;
}

void print_database(database *db) {
  for (int i = 0; i < db->num_rows; i++) {
    row *r = &db->rows[i];
    printf("%d %s %s\n", r->id, r->name, r->email);
  }
}

int main() {
  database *db = create_database();
  row r1 = {1, "John Doe", "john.doe@example.com"};
  row r2 = {2, "Jane Doe", "jane.doe@example.com"};
  insert_row(db, &r1);
  insert_row(db, &r2);
  print_database(db);
  row *r = find_row(db, 1);
  if (r != NULL) {
    printf("Found row: %d %s %s\n", r->id, r->name, r->email);
  } else {
    printf("Row not found.\n");
  }
  delete_row(db, 2);
  print_database(db);
  free(db);
  return 0;
}