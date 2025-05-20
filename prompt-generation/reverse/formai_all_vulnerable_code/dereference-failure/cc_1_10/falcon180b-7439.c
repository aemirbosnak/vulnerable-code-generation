//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *data;
    int rows;
    int cols;
} Table;

Table *create_table(int rows, int cols) {
    Table *table = malloc(sizeof(Table));
    table->data = malloc(rows * cols * sizeof(char));
    table->rows = rows;
    table->cols = cols;
    return table;
}

void destroy_table(Table *table) {
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%c", table->data[i * table->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(5, 5);
    char input[MAX_ROWS * MAX_COLS];
    int row, col;

    printf("Enter data for the table:\n");
    fgets(input, sizeof(input), stdin);

    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            table->data[row * 5 + col] = input[row * 5 + col];
        }
    }

    printf("The table:\n");
    print_table(table);

    destroy_table(table);

    return 0;
}