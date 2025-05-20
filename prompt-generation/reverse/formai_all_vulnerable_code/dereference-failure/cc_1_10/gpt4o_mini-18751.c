//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define DATABASE "employee.db"
#define QUERY_SIZE 256

void check_sqlite_error(int rc, sqlite3 *db) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }
}

void print_employee_data(int num_columns, char **column_values, char **column_names) {
    printf("| %-5s | %-25s | %-20s |\n", column_names[0], column_names[1], column_names[2]);
    printf("|-------|-------------------------|----------------------|\n");
    for (int i = 0; i < num_columns; ++i) {
        printf("| %-5s | %-25s | %-20s |\n", column_values[i * 3], column_values[i * 3 + 1], column_values[i * 3 + 2]);
    }
    printf("|-------|-------------------------|----------------------|\n");
}

void execute_query(sqlite3 *db, const char *sql_query) {
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_query, -1, &stmt, NULL);
    check_sqlite_error(rc, db);

    int num_columns = 0;
    char **column_values = NULL;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        num_columns++;
        column_values = realloc(column_values, num_columns * 3 * sizeof(char *));
        
        for (int i = 0; i < 3; i++) {
            column_values[(num_columns - 1) * 3 + i] = strdup((const char *)sqlite3_column_text(stmt, i));
        }
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    const char *col_names[] = {"ID", "Name", "Position"};
    print_employee_data(num_columns, column_values, col_names);

    for (int i = 0; i < num_columns * 3; i++) {
        free(column_values[i]);
    }
    free(column_values);
    sqlite3_finalize(stmt);
}

void query_employees(sqlite3 *db) {
    const char *sql_query = "SELECT id, name, position FROM employees;";
    execute_query(db, sql_query);
}

int main(void) {
    sqlite3 *db;
    int rc = sqlite3_open(DATABASE, &db);
    check_sqlite_error(rc, db);

    printf("Welcome to the Employee Database Querying System\n");
    printf("------------------------------------------------\n");

    query_employees(db);

    sqlite3_close(db);
    printf("Database connection closed successfully.\n");
    return 0;
}