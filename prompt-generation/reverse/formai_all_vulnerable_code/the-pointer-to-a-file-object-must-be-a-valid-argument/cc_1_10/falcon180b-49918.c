//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to split a line of text into individual fields
char **split_line(char *line) {
    char **fields = NULL;
    char *token = strtok(line, ",");
    int count = 0;

    while (token!= NULL) {
        fields = realloc(fields, sizeof(char *) * ++count);
        fields[count-1] = strdup(token);
        token = strtok(NULL, ",");
    }

    return fields;
}

// Function to read a CSV file and return its contents as a 2D array
int **read_csv(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int rows = 0, cols = 0;
    int **data = NULL;

    // Read the first line to determine the number of columns
    fgets(line, MAX_LINE_LENGTH, file);
    char **header = split_line(line);
    cols = strlen(header[0]) > 0? strlen(header[0]) : 1;

    // Allocate memory for the data array
    data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        data[i] = malloc(sizeof(int) * cols);
    }

    // Read the remaining lines and fill in the data array
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char **row_data = split_line(line);
        if (strlen(row_data[0]) > 0) {
            for (int i = 0; i < cols; i++) {
                data[rows][i] = atoi(row_data[i]);
            }
            rows++;
        }
        for (int i = 0; i < cols; i++) {
            free(row_data[i]);
        }
        free(row_data);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    return data;
}

int main() {
    FILE *file = fopen("example.csv", "r");
    int **data = read_csv(file);
    fclose(file);

    return 0;
}