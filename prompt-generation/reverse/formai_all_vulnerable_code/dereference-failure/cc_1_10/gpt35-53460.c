//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_DELIMITER_LENGTH 5

typedef struct {
    char** data;
    int num_columns;
} row_t;

typedef struct {
    row_t* rows;
    int num_rows;
} csv_t;

void free_csv(csv_t* csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->rows[i].data);
    }
    free(csv->rows);
    csv->num_rows = 0;
}

csv_t* read_csv(FILE* fp, char* delimiter) {
    csv_t* csv = malloc(sizeof(csv_t));
    csv->num_rows = 0;
    csv->rows = NULL;

    char line[MAX_LINE_LENGTH];
    char* token;
    char* end;
    int row_length = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        row_t row;
        row.num_columns = 0;
        row.data = NULL;

        token = strtok_r(line, delimiter, &end);
        while (token != NULL) {
            row.data = realloc(row.data, sizeof(char*) * (row.num_columns + 1));
            row.data[row.num_columns] = malloc(strlen(token) + 1);
            strcpy(row.data[row.num_columns], token);
            row.num_columns++;

            token = strtok_r(NULL, delimiter, &end);
        }

        if (row.num_columns > 0) {
            if (csv->num_rows == 0) {
                csv->rows = malloc(sizeof(row_t));
            }
            else {
                csv->rows = realloc(csv->rows, sizeof(row_t) * (csv->num_rows + 1));
            }
            csv->rows[csv->num_rows++] = row;

            if (row_length == 0) {
                row_length = row.num_columns;
            }
            else if (row_length != row.num_columns) {
                fprintf(stderr, "CSV Error: row length mismatch at row %d\n", csv->num_rows);
                free_csv(csv);
                return NULL;
            }
        }
    }

    return csv;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [filename] [delimiter]\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    char* delimiter = ",";

    if (argc >= 3) {
        delimiter = argv[2];
    }

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: File '%s' could not be opened\n", filename);
        return 2;
    }

    csv_t* csv = read_csv(fp, delimiter);
    if (csv == NULL) {
        fclose(fp);
        return 3;
    }

    printf("Read %d rows with %d columns each.\n", csv->num_rows, csv->rows[0].num_columns);

    free_csv(csv);
    fclose(fp);

    return 0;
}