//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// Define the CSV data structure
typedef struct Csv {
    char **data;
    int rows;
    int columns;
} Csv;

// Parse and extract CSV data from file
Csv *read_csv(char *filename) {
    FILE *csv_file = fopen(filename, "r");
    if (csv_file == NULL) {
        printf("Could not open the file %s\n", filename);
        return NULL;
    }

    char buffer[MAX_BUFFER_SIZE];
    int row_count = 0, column_count = 0;
    Csv *csv_data = malloc(sizeof(Csv));
    csv_data->data = malloc(MAX_BUFFER_SIZE * sizeof(char *));
    while (fgets(buffer, MAX_BUFFER_SIZE, csv_file) != NULL) {
        column_count = 0;
        char *token = strtok(buffer, ",");
        while (token != NULL) {
            csv_data->data[row_count * csv_data->columns + column_count] = strdup(token);
            column_count++;
            token = strtok(NULL, ",");
        }
        row_count++;
        csv_data->rows = row_count;
        csv_data->columns = column_count;
    }

    fclose(csv_file);
    return csv_data;
}

// Print the extracted CSV data
void print_csv(Csv *csv_data) {
    if (csv_data == NULL) {
        printf("No data to print!\n");
        return;
    }

    printf("Rows: %d, Columns: %d\n", csv_data->rows, csv_data->columns);
    for (int i = 0; i < csv_data->rows; i++) {
        for (int j = 0; j < csv_data->columns; j++) {
            printf("%s ", csv_data->data[i * csv_data->columns + j]);
        }
        printf("\n");
    }
}

// Clear the extracted CSV data
void clear_csv(Csv *csv_data) {
    if (csv_data == NULL) {
        return;
    }

    for (int i = 0; i < csv_data->rows * csv_data->columns; i++) {
        free(csv_data->data[i]);
    }
    free(csv_data->data);
    free(csv_data);
}

// Example usage of CSV reader
int main() {
    Csv *csv_data = read_csv("example.csv");
    printf("\nExtracted CSV Data:\n");
    print_csv(csv_data);
    clear_csv(csv_data);
    return 0;
}