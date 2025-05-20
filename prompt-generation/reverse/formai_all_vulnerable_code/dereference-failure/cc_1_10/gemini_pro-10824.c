//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a database table
typedef struct {
    char *name;
    int num_columns;
    char **columns;
    int num_rows;
    char ***rows;
} table;

// Function to create a new table
table *create_table(char *name, int num_columns, char **columns) {
    table *t = malloc(sizeof(table));
    t->name = name;
    t->num_columns = num_columns;
    t->columns = columns;
    t->num_rows = 0;
    t->rows = NULL;
    return t;
}

// Function to insert a new row into a table
void insert_row(table *t, char **values) {
    t->rows = realloc(t->rows, (t->num_rows + 1) * sizeof(char **));
    t->rows[t->num_rows] = values;
    t->num_rows++;
}

// Function to print a table
void print_table(table *t) {
    printf("Table: %s\n", t->name);
    printf("Columns: ");
    for (int i = 0; i < t->num_columns; i++) {
        printf("%s ", t->columns[i]);
    }
    printf("\n");
    for (int i = 0; i < t->num_rows; i++) {
        printf("Row: ");
        for (int j = 0; j < t->num_columns; j++) {
            printf("%s ", t->rows[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new table
    table *t = create_table("students", 3, (char *[]){"name", "age", "grade"});

    // Insert some rows into the table
    insert_row(t, (char *[]){"John", "20", "A"});
    insert_row(t, (char *[]){"Mary", "21", "B"});
    insert_row(t, (char *[]){"Bob", "22", "C"});

    // Print the table
    print_table(t);

    return 0;
}