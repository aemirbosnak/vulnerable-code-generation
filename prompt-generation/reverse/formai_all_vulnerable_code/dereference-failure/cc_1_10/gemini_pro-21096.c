//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
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
    row *rows;
} table;

// Create a new database table
table *create_table(char *name, int num_rows, int num_cols) {
    table *t = malloc(sizeof(table));
    t->name = strdup(name);
    t->num_rows = num_rows;
    t->num_cols = num_cols;
    t->rows = malloc(sizeof(row) * num_rows);
    return t;
}

// Insert a row into a database table
void insert_row(table *t, int row_num, row *r) {
    t->rows[row_num] = *r;
}

// Print the contents of a database table
void print_table(table *t) {
    printf("Table: %s\n", t->name);
    for (int i = 0; i < t->num_rows; i++) {
        row r = t->rows[i];
        switch (r.type) {
            case INT:
                printf("%d", r.value.i);
                break;
            case FLOAT:
                printf("%f", r.value.f);
                break;
            case STRING:
                printf("%s", r.value.s);
                break;
        }
        printf("\n");
    }
}

// Free the memory allocated for a database table
void free_table(table *t) {
    free(t->name);
    free(t->rows);
    free(t);
}

int main() {
    // Create a new database table
    table *t = create_table("my_table", 3, 2);

    // Insert some rows into the table
    row r1 = {INT, {1}};
    insert_row(t, 0, &r1);
    row r2 = {FLOAT, {3.14}};
    insert_row(t, 1, &r2);
    row r3 = {STRING, {"Hello, world!"}};
    insert_row(t, 2, &r3);

    // Print the contents of the table
    print_table(t);

    // Free the memory allocated for the table
    free_table(t);

    return 0;
}