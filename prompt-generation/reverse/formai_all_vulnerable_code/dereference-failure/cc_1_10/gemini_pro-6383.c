//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: ultraprecise
// Ultraprecise Database Simulation in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constants for table and column limits
#define MAX_TABLES 100
#define MAX_COLUMNS 50
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 255

// Data structures for table and column metadata
typedef struct {
    char name[MAX_NAME_LEN];
    int num_columns;
    char** column_names;
    char** column_types;
} table_metadata;

typedef struct {
    char name[MAX_NAME_LEN];
    char type[MAX_NAME_LEN];
    int size;
    bool is_primary_key;
} column_metadata;

// Data structure for a single row of data
typedef struct {
    char** values;
} row_data;

// Database structure
typedef struct {
    int num_tables;
    table_metadata* tables;
    row_data** rows;
} database;

// Function to create a new database
database* create_database() {
    database* db = malloc(sizeof(database));
    db->num_tables = 0;
    db->tables = NULL;
    db->rows = NULL;
    return db;
}

// Function to add a new table to the database
void add_table(database* db, char* name, int num_columns, char** column_names, char** column_types) {
    if (db->num_tables >= MAX_TABLES) {
        printf("Error: Maximum number of tables reached. (%d)\n", MAX_TABLES);
        return;
    }
    db->num_tables++;
    db->tables = realloc(db->tables, sizeof(table_metadata) * db->num_tables);
    table_metadata* table = &db->tables[db->num_tables - 1];
    strcpy(table->name, name);
    table->num_columns = num_columns;
    table->column_names = malloc(sizeof(char*) * num_columns);
    table->column_types = malloc(sizeof(char*) * num_columns);
    for (int i = 0; i < num_columns; i++) {
        table->column_names[i] = malloc(MAX_NAME_LEN);
        table->column_types[i] = malloc(MAX_NAME_LEN);
        strcpy(table->column_names[i], column_names[i]);
        strcpy(table->column_types[i], column_types[i]);
    }
}

// Function to add a new row to a table
void add_row(database* db, int table_index, char** values) {
    table_metadata* table = &db->tables[table_index];
    db->rows = realloc(db->rows, sizeof(row_data*) * db->num_tables);
    row_data* row = malloc(sizeof(row_data));
    row->values = malloc(sizeof(char*) * table->num_columns);
    for (int i = 0; i < table->num_columns; i++) {
        row->values[i] = malloc(MAX_VALUE_LEN);
        strcpy(row->values[i], values[i]);
    }
    db->rows[db->num_tables - 1] = row;
}

// Function to print the database
void print_database(database* db) {
    for (int i = 0; i < db->num_tables; i++) {
        table_metadata* table = &db->tables[i];
        printf("Table: %s\n", table->name);
        printf("Columns:\n");
        for (int j = 0; j < table->num_columns; j++) {
            printf(" - %s (%s)\n", table->column_names[j], table->column_types[j]);
        }
        printf("Rows:\n");
        for (int j = 0; j < db->num_tables; j++) {
            row_data* row = db->rows[j];
            for (int k = 0; k < table->num_columns; k++) {
                printf(" - %s", row->values[k]);
            }
            printf("\n");
        }
    }
}

// Main function
int main() {
    // Create a new database
    database* db = create_database();

    // Add a table to the database
    add_table(db, "Customers", 3, (char*[]){"id", "name", "email"}, (char*[]){"int", "string", "string"});

    // Add some rows to the table
    add_row(db, 0, (char*[]){"1", "John Doe", "john.doe@example.com"});
    add_row(db, 0, (char*[]){"2", "Jane Smith", "jane.smith@example.com"});
    add_row(db, 0, (char*[]){"3", "Bill Jones", "bill.jones@example.com"});

    // Print the database
    print_database(db);

    return 0;
}