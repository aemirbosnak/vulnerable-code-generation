//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int num_cols;
} csv_row;

typedef struct {
    csv_row **rows;
    int num_rows;
} csv_file;

csv_file *read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    csv_file *file = malloc(sizeof(csv_file));
    file->rows = NULL;
    file->num_rows = 0;

    char line[1024];
    char *token;
    while (fgets(line, 1024, fp)) {
        if (file->num_rows == 0) {
            // First row - initialize array of column headers
            csv_row *row = malloc(sizeof(csv_row));
            row->num_cols = 0;
            row->data = NULL;

            token = strtok(line, ",");
            while (token != NULL) {
                row->num_cols++;
                row->data = realloc(row->data, row->num_cols * sizeof(char *));
                row->data[row->num_cols - 1] = strdup(token);
                token = strtok(NULL, ",");
            }

            file->num_rows++;
            file->rows = realloc(file->rows, file->num_rows * sizeof(csv_row *));
            file->rows[file->num_rows - 1] = row;
        } else {
            // Subsequent rows - fill in data array
            csv_row *row = malloc(sizeof(csv_row));
            row->num_cols = file->rows[0]->num_cols;
            row->data = NULL;

            token = strtok(line, ",");
            int i = 0;
            while (token != NULL) {
                row->data = realloc(row->data, row->num_cols * sizeof(char *));
                row->data[i] = strdup(token);
                token = strtok(NULL, ",");
                i++;
            }

            file->num_rows++;
            file->rows = realloc(file->rows, file->num_rows * sizeof(csv_row *));
            file->rows[file->num_rows - 1] = row;
        }
    }

    fclose(fp);
    return file;
}

int main() {
    csv_file *file = read_csv("example.csv");

    // Display column headers
    for (int i = 0; i < file->rows[0]->num_cols; i++) {
        printf("%s\t", file->rows[0]->data[i]);
    }
    printf("\n");

    // Display data rows
    for (int i = 1; i < file->num_rows; i++) {
        for (int j = 0; j < file->rows[i]->num_cols; j++) {
            printf("%s\t", file->rows[i]->data[j]);
        }
        printf("\n");
    }

    return 0;
}