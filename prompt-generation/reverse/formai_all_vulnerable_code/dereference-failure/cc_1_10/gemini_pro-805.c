//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: active
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

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    // Allocate memory for the CSV data
    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the CSV data into the buffer
    fread(buffer, 1, size, fp);
    buffer[size] = '\0';

    // Close the file
    fclose(fp);

    // Parse the CSV data
    csv_t *csv = malloc(sizeof(csv_t));
    if (csv == NULL) {
        free(buffer);
        return NULL;
    }

    // Get the number of rows and columns
    char *row = buffer;
    char *col = NULL;
    while (*row != '\0') {
        if (*row == '\n') {
            csv->rows++;
        } else if (*row == ',') {
            csv->cols++;
        }
        row++;
    }
    csv->cols++;

    // Allocate memory for the CSV data
    csv->data = malloc(sizeof(char *) * csv->rows);
    if (csv->data == NULL) {
        free(buffer);
        free(csv);
        return NULL;
    }

    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(sizeof(char) * csv->cols);
        if (csv->data[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(csv->data[j]);
            }
            free(csv->data);
            free(buffer);
            free(csv);
            return NULL;
        }
    }

    // Parse the CSV data
    row = buffer;
    col = NULL;
    int row_index = 0;
    int col_index = 0;
    while (*row != '\0') {
        if (*row == '\n') {
            csv->data[row_index][col_index] = '\0';
            row_index++;
            col_index = 0;
        } else if (*row == ',') {
            csv->data[row_index][col_index] = '\0';
            col_index++;
        } else {
            csv->data[row_index][col_index] = *row;
            col_index++;
        }
        row++;
    }
    csv->data[row_index][col_index] = '\0';

    // Free the buffer
    free(buffer);

    // Return the CSV data
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
        return EXIT_FAILURE;
    }

    // Print the CSV data
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    // Free the CSV data
    csv_free(csv);

    return EXIT_SUCCESS;
}