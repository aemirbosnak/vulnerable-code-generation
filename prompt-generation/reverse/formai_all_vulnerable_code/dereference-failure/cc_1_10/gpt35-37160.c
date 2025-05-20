//FormAI DATASET v1.0 Category: Database querying ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

void print_result(int count, char **values, char **column_names) {
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", column_names[i], values[i]);
    }
}

int main() {
    sqlite3 *db;
    char *error_message = NULL;

    int rc = sqlite3_open("my_database.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    char *query = "SELECT * FROM customers WHERE name = 'Juliet'";

    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    rc = sqlite3_step(stmt);

    if (rc != SQLITE_ROW) {
        printf("No records found\n");
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        exit(0);
    }

    int count = sqlite3_column_count(stmt);
    char **column_names = malloc(sizeof(char*) * count);

    for (int i = 0; i < count; i++) {
        column_names[i] = strdup(sqlite3_column_name(stmt, i));
    }

    char **values = malloc(sizeof(char*) * count);

    for (int i = 0; i < count; i++) {
        values[i] = strdup((char*) sqlite3_column_text(stmt, i));
    }

    print_result(count, values, column_names);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    exit(0);
}