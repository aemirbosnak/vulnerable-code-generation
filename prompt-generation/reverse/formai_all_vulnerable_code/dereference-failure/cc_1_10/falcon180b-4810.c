//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_FIELD_SIZE 100

// Struct to hold table information
typedef struct {
    char name[MAX_FIELD_SIZE];
    int num_rows;
    int num_columns;
    char **data;
} Table;

// Function to create a new table
Table *create_table(char *name, int num_rows, int num_columns) {
    Table *table = (Table *) malloc(sizeof(Table));
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = (char **) malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *) malloc(num_columns * sizeof(char));
        for (int j = 0; j < num_columns; j++) {
            table->data[i][j] = '\0';
        }
    }
    return table;
}

// Function to insert data into a table
void insert_data(Table *table, int row, int column, char *data) {
    strcpy(table->data[row - 1][column - 1], data);
}

// Function to retrieve data from a table
char *get_data(Table *table, int row, int column) {
    return table->data[row - 1][column - 1];
}

// Function to display a table
void display_table(Table *table) {
    printf("Table Name: %s\n", table->name);
    printf("Number of Rows: %d\n", table->num_rows);
    printf("Number of Columns: %d\n", table->num_columns);
    printf("Data:\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s ", get_data(table, i + 1, j + 1));
        }
        printf("\n");
    }
}

// Function to delete a table
void delete_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

// Main function to test the database functions
int main() {
    Table *table = create_table("test_table", 3, 3);
    insert_data(table, 1, 1, "John");
    insert_data(table, 1, 2, "Doe");
    insert_data(table, 2, 1, "Jane");
    insert_data(table, 2, 2, "Doe");
    insert_data(table, 3, 1, "Bob");
    insert_data(table, 3, 2, "Smith");
    display_table(table);
    delete_table(table);
    return 0;
}