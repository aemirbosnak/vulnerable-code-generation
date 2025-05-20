//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing CSV file contents
typedef struct {
    char **data;    // A 2D array to store the file content
    int rows;       // Number of rows in the file
    int cols;       // Number of columns in the file
} CSVFile;

// Function to parse CSV file and store in CSVFile structure
CSVFile* readCSVFile(char *filename) {
    FILE *fp = fopen(filename, "r");    // Open the file in read mode
    if (fp == NULL) {   // Check if file opened successfully
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    CSVFile *csv = (CSVFile*) malloc(sizeof(CSVFile)); // Allocate memory for CSVFile structure
    csv->rows = csv->cols = 0;      // Initialize rows and columns to zero

    // Read first line of file to determine number of columns
    char buffer[1024];
    fgets(buffer, 1024, fp);
    char *token = strtok(buffer, ",");
    while (token != NULL) {
        csv->cols++;
        token = strtok(NULL, ",");
    }

    // Initialize 2D array to store the file contents
    csv->data = (char**) malloc(sizeof(char*) * 1024);
    for (int i = 0; i < 1024; i++) {
        csv->data[i] = (char*) malloc(sizeof(char) * 256);
    }

    // Parse remaining lines of file and store in 2D array
    while (fgets(buffer, 1024, fp)) {
        int colIndex = 0;
        char *colValue = strtok(buffer, ",");
        while (colValue != NULL) {
            strcpy(csv->data[csv->rows * csv->cols + colIndex], colValue);
            colIndex++;
            colValue = strtok(NULL, ",");
        }
        csv->rows++;
    }

    fclose(fp); // Close the file
    return csv; // Return the parsed CSVFile structure
}

// Utility function to print the contents of CSVFile structure
void printCSVFile(CSVFile *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    CSVFile *csv = readCSVFile("example.csv");    // Read CSV file
    printCSVFile(csv);  // Print CSV file contents
    return 0;
}