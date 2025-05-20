//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10

typedef struct table_cell {
    char value;
    char color;
} table_cell_t;

typedef struct table {
    table_cell_t cells[TABLE_ROWS][TABLE_COLS];
    int row_selected;
    int col_selected;
} table_t;

table_t *create_table(void);
void print_table(table_t *table);
void select_cell(table_t *table, int row, int col);
void toggle_color(table_t *table, int row, int col);
void randomize_colors(table_t *table);
void clear_table(table_t *table);

int main(void) {
    srand(time(NULL));

    table_t *table = create_table();
    print_table(table);

    while (1) {
        int row = rand() % TABLE_ROWS;
        int col = rand() % TABLE_COLS;

        select_cell(table, row, col);

        toggle_color(table, row, col);

        randomize_colors(table);

        clear_table(table);
    }

    return 0;
}

table_t *create_table(void) {
    table_t *table = malloc(sizeof(table_t));

    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            table->cells[i][j].value = ' ';
            table->cells[i][j].color = ' ';
        }
    }

    return table;
}

void print_table(table_t *table) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            printf("%c%c", table->cells[i][j].value, table->cells[i][j].color);
        }
        printf("\n");
    }
}

void select_cell(table_t *table, int row, int col) {
    table->row_selected = row;
    table->col_selected = col;
}

void toggle_color(table_t *table, int row, int col) {
    table->cells[row][col].color = table->cells[row][col].value;
    table->cells[row][col].value = ' ';
}

void randomize_colors(table_t *table) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            table->cells[i][j].color = ' ';
        }
    }

    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            table->cells[i][j].color = (char)rand() % 2;
        }
    }
}

void clear_table(table_t *table) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            table->cells[i][j].value = ' ';
            table->cells[i][j].color = ' ';
        }
    }
}