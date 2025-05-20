//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define PARANOIA_LEVEL 10

int main(int argc, char **argv) {
  sqlite3 *db;
  sqlite3_stmt *stmt;
  const char *sql = "SELECT * FROM T;";
  int rc;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s database\n", argv[0]);
    return 1;
  }

  // Open the database in read-only mode.
  rc = sqlite3_open_v2(argv[1], &db, SQLITE_OPEN_READONLY, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Prepare the statement.
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  // Bind the parameters.
  rc = sqlite3_bind_text(stmt, 1, argv[2], -1, SQLITE_TRANSIENT);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error binding parameter: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  // Execute the statement.
  rc = sqlite3_step(stmt);
  if (rc != SQLITE_ROW) {
    fprintf(stderr, "Error executing statement: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  // Get the results.
  char *text = (char *)sqlite3_column_text(stmt, 0);
  if (text == NULL) {
    fprintf(stderr, "Error getting result: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  // Print the results.
  printf("%s\n", text);

  // Check that everything worked as expected.
  if (sqlite3_column_bytes(stmt, 0) != strlen(text)) {
    fprintf(stderr, "Error checking result: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  // Finalize the statement.
  sqlite3_finalize(stmt);

  // Close the database.
  sqlite3_close(db);

  return 0;
}