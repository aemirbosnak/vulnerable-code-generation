//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;   // Pointer to an array of strings for storing data
    int rows;      // Number of rows
    int columns;   // Number of columns
} CSVData;

// Function to allocate memory for the CSVData structure
CSVData* create_csv_data(int rows, int columns) {
    CSVData* csv_data = (CSVData*)malloc(sizeof(CSVData));
    if (csv_data == NULL) {
        perror("Failed to allocate memory for CSV Data");
        return NULL;
    }

    csv_data->data = (char**)malloc(rows * sizeof(char*));
    for(int i = 0; i < rows; i++) {
        csv_data->data[i] = (char*)malloc(columns * MAX_LINE_LENGTH * sizeof(char));
    }
    
    csv_data->rows = rows;
    csv_data->columns = columns;
    return csv_data;
}

// Function to free the allocated memory for CSVData
void free_csv_data(CSVData* csv_data) {
    for (int i = 0; i < csv_data->rows; i++) {
        free(csv_data->data[i]);
    }
    free(csv_data->data);
    free(csv_data);
}

// Function to read CSV file
CSVData* read_csv(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    CSVData* csv_data = create_csv_data(MAX_COLUMNS, MAX_COLUMNS);
    if (csv_data == NULL) {
        fclose(file);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    int row = 0;

    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        int column = 0;

        while (token != NULL && column < MAX_COLUMNS) {
            strcpy(csv_data->data[row * MAX_COLUMNS + column], token);
            token = strtok(NULL, ",");
            column++;
        }

        row++;
        if (row >= MAX_COLUMNS) {
            break; // Prevent buffer overflow
        }
    }

    csv_data->rows = row; // Update actual row count
    fclose(file);
    return csv_data;
}

// Function to print CSV data
void print_csv_data(CSVData* csv_data) {
    for (int i = 0; i < csv_data->rows; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (strlen(csv_data->data[i * MAX_COLUMNS + j]) > 0) { // Check for non-empty data
                printf("%s", csv_data->data[i * MAX_COLUMNS + j]);
                if (j < MAX_COLUMNS - 1) {
                    printf(", ");
                }
            }
        }
        printf("\n");
    }
}

// Function to count occurrences of a specific value in a column
int count_occurrences(CSVData* csv_data, int column, const char* value) {
    int count = 0;

    for (int i = 0; i < csv_data->rows; i++) {
        if (strcmp(csv_data->data[i * MAX_COLUMNS + column], value) == 0) {
            count++;
        }
    }

    return count;
}

// Main function
int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <csv_file> <value_to_search>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* filename = argv[1];
    const char* search_value = argv[2];

    CSVData* csv_data = read_csv(filename);

    if (csv_data == NULL) {
        return EXIT_FAILURE;
    }

    printf("CSV Data Loaded:\n");
    print_csv_data(csv_data);

    // Count occurrences of the search value in the first column (index 0)
    int occurrences = count_occurrences(csv_data, 0, search_value);
    printf("The value '%s' occurs %d times in column 0.\n", search_value, occurrences);

    free_csv_data(csv_data);
    return EXIT_SUCCESS;
}