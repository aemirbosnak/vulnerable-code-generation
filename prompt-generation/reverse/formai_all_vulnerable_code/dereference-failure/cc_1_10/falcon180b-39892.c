//Falcon-180B DATASET v1.0 Category: Database querying ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DATA_SIZE 1024

//struct to represent a row of data
typedef struct {
    char *key;
    char *value;
} data_t;

//struct to represent a table
typedef struct {
    data_t **rows;
    int num_rows;
} table_t;

//function to create a new table
table_t *create_table() {
    table_t *table = (table_t *)malloc(sizeof(table_t));
    table->rows = NULL;
    table->num_rows = 0;
    return table;
}

//function to add a row to a table
void add_row(table_t *table, char *key, char *value) {
    data_t *row = (data_t *)malloc(sizeof(data_t));
    row->key = strdup(key);
    row->value = strdup(value);
    table->rows = (data_t **)realloc(table->rows, sizeof(data_t *) * (table->num_rows + 1));
    table->rows[table->num_rows] = row;
    table->num_rows++;
}

//function to print a table
void print_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        data_t *row = table->rows[i];
        printf("%s: %s\n", row->key, row->value);
    }
}

//function to query a table
void query_table(table_t *table, char *query) {
    char *key = strtok(query, " ");
    char *value = strtok(NULL, " ");
    if (key == NULL || value == NULL) {
        printf("Invalid query\n");
        return;
    }
    for (int i = 0; i < table->num_rows; i++) {
        data_t *row = table->rows[i];
        if (strcmp(row->key, key) == 0 && strcmp(row->value, value) == 0) {
            printf("Found matching row: %s = %s\n", row->key, row->value);
            return;
        }
    }
    printf("No matching row found\n");
}

//main function
int main() {
    table_t *table = create_table();
    add_row(table, "name", "John");
    add_row(table, "age", "30");
    add_row(table, "city", "New York");
    print_table(table);
    query_table(table, "name John");
    query_table(table, "age 25");
    query_table(table, "city Chicago");
    return 0;
}