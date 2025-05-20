//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

struct cell {
    char value;
    int row;
    int col;
};

struct table {
    struct cell **data;
    int rows;
    int cols;
};

void create_table(struct table *table, int rows, int cols) {
    table->data = (struct cell **)malloc(rows * sizeof(struct cell *));
    for (int i = 0; i < rows; i++) {
        table->data[i] = (struct cell *)malloc(cols * sizeof(struct cell));
        for (int j = 0; j < cols; j++) {
            table->data[i][j].value = '\0';
            table->data[i][j].row = i;
            table->data[i][j].col = j;
        }
    }
    table->rows = rows;
    table->cols = cols;
}

void destroy_table(struct table *table) {
    for (int i = 0; i < table->rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
}

void print_table(struct table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%c ", table->data[i][j].value);
        }
        printf("\n");
    }
}

int main() {
    struct table table;
    create_table(&table, 5, 5);
    table.data[0][0].value = 'A';
    table.data[0][1].value = 'B';
    table.data[0][2].value = 'C';
    table.data[0][3].value = 'D';
    table.data[0][4].value = 'E';
    table.data[1][0].value = 'F';
    table.data[1][1].value = 'G';
    table.data[1][2].value = 'H';
    table.data[1][3].value = 'I';
    table.data[1][4].value = 'J';
    table.data[2][0].value = 'K';
    table.data[2][1].value = 'L';
    table.data[2][2].value = 'M';
    table.data[2][3].value = 'N';
    table.data[2][4].value = 'O';
    table.data[3][0].value = 'P';
    table.data[3][1].value = 'Q';
    table.data[3][2].value = 'R';
    table.data[3][3].value = 'S';
    table.data[3][4].value = 'T';
    table.data[4][0].value = 'U';
    table.data[4][1].value = 'V';
    table.data[4][2].value = 'W';
    table.data[4][3].value = 'X';
    table.data[4][4].value = 'Y';
    table.data[5][0].value = 'Z';
    table.data[5][1].value = 'a';
    table.data[5][2].value = 'b';
    table.data[5][3].value = 'c';
    table.data[5][4].value = 'd';
    print_table(&table);
    destroy_table(&table);
    return 0;
}