//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_ROW_SIZE 100

typedef struct {
    char *data[MAX_COLS];
} Row;

typedef struct {
    Row rows[MAX_ROWS];
    int num_rows;
    int num_cols;
} Database;

Database *create_database(int num_cols) {
    Database *db = malloc(sizeof(Database));
    db->num_cols = num_cols;
    db->num_rows = 0;
    return db;
}

void free_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            free(db->rows[i].data[j]);
        }
    }
    free(db);
}

int add_row(Database *db, char **data) {
    if (db->num_rows == MAX_ROWS) {
        return -1;
    }

    Row *row = &db->rows[db->num_rows++];
    for (int i = 0; i < db->num_cols; i++) {
        row->data[i] = malloc(MAX_ROW_SIZE);
        strcpy(row->data[i], data[i]);
    }

    return 0;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        Row *row = &db->rows[i];
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s ", row->data[j]);
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database(3);

    char *data1[] = {"John", "Doe", "123 Main Street"};
    char *data2[] = {"Jane", "Smith", "456 Elm Street"};
    char *data3[] = {"Bob", "Jones", "789 Oak Street"};

    add_row(db, data1);
    add_row(db, data2);
    add_row(db, data3);

    print_database(db);

    free_database(db);

    return 0;
}