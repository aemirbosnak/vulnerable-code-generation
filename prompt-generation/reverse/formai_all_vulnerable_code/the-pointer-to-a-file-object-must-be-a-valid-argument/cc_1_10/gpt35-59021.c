//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 100
#define COLS 100
#define BUFFER_SIZE 1024

int main() {
    // Define variables
    char buffer[BUFFER_SIZE];
    char* values[COLS];
    char** data[ROWS];
    int rows = 0, cols = 0;

    // Read CSV file
    FILE* file = fopen("data.csv", "r");
    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Remove new line character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Split values by comma
        cols = 0;
        values[cols] = strtok(buffer, ",");
        while (values[cols] != NULL && cols < COLS) {
            values[++cols] = strtok(NULL, ",");
        }

        // Store values in data array
        char** row = (char**) malloc(sizeof(char*) * cols);
        for (int i = 0; i < cols; i++) {
            row[i] = values[i];
        }
        data[rows++] = row;
    }
    fclose(file);

    // Print data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s\t", data[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }

    return 0;
}