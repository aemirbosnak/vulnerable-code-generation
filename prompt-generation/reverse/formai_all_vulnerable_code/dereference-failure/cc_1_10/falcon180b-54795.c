//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ELEMENTS 1000

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **) malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *) malloc(num_cols * sizeof(char));
        for (int j = 0; j < num_cols; j++) {
            table->data[i][j] = '\0';
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
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%c", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3, 3);
    strcpy(table->data[0], "Name");
    strcpy(table->data[1], "Age");
    strcpy(table->data[2], "Gender");

    strcpy(table->data[0][1], "John");
    strcpy(table->data[0][2], "Male");

    strcpy(table->data[1][1], "25");

    strcpy(table->data[2][1], "Jane");
    strcpy(table->data[2][2], "Female");

    print_table(table);

    destroy_table(table);
    return 0;
}