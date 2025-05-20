//Falcon-180B DATASET v1.0 Category: Database querying ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table() {
    Table *t = (Table *)malloc(sizeof(Table));
    t->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    t->num_rows = 0;
    t->num_cols = 0;
    return t;
}

void destroy_table(Table *t) {
    int i;
    for (i = 0; i < t->num_rows; i++) {
        free(t->data[i]);
    }
    free(t->data);
    free(t);
}

void add_row(Table *t, char *row) {
    if (t->num_rows >= MAX_ROWS) {
        printf("Error: Table is full.\n");
        return;
    }
    t->data[t->num_rows] = (char *)malloc(MAX_ROW_SIZE * sizeof(char));
    strcpy(t->data[t->num_rows], row);
    t->num_rows++;
}

void add_col(Table *t, char *col) {
    if (t->num_cols >= MAX_COLS) {
        printf("Error: Table is full.\n");
        return;
    }
    int i;
    for (i = 0; i < t->num_rows; i++) {
        t->data[i] = (char *)realloc(t->data[i], strlen(t->data[i]) + strlen(col) + 2);
        strcat(t->data[i], col);
    }
    t->num_cols++;
}

void print_table(Table *t) {
    int i, j;
    for (i = 0; i < t->num_rows; i++) {
        for (j = 0; j < t->num_cols; j++) {
            printf("%s ", t->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Table *t = create_table();
    add_row(t, "Name");
    add_row(t, "Age");
    add_row(t, "Gender");
    add_col(t, "John");
    add_col(t, "25");
    add_col(t, "Male");
    add_row(t, "Jane");
    add_col(t, "30");
    add_col(t, "Female");
    add_row(t, "Bob");
    add_col(t, "20");
    add_col(t, "Male");
    print_table(t);
    destroy_table(t);
    return 0;
}