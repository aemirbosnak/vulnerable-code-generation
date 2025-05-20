//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: minimalist
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

void init_database(Database *db) {
    db->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    db->num_rows = 0;
    db->num_cols = 0;
}

void destroy_database(Database *db) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

void add_row(Database *db, char *row_data) {
    db->data[db->num_rows] = (char *)malloc(strlen(row_data) + 1);
    strcpy(db->data[db->num_rows], row_data);
    db->num_rows++;
}

void print_database(Database *db) {
    int i, j;
    for (i = 0; i < db->num_rows; i++) {
        for (j = 0; j < db->num_cols; j++) {
            printf("%s ", db->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    init_database(&db);
    add_row(&db, "John Doe");
    add_row(&db, "Jane Smith");
    add_row(&db, "Bob Johnson");
    print_database(&db);
    destroy_database(&db);
    return 0;
}