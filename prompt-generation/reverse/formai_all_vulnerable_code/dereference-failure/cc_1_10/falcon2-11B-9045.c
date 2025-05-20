//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 5

struct Database {
    char name[50];
    int columns;
    int rows;
    int *data;
};

void create_database(struct Database *db) {
    printf("Creating database: %s...\n", db->name);
    db->columns = MAX_COLUMNS;
    db->rows = MAX_ROWS;
    db->data = (int*)malloc(MAX_ROWS * MAX_COLUMNS * sizeof(int));
    printf("Database created.\n");
}

void insert_data(struct Database *db, int row, int column, int value) {
    if (row < 0 || row >= db->rows || column < 0 || column >= db->columns) {
        printf("Invalid row or column number.\n");
        return;
    }
    db->data[row * db->columns + column] = value;
}

void display_data(struct Database *db) {
    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->columns; j++) {
            printf("%d ", db->data[i * db->columns + j]);
        }
        printf("\n");
    }
}

void delete_data(struct Database *db, int row, int column) {
    if (row < 0 || row >= db->rows || column < 0 || column >= db->columns) {
        printf("Invalid row or column number.\n");
        return;
    }
    db->data[row * db->columns + column] = 0;
}

int main() {
    struct Database db;
    create_database(&db);
    insert_data(&db, 0, 0, 10);
    insert_data(&db, 1, 0, 20);
    insert_data(&db, 0, 1, 30);
    display_data(&db);
    delete_data(&db, 1, 0);
    display_data(&db);
    free(db.data);
    return 0;
}