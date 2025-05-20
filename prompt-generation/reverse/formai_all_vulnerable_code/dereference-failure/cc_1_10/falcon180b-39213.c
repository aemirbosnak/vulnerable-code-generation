//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} database_t;

database_t *create_database(int rows, int cols) {
    database_t *db = (database_t *)malloc(sizeof(database_t));
    db->data = (char *)malloc(rows * cols * sizeof(char));
    db->rows = rows;
    db->cols = cols;
    return db;
}

void destroy_database(database_t *db) {
    free(db->data);
    free(db);
}

void set_data(database_t *db, int row, int col, char c) {
    int index = row * db->cols + col;
    db->data[index] = c;
}

char get_data(database_t *db, int row, int col) {
    int index = row * db->cols + col;
    return db->data[index];
}

void print_database(database_t *db) {
    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->cols; j++) {
            printf("%c", get_data(db, i, j));
        }
        printf("\n");
    }
}

int main() {
    database_t *db = create_database(3, 3);
    set_data(db, 0, 0, 'A');
    set_data(db, 0, 1, 'B');
    set_data(db, 0, 2, 'C');
    set_data(db, 1, 0, 'D');
    set_data(db, 1, 1, 'E');
    set_data(db, 1, 2, 'F');
    set_data(db, 2, 0, 'G');
    set_data(db, 2, 1, 'H');
    set_data(db, 2, 2, 'I');
    print_database(db);
    destroy_database(db);
    return 0;
}