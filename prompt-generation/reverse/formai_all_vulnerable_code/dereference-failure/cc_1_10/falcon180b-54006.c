//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int size;
} Data;

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    Data **data;
} Table;

Table *create_table(char *name, int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->name = strdup(name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (Data **)malloc(num_rows * sizeof(Data *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (Data *)malloc(sizeof(Data));
        table->data[i]->data = (char *)malloc(MAX_DATA_SIZE);
        table->data[i]->size = 0;
    }
    return table;
}

void delete_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]->data);
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

void set_cell_value(Table *table, int row, int col, char *value) {
    Data *data = table->data[row];
    if (data->size >= MAX_DATA_SIZE) {
        printf("Error: Cell value too large.\n");
        return;
    }
    strncpy(data->data + data->size, value, MAX_DATA_SIZE - data->size);
    data->size += strlen(value);
}

char *get_cell_value(Table *table, int row, int col) {
    Data *data = table->data[row];
    char *value = (char *)malloc(data->size + 1);
    strncpy(value, data->data, data->size);
    value[data->size] = '\0';
    return value;
}

void print_table(Table *table) {
    printf("Table '%s':\n", table->name);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            char *value = get_cell_value(table, i, j);
            printf("%s ", value);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table("example", 2, 3);
    set_cell_value(table, 0, 0, "Hello");
    set_cell_value(table, 0, 1, "World");
    set_cell_value(table, 0, 2, "Foo");
    set_cell_value(table, 1, 0, "Bar");
    set_cell_value(table, 1, 1, "Baz");
    print_table(table);
    delete_table(table);
    return 0;
}