//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

Database *create_database(int num_rows, int num_cols) {
    Database *db = malloc(sizeof(Database));
    if (db == NULL) {
        printf("Error: Could not allocate memory for database.\n");
        exit(1);
    }

    db->data = malloc(num_rows * sizeof(char *));
    if (db->data == NULL) {
        printf("Error: Could not allocate memory for database data.\n");
        exit(1);
    }

    for (int i = 0; i < num_rows; i++) {
        db->data[i] = malloc(num_cols * sizeof(char));
        if (db->data[i] == NULL) {
            printf("Error: Could not allocate memory for database data row %d.\n", i);
            exit(1);
        }
    }

    db->num_rows = num_rows;
    db->num_cols = num_cols;

    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%c", db->data[i][j]);
        }
        printf("\n");
    }
}

void set_cell(Database *db, int row, int col, char value) {
    if (row >= db->num_rows || col >= db->num_cols) {
        printf("Error: Cell out of bounds.\n");
        exit(1);
    }

    db->data[row][col] = value;
}

char get_cell(Database *db, int row, int col) {
    if (row >= db->num_rows || col >= db->num_cols) {
        printf("Error: Cell out of bounds.\n");
        exit(1);
    }

    return db->data[row][col];
}

int main() {
    Database *db = create_database(MAX_ROWS, MAX_COLS);

    set_cell(db, 0, 0, 'A');
    set_cell(db, 0, 1, 'B');
    set_cell(db, 0, 2, 'C');

    print_database(db);

    destroy_database(db);

    return 0;
}