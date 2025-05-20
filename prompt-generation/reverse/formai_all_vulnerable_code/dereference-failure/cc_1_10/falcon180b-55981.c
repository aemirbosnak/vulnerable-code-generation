//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    char *table_name;
    int num_rows;
    int num_cols;
    void **data;
} Table;

void init_table(Table *table, char *name, int rows, int cols) {
    table->table_name = name;
    table->num_rows = rows;
    table->num_cols = cols;
    table->data = malloc(rows * cols * sizeof(void *));
    memset(table->data, 0, rows * cols * sizeof(void *));
}

int add_row(Table *table) {
    if (table->num_rows >= MAX_ROWS) {
        printf("Table is full.\n");
        return -1;
    }
    table->num_rows++;
    return 0;
}

int add_col(Table *table) {
    if (table->num_cols >= MAX_COLS) {
        printf("Table is full.\n");
        return -1;
    }
    table->num_cols++;
    return 0;
}

int set_value(Table *table, int row, int col, void *value) {
    if (row < 0 || row >= table->num_rows || col < 0 || col >= table->num_cols) {
        printf("Invalid row or column.\n");
        return -1;
    }
    table->data[row * table->num_cols + col] = value;
    return 0;
}

void *get_value(Table *table, int row, int col) {
    if (row < 0 || row >= table->num_rows || col < 0 || col >= table->num_cols) {
        printf("Invalid row or column.\n");
        return NULL;
    }
    return table->data[row * table->num_cols + col];
}

int main() {
    Table people;
    init_table(&people, "People", 0, 2);

    add_row(&people);
    set_value(&people, 0, 0, "Alice");
    set_value(&people, 0, 1, 25);

    add_row(&people);
    set_value(&people, 1, 0, "Bob");
    set_value(&people, 1, 1, 30);

    Person *alice = get_value(&people, 0, 0);
    Person *bob = get_value(&people, 1, 0);

    printf("Alice is %d years old.\n", alice->age);
    printf("Bob is %d years old.\n", bob->age);

    return 0;
}