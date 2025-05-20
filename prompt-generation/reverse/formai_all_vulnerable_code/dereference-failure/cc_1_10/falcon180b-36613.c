//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

Database *create_database(int num_rows, int num_cols) {
    Database *db = malloc(sizeof(Database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = calloc(num_rows, sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = calloc(num_cols, sizeof(char));
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void set_cell(Database *db, int row, int col, char *value) {
    if (row >= 0 && row < db->num_rows && col >= 0 && col < db->num_cols) {
        db->data[row][col] = strdup(value);
    }
}

char *get_cell(Database *db, int row, int col) {
    if (row >= 0 && row < db->num_rows && col >= 0 && col < db->num_cols) {
        return db->data[row][col];
    }
    return NULL;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            char *cell = get_cell(db, i, j);
            if (cell!= NULL) {
                printf("%s ", cell);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database(3, 3);
    set_cell(db, 0, 0, "foo");
    set_cell(db, 0, 1, "bar");
    set_cell(db, 1, 0, "baz");
    set_cell(db, 1, 1, "qux");
    set_cell(db, 2, 0, "quux");
    set_cell(db, 2, 1, "corge");
    print_database(db);
    destroy_database(db);
    return 0;
}