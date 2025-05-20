//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1024

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSVData;

CSVData *read_csv(FILE *file) {
    CSVData *data = malloc(sizeof(CSVData));
    data->num_rows = 0;
    data->num_cols = 0;
    data->data = malloc(MAX_ROWS * sizeof(char*));

    char line[MAX_CELL_SIZE];
    char *token = strtok(line, ",");
    int row = 0;
    int col = 0;

    while (token!= NULL) {
        if (row >= MAX_ROWS) {
            fprintf(stderr, "Error: Too many rows in CSV file.\n");
            exit(1);
        }
        if (col >= MAX_COLS) {
            fprintf(stderr, "Error: Too many columns in CSV file.\n");
            exit(1);
        }

        data->data[row] = realloc(data->data[row], sizeof(char) * (col + 1));
        strncpy(data->data[row] + col, token, MAX_CELL_SIZE);
        col++;

        if (col == data->num_cols) {
            data->num_cols++;
        }

        token = strtok(NULL, ",");
        row++;
    }

    if (row == 0) {
        fprintf(stderr, "Error: CSV file is empty.\n");
        exit(1);
    }

    data->num_rows = row;

    return data;
}

void print_csv(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s ", data->data[i] + j);
        }
        printf("\n");
    }
}

void free_csv(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open CSV file.\n");
        exit(1);
    }

    CSVData *data = read_csv(file);
    print_csv(data);

    free_csv(data);
    fclose(file);

    return 0;
}