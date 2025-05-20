//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_COLUMNS 10

typedef struct {
    char **values;
    int num_columns;
} CsvRow;

typedef struct {
    CsvRow **rows;
    int num_rows;
} CsvTable;

CsvRow* parse_csv_row(const char *line, char separator) {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->num_columns = 0;
    row->values = malloc(MAX_COLUMNS * sizeof(char*));

    char *field = strtok((char*) line, &separator);

    while (field != NULL) {
        row->values[row->num_columns] = strdup(field);
        row->num_columns++;
        field = strtok(NULL, &separator);
    }

    return row;
}

CsvTable* read_csv_file(const char *filename, char separator) {
    CsvTable *table = malloc(sizeof(CsvTable));
    table->num_rows = 0;
    table->rows = malloc(MAX_LINE_LENGTH * sizeof(CsvRow*));

    FILE *file = fopen(filename, "r");

    if (file) {
        char line[MAX_LINE_LENGTH];
        while (fgets(line, MAX_LINE_LENGTH, file)) {
            CsvRow *row = parse_csv_row(line, separator);
            if (row != NULL) {
                table->rows[table->num_rows] = row;
                table->num_rows++;
            }
        }
        fclose(file);
    }

    return table;
}

int main() {
    CsvTable *table = read_csv_file("example.csv", ',');

    printf("Num rows: %d\n", table->num_rows);

    for (int i = 0; i < table->num_rows; i++) {
        CsvRow *row = table->rows[i];

        for (int j = 0; j < row->num_columns; j++) {
            printf("%s,", row->values[j]);
        }

        printf("\n");
    }

    return 0;
}