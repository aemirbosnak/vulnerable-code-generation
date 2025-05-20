//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Struct to hold CSV data
typedef struct {
    char **data;
    int rows;
    int columns;
} CSVData;

// Function to initialize the CSVData
CSVData* init_csv_data(int max_rows, int max_columns) {
    CSVData *csv = (CSVData *)malloc(sizeof(CSVData));
    csv->rows = 0;
    csv->columns = max_columns;
    csv->data = (char **)malloc(max_rows * sizeof(char *));
    
    for (int i = 0; i < max_rows; i++) {
        csv->data[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    
    return csv;
}

// Function to free the CSVData
void free_csv_data(CSVData *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

// Function to read CSV file
int read_csv(const char *filename, CSVData *csv) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // Remove trailing newline
        
        // Split line into columns
        char *token;
        int column = 0;
        
        token = strtok(line, ",");
        while (token != NULL && column < csv->columns) {
            strcpy(csv->data[csv->rows * csv->columns + column], token);
            token = strtok(NULL, ",");
            column++;
        }
        
        csv->rows++;
    }

    fclose(file);
    return 0;
}

// Function to print CSV data
void print_csv_data(CSVData *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            printf("%s", csv->data[i * csv->columns + j]);
            if (j < csv->columns - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    // Initialize CSV data structure
    CSVData *csv = init_csv_data(100, MAX_COLUMNS);

    // Read the CSV data
    if (read_csv(argv[1], csv) != 0) {
        free_csv_data(csv);
        return 1;
    }

    // Print the CSV data
    printf("Contents of the CSV file:\n");
    print_csv_data(csv);

    // Free CSV data memory
    free_csv_data(csv);

    return 0;
}