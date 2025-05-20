//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the first line to get the number of columns
    char line[1024];
    fgets(line, sizeof(line), fp);
    int num_cols = 0;
    char *p = strtok(line, ",");
    while (p != NULL) {
        num_cols++;
        p = strtok(NULL, ",");
    }

    // Allocate memory for the CSV struct
    csv_t *csv = malloc(sizeof(csv_t));
    csv->data = malloc(sizeof(char *) * num_cols);
    csv->num_rows = 0;
    csv->num_cols = num_cols;

    // Read the rest of the lines
    while (fgets(line, sizeof(line), fp)) {
        // Allocate memory for the row
        csv->data = realloc(csv->data, sizeof(char *) * (csv->num_rows + 1));
        csv->data[csv->num_rows] = malloc(sizeof(char) * strlen(line));

        // Copy the line into the row
        strcpy(csv->data[csv->num_rows], line);

        // Increment the number of rows
        csv->num_rows++;
    }

    // Close the file
    fclose(fp);

    return csv;
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    // Read the CSV file
    csv_t *csv = csv_read("data.csv");
    if (csv == NULL) {
        return 1;
    }

    // Print the CSV data
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    // Free the CSV data
    csv_free(csv);

    return 0;
}