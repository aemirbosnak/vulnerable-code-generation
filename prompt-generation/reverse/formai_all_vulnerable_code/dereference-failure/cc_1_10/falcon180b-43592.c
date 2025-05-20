//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int num_cols;
    int num_rows;
    char **data;
} Database;

Database *create_database(int num_cols, int num_rows) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->num_cols = num_cols;
    db->num_rows = num_rows;
    db->data = (char **)malloc(sizeof(char *) * num_cols);
    for (int i = 0; i < num_cols; i++) {
        db->data[i] = (char *)malloc(sizeof(char) * MAX_DATA_SIZE);
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_cols; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

int add_row(Database *db) {
    if (db->num_rows == MAX_ROWS) {
        return -1;
    }
    db->num_rows++;
    return 0;
}

int add_col(Database *db) {
    if (db->num_cols == MAX_COLS) {
        return -1;
    }
    db->num_cols++;
    return 0;
}

int insert_data(Database *db, int row, int col, char *data) {
    if (row >= db->num_rows || col >= db->num_cols) {
        return -1;
    }
    strcpy(db->data[col][row], data);
    return 0;
}

char *get_data(Database *db, int row, int col) {
    if (row >= db->num_rows || col >= db->num_cols) {
        return NULL;
    }
    return db->data[col][row];
}

int main() {
    Database *db = create_database(3, 2);
    add_row(db);
    add_col(db);
    insert_data(db, 0, 0, "John");
    insert_data(db, 0, 1, "Doe");
    insert_data(db, 1, 0, "Jane");
    insert_data(db, 1, 1, "Doe");
    char *name = get_data(db, 0, 0);
    printf("%s\n", name);
    destroy_database(db);
    return 0;
}