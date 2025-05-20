//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int value;
    char *label;
} cell;

typedef struct {
    cell **cells;
    int rows;
    int cols;
} table;

table *create_table(int rows, int cols) {
    table *t = malloc(sizeof(table));
    t->rows = rows;
    t->cols = cols;
    t->cells = malloc(sizeof(cell *) * rows);
    for (int i = 0; i < rows; i++) {
        t->cells[i] = malloc(sizeof(cell) * cols);
        for (int j = 0; j < cols; j++) {
            t->cells[i][j].value = 0;
            t->cells[i][j].label = NULL;
        }
    }
    return t;
}

void free_table(table *t) {
    for (int i = 0; i < t->rows; i++) {
        for (int j = 0; j < t->cols; j++) {
            free(t->cells[i][j].label);
        }
        free(t->cells[i]);
    }
    free(t->cells);
    free(t);
}

void print_table(table *t) {
    for (int i = 0; i < t->rows; i++) {
        for (int j = 0; j < t->cols; j++) {
            printf("%d ", t->cells[i][j].value);
        }
        printf("\n");
    }
}

int main() {
    table *t = create_table(3, 3);
    t->cells[0][0].value = 1;
    t->cells[0][0].label = "X";
    t->cells[0][1].value = 2;
    t->cells[0][1].label = "O";
    t->cells[0][2].value = 3;
    t->cells[0][2].label = "X";
    t->cells[1][0].value = 4;
    t->cells[1][0].label = "O";
    t->cells[1][1].value = 5;
    t->cells[1][1].label = "X";
    t->cells[1][2].value = 6;
    t->cells[1][2].label = "O";
    t->cells[2][0].value = 7;
    t->cells[2][0].label = "X";
    t->cells[2][1].value = 8;
    t->cells[2][1].label = "O";
    t->cells[2][2].value = 9;
    t->cells[2][2].label = "X";
    print_table(t);
    free_table(t);
    return 0;
}