//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Define a struct to hold a row of data from the CSV file
typedef struct {
    char **columns; // An array of strings representing each column in the row
    int num_columns; // The number of columns in the row
} CsvRow;

// Define a struct to hold the CSV file data
typedef struct {
    CsvRow **rows; // An array of CsvRows representing each row of data in the CSV file
    int num_rows; // The number of rows in the CSV file
    int num_columns; // The number of columns in the CSV file
} CsvData;

// Function to allocate memory for a CsvRow struct
CsvRow *csv_row_new(int num_columns) {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->num_columns = num_columns;
    row->columns = malloc(num_columns * sizeof(char *));
    for (int i = 0; i < num_columns; i++) {
        row->columns[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    return row;
}

// Function to free memory for a CsvRow struct
void csv_row_free(CsvRow *row) {
    for (int i = 0; i < row->num_columns; i++) {
        free(row->columns[i]);
    }
    free(row->columns);
    free(row);
}

// Function to allocate memory for a CsvData struct
CsvData *csv_data_new() {
    CsvData *data = malloc(sizeof(CsvData));
    data->num_rows = 0;
    data->num_columns = 0;
    data->rows = NULL;
    return data;
}

// Function to free memory for a CsvData struct
void csv_data_free(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        csv_row_free(data->rows[i]);
    }
    free(data->rows);
    free(data);
}

// Function to read a line from a CSV file and split it into columns
CsvRow *csv_row_read(FILE *file) {
    CsvRow *row = NULL;
    char line[MAX_LINE_LENGTH];
    char *token;
    if (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int num_columns = 0;
        row = csv_row_new(num_columns);
        token = strtok(line, ",");
        while (token != NULL) {
            if (num_columns >= row->num_columns) {
                int old_num_columns = row->num_columns;
                row->num_columns += 10;
                row->columns = realloc(row->columns, row->num_columns * sizeof(char *));
                for (int i = old_num_columns; i < row->num_columns; i++) {
                    row->columns[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
                }
            }
            strcpy(row->columns[num_columns], token);
            num_columns++;
            token = strtok(NULL, ",");
        }
        if (num_columns < row->num_columns) {
            row->num_columns = num_columns;
            row->columns = realloc(row->columns, row->num_columns * sizeof(char *));
        }
    }
    return row;
}

// Function to read a CSV file and store the data in a CsvData struct
CsvData *csv_data_read(const char *filename) {
    CsvData *data = csv_data_new();
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        CsvRow *row;
        while ((row = csv_row_read(file)) != NULL) {
            if (data->num_rows == 0) {
                data->num_columns = row->num_columns;
            } else if (row->num_columns != data->num_columns) {
                csv_row_free(row);
                continue;
            }
            data->num_rows++;
            data->rows = realloc(data->rows, data->num_rows * sizeof(CsvRow *));
            data->rows[data->num_rows - 1] = row;
        }
        fclose(file);
    }
    return data;
}

// Function to print the contents of a CsvData struct
void csv_data_print(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s", data->rows[i]->columns[j]);
            if (j < data->num_columns - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

// Example usage
int main() {
    CsvData *data = csv_data_read("example.csv");
    if (data != NULL) {
        csv_data_print(data);
        csv_data_free(data);
    }
    return 0;
}