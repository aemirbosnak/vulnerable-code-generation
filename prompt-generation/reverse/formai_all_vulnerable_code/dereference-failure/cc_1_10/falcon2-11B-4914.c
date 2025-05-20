//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 10

struct database {
    int rows;
    int cols;
    int **data;
};

struct database create_database(int rows, int cols) {
    struct database db;
    db.rows = rows;
    db.cols = cols;
    db.data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        db.data[i] = malloc(cols * sizeof(int));
    }
    return db;
}

void destroy_database(struct database *db) {
    for (int i = 0; i < db->rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void insert_data(struct database *db, int row, int col, int value) {
    db->data[row][col] = value;
}

int get_data(struct database *db, int row, int col) {
    return db->data[row][col];
}

int main() {
    struct database db;
    db = create_database(3, 3);
    insert_data(&db, 0, 0, 10);
    insert_data(&db, 0, 1, 20);
    insert_data(&db, 0, 2, 30);
    insert_data(&db, 1, 0, 40);
    insert_data(&db, 1, 1, 50);
    insert_data(&db, 1, 2, 60);
    insert_data(&db, 2, 0, 70);
    insert_data(&db, 2, 1, 80);
    insert_data(&db, 2, 2, 90);

    printf("Database:\n");
    for (int i = 0; i < db.rows; i++) {
        for (int j = 0; j < db.cols; j++) {
            printf("%d ", get_data(&db, i, j));
        }
        printf("\n");
    }

    destroy_database(&db);
    return 0;
}