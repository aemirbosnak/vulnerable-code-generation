//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char **values;
    int num_rows;
    int num_columns;
} Database;

void create_database(Database *db) {
    db->values = (char **)malloc(sizeof(char *) * MAX_ROWS);
    db->num_rows = 0;
    db->num_columns = 0;
}

void add_column(Database *db, char *name) {
    db->num_columns++;
}

void add_row(Database *db, char **values) {
    db->num_rows++;
    db->values = (char **)realloc(db->values, sizeof(char *) * db->num_rows);
    memcpy(&db->values[db->num_rows - 1], values, sizeof(char *) * db->num_columns);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_columns; j++) {
            printf("%s\t", db->values[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    create_database(&db);

    add_column(&db, "ID");
    add_column(&db, "Name");
    add_column(&db, "Age");

    char *values[3] = {"1", "John", "25"};
    add_row(&db, values);

    char *values2[3] = {"2", "Jane", "30"};
    add_row(&db, values2);

    print_database(&db);

    return 0;
}