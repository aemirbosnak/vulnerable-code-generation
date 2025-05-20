//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: unmistakable
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

void create_database(Database *db, int num_rows, int num_cols) {
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = (char *)malloc(num_cols * MAX_DATA_SIZE);
        memset(db->data[i], 0, num_cols * MAX_DATA_SIZE);
    }
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

int main() {
    Database db;
    create_database(&db, 10, 5);

    for (int i = 0; i < db.num_rows; i++) {
        for (int j = 0; j < db.num_cols; j++) {
            sprintf(db.data[i] + j * MAX_DATA_SIZE, "%d", i * db.num_cols + j);
        }
    }

    for (int i = 0; i < db.num_rows; i++) {
        for (int j = 0; j < db.num_cols; j++) {
            printf("%s ", db.data[i] + j * MAX_DATA_SIZE);
        }
        printf("\n");
    }

    destroy_database(&db);
    return 0;
}