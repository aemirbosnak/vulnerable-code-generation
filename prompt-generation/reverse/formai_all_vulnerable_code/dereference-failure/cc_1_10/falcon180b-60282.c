//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_TABLES 100

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    int **data;
} Table;

Table *tables[MAX_TABLES];
int num_tables = 0;

void create_table(char *name, int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->name = strdup(name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (int **)malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (int *)malloc(num_cols * sizeof(int));
    }
    tables[num_tables++] = table;
}

void insert_row(char *table_name, int *row_data, int num_cols) {
    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i]->name, table_name) == 0) {
            for (int j = 0; j < num_cols; j++) {
                tables[i]->data[tables[i]->num_rows - 1][j] = row_data[j];
            }
            break;
        }
    }
}

void print_table(char *table_name) {
    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i]->name, table_name) == 0) {
            for (int j = 0; j < tables[i]->num_rows; j++) {
                for (int k = 0; k < tables[i]->num_cols; k++) {
                    printf("%d ", tables[i]->data[j][k]);
                }
                printf("\n");
            }
            break;
        }
    }
}

int main() {
    create_table("table1", 3, 3);
    create_table("table2", 2, 2);
    insert_row("table1", (int []) { 1, 2, 3 }, 3);
    insert_row("table2", (int []) { 4, 5 }, 2);
    print_table("table1");
    print_table("table2");
    return 0;
}