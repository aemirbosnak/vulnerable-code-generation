//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main() {
  sqlite3 *db;
  sqlite3_stmt *stmt;
  int rc;
  const char *sql;
  char *zErrMsg = 0;
  int nrows = 0;
  int ncols = 0;
  int i;
  char **result;

  rc = sqlite3_open("apocalypse.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  sql = "SELECT * FROM survivors";

  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    nrows++;
  }

  ncols = sqlite3_column_count(stmt);

  result = (char **)malloc(sizeof(char *) * nrows * ncols);
  if (result == NULL) {
    fprintf(stderr, "Failed to allocate memory for result set\n");
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  sqlite3_reset(stmt);

  i = 0;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    for (int j = 0; j < ncols; j++) {
      result[i++] = (char *)sqlite3_column_text(stmt, j);
    }
  }

  sqlite3_finalize(stmt);

  for (i = 0; i < nrows * ncols; i++) {
    printf("%s\n", result[i]);
  }

  free(result);
  sqlite3_close(db);

  return 0;
}