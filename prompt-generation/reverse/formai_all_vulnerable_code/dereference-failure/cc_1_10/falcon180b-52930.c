//Falcon-180B DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 200

// Define the structure for a table
typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} table_t;

// Define the structure for a database
typedef struct {
    int num_tables;
    table_t *tables;
} database_t;

// Function to initialize a new database
database_t *database_init(int num_tables) {
    database_t *db = (database_t *) malloc(sizeof(database_t));
    db->num_tables = num_tables;
    db->tables = (table_t *) malloc(sizeof(table_t) * num_tables);
    for (int i = 0; i < num_tables; i++) {
        strcpy(db->tables[i].name, "");
        strcpy(db->tables[i].value, "");
    }
    return db;
}

// Function to add a new table to the database
void database_add_table(database_t *db, char *name, char *value) {
    strcpy(db->tables[db->num_tables - 1].name, name);
    strcpy(db->tables[db->num_tables - 1].value, value);
}

// Function to print the contents of a table
void table_print(table_t *table) {
    printf("Name: %s\nValue: %s\n", table->name, table->value);
}

// Function to print the contents of a database
void database_print(database_t *db) {
    for (int i = 0; i < db->num_tables; i++) {
        table_print(&db->tables[i]);
    }
}

// Function to query the database for a specific value
void database_query(database_t *db, char *value) {
    for (int i = 0; i < db->num_tables; i++) {
        if (strcmp(db->tables[i].value, value) == 0) {
            printf("Table %d contains the value '%s'\n", i + 1, value);
        }
    }
}

int main() {
    database_t *db = database_init(3);
    database_add_table(db, "Table 1", "Value 1");
    database_add_table(db, "Table 2", "Value 2");
    database_add_table(db, "Table 3", "Value 3");
    database_print(db);
    database_query(db, "Value 2");
    return 0;
}