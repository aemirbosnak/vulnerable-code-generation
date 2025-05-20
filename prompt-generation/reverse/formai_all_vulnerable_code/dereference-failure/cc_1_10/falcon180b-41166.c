//Falcon-180B DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DATABASE_NAME "example.db"
#define TABLE_NAME "users"
#define COLUMN_ID "id"
#define COLUMN_NAME "name"
#define COLUMN_EMAIL "email"

static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i]? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    rc = sqlite3_open(DATABASE_NAME, &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sql = "CREATE TABLE IF NOT EXISTS " TABLE_NAME " (" COLUMN_ID " INTEGER PRIMARY KEY," COLUMN_NAME " TEXT," COLUMN_EMAIL " TEXT);";
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully\n");
    }

    sqlite3_stmt *stmt;
    char *query = "INSERT INTO " TABLE_NAME " (" COLUMN_NAME ", " COLUMN_EMAIL ") VALUES ('John Doe', 'johndoe@example.com');";
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    rc = sqlite3_step(stmt);

    if (rc!= SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    } else {
        printf("1 row inserted\n");
    }

    sqlite3_finalize(stmt);

    query = "SELECT * FROM " TABLE_NAME;
    stmt = NULL;
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        callback(NULL, sqlite3_column_count(stmt), sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1));
    } else {
        fprintf(stderr, "No rows found\n");
    }

    sqlite3_finalize(stmt);

    sqlite3_close(db);
    return 0;
}