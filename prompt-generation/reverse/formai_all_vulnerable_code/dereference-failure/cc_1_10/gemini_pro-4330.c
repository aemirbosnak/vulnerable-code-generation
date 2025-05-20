//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main() {
  sqlite3 *db;
  sqlite3_stmt *stmt;
  int rc;
  char *sql;
  char *zErrMsg = 0;
  char **row_data = NULL;
  int row_count = 0;
  int column_count = 0;
  int i = 0;

  /* Open the database */
  rc = sqlite3_open("test.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  /* Prepare the SQL statement */
  sql = "SELECT * FROM test_table";
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  /* Execute the SQL statement */
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    row_count++;
    column_count = sqlite3_column_count(stmt);
    row_data = malloc(sizeof(void *) * column_count);
    for (i = 0; i < column_count; i++) {
      row_data[i] = (char *)sqlite3_column_text(stmt, i);
      printf("%s = %s\n", sqlite3_column_name(stmt, i), row_data[i]);
    }
    free(row_data);
  }
  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Cannot execute statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  /* Finalize the SQL statement */
  sqlite3_finalize(stmt);
  /* Close the database */
  sqlite3_close(db);
  return 0;
}