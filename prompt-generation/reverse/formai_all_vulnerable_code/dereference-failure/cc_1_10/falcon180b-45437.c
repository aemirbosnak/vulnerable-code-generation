//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1024

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

void init_db(Database *db) {
    db->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    db->num_rows = 0;
    db->num_cols = 0;
}

void free_db(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

void add_row(Database *db, char *row_data) {
    db->data[db->num_rows] = strdup(row_data);
    db->num_rows++;
    int col_count = 0;
    while (row_data[col_count]!= '\0') {
        col_count++;
    }
    if (col_count > db->num_cols) {
        db->num_cols = col_count;
    }
}

int main() {
    Database db;
    init_db(&db);

    char input_buffer[MAX_DATA_SIZE];
    while (fgets(input_buffer, MAX_DATA_SIZE, stdin)!= NULL) {
        char *row_data = strtok(input_buffer, "\n");
        add_row(&db, row_data);
    }

    for (int i = 0; i < db.num_rows; i++) {
        for (int j = 0; j < db.num_cols; j++) {
            printf("%c", db.data[i][j]);
        }
        printf("\n");
    }

    free_db(&db);

    return 0;
}