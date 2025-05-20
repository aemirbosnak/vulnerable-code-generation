//Falcon-180B DATASET v1.0 Category: Database querying ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char *name;
    int data_size;
    char data[MAX_DATA_SIZE];
} Column;

typedef struct {
    Column *columns;
    int num_rows;
    int num_columns;
} Table;

void create_column(Column *column, char *name, int data_size) {
    column->name = strdup(name);
    column->data_size = data_size;
}

void create_table(Table *table) {
    table->columns = malloc(MAX_COLUMNS * sizeof(Column));
    table->num_rows = 0;
    table->num_columns = 0;
}

void add_column(Table *table, char *name, int data_size) {
    Column *column = malloc(sizeof(Column));
    create_column(column, name, data_size);
    table->columns[table->num_columns++] = *column;
}

void add_row(Table *table, char *data) {
    for (int i = 0; i < table->num_columns; i++) {
        Column *column = &table->columns[i];
        strncpy(column->data, data, column->data_size);
        data += column->data_size;
    }
    table->num_rows++;
}

void print_table(Table *table) {
    printf("+----+");
    for (int i = 0; i < table->num_columns; i++) {
        Column *column = &table->columns[i];
        printf("+----+");
    }
    printf("\n");
    for (int i = 0; i < table->num_rows; i++) {
        printf("|");
        for (int j = 0; j < table->num_columns; j++) {
            Column *column = &table->columns[j];
            printf("%s|", column->data);
        }
        printf("\n");
    }
    printf("+----+\n");
}

int main() {
    Table table;
    create_table(&table);
    add_column(&table, "Name", 50);
    add_column(&table, "Age", 3);
    add_column(&table, "Gender", 7);
    add_row(&table, "John");
    add_row(&table, "22");
    add_row(&table, "Male");
    add_row(&table, "Jane");
    add_row(&table, "25");
    add_row(&table, "Female");
    print_table(&table);
    return 0;
}