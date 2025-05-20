//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    csv_t *csv = malloc(sizeof(csv_t));
    if (csv == NULL) {
        fclose(fp);
        return NULL;
    }

    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Count the number of columns in the line
        int cols = 0;
        char *p = line;
        while (*p != '\0') {
            if (*p == ',') {
                cols++;
            }
            p++;
        }

        // Allocate memory for the data
        csv->data = realloc(csv->data, sizeof(char *) * (csv->rows + 1));
        csv->data[csv->rows] = malloc(sizeof(char) * (cols + 1));

        // Copy the line into the data
        strcpy(csv->data[csv->rows], line);

        // Increment the number of rows and columns
        csv->rows++;
        csv->cols = cols + 1;
    }

    fclose(fp);

    return csv;
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_t *csv = csv_read("data.csv");
    if (csv == NULL) {
        fprintf(stderr, "Error reading CSV file\n");
        return 1;
    }

    // Print the CSV data
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_free(csv);

    return 0;
}