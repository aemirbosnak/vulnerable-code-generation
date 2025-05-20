//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_ROWS 1000
#define MAX_NUM_COLS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int num_rows;
    int num_cols;
    int **data;
} Table;

void create_table(Table *table, char *name, int num_rows, int num_cols) {
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (int **)malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (int *)malloc(num_cols * sizeof(int));
        for (int j = 0; j < num_cols; j++) {
            table->data[i][j] = 0;
        }
    }
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
}

void print_table(Table *table) {
    printf("Table name: %s\n", table->name);
    printf("Number of rows: %d\n", table->num_rows);
    printf("Number of columns: %d\n", table->num_cols);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%d ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table table1, table2;
    create_table(&table1, "table1", 3, 3);
    create_table(&table2, "table2", 2, 4);
    print_table(&table1);
    print_table(&table2);
    destroy_table(&table1);
    destroy_table(&table2);
    return 0;
}