//Falcon-180B DATASET v1.0 Category: Database querying ; Style: curious
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
    Data **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(char *name) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->name = name;
    table->data = (Data **) malloc(MAX_ROWS * sizeof(Data *));
    table->num_rows = 0;
    table->num_cols = 0;
    return table;
}

int add_row(Table *table, char *row_data, int num_cols) {
    Data *data = (Data *) malloc(sizeof(Data));
    data->data = (char *) malloc(num_cols * MAX_DATA_SIZE);
    strcpy(data->data, row_data);
    data->size = strlen(row_data);
    table->data[table->num_rows++] = data;
    if (num_cols > table->num_cols) {
        table->num_cols = num_cols;
    }
    return 0;
}

int add_col(Table *table, char *col_name) {
    table->num_cols++;
    return 0;
}

int main() {
    Table *table = create_table("my_table");
    add_row(table, "John Doe", 2);
    add_row(table, "Jane Doe", 2);
    add_col(table, "Age");
    add_col(table, "Gender");
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i]->data);
        }
        printf("\n");
    }
    return 0;
}