//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rows and columns in the database
#define MAX_ROWS 100
#define MAX_COLS 10

// Define the data types that can be stored in the database
typedef enum {
    INT,
    FLOAT,
    STRING
} data_type;

// Define the structure of a database row
typedef struct {
    data_type type;
    union {
        int i;
        float f;
        char *s;
    } value;
} row;

// Define the structure of a database table
typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    row rows[MAX_ROWS];
} table;

// Create a new database
table *create_database(char *name) {
    table *db = malloc(sizeof(table));
    db->name = strdup(name);
    db->num_rows = 0;
    db->num_cols = 0;
    return db;
}

// Add a new row to a database table
void add_row(table *db, row *row) {
    db->rows[db->num_rows++] = *row;
}

// Print the contents of a database table
void print_table(table *db) {
    for (int i = 0; i < db->num_rows; i++) {
        row *row = &db->rows[i];
        switch (row->type) {
            case INT:
                printf("%d ", row->value.i);
                break;
            case FLOAT:
                printf("%f ", row->value.f);
                break;
            case STRING:
                printf("%s ", row->value.s);
                break;
        }
    }
    printf("\n");
}

// Free the memory allocated for a database
void free_database(table *db) {
    for (int i = 0; i < db->num_rows; i++) {
        row *row = &db->rows[i];
        if (row->type == STRING) {
            free(row->value.s);
        }
    }
    free(db->name);
    free(db);
}

// Main function
int main() {
    // Create a new database
    table *db = create_database("mydb");

    // Add some rows to the database
    row row1 = {INT, {1}};
    add_row(db, &row1);
    row row2 = {FLOAT, {3.14}};
    add_row(db, &row2);
    row row3 = {STRING, {"Hello, world!"}};
    add_row(db, &row3);

    // Print the contents of the database
    print_table(db);

    // Free the memory allocated for the database
    free_database(db);

    return 0;
}