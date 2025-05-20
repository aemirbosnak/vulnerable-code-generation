//Falcon-180B DATASET v1.0 Category: Database querying ; Style: irregular
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
    Data data;
} Column;

typedef struct {
    Column *cols;
    int num_cols;
    int num_rows;
} Table;

Table *create_table(int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->cols = malloc(num_cols * sizeof(Column));
    table->num_cols = num_cols;
    table->num_rows = 0;
    for (int i = 0; i < num_cols; i++) {
        table->cols[i].name = "";
        table->cols[i].data.data = NULL;
        table->cols[i].data.size = 0;
    }
    return table;
}

void add_row(Table *table, Data *data, int num_cols) {
    for (int i = 0; i < num_cols; i++) {
        Column *col = &table->cols[i];
        if (col->data.data == NULL) {
            col->data.data = malloc(MAX_DATA_SIZE);
            col->data.size = 0;
        }
        if (col->data.size + data[i].size + 1 >= MAX_DATA_SIZE) {
            col->data.data = realloc(col->data.data, col->data.size + data[i].size + MAX_DATA_SIZE);
        }
        strcat(col->data.data, data[i].data);
        col->data.size += data[i].size;
    }
    table->num_rows++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_cols; i++) {
        Column *col = &table->cols[i];
        printf("%s:\t", col->name);
        printf("%s", col->data.data);
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3);
    Data data1 = {"John", 5};
    Data data2 = {"Jane", 6};
    Data data3 = {"Bob", 4};
    add_row(table, &data1, 3);
    add_row(table, &data2, 3);
    add_row(table, &data3, 3);
    print_table(table);
    return 0;
}