//MISTRAL-7B DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 20

typedef struct {
    char name[50];
    double mass;
    int atomic_number;
} Element;

void print_result(sqlite3 *db, char *sql, int num_columns) {
    sqlite3_stmt *statement;
    int i;
    Element element;

    if (sqlite3_prepare_v2(db, sql, strlen(sql), &statement, NULL) == SQLITE_OK) {
        for (i = 0; i < num_columns; i++) {
            printf("%-20s", sqlite3_column_name(statement, i));
        }
        printf("\n");

        while (sqlite3_step(statement) == SQLITE_ROW) {
            memset(&element, 0, sizeof(Element));

            strcpy(element.name, (char *) sqlite3_column_text(statement, 0));
            element.mass = sqlite3_column_double(statement, 1);
            element.atomic_number = sqlite3_column_int(statement, 2);

            printf("%-20s | %12.6f | %10d\n", element.name, element.mass, element.atomic_number);
        }

        sqlite3_finalize(statement);
    } else {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
    }
}

int main() {
    sqlite3 *db;
    char *db_name = "elements.db";
    char *err_msg = 0;

    if (sqlite3_open(db_name, &db) != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char create_table[] = "CREATE TABLE IF NOT EXISTS elements ("
                          "name TEXT NOT NULL,"
                          "mass REAL NOT NULL,"
                          "atomic_number INTEGER NOT NULL PRIMARY KEY)";

    char insert_helium[] = "INSERT INTO elements (name, mass, atomic_number) VALUES"
                          "('Helium', 4.003, 2)";
    char insert_hydrogen[] = "INSERT INTO elements (name, mass, atomic_number) VALUES"
                           "('Hydrogen', 1.008, 1)";

    if (sqlite3_exec(db, create_table, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to create table: %s\n", err_msg);
        sqlite3_close(db);
        return 1;
    }

    if (sqlite3_exec(db, insert_helium, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to insert Helium: %s\n", err_msg);
        sqlite3_close(db);
        return 1;
    }

    if (sqlite3_exec(db, insert_hydrogen, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to insert Hydrogen: %s\n", err_msg);
        sqlite3_close(db);
        return 1;
    }

    char select_all[] = "SELECT name, mass, atomic_number FROM elements";

    print_result(db, select_all, 3);

    sqlite3_close(db);

    return 0;
}