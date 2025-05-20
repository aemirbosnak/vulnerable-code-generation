//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// A custom data structure to represent a row in the database.
typedef struct row_t {
  int id;
  char *name;
  int age;
} row_t;

// A function to print a row of data.
void print_row(row_t *row) {
  printf("%d | %s | %d\n", row->id, row->name, row->age);
}

// A function to free the memory allocated for a row of data.
void free_row(row_t *row) {
  free(row->name);
  free(row);
}

// A function to query the database and print the results.
void query_database(sqlite3 *db) {
  // Prepare the SQL statement.
  sqlite3_stmt *stmt;
  const char *sql = "SELECT * FROM people;";
  int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
    return;
  }

  // Bind the parameters.

  // Execute the statement.
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    // Get the data from the row.
    int id = sqlite3_column_int(stmt, 0);
    const char *name = (const char *)sqlite3_column_text(stmt, 1);
    int age = sqlite3_column_int(stmt, 2);

    // Create a row of data.
    row_t *row = malloc(sizeof(row_t));
    row->id = id;
    row->name = strdup(name);
    row->age = age;

    // Print the row of data.
    print_row(row);

    // Free the memory allocated for the row of data.
    free_row(row);
  }

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Error executing statement: %s\n", sqlite3_errmsg(db));
  }

  // Finalize the statement.
  sqlite3_finalize(stmt);
}

int main(int argc, char **argv) {
  // Open the database.
  sqlite3 *db;
  int rc = sqlite3_open("people.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
    return 1;
  }

  // Query the database.
  query_database(db);

  // Close the database.
  sqlite3_close(db);

  return 0;
}