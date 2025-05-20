//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a CSV field
#define MAX_FIELD_LENGTH 128

// Define the maximum number of rows to read from a CSV file
#define MAX_ROWS 100

// Define the CSV reader struct
struct CSVReader {
    char filename[MAX_FIELD_LENGTH];
    char delimiter;
    int num_columns;
    char** data;
};

// Function to read a CSV file and store its data in a CSVReader struct
void read_csv_file(struct CSVReader* reader) {
    // Open the CSV file for reading
    FILE* file = fopen(reader->filename, "r");
    if (file == NULL) {
        printf("Error opening %s", reader->filename);
        exit(1);
    }

    // Initialize the CSV data array
    reader->data = (char**) malloc(MAX_ROWS * sizeof(char*));
    for (int i = 0; i < MAX_ROWS; i++) {
        reader->data[i] = (char*) malloc(MAX_FIELD_LENGTH * sizeof(char));
    }

    // Read each row of the CSV file and store its data in the CSV data array
    char line[MAX_FIELD_LENGTH];
    int row_count = 0;
    while (fgets(line, MAX_FIELD_LENGTH, file) != NULL && row_count < MAX_ROWS) {
        // Parse each field of the row
        char* field = strtok(line, &reader->delimiter);
        int col_count = 0;
        while (field != NULL && col_count < reader->num_columns) {
            // Copy the field data into the CSV data array
            strcpy(reader->data[row_count * reader->num_columns + col_count], field);
            col_count++;
            field = strtok(NULL, &reader->delimiter);
        }
        row_count++;
    }

    // Close the CSV file and free its resources
    fclose(file);
}

int main() {
    // Initialize a CSVReader struct for reading a sample CSV file
    struct CSVReader reader;
    strcpy(reader.filename, "sample.csv");
    reader.delimiter = ',';
    reader.num_columns = 3;

    // Read the CSV file and store its data in the CSVReader struct
    read_csv_file(&reader);

    // Print the CSV data array
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < reader.num_columns; j++) {
            printf("%s ", reader.data[i * reader.num_columns + j]);
        }
        printf("\n");
    }

    // Free the resources used by the CSV data array
    for (int i = 0; i < MAX_ROWS; i++) {
        free(reader.data[i]);
    }
    free(reader.data);

    return 0;
}