//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 10

typedef struct {
    char *data;
    size_t length;
} String;

typedef struct {
    String *columns;
    size_t num_columns;
} Row;

typedef struct {
    Row *rows;
    size_t num_rows;
} CSV;

CSV *csv_new() {
    CSV *csv = malloc(sizeof(CSV));
    csv->rows = NULL;
    csv->num_rows = 0;
    return csv;
}

void csv_free(CSV *csv) {
    for (size_t i = 0; i < csv->num_rows; i++) {
        for (size_t j = 0; j < csv->rows[i].num_columns; j++) {
            free(csv->rows[i].columns[j].data);
        }
        free(csv->rows[i].columns);
    }
    free(csv->rows);
    free(csv);
}

int csv_load(CSV *csv, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        Row row;
        row.num_columns = 0;
        row.columns = NULL;

        char *column_start = line;
        char *column_end;
        while ((column_end = strchr(column_start, ',')) != NULL) {
            String column;
            column.data = column_start;
            column.length = column_end - column_start;

            if (row.num_columns == 0) {
                row.columns = malloc(sizeof(String));
            } else {
                row.columns = realloc(row.columns, (row.num_columns + 1) * sizeof(String));
            }
            row.columns[row.num_columns++] = column;

            column_start = column_end + 1;
        }

        if (*column_start != '\0') {
            String column;
            column.data = column_start;
            column.length = strlen(column_start);

            if (row.num_columns == 0) {
                row.columns = malloc(sizeof(String));
            } else {
                row.columns = realloc(row.columns, (row.num_columns + 1) * sizeof(String));
            }
            row.columns[row.num_columns++] = column;
        }

        if (csv->num_rows == 0) {
            csv->rows = malloc(sizeof(Row));
        } else {
            csv->rows = realloc(csv->rows, (csv->num_rows + 1) * sizeof(Row));
        }
        csv->rows[csv->num_rows++] = row;
    }

    fclose(file);

    return 0;
}

void csv_print(const CSV *csv) {
    for (size_t i = 0; i < csv->num_rows; i++) {
        for (size_t j = 0; j < csv->rows[i].num_columns; j++) {
            printf("%s", csv->rows[i].columns[j].data);
            if (j < csv->rows[i].num_columns - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_new();
    if (csv_load(csv, "data.csv") != 0) {
        printf("Error loading CSV file.\n");
        return 1;
    }

    csv_print(csv);

    csv_free(csv);

    return 0;
}