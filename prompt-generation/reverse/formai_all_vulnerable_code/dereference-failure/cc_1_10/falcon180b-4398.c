//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_COLUMNS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_columns;
    int *column_types;
    int *column_lengths;
    void **column_data;
} Table;

typedef struct {
    int type;
    int length;
    void *data;
} Column;

Table *create_table(char *name, int num_columns, int *column_types, int *column_lengths) {
    Table *table = malloc(sizeof(Table));
    strncpy(table->name, name, MAX_NAME_LENGTH);
    table->num_columns = num_columns;
    table->column_types = column_types;
    table->column_lengths = column_lengths;
    table->column_data = malloc(num_columns * sizeof(void *));
    for (int i = 0; i < num_columns; i++) {
        table->column_data[i] = malloc(column_lengths[i]);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_columns; i++) {
        free(table->column_data[i]);
    }
    free(table->column_data);
    free(table);
}

void print_table(Table *table) {
    printf("Table name: %s\n", table->name);
    printf("Number of columns: %d\n", table->num_columns);
    for (int i = 0; i < table->num_columns; i++) {
        printf("Column %d: ", i + 1);
        switch (table->column_types[i]) {
            case 1: // int
                printf("int");
                break;
            case 2: // float
                printf("float");
                break;
            case 3: // string
                printf("string");
                break;
            default:
                printf("unknown");
                break;
        }
        printf(" (%d bytes)\n", table->column_lengths[i]);
    }
}

int main() {
    Table *table = create_table("example_table", 3, (int []) {1, 2, 3}, (int []) {4, 8, 50});
    print_table(table);
    destroy_table(table);
    return 0;
}