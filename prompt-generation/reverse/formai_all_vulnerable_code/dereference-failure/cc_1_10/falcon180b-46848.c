//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} Database;

void database_init(Database *db) {
    db->rows = (char **)malloc(MAX_ROWS * sizeof(char *));
    db->num_rows = 0;
    db->num_cols = 0;
}

void database_destroy(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->rows[i]);
    }
    free(db->rows);
}

void database_add_row(Database *db, char *row) {
    db->rows[db->num_rows] = row;
    db->num_rows++;
}

void database_print(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("%s\n", db->rows[i]);
    }
}

int main() {
    Database db;
    database_init(&db);

    char row1[] = "Name,Age,City";
    char row2[] = "John,25,New York";
    char row3[] = "Jane,30,Los Angeles";

    database_add_row(&db, row1);
    database_add_row(&db, row2);
    database_add_row(&db, row3);

    database_print(&db);

    database_destroy(&db);

    return 0;
}