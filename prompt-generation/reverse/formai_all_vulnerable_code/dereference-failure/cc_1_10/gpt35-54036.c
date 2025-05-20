//FormAI DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define DATABASE_SIZE 100 // maximum size of the database
#define COLUMN_SIZE 20 // maximum size of a column
#define QUERY_SIZE 100 // maximum size of a query

// Function to trim whitespace characters from a string
char *trim(char *str)
{
    char *end = str + strlen(str) - 1;
    while(isspace(*end)) end--;
    *(end+1) = '\0';
    while(isspace(*str)) str++;
    return str;
}

// Structure to represent a row in the database
typedef struct row {
    int id;
    char *name;
    int age;
} Row;

// Structure to represent a database
typedef struct database {
    int size;
    Row *rows;
} Database;

// Function to create an empty database
Database *create_database()
{
    Database *db = malloc(sizeof(Database));
    db->size = 0;
    db->rows = malloc(DATABASE_SIZE * sizeof(Row));
    return db;
}

// Function to destroy a database
void destroy_database(Database *db)
{
    for(int i=0; i<db->size; i++) {
        free(db->rows[i].name);
    }
    free(db->rows);
    free(db);
}

// Function to insert a row into the database
void insert_row(Database *db, char *values[])
{
    // Create a new row
    Row row;
    row.id = atoi(values[0]);
    row.name = strdup(trim(values[1]));
    row.age = atoi(values[2]);

    // Insert the row into the database
    db->rows[db->size] = row;
    db->size++;
}

// Function to select rows from the database based on a query
Row *select_rows(Database *db, char *query)
{
    // Parse the query to get the column and value to search for
    char column[COLUMN_SIZE];
    char value[COLUMN_SIZE];
    sscanf(query, "select * from users where %s = '%s'", column, value);

    // Create an array to store the matching rows
    Row *rows = malloc(DATABASE_SIZE * sizeof(Row));
    int count = 0;

    // Iterate over rows in the database and check if column matches value
    for(int i=0; i<db->size; i++) {
        if(strcmp(column, "id") == 0 && atoi(value) == db->rows[i].id) {
            rows[count] = db->rows[i];
            count++;
        } else if(strcmp(column, "name") == 0 && strcmp(value, db->rows[i].name) == 0) {
            rows[count] = db->rows[i];
            count++;
        } else if(strcmp(column, "age") == 0 && atoi(value) == db->rows[i].age) {
            rows[count] = db->rows[i];
            count++;
        }
    }

    // Reallocate the array to free up unused memory
    rows = realloc(rows, count * sizeof(Row));
    return rows;
}

int main()
{
    // Create an empty database
    Database *db = create_database();

    // Insert some example data into the database
    char *values1[] = {"1", "Alice", "20"};
    char *values2[] = {"2", "Bob", "30"};
    char *values3[] = {"3", "Charlie", "40"};
    insert_row(db, values1);
    insert_row(db, values2);
    insert_row(db, values3);

    // Search for a row in the database based on a query
    char query[QUERY_SIZE];
    printf("Enter a query: ");
    fgets(query, QUERY_SIZE, stdin);
    Row *search_results = select_rows(db, query);
    for(int i=0; i<sizeof(search_results); i++) {
        printf("ID: %d, Name: %s, Age: %d\n", search_results[i].id, search_results[i].name, search_results[i].age);
    }

    // Free memory used by the search results and the database
    free(search_results);
    destroy_database(db);

    return 0;
}