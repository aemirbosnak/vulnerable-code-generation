//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    char **data;
} Table;

Table *create_table(char *name, int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->name = strdup(name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(num_cols * MAX_DATA_SIZE);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    printf("Num Rows: %d\n", table->num_rows);
    printf("Num Cols: %d\n", table->num_cols);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table1 = create_table("table1", 3, 3);
    table1->data[0][0] = strdup("1");
    table1->data[0][1] = strdup("2");
    table1->data[0][2] = strdup("3");
    table1->data[1][0] = strdup("4");
    table1->data[1][1] = strdup("5");
    table1->data[1][2] = strdup("6");
    table1->data[2][0] = strdup("7");
    table1->data[2][1] = strdup("8");
    table1->data[2][2] = strdup("9");

    Table *table2 = create_table("table2", 2, 2);
    table2->data[0][0] = strdup("a");
    table2->data[0][1] = strdup("b");
    table2->data[1][0] = strdup("c");
    table2->data[1][1] = strdup("d");

    print_table(table1);
    print_table(table2);

    destroy_table(table1);
    destroy_table(table2);

    return 0;
}