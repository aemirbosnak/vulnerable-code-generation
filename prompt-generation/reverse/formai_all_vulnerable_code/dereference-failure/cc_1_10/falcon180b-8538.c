//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

Database *create_database(int num_rows, int num_cols) {
    Database *db = malloc(sizeof(Database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = malloc(num_cols * MAX_DATA_SIZE);
        for (int j = 0; j < num_cols; j++) {
            db->data[i][j] = '\0';
        }
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            free(db->data[i][j]);
        }
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void print_database(const Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s ", db->data[i][j]);
        }
        printf("\n");
    }
}

void set_cell_value(Database *db, int row, int col, const char *value) {
    strcpy(db->data[row][col], value);
}

const char *get_cell_value(const Database *db, int row, int col) {
    return db->data[row][col];
}

int main() {
    Database *db = create_database(3, 3);

    set_cell_value(db, 0, 0, "Name");
    set_cell_value(db, 0, 1, "Age");
    set_cell_value(db, 0, 2, "City");

    set_cell_value(db, 1, 0, "John");
    set_cell_value(db, 1, 1, "30");
    set_cell_value(db, 1, 2, "New York");

    set_cell_value(db, 2, 0, "Jane");
    set_cell_value(db, 2, 1, "25");
    set_cell_value(db, 2, 2, "Los Angeles");

    print_database(db);

    destroy_database(db);

    return 0;
}