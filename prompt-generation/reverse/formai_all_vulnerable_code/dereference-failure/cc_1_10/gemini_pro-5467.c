//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
    char *data[MAX_COLS];
} Row;

typedef struct {
    Row rows[MAX_ROWS];
    int num_rows;
    int num_cols;
} Database;

Database *create_database(int num_rows, int num_cols) {
    Database *db = malloc(sizeof(Database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            db->rows[i].data[j] = NULL;
        }
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            free(db->rows[i].data[j]);
        }
    }
    free(db);
}

void insert_row(Database *db, int row_num, char **data) {
    if (row_num >= db->num_rows) {
        fprintf(stderr, "Error: row number %d out of bounds\n", row_num);
        return;
    }
    for (int i = 0; i < db->num_cols; i++) {
        db->rows[row_num].data[i] = strdup(data[i]);
    }
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s ", db->rows[i].data[j]);
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database(5, 3);

    insert_row(db, 0, (char *[]) {"John", "Doe", "123 Main Street"});
    insert_row(db, 1, (char *[]) {"Jane", "Doe", "456 Elm Street"});
    insert_row(db, 2, (char *[]) {"Jack", "Jones", "789 Oak Street"});
    insert_row(db, 3, (char *[]) {"Jill", "Jones", "1011 Pine Street"});
    insert_row(db, 4, (char *[]) {"John", "Smith", "1213 Maple Street"});

    print_database(db);

    destroy_database(db);

    return 0;
}