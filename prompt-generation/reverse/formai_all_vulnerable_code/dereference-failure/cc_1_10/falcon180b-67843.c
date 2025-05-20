//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 1000
#define MAX_VAL_LEN 100

typedef struct {
    char **values;
    int num_cols;
    int num_rows;
} Database;

Database *create_database(int num_cols, int num_rows) {
    Database *db = malloc(sizeof(Database));
    db->num_cols = num_cols;
    db->num_rows = num_rows;
    db->values = malloc(num_cols * num_rows * sizeof(char*));
    for (int i = 0; i < num_cols * num_rows; i++) {
        db->values[i] = NULL;
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_cols * db->num_rows; i++) {
        if (db->values[i]!= NULL) {
            free(db->values[i]);
        }
    }
    free(db->values);
    free(db);
}

void set_value(Database *db, int row, int col, char *val) {
    if (row >= 0 && row < db->num_rows && col >= 0 && col < db->num_cols) {
        if (db->values[row * db->num_cols + col]!= NULL) {
            free(db->values[row * db->num_cols + col]);
        }
        db->values[row * db->num_cols + col] = strdup(val);
    }
}

char *get_value(Database *db, int row, int col) {
    if (row >= 0 && row < db->num_rows && col >= 0 && col < db->num_cols) {
        return db->values[row * db->num_cols + col];
    }
    return NULL;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            char *val = get_value(db, i, j);
            printf("%-*s", MAX_VAL_LEN, val!= NULL? val : "");
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database(3, 2);
    set_value(db, 0, 0, "Alice");
    set_value(db, 0, 1, "25");
    set_value(db, 0, 2, "Developer");
    set_value(db, 1, 0, "Bob");
    set_value(db, 1, 1, "30");
    set_value(db, 1, 2, "Manager");
    set_value(db, 2, 0, "Charlie");
    set_value(db, 2, 1, "35");
    set_value(db, 2, 2, "CEO");
    print_database(db);
    destroy_database(db);
    return 0;
}