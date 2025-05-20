//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NAME_LEN 50

struct database {
    char name[MAX_NAME_LEN];
    int rows;
    int cols;
    int* data;
};

void create_database(struct database* db) {
    db->rows = 0;
    db->cols = 0;
    db->data = NULL;
}

void add_row(struct database* db, int* data, int rows) {
    db->rows++;
    db->data = realloc(db->data, (db->rows * db->cols + rows) * sizeof(int));
    memcpy(&(db->data[db->rows * db->cols]), data, rows * sizeof(int));
}

void print_database(struct database* db) {
    printf("%s\n", db->name);
    printf("Rows: %d\n", db->rows);
    printf("Columns: %d\n", db->cols);
    printf("Data:\n");
    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->cols; j++) {
            printf("%d ", db->data[i * db->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    struct database db;
    create_database(&db);

    int data[5] = {1, 2, 3, 4, 5};
    add_row(&db, data, 5);

    print_database(&db);

    return 0;
}