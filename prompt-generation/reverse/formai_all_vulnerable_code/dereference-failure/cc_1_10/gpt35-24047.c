//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char **cols;
    int num_cols;
} CsvRow;

typedef struct {
    CsvRow **rows;
    int num_rows;
    int max_rows;
} CsvTable;

CsvRow *parse_csv_row(char *line, const char *delim) {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->cols = NULL;
    row->num_cols = 0;

    char *col = strtok(line, delim);
    while (col != NULL) {
        row->cols = realloc(row->cols, sizeof(char *) * (row->num_cols + 1));
        row->cols[row->num_cols++] = col;
        col = strtok(NULL, delim);
    }

    return row;
}

CsvTable *parse_csv_file(const char *filename, const char *delim) {
    CsvTable *table = malloc(sizeof(CsvTable));
    table->rows = NULL;
    table->num_rows = 0;
    table->max_rows = 0;

    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        CsvRow *row = parse_csv_row(line, delim);
        table->rows = realloc(table->rows, sizeof(CsvRow *) * (table->num_rows + 1));
        table->rows[table->num_rows++] = row;
        if (table->num_rows == table->max_rows) {
            table->max_rows *= 2;
            table->rows = realloc(table->rows, sizeof(CsvRow *) * table->max_rows);
        }
    }
    fclose(file);

    return table;
}

void print_csv_table(CsvTable *table) {
    for (int i = 0; i < table->num_rows; i++) {
        CsvRow *row = table->rows[i];
        for (int j = 0; j < row->num_cols; j++) {
            printf("%s", row->cols[j]);
            if (j < row->num_cols - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

void free_csv_table(CsvTable *table) {
    for (int i = 0; i < table->num_rows; i++) {
        CsvRow *row = table->rows[i];
        for (int j = 0; j < row->num_cols; j++) {
            free(row->cols[j]);
        }
        free(row->cols);
        free(row);
    }
    free(table->rows);
    free(table);
}

int main() {
    CsvTable *table = parse_csv_file("example.csv", ",");
    print_csv_table(table);
    free_csv_table(table);
    return 0;
}