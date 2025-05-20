//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Cell;

typedef struct {
    int rows;
    int cols;
    Cell **data;
} Table;

Table *create_table(int rows, int cols) {
    Table *t = (Table *) malloc(sizeof(Table));
    t->rows = rows;
    t->cols = cols;
    t->data = (Cell **) malloc(rows * sizeof(Cell *));
    for (int i = 0; i < rows; i++) {
        t->data[i] = (Cell *) malloc(cols * sizeof(Cell));
    }
    return t;
}

void destroy_table(Table *t) {
    for (int i = 0; i < t->rows; i++) {
        for (int j = 0; j < t->cols; j++) {
            free(t->data[i][j].name);
            free(t->data[i][j].value);
        }
        free(t->data[i]);
    }
    free(t->data);
    free(t);
}

void print_table(Table *t) {
    for (int i = 0; i < t->rows; i++) {
        for (int j = 0; j < t->cols; j++) {
            printf("%s = %s\n", t->data[i][j].name, t->data[i][j].value);
        }
    }
}

int main() {
    srand(time(NULL));
    int rows = rand() % MAX_ROWS + 1;
    int cols = rand() % MAX_COLS + 1;
    Table *t = create_table(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char name[MAX_NAME_LEN];
            char value[MAX_VALUE_LEN];
            sprintf(name, "Cell_%d_%d", i, j);
            sprintf(value, "%d", rand() % 100);
            strcpy(t->data[i][j].name, name);
            strcpy(t->data[i][j].value, value);
        }
    }
    print_table(t);
    destroy_table(t);
    return 0;
}