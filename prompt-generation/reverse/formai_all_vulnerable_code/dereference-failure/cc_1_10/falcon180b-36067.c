//Falcon-180B DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 10000
#define MAX_TABLES 100

typedef struct {
    char name[50];
    int num_rows;
    int num_columns;
    int **data;
} Table;

Table *tables[MAX_TABLES];
int num_tables = 0;

void create_table(char *name, int num_rows, int num_columns) {
    Table *table = malloc(sizeof(Table));
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(num_columns * sizeof(int));
    }
    tables[num_tables++] = table;
}

void insert_row(char *table_name, int *row_data) {
    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i]->name, table_name) == 0) {
            int **data = tables[i]->data;
            for (int j = 0; j < tables[i]->num_columns; j++) {
                data[tables[i]->num_rows - 1][j] = row_data[j];
            }
            break;
        }
    }
}

void query_rows(char *table_name, int column_num, int value) {
    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i]->name, table_name) == 0) {
            int **data = tables[i]->data;
            for (int j = 0; j < tables[i]->num_rows; j++) {
                if (data[j][column_num] == value) {
                    for (int k = 0; k < tables[i]->num_columns; k++) {
                        printf("%d ", data[j][k]);
                    }
                    printf("\n");
                }
            }
            break;
        }
    }
}

int main() {
    create_table("employees", 5, 3);
    insert_row("employees", (int *) {1, 2, 3});
    insert_row("employees", (int *) {4, 5, 6});
    insert_row("employees", (int *) {7, 8, 9});
    query_rows("employees", 2, 5);
    return 0;
}