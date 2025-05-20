//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 1000 // Maximum size of a line

// Function to split a string using delimiter
void split(char* str, char delimiter, char** tokens) {
    char* token = strtok(str, delimiter);
    int count = 0;
    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, delimiter);
    }
}

// Function to read a CSV file
void read_csv(FILE* file, int num_columns, char** data) {
    char line[MAX_LINE_SIZE];
    int row = 0;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char delimiter = ',';
        char* token;
        int col = 0;
        split(line, delimiter, (char**)&token);
        while (token!= NULL && col < num_columns) {
            data[row][col++] = token;
            token = strtok(NULL, delimiter);
        }
        row++;
    }
}

// Function to print a 2D array
void print_array(int rows, int cols, char** data) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    FILE* file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_rows, num_columns;
    char** data;

    // Get number of rows and columns
    fscanf(file, "%d,%d", &num_rows, &num_columns);

    // Allocate memory for data
    data = (char**)malloc(sizeof(char*) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        data[i] = (char*)malloc(sizeof(char) * (num_columns * MAX_LINE_SIZE));
    }

    // Read CSV file
    read_csv(file, num_columns, data);

    // Print CSV data
    printf("CSV Data:\n");
    print_array(num_rows, num_columns, data);

    // Free memory
    for (int i = 0; i < num_rows; i++) {
        free(data[i]);
    }
    free(data);

    fclose(file);
    return 0;
}