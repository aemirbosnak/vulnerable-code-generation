//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: satisfied
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
    void *data;
} row_data;

// Define the structure of a database table
typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    row_data **data;
} table;

// Create a new database table
table *create_table(char *name, int num_rows, int num_cols) {
    table *t = malloc(sizeof(table));
    t->name = strdup(name);
    t->num_rows = num_rows;
    t->num_cols = num_cols;
    t->data = malloc(sizeof(row_data *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        t->data[i] = malloc(sizeof(row_data) * num_cols);
    }
    return t;
}

// Insert a row into a database table
void insert_row(table *t, int row, row_data *data) {
    for (int i = 0; i < t->num_cols; i++) {
        t->data[row][i] = data[i];
    }
}

// Print the contents of a database table
void print_table(table *t) {
    for (int i = 0; i < t->num_rows; i++) {
        for (int j = 0; j < t->num_cols; j++) {
            switch (t->data[i][j].type) {
                case INT:
                    printf("%d ", *(int *)t->data[i][j].data);
                    break;
                case FLOAT:
                    printf("%f ", *(float *)t->data[i][j].data);
                    break;
                case STRING:
                    printf("%s ", (char *)t->data[i][j].data);
                    break;
            }
        }
        printf("\n");
    }
}

// Free the memory allocated for a database table
void free_table(table *t) {
    for (int i = 0; i < t->num_rows; i++) {
        free(t->data[i]);
    }
    free(t->data);
    free(t->name);
    free(t);
}

int main() {
    // Create a new database table
    table *t = create_table("students", 3, 4);

    // Insert some rows into the table
    row_data row1[] = {
        {INT, malloc(sizeof(int))},
        {FLOAT, malloc(sizeof(float))},
        {STRING, malloc(sizeof(char) * 10)},
        {STRING, malloc(sizeof(char) * 10)}
    };
    *(int *)row1[0].data = 1;
    *(float *)row1[1].data = 3.14;
    strcpy((char *)row1[2].data, "John");
    strcpy((char *)row1[3].data, "Doe");
    insert_row(t, 0, row1);

    row_data row2[] = {
        {INT, malloc(sizeof(int))},
        {FLOAT, malloc(sizeof(float))},
        {STRING, malloc(sizeof(char) * 10)},
        {STRING, malloc(sizeof(char) * 10)}
    };
    *(int *)row2[0].data = 2;
    *(float *)row2[1].data = 3.14;
    strcpy((char *)row2[2].data, "Jane");
    strcpy((char *)row2[3].data, "Doe");
    insert_row(t, 1, row2);

    row_data row3[] = {
        {INT, malloc(sizeof(int))},
        {FLOAT, malloc(sizeof(float))},
        {STRING, malloc(sizeof(char) * 10)},
        {STRING, malloc(sizeof(char) * 10)}
    };
    *(int *)row3[0].data = 3;
    *(float *)row3[1].data = 3.14;
    strcpy((char *)row3[2].data, "Bob");
    strcpy((char *)row3[3].data, "Smith");
    insert_row(t, 2, row3);

    // Print the contents of the table
    print_table(t);

    // Free the memory allocated for the table
    free_table(t);

    return 0;
}