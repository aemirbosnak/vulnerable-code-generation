//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_VAL_LEN 100

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    char **values;
} table_t;

void init_table(table_t *table, char *name, int num_rows, int num_cols) {
    table->name = strdup(name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->values = (char **)malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->values[i] = (char *)malloc(sizeof(char) * num_cols);
        memset(table->values[i], '\0', num_cols);
    }
}

void destroy_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->values[i]);
    }
    free(table->values);
    free(table->name);
}

void print_table(table_t *table) {
    printf("Table: %s\n", table->name);
    printf("Num Rows: %d\n", table->num_rows);
    printf("Num Cols: %d\n", table->num_cols);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->values[i][j]);
        }
        printf("\n");
    }
}

int main() {
    table_t table1, table2;

    init_table(&table1, "table1", 3, 3);
    strcpy(table1.values[0], "1");
    strcpy(table1.values[1], "2");
    strcpy(table1.values[2], "3");

    init_table(&table2, "table2", 2, 2);
    strcpy(table2.values[0], "a");
    strcpy(table2.values[1], "b");

    print_table(&table1);
    print_table(&table2);

    destroy_table(&table1);
    destroy_table(&table2);

    return 0;
}