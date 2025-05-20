//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    int row;
    int col;
    char *value;
} Cell;

typedef struct {
    Cell *cells;
    int row_count;
    int col_count;
} Table;

void init_table(Table *table) {
    table->cells = (Cell *)malloc(MAX_ROW * MAX_COL * sizeof(Cell));
    table->row_count = 0;
    table->col_count = 0;
}

void add_row(Table *table) {
    table->row_count++;
}

void add_col(Table *table) {
    table->col_count++;
}

void set_cell(Table *table, int row, int col, char *value) {
    table->cells[row * table->col_count + col].row = row;
    table->cells[row * table->col_count + col].col = col;
    table->cells[row * table->col_count + col].value = value;
}

void print_table(Table *table) {
    for (int i = 0; i < table->row_count; i++) {
        for (int j = 0; j < table->col_count; j++) {
            printf("%s\t", table->cells[i * table->col_count + j].value);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    init_table(&table);
    FILE *fp = fopen("example.csv", "r");
    if (!fp) {
        printf("Error: cannot open file\n");
        return 1;
    }
    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        int row = 0;
        int col = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            set_cell(&table, row, col++, token);
            token = strtok(NULL, ",");
        }
        add_row(&table);
    }
    fclose(fp);
    print_table(&table);
    return 0;
}