//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_ROWS 100
#define MAX_NUM_COLUMNS 50

typedef struct {
    char name[MAX_NAME_LEN];
    int num_rows;
    int num_columns;
    int **data;
} Table;

Table *create_table(char *name, int num_rows, int num_columns) {
    Table *table = malloc(sizeof(Table));
    strncpy(table->name, name, MAX_NAME_LEN);
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = malloc(sizeof(int *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(sizeof(int) * num_columns);
        for (int j = 0; j < num_columns; j++) {
            table->data[i][j] = 0;
        }
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    printf("Table name: %s\n", table->name);
    printf("Number of rows: %d\n", table->num_rows);
    printf("Number of columns: %d\n", table->num_columns);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%d ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table("my_table", 3, 4);
    table->data[0][0] = 1;
    table->data[0][1] = 2;
    table->data[0][2] = 3;
    table->data[0][3] = 4;
    table->data[1][0] = 5;
    table->data[1][1] = 6;
    table->data[1][2] = 7;
    table->data[1][3] = 8;
    table->data[2][0] = 9;
    table->data[2][1] = 10;
    table->data[2][2] = 11;
    table->data[2][3] = 12;
    print_table(table);
    destroy_table(table);
    return 0;
}