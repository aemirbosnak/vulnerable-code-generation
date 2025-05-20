//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: random
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
  int nrows, ncols;
  int i;
  char **result;

  rc = sqlite3_open("test.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  sql = "SELECT * FROM test_table";

  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  nrows = sqlite3_column_count(stmt);
  ncols = sqlite3_step(stmt);

  result = (char **)malloc(sizeof(char *) * nrows * ncols);
  if (result == NULL) {
    fprintf(stderr, "Out of memory\n");
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  for (i = 0; i < nrows; i++) {
    result[i] = (char *)malloc(sizeof(char) * 1024);
    if (result[i] == NULL) {
      fprintf(stderr, "Out of memory\n");
      sqlite3_finalize(stmt);
      sqlite3_close(db);
      return 1;
    }
  }

  for (i = 0; i < nrows; i++) {
    strcpy(result[i], sqlite3_column_text(stmt, i));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  for (i = 0; i < nrows; i++) {
    printf("%s\n", result[i]);
    free(result[i]);
  }

  free(result);

  return 0;
}