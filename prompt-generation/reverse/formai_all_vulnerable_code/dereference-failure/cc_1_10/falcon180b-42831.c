//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line from the CSV file
char* read_line(FILE* file) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the line
    while ((read = getline(&line, &len, file))!= -1) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
            break;
        } else {
            line = realloc(line, len + 1);
        }
    }

    return line;
}

// Function to parse the CSV data
void parse_data(char* line, int* data, int num_cols) {
    int i = 0;
    char* token = strtok(line, ",");

    // Parse each column
    while (token!= NULL && i < num_cols) {
        data[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }
}

// Function to print the CSV data
void print_data(int* data, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", data[i * num_cols + j]);
        }
        printf("\n");
    }
}

int main() {
    char* filename = "data.csv";
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Read the first line to get the number of columns
    char* line = read_line(file);
    int num_cols = 0;
    char* token = strtok(line, ",");
    while (token!= NULL) {
        num_cols++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the CSV data
    int* data = malloc(sizeof(int) * num_cols * 1000);

    // Read the rest of the file
    int num_rows = 0;
    while ((line = read_line(file))!= NULL) {
        parse_data(line, data + num_rows * num_cols, num_cols);
        num_rows++;
    }

    // Print the CSV data
    print_data(data, num_rows, num_cols);

    // Free memory and close the file
    free(data);
    free(line);
    fclose(file);

    return 0;
}