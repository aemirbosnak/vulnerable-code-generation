//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_ROW {
    char **data;
    int num_cols;
} CSV_ROW;

typedef struct CSV_FILE {
    CSV_ROW **rows;
    int num_rows;
} CSV_FILE;

CSV_FILE *csv_file_read(char *filename) {
    CSV_FILE *file = malloc(sizeof(CSV_FILE));
    file->rows = malloc(MAX_ROWS * sizeof(CSV_ROW));
    file->num_rows = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_COLS];
    while (fgets(line, MAX_COLS, fp) != NULL) {
        CSV_ROW *row = malloc(sizeof(CSV_ROW));
        row->data = malloc(MAX_COLS * sizeof(char *));
        row->num_cols = 0;

        char *ptr = line;
        char **data = row->data;
        while (*ptr) {
            *data++ = strdup(*ptr);
            ptr++;
            row->num_cols++;
        }

        file->rows[file->num_rows++] = row;
    }

    fclose(fp);
    return file;
}

int main() {
    CSV_FILE *file = csv_file_read("data.csv");

    for (int i = 0; i < file->num_rows; i++) {
        CSV_ROW *row = file->rows[i];
        for (int j = 0; j < row->num_cols; j++) {
            printf("%s, ", row->data[j]);
        }
        printf("\n");
    }

    free(file->rows);
    free(file);

    return 0;
}