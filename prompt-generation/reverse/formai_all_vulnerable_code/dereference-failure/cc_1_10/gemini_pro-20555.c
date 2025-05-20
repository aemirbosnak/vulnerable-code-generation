//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the first line to get the number of columns.
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, fp);
    int num_cols = 0;
    char *ptr = strtok(line, ",");
    while (ptr != NULL) {
        num_cols++;
        ptr = strtok(NULL, ",");
    }
    free(line);

    // Read the rest of the lines and store the data in a 2D array.
    csv_t *csv = malloc(sizeof(csv_t));
    csv->num_rows = 0;
    csv->num_cols = num_cols;
    csv->rows = malloc(sizeof(char *) * csv->num_rows);

    while (getline(&line, &len, fp) != -1) {
        csv->num_rows++;
        csv->rows = realloc(csv->rows, sizeof(char *) * csv->num_rows);
        csv->rows[csv->num_rows - 1] = malloc(sizeof(char) * strlen(line) + 1);
        strcpy(csv->rows[csv->num_rows - 1], line);
    }
    free(line);

    // Close the file.
    fclose(fp);

    return csv;
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->rows[i]);
    }
    free(csv->rows);
    free(csv);
}

int main() {
    csv_t *csv = csv_read("data.csv");
    if (csv == NULL) {
        printf("Error reading CSV file.\n");
        return 1;
    }

    // Print the CSV data.
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s", csv->rows[i][j]);
            if (j < csv->num_cols - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    // Free the CSV data.
    csv_free(csv);

    return 0;
}