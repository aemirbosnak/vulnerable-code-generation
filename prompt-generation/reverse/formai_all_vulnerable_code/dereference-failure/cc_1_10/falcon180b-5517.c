//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int rows;
    int cols;
    int **data;
} Table;

Table *create_table(char *name, int rows, int cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    strncpy(table->name, name, MAX_NAME_LEN);
    table->rows = rows;
    table->cols = cols;
    table->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        table->data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            table->data[i][j] = 0;
        }
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%d ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table1 = create_table("table1", 3, 3);
    Table *table2 = create_table("table2", 2, 4);

    table1->data[0][0] = 1;
    table1->data[0][1] = 2;
    table1->data[0][2] = 3;
    table1->data[1][0] = 4;
    table1->data[1][1] = 5;
    table1->data[1][2] = 6;
    table1->data[2][0] = 7;
    table1->data[2][1] = 8;
    table1->data[2][2] = 9;

    table2->data[0][0] = 1;
    table2->data[0][1] = 2;
    table2->data[0][2] = 3;
    table2->data[0][3] = 4;
    table2->data[1][0] = 5;
    table2->data[1][1] = 6;
    table2->data[1][2] = 7;
    table2->data[1][3] = 8;

    printf("table1:\n");
    print_table(table1);
    printf("\ntable2:\n");
    print_table(table2);

    destroy_table(table1);
    destroy_table(table2);

    return 0;
}