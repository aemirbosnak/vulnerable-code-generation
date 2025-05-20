//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100

typedef struct {
    char *name;
    char *type;
    int size;
} Column;

typedef struct {
    Column columns[MAX_COLUMNS];
    int num_columns;
    char *data[MAX_ROWS][MAX_COLUMNS];
    int num_rows;
} Table;

Table *create_table(char *name) {
    Table *table = malloc(sizeof(Table));
    table->num_columns = 0;
    table->num_rows = 0;
    return table;
}

void add_column(Table *table, char *name, char *type, int size) {
    if (table->num_columns >= MAX_COLUMNS) {
        return;
    }
    Column column;
    column.name = malloc(strlen(name) + 1);
    strcpy(column.name, name);
    column.type = malloc(strlen(type) + 1);
    strcpy(column.type, type);
    column.size = size;
    table->columns[table->num_columns++] = column;
}

void add_row(Table *table, char **values) {
    if (table->num_rows >= MAX_ROWS) {
        return;
    }
    for (int i = 0; i < table->num_columns; i++) {
        table->data[table->num_rows][i] = malloc(strlen(values[i]) + 1);
        strcpy(table->data[table->num_rows][i], values[i]);
    }
    table->num_rows++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_columns; i++) {
        printf("%s\t", table->columns[i].name);
    }
    printf("\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s\t", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table("people");
    add_column(table, "name", "VARCHAR", 255);
    add_column(table, "age", "INT", 11);
    add_column(table, "city", "VARCHAR", 255);
    add_row(table, (char *[]) {"John", "30", "New York"});
    add_row(table, (char *[]) {"Mary", "25", "London"});
    add_row(table, (char *[]) {"Bob", "40", "Paris"});
    print_table(table);
    return 0;
}