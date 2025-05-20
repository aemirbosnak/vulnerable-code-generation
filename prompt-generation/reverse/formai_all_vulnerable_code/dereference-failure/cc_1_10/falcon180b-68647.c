//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char data[MAX_DATA_SIZE];
    int row;
    int col;
} Data;

typedef struct {
    Data **data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db, int num_rows, int num_cols) {
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = (Data **)malloc(num_rows * sizeof(Data *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = (Data *)malloc(num_cols * sizeof(Data));
        for (int j = 0; j < num_cols; j++) {
            db->data[i][j].row = i;
            db->data[i][j].col = j;
        }
    }
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

void set_data(Database *db, int row, int col, char *data) {
    strcpy(db->data[row][col].data, data);
}

char *get_data(Database *db, int row, int col) {
    return db->data[row][col].data;
}

int main() {
    Database db;
    init_database(&db, 5, 5);

    set_data(&db, 0, 0, "Hello");
    set_data(&db, 0, 1, "World");
    set_data(&db, 1, 0, "Foo");
    set_data(&db, 1, 1, "Bar");

    char *data = get_data(&db, 0, 0);
    printf("%s\n", data);

    destroy_database(&db);

    return 0;
}