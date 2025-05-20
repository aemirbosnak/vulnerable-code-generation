//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int id;
} row_t;

typedef struct {
    row_t **rows;
    int num_rows;
    int num_cols;
} database_t;

database_t *db_create(int num_rows, int num_cols) {
    database_t *db = malloc(sizeof(database_t));
    db->rows = malloc(num_rows * sizeof(row_t *));
    db->num_rows = num_rows;
    db->num_cols = num_cols;

    for (int i = 0; i < num_rows; i++) {
        db->rows[i] = malloc(num_cols * sizeof(row_t));
    }

    return db;
}

void db_destroy(database_t *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            free(db->rows[i][j].name);
        }
        free(db->rows[i]);
    }
    free(db->rows);
    free(db);
}

void db_print(database_t *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s ", db->rows[i][j].name);
        }
        printf("\n");
    }
}

int main() {
    database_t *db = db_create(3, 2);

    db->rows[0][0].name = strdup("Alice");
    db->rows[0][1].name = strdup("25");

    db->rows[1][0].name = strdup("Bob");
    db->rows[1][1].name = strdup("30");

    db->rows[2][0].name = strdup("Charlie");
    db->rows[2][1].name = strdup("35");

    db_print(db);

    db_destroy(db);

    return 0;
}