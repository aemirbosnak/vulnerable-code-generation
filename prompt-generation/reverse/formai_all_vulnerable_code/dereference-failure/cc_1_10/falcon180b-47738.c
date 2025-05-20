//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} table_t;

table_t *create_table(int rows, int cols) {
    table_t *t = malloc(sizeof(table_t));
    t->data = malloc(rows * cols * sizeof(char));
    t->rows = rows;
    t->cols = cols;
    return t;
}

void set_data(table_t *t, int row, int col, char *data) {
    int index = row * t->cols + col;
    strcpy(&t->data[index], data);
}

char *get_data(table_t *t, int row, int col) {
    int index = row * t->cols + col;
    return &t->data[index];
}

void print_table(table_t *t) {
    for (int i = 0; i < t->rows; i++) {
        for (int j = 0; j < t->cols; j++) {
            printf("%s ", get_data(t, i, j));
        }
        printf("\n");
    }
}

void delete_table(table_t *t) {
    free(t->data);
    free(t);
}

int main() {
    table_t *t = create_table(3, 3);
    set_data(t, 0, 0, "Name");
    set_data(t, 0, 1, "Age");
    set_data(t, 0, 2, "Gender");
    set_data(t, 1, 0, "John");
    set_data(t, 1, 1, "25");
    set_data(t, 1, 2, "Male");
    set_data(t, 2, 0, "Jane");
    set_data(t, 2, 1, "30");
    set_data(t, 2, 2, "Female");
    print_table(t);
    delete_table(t);
    return 0;
}