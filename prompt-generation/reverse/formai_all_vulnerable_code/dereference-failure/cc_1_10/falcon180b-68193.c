//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a CSV file and return a 2D array of strings
int **readCSV(char *filename) {
    FILE *fp;
    char line[1024];
    int rows = 0, cols = 0;
    int **data = NULL;

    // Open the CSV file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the first line to determine the number of columns
    fgets(line, sizeof(line), fp);
    cols = strlen(line) - 1;

    // Allocate memory for the 2D array
    data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        data[i] = (int *)malloc(cols * sizeof(int));
    }

    // Read the CSV file and store the data in the 2D array
    while (fgets(line, sizeof(line), fp)!= NULL) {
        rows++;
        char *token = strtok(line, ",");
        for (int i = 0; i < cols; i++) {
            data[rows - 1][i] = atoi(token);
            token = strtok(NULL, ",");
        }
    }

    // Close the CSV file
    fclose(fp);

    return data;
}

// Function to print a 2D array of strings
void printArray(int rows, int cols, int **data) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char filename[100] = "example.csv";
    int **data = readCSV(filename);
    if (data!= NULL) {
        printArray(data[0][0], data[0][1], data);
        for (int i = 0; i < data[0][0]; i++) {
            for (int j = 0; j < data[0][1]; j++) {
                printf("%d ", data[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}