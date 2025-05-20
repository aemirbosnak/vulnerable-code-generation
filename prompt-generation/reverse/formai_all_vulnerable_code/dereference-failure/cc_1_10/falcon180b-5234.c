//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Define the struct for a row of data
typedef struct {
    int num_cols;
    char **data;
} Row;

// Define the struct for the database
typedef struct {
    int num_rows;
    int num_cols;
    Row **rows;
} Database;

// Function to initialize the database
void init_database(Database *db, int num_rows, int num_cols) {
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->rows = (Row *)malloc(num_rows * sizeof(Row));
    for (int i = 0; i < num_rows; i++) {
        db->rows[i] = (Row *)malloc(sizeof(Row));
        db->rows[i]->num_cols = num_cols;
        db->rows[i]->data = (char **)malloc(num_cols * sizeof(char *));
        for (int j = 0; j < num_cols; j++) {
            db->rows[i]->data[j] = NULL;
        }
    }
}

// Function to add data to the database
void add_data(Database *db, int row, int col, char *data) {
    db->rows[row]->data[col] = (char *)malloc(strlen(data) + 1);
    strcpy(db->rows[row]->data[col], data);
}

// Function to print the database
void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            if (db->rows[i]->data[j]!= NULL) {
                printf("%s\t", db->rows[i]->data[j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

// Function to free the memory used by the database
void free_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            if (db->rows[i]->data[j]!= NULL) {
                free(db->rows[i]->data[j]);
            }
        }
        free(db->rows[i]->data);
        free(db->rows[i]);
    }
    free(db->rows);
}

int main() {
    Database db;
    init_database(&db, 2, 3);
    add_data(&db, 0, 0, "Name");
    add_data(&db, 0, 1, "John");
    add_data(&db, 0, 2, "Doe");
    add_data(&db, 1, 0, "Age");
    add_data(&db, 1, 1, "30");
    add_data(&db, 1, 2, "Male");
    print_database(&db);
    free_database(&db);
    return 0;
}