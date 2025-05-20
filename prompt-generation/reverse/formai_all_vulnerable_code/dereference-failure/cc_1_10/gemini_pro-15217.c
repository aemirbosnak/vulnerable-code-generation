//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 10

typedef struct {
    char *data;
    int length;
} Column;

typedef struct {
    Column columns[MAX_NUM_COLUMNS];
    int num_columns;
} Row;

typedef struct {
    Row rows[MAX_LINE_LENGTH];
    int num_rows;
} CSV;

CSV *csv_new() {
    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    return csv;
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_columns; j++) {
            free(csv->rows[i].columns[j].data);
        }
    }
    free(csv);
}

int csv_load(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        Row row;
        row.num_columns = 0;

        char *token = strtok(line, ",");
        while (token != NULL) {
            Column column;
            column.length = strlen(token);
            column.data = malloc(column.length + 1);
            strcpy(column.data, token);
            row.columns[row.num_columns++] = column;

            token = strtok(NULL, ",");
        }

        csv->rows[csv->num_rows++] = row;
    }

    fclose(fp);
    return 0;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_columns; j++) {
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
    if (csv_load(csv, "data.csv") == -1) {
        printf("Error loading CSV file.\n");
        return 1;
    }

    csv_print(csv);

    csv_free(csv);
    return 0;
}