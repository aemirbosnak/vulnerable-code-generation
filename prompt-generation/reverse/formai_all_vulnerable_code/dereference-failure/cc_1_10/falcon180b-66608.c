//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static char *sqlite_errmsg(sqlite3 *db) {
    const char *msg = sqlite3_errmsg(db);
    char *res = malloc(strlen(msg) + 1);
    strcpy(res, msg);
    return res;
}

static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i]? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *errMsg = NULL;
    if (sqlite3_open("test.db", &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sqlCreate = "CREATE TABLE IF NOT EXISTS users(" \
                      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
                      "name TEXT NOT NULL," \
                      "age INTEGER);";
    char *sqlInsert = "INSERT INTO users(name, age) VALUES('John', 30);";
    char *sqlUpdate = "UPDATE users SET age = 31 WHERE name = 'John';";
    char *sqlDelete = "DELETE FROM users WHERE name = 'John';";
    char *sqlSelect = "SELECT * FROM users;";

    if (sqlite3_exec(db, sqlCreate, NULL, NULL, &errMsg)) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    if (sqlite3_exec(db, sqlInsert, NULL, NULL, &errMsg)) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    if (sqlite3_exec(db, sqlUpdate, NULL, NULL, &errMsg)) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    if (sqlite3_exec(db, sqlDelete, NULL, NULL, &errMsg)) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    if (sqlite3_exec(db, sqlSelect, callback, NULL, &errMsg)) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);
    return 0;
}