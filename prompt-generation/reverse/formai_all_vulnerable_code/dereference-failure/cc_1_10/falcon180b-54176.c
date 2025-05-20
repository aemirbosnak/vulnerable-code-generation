//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 100

typedef struct {
    char **data;
    int row_count;
    int col_count;
} CSVData;

CSVData *csv_open(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    CSVData *csv = (CSVData *) malloc(sizeof(CSVData));
    csv->data = NULL;
    csv->row_count = 0;
    csv->col_count = 0;

    char line[MAX_ROW_SIZE];
    while (fgets(line, MAX_ROW_SIZE, file)!= NULL) {
        char *delimiter = strchr(line, ',');
        int col_length = delimiter? delimiter - line : strlen(line);
        if (col_length > MAX_COL_SIZE) {
            printf("Error: column too long\n");
            exit(1);
        }

        csv->col_count = csv->col_count > col_length? csv->col_count : col_length;

        if (csv->data == NULL) {
            csv->data = (char **) malloc(csv->col_count * sizeof(char *));
            for (int i = 0; i < csv->col_count; i++) {
                csv->data[i] = NULL;
            }
        } else {
            csv->data = (char **) realloc(csv->data, csv->col_count * sizeof(char *));
        }

        if (delimiter) {
            *delimiter = '\0';
            csv->data[csv->row_count] = strdup(line);
        } else {
            csv->data[csv->row_count] = strdup(line);
        }
        csv->row_count++;
    }

    fclose(file);
    return csv;
}

void csv_close(CSVData *csv) {
    int i;
    for (i = 0; i < csv->row_count; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

char **csv_get_row(CSVData *csv, int row_num) {
    if (row_num >= csv->row_count) {
        return NULL;
    }

    return csv->data[row_num];
}

int csv_get_col_count(CSVData *csv) {
    return csv->col_count;
}

int csv_get_row_count(CSVData *csv) {
    return csv->row_count;
}

void csv_print(CSVData *csv) {
    int i, j;
    for (i = 0; i < csv->row_count; i++) {
        for (j = 0; j < csv->col_count; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    CSVData *csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);

    return 0;
}