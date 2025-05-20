//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_VAL_LEN 50

typedef struct {
    char **values;
    int num_rows;
    int num_cols;
} Table;

void create_table(Table *table, int num_rows, int num_cols) {
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->values = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->values[i] = (char *)malloc(num_cols * MAX_VAL_LEN * sizeof(char));
    }
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->values[i]);
    }
    free(table->values);
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->values[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    create_table(&table, 5, 3);

    strcpy(table.values[0][0], "Name");
    strcpy(table.values[0][1], "Age");
    strcpy(table.values[0][2], "Location");

    strcpy(table.values[1][0], "John");
    strcpy(table.values[1][1], "25");
    strcpy(table.values[1][2], "New York");

    strcpy(table.values[2][0], "Jane");
    strcpy(table.values[2][1], "30");
    strcpy(table.values[2][2], "Los Angeles");

    strcpy(table.values[3][0], "Bob");
    strcpy(table.values[3][1], "40");
    strcpy(table.values[3][2], "Chicago");

    strcpy(table.values[4][0], "Alice");
    strcpy(table.values[4][1], "35");
    strcpy(table.values[4][2], "Miami");

    print_table(&table);

    destroy_table(&table);

    return 0;
}