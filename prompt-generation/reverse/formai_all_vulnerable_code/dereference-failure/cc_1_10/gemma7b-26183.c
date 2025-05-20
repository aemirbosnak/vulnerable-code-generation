//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Data {
    char **data;
    int rows;
    int cols;
} CSV_Data;

CSV_Data* csv_read(char* filename) {
    CSV_Data* csv_data = malloc(sizeof(CSV_Data));
    csv_data->data = NULL;
    csv_data->rows = 0;
    csv_data->cols = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Count the number of rows and columns
    int rows = 0;
    int cols = 0;
    char line[MAX_ROWS];
    while (fgets(line, MAX_ROWS, file) != NULL) {
        rows++;
        char* column = strtok(line, ",");
        while (column) {
            cols++;
            column = strtok(NULL, ",");
        }
    }

    // Allocate memory for the data
    csv_data->data = malloc(sizeof(char*) * rows);
    for (int r = 0; r < rows; r++) {
        csv_data->data[r] = malloc(sizeof(char) * cols);
    }

    // Read the data from the file
    rewind(file);
    while (fgets(line, MAX_ROWS, file) != NULL) {
        char* column = strtok(line, ",");
        int r = 0;
        while (column) {
            csv_data->data[r][cols - 1] = column[0];
            column = strtok(NULL, ",");
            r++;
        }
    }

    fclose(file);

    return csv_data;
}

int main() {
    char* filename = "data.csv";
    CSV_Data* csv_data = csv_read(filename);

    if (csv_data) {
        printf("Number of rows: %d\n", csv_data->rows);
        printf("Number of columns: %d\n", csv_data->cols);

        for (int r = 0; r < csv_data->rows; r++) {
            for (int c = 0; c < csv_data->cols; c++) {
                printf("%c ", csv_data->data[r][c]);
            }
            printf("\n");
        }

        free(csv_data->data);
        free(csv_data);
    }

    return 0;
}