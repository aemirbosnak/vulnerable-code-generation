//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns and rows in the database
#define MAX_COLUMNS 10
#define MAX_ROWS 100

// Define the structure of a database table
typedef struct {
    char name[32];
    int num_columns;
    char columns[MAX_COLUMNS][32];
    int num_rows;
    char rows[MAX_ROWS][MAX_COLUMNS][1024];
} table;

// Create a new database table
table* create_table(char* name, int num_columns, char** columns) {
    table* t = malloc(sizeof(table));
    strcpy(t->name, name);
    t->num_columns = num_columns;
    for (int i = 0; i < num_columns; i++) {
        strcpy(t->columns[i], columns[i]);
    }
    t->num_rows = 0;
    return t;
}

// Insert a new row into a database table
void insert_row(table* t, char** values) {
    for (int i = 0; i < t->num_columns; i++) {
        strcpy(t->rows[t->num_rows][i], values[i]);
    }
    t->num_rows++;
}

// Print the contents of a database table
void print_table(table* t) {
    printf("Table: %s\n", t->name);
    printf("Columns: ");
    for (int i = 0; i < t->num_columns; i++) {
        printf("%s ", t->columns[i]);
    }
    printf("\n");
    printf("Rows:\n");
    for (int i = 0; i < t->num_rows; i++) {
        for (int j = 0; j < t->num_columns; j++) {
            printf("%s ", t->rows[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new database table
    table* t = create_table("students", 3, (char*[]){"name", "age", "gpa"});

    // Insert some rows into the table
    insert_row(t, (char*[]){"John", "20", "3.5"});
    insert_row(t, (char*[]){"Jane", "21", "3.8"});
    insert_row(t, (char*[]){"Bob", "22", "3.2"});

    // Print the contents of the table
    print_table(t);

    return 0;
}