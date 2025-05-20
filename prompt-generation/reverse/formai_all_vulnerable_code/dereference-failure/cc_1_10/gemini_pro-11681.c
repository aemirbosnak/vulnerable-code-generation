//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main() {
  sqlite3 *db;
  sqlite3_stmt *stmt;
  int rc;
  const char *sql;
  char *zErrMsg = NULL;
  int nrows, ncols;
  int i, j;
  char **result;

  // Open the database
  rc = sqlite3_open("test.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Prepare the statement
  sql = "SELECT * FROM people;";
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Step through the results
  nrows = 0;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    nrows++;
  }

  // Get the number of columns
  ncols = sqlite3_column_count(stmt);

  // Allocate memory for the results
  result = malloc(sizeof(char *) * nrows * ncols);
  if (result == NULL) {
    fprintf(stderr, "Out of memory\n");
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  // Populate the results array
  i = 0;
  sqlite3_reset(stmt);
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    for (j = 0; j < ncols; j++) {
      result[i++] = strdup(sqlite3_column_text(stmt, j));
    }
  }

  // Print the results
  for (i = 0; i < nrows; i++) {
    for (j = 0; j < ncols; j++) {
      printf("%s ", result[i * ncols + j]);
    }
    printf("\n");
  }

  // Free the results
  for (i = 0; i < nrows * ncols; i++) {
    free(result[i]);
  }
  free(result);

  // Finalize the statement
  sqlite3_finalize(stmt);

  // Close the database
  sqlite3_close(db);

  return 0;
}