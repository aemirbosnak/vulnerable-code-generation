//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_CELL_SIZE 1024

// Define a structure to hold the CSV data
typedef struct {
    char **data; // 2D array of strings
    int rows; // number of rows
    int cols; // number of columns
} CSVData;

// Function to read the CSV file and populate the CSVData structure
CSVData readCSV(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    CSVData csvData;
    csvData.data = (char **)malloc(MAX_ROWS * sizeof(char *));
    csvData.rows = 0;
    csvData.cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csvData.cols++;
            if (csvData.rows >= MAX_ROWS) {
                printf("Error: Maximum number of rows exceeded\n");
                exit(1);
            }
            csvData.data[csvData.rows] = (char *)malloc(strlen(token) + 1);
            strcpy(csvData.data[csvData.rows], token);
            csvData.rows++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return csvData;
}

// Function to print the CSV data in a formatted manner
void printCSV(CSVData csvData) {
    for (int i = 0; i < csvData.rows; i++) {
        for (int j = 0; j < csvData.cols; j++) {
            printf("%s\t", csvData.data[i]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the CSV data
void freeCSV(CSVData csvData) {
    for (int i = 0; i < csvData.rows; i++) {
        free(csvData.data[i]);
    }
    free(csvData.data);
}

int main() {
    CSVData csvData = readCSV("example.csv");
    printCSV(csvData);
    freeCSV(csvData);
    return 0;
}