//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1024
#define MAX_COL_SIZE 1024

// Function to read data from CSV file
void read_csv(FILE *file, char *data, int row_size, int col_size) {
    char line[MAX_ROW_SIZE];
    char *token;
    int row = 0;
    int col = 0;

    // Read each line of the CSV file
    while (fgets(line, MAX_ROW_SIZE, file)!= NULL) {
        // Split the line into tokens
        token = strtok(line, ",");

        // Copy each token to the data array
        while (token!= NULL) {
            if (col >= col_size) {
                printf("Error: Column size exceeded.\n");
                exit(1);
            }

            if (row >= row_size) {
                printf("Error: Row size exceeded.\n");
                exit(1);
            }

            strcpy(data + (row * col_size) + col, token);

            col++;

            token = strtok(NULL, ",");
        }

        row++;
        col = 0;
    }
}

// Function to print data from CSV file
void print_csv(char *data, int row_size, int col_size) {
    int row = 0;
    int col = 0;

    // Print each row of the CSV file
    while (row < row_size) {
        printf("Row %d:\n", row);
        for (col = 0; col < col_size; col++) {
            if (data[(row * col_size) + col]!= '\0') {
                printf("%s\t", data[(row * col_size) + col]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
        row++;
    }
}

int main() {
    FILE *file;
    char *data;
    int row_size, col_size;

    // Open the CSV file
    file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Get the size of the CSV file
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Allocate memory for the CSV data
    data = (char *)malloc(size + 1);
    if (data == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    // Read the CSV data from the file
    read_csv(file, data, size, 3);

    // Print the CSV data
    print_csv(data, 3, 3);

    // Close the CSV file
    fclose(file);

    return 0;
}