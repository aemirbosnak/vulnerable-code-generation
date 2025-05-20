//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_FIELD_LENGTH 50

typedef struct {
    char data[MAX_FIELD_LENGTH];
    int length;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} row_t;

typedef struct {
    row_t **rows;
    int num_rows;
    int num_columns;
} table_t;

void create_table(table_t *table, int num_columns) {
    table->rows = (row_t **) malloc(MAX_ROWS * sizeof(row_t *));
    table->num_rows = 0;
    table->num_columns = num_columns;

    for (int i = 0; i < MAX_ROWS; i++) {
        table->rows[i] = (row_t *) malloc(MAX_COLUMNS * sizeof(row_t));
        table->rows[i]->fields = (field_t *) malloc(MAX_COLUMNS * sizeof(field_t));
        table->rows[i]->num_fields = 0;
    }
}

void add_row(table_t *table, char **data) {
    row_t *row = table->rows[table->num_rows++];

    for (int i = 0; i < table->num_columns; i++) {
        row->fields[i].length = strlen(data[i]);
        strcpy(row->fields[i].data, data[i]);
    }
}

void print_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s\t", table->rows[i]->fields[j].data);
        }
        printf("\n");
    }
}

int main() {
    table_t table;
    char *data[MAX_COLUMNS];

    create_table(&table, 3);

    data[0] = "John";
    data[1] = "Doe";
    data[2] = "25";
    add_row(&table, data);

    data[0] = "Jane";
    data[1] = "Doe";
    data[2] = "30";
    add_row(&table, data);

    print_table(&table);

    return 0;
}