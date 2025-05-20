//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_ROWS 1000
#define MAX_NUM_COLUMNS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_rows;
    int num_columns;
    int **data;
} Database;

void create_database(Database *db, char *name, int num_rows, int num_columns) {
    strcpy(db->name, name);
    db->num_rows = num_rows;
    db->num_columns = num_columns;
    db->data = (int **) malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = (int *) malloc(num_columns * sizeof(int));
    }
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

void set_value(Database *db, int row, int column, int value) {
    db->data[row][column] = value;
}

int get_value(Database *db, int row, int column) {
    return db->data[row][column];
}

int main() {
    Database db;
    create_database(&db, "example_database", 3, 3);

    set_value(&db, 0, 0, 1);
    set_value(&db, 0, 1, 2);
    set_value(&db, 0, 2, 3);
    set_value(&db, 1, 0, 4);
    set_value(&db, 1, 1, 5);
    set_value(&db, 1, 2, 6);
    set_value(&db, 2, 0, 7);
    set_value(&db, 2, 1, 8);
    set_value(&db, 2, 2, 9);

    int value = get_value(&db, 1, 2);
    printf("Value at (1, 2) is %d\n", value);

    destroy_database(&db);

    return 0;
}