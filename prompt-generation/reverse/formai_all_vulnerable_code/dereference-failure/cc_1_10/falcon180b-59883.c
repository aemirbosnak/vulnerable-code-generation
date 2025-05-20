//Falcon-180B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_WORDS 1000

typedef struct {
    int row;
    int col;
    char word[MAX_WORDS];
} Cell;

typedef struct {
    int rows;
    int cols;
    Cell **data;
} Table;

Table *create_table(int rows, int cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->rows = rows;
    table->cols = cols;
    table->data = (Cell **)malloc(sizeof(Cell *) * rows);
    for (int i = 0; i < rows; i++) {
        table->data[i] = (Cell *)malloc(sizeof(Cell) * cols);
        for (int j = 0; j < cols; j++) {
            strcpy(table->data[i][j].word, "");
        }
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%s ", table->data[i][j].word);
        }
        printf("\n");
    }
}

void read_table(Table *table, FILE *fp) {
    char line[MAX_WORDS];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, " ");
        int row = 0;
        int col = 0;
        while (token!= NULL) {
            strcpy(table->data[row][col].word, token);
            col++;
            token = strtok(NULL, " ");
        }
        row++;
    }
}

void write_table(Table *table, FILE *fp) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            fprintf(fp, "%s ", table->data[i][j].word);
        }
        fprintf(fp, "\n");
    }
}

int main() {
    Table *table = create_table(3, 3);
    read_table(table, stdin);
    print_table(table);
    write_table(table, stdout);
    destroy_table(table);
    return 0;
}