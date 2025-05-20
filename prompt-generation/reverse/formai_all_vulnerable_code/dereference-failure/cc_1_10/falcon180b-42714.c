//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

// Function to read a line from the CSV file and store it in a buffer
char* read_line(FILE* fp) {
    char* buffer = NULL;
    size_t size = 0;
    ssize_t read;

    buffer = malloc(MAX_CELL_SIZE * sizeof(char));
    if (buffer == NULL) {
        printf("Error: Failed to allocate memory for buffer.\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&buffer, &size, fp))!= -1) {
        if (read > 0) {
            buffer[read - 1] = '\0';
        }
    }

    return buffer;
}

// Function to split a line into cells and store them in an array
void split_line(char* line, char** cells, int* num_cells) {
    char* token = strtok(line, ",");
    int count = 0;

    *num_cells = 0;

    while (token!= NULL) {
        cells[*num_cells] = token;
        (*num_cells)++;
        token = strtok(NULL, ",");
        count++;

        if (count >= MAX_COLS) {
            printf("Error: Maximum number of columns exceeded.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE* fp) {
    char* line = NULL;
    char** cells = NULL;
    int num_cells = 0;

    while ((line = read_line(fp))!= NULL) {
        split_line(line, &cells, &num_cells);
        for (int i = 0; i < num_cells; i++) {
            printf("%s ", cells[i]);
        }
        printf("\n");

        free(line);
        for (int i = 0; i < num_cells; i++) {
            free(cells[i]);
        }
        free(cells);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <CSV file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Failed to open CSV file.\n");
        exit(EXIT_FAILURE);
    }

    read_csv_file(fp);

    fclose(fp);
    return 0;
}